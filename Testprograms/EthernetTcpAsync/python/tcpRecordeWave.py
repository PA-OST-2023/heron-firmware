import socket
import numpy as np
import wavio

HOST = '192.168.40.80'  # The server's IP address
PORT = 6666             # The port used by the server
CHANNEL_COUNT = 32
SAMPLE_RATE = 44100  # Sample rate in Hz
RECORDING_TIME = 5  # Recording time in seconds
TOTAL_SAMPLES = SAMPLE_RATE * RECORDING_TIME * CHANNEL_COUNT  # Total number of samples to record

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(b'\n')
        print(f"Connected to {HOST}:{PORT}")

        dataBuffer = bytearray()
        audiodata = []

        while len(audiodata) < TOTAL_SAMPLES:
            data = s.recv(4096)
            if not data:
                break
            dataBuffer.extend(data)

            if len(dataBuffer) >= 2 * CHANNEL_COUNT:
                num_samples = len(dataBuffer) // (2 * CHANNEL_COUNT)
                received_samples = np.frombuffer(dataBuffer[:num_samples * 2 * CHANNEL_COUNT], dtype=np.int16)
                audiodata.extend(received_samples)
                dataBuffer = dataBuffer[num_samples * 2 * CHANNEL_COUNT:]

        audiodata = np.array(audiodata, dtype=np.int16)[:TOTAL_SAMPLES].reshape((-1, CHANNEL_COUNT))
        print(f"Total audio data length: {len(audiodata)} frames")

        output_filename = "output.wav"
        wavio.write(output_filename, audiodata, SAMPLE_RATE, sampwidth=2)
        print(f"Audio data saved to {output_filename}")

        print("Closing connection")
        s.close()

if __name__ == '__main__':
    main()
