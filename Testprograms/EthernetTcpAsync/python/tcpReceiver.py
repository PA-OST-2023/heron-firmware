import socket
import time

HOST = '192.168.33.80'
PORT = 6666
TCP_CONNECTION_TIMEOUT = 5.0

def main():
    dataBuffer = bytearray()
    magicStartSequence = bytes("HERON666", 'utf-8')

    headerSize = 20
    channelCount = 32
    blockSampleCount = 128
    audioBlockSize = channelCount * blockSampleCount * 2
    packetSize = audioBlockSize + headerSize
    

    while True:                     # Keep trying to connect
        try:
            with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                s.settimeout(0.5)
                s.connect((HOST, PORT))
                s.sendall(b'0')
                print(f"Connected to {HOST}:{PORT}")
                i = 0
                lastReceived = time.time()
                
                while True:         # Keep trying to receive data
                    try:
                        data = s.recv(10000)
                        lastReceived = time.time()
                        if not data:
                            continue
                        dataBuffer.extend(data)

                        headerIndex = dataBuffer.find(magicStartSequence)
                        if headerIndex != -1 and len(dataBuffer) >= packetSize:
                            packetIndex = int.from_bytes(dataBuffer[headerIndex + 8 : headerIndex + 12], 'little')
                            timestamp = int.from_bytes(dataBuffer[headerIndex + 12 : headerIndex + headerSize], 'little')
                            audioData = dataBuffer[headerIndex + headerSize : headerIndex + headerSize + audioBlockSize]
                            dataBuffer = dataBuffer[packetSize:]
                            i+=1
                            if i%100 == 0:
                                # print(f"Received {len(audioData)} bytes: {[int(i) for i in audioData[:20]]}")
                                print(f"Packet index: {packetIndex}, Timestamp: {timestamp/1000000000:.6f}")

                    except (socket.timeout, TimeoutError) as e:      # Don't care about short connection drops, as long as the connection is re-established
                        if(time.time() - lastReceived > TCP_CONNECTION_TIMEOUT):
                            break
                        continue
                    except Exception as e:
                        print("Trying to re-establish connection")
                        break

        except (socket.timeout, TimeoutError, ConnectionRefusedError) as e:
            pass


if __name__ == '__main__':
    main()
