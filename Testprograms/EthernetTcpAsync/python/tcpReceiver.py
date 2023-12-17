import socket

HOST = '192.168.40.80'  # The server's IP address
PORT = 6666             # The port used by the server

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(b'\n')
        print(f"Connected to {HOST}:{PORT}")

        dataBuffer = bytearray()  # Buffer to store received data
        magicStartSequence = bytes([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF])

        try:
            while True:
                data = s.recv(10000)
                if not data:
                    break  # Exit loop if no data is received (connection closed)

                dataBuffer.extend(data)

                # Search for the magic sequence
                magicIndex = dataBuffer.find(magicStartSequence)
                if magicIndex != -1:
                    alignedData = dataBuffer[magicIndex + len(magicStartSequence):]
                    print(f"Received {len(alignedData)} bytes: {[int(i) for i in alignedData[:10]]}")

                    # Clear the buffer or remove processed part
                    dataBuffer = dataBuffer[magicIndex + len(magicStartSequence):]
                    
                # Optional: Add more logic to process alignedData

        finally:
            print("Closing connection")
            s.close()

if __name__ == '__main__':
    main()
