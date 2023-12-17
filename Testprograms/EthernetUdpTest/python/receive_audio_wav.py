import socket
import numpy as np
import wavio

UDP_IP = "192.168.33.30"
UDP_PORT = 666

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

recordTime = 20
channelCount = 32
packetSize = 2048
samplerate = 44100

samplesPerPacket = packetSize // (channelCount * 2)

sampleCount = int(samplerate * recordTime)
packet_count = sampleCount // samplesPerPacket
audiodata = np.empty((packet_count, samplesPerPacket, channelCount), dtype=np.int16)

for sampelData in audiodata:
    try:
        data, addr = sock.recvfrom(packetSize)
        decoded_data = np.frombuffer(data, dtype=np.int16)
        sampelData[:] = decoded_data.reshape((samplesPerPacket, channelCount))
    except KeyboardInterrupt:
        sock.close()
        break
    except Exception as e:
        print("Error:", str(e))


audiodata = audiodata.reshape((-1, channelCount))
output_filename = "output.wav"
wavio.write(output_filename, audiodata, samplerate, sampwidth=2)
print(f"Audio data saved to {output_filename}")