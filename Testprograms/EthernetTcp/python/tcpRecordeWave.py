import socket
import numpy as np
import wavio

HOST = '192.168.40.80'  # The server's IP address
PORT = 6666             # The port used by the server
CHANNEL_COUNT = 32
SAMPLE_RATE = 44100     # Sample rate in Hz
RECORDING_TIME = 120    # Recording time in seconds
TOTAL_SAMPLES = SAMPLE_RATE * RECORDING_TIME  # Total number of samples per channel

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(b'\n')
        print(f"Connected to {HOST}:{PORT}")

        dataBuffer = bytearray()
        audiodata = []

        magicStartSequence = bytes("HERON666", 'utf-8')
        headerSize = 20
        blockSampleCount = 128
        audioBlockSize = CHANNEL_COUNT * blockSampleCount * 2
        packetSize = audioBlockSize + headerSize

        lastPacketIndex = 0
        seconds = 0
        startSeconds = -1

        while len(audiodata) < TOTAL_SAMPLES * CHANNEL_COUNT:
            data = s.recv(10000)
            if not data:
                break
            dataBuffer.extend(data)

            while True:
                headerIndex = dataBuffer.find(magicStartSequence)
                if headerIndex != -1 and len(dataBuffer) >= headerIndex + packetSize:
                    packetIndex = int.from_bytes(dataBuffer[headerIndex + 8 : headerIndex + 12], 'little')
                    timestamp = int.from_bytes(dataBuffer[headerIndex + 12 : headerIndex + headerSize], 'little')
                    audioData = dataBuffer[headerIndex + headerSize : headerIndex + headerSize + audioBlockSize]
                    audiodata.extend(np.frombuffer(audioData, dtype=np.int16))
                    dataBuffer = dataBuffer[headerIndex + packetSize:]

                    if(packetIndex != lastPacketIndex + 1):
                        print(f"Packet Drop Detected: {packetIndex}, Timestamp: {timestamp/1000000000:.6f}")
                    lastPacketIndex = packetIndex

                    if startSeconds == -1:
                        startSeconds = timestamp / 1000000000

                    if timestamp // 1000000000 > seconds:
                        seconds = timestamp // 1000000000
                        print(f"Recording time: {seconds - startSeconds:.2f}/{RECORDING_TIME:.2f} seconds")

                    
                else:
                    break

        audiodata = np.array(audiodata, dtype=np.int16)[:SAMPLE_RATE * RECORDING_TIME * CHANNEL_COUNT]
        audiodata = audiodata.reshape((-1, CHANNEL_COUNT))
        print(f"Total audio data length: {len(audiodata)} frames")

        output_filename = "output.wav"
        wavio.write(output_filename, audiodata, SAMPLE_RATE, sampwidth=2)
        print(f"Audio data saved to {output_filename}")

        print("Closing connection")
        s.close()

if __name__ == '__main__':
    main()
