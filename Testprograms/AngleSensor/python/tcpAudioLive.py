import socket
import numpy as np
import pyaudio

# TCP configuration
TCP_IP = '192.168.33.80'
TCP_PORT = 6666

# Create and connect the TCP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((TCP_IP, TCP_PORT))
sock.sendall(b'\n')  # If needed to initiate the data stream

# Audio configuration
channelCount = 32
headerSize = 20
blockSampleCount = 128
audioBlockSize = channelCount * blockSampleCount * 2
packetSize = audioBlockSize + headerSize
samplerate = 44100

# PyAudio configuration
p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16,
                channels=2,
                rate=samplerate,
                output=True)

# Select channels for right and left (0-indexed)
left_channel = 5
right_channel = 12

magicStartSequence = bytes("HERON666", 'utf-8')
dataBuffer = bytearray()

lastPacketIndex = 0

try:
    while True:
        data = sock.recv(1460 * 8)
        if not data:
            break
        dataBuffer.extend(data)

        headerIndex = dataBuffer.find(magicStartSequence)
        if headerIndex != -1 and len(dataBuffer) >= headerIndex + packetSize:
            packetIndex = int.from_bytes(dataBuffer[headerIndex + 8 : headerIndex + 12], 'little')
            timestamp = int.from_bytes(dataBuffer[headerIndex + 12 : headerIndex + headerSize], 'little')
            audioData = dataBuffer[headerIndex + headerSize:headerIndex + headerSize + audioBlockSize]
            decoded_data = np.frombuffer(audioData, dtype=np.int16).reshape(-1, channelCount)

            if(packetIndex != lastPacketIndex + 1):
                print(f"Packet Drop Detected: {packetIndex}, Timestamp: {timestamp/1000000000:.6f}")
            lastPacketIndex = packetIndex

            # Extract the two channels and interleave them for stereo output
            stereo_data = np.column_stack((decoded_data[:, left_channel], decoded_data[:, right_channel]))
            stereo_data = stereo_data.flatten().astype(np.int16).tobytes()
            stream.write(stereo_data)

            # Update the data buffer
            dataBuffer = dataBuffer[headerIndex + packetSize:]
except KeyboardInterrupt:
    print("Interrupted by user")
except Exception as e:
    print("Error:", str(e))
finally:
    sock.close()
    stream.stop_stream()
    stream.close()
    p.terminate()

print("Audio playback stopped")
