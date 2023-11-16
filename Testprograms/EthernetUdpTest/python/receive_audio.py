import socket
import numpy as np
import matplotlib.pyplot as plt

UDP_IP = "192.168.33.30"
UDP_PORT = 666

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

channelCount = 32
packetSize = 2048

samplesPerPacket = packetSize // (channelCount * 2)

sampleCount = int(44100 * 2)
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

audiodata = audiodata.reshape(( packet_count * samplesPerPacket, channelCount))

print("plotting")

# plt.plot(audiodata[..., 0])
# plt.show()

fig, axs = plt.subplots(channelCount, 1, figsize=(10, 10), sharex=True)

for i in range(channelCount):
    axs[i].plot(audiodata[..., i])
    axs[i].set_title(f'Channel {i+1}')

plt.xlabel('Sample Index')
plt.tight_layout()
plt.show()