import socket
import numpy as np
import pyaudio

# UDP configuration
UDP_IP = "192.168.33.30"
UDP_PORT = 666

# Create and bind the socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

# Audio configuration
channelCount = 32
packetSize = 2048
samplerate = 44100
samplesPerPacket = packetSize // (channelCount * 2)

# PyAudio configuration
p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16,
                channels=2,
                rate=samplerate,
                output=True)

# Select channels for right and left (0-indexed)
left_channel = 5
right_channel = 12

try:
    while True:
        data, addr = sock.recvfrom(packetSize)
        decoded_data = np.frombuffer(data, dtype=np.int16).reshape(-1, channelCount)
        
        # Extract the two channels and interleave them for stereo output
        stereo_data = np.column_stack((decoded_data[:, left_channel], decoded_data[:, right_channel]))
        stereo_data = stereo_data.flatten().astype(np.int16).tobytes()

        stream.write(stereo_data)
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
