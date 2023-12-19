import socket

HOST = '192.168.33.80'  # The server's IP address
PORT = 6666             # The port used by the server

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(b'\n')
        print(f"Connected to {HOST}:{PORT}")

        dataBuffer = bytearray()  # Buffer to store received data
        magicStartSequence = bytes("HERON666", 'utf-8')

        headerSize = 20
        channelCount = 32
        blockSampleCount = 128
        audioBlockSize = channelCount * blockSampleCount * 2
        packetSize = audioBlockSize + headerSize


        try:
            while True:
                data = s.recv(10000)
                if not data:
                    break  # Exit loop if no data is received (connection closed)

                dataBuffer.extend(data)

                headerIndex = dataBuffer.find(magicStartSequence)
                if headerIndex != -1 and len(dataBuffer) >= packetSize:
                    packetIndex = int.from_bytes(dataBuffer[headerIndex + 8 : headerIndex + 12], 'little')
                    timestamp = int.from_bytes(dataBuffer[headerIndex + 12 : headerIndex + headerSize], 'little')
                    audioData = dataBuffer[headerIndex + headerSize : headerIndex + headerSize + audioBlockSize]
                    dataBuffer = dataBuffer[packetSize:]

                    # print(f"Packet index: {packetIndex}, Timestamp: {timestamp/1000000000:.6f}")
                    print(f"Received {len(audioData)} bytes: {[int(i) for i in audioData[:20]]}")

                    


        finally:
            print("Closing connection")
            s.close()

if __name__ == '__main__':
    main()
