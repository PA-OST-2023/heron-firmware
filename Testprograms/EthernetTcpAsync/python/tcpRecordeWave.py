import socket

HOST = '192.168.40.80'  # The server's IP address
PORT = 6666             # The port used by the server

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(b'\n')
        print(f"Connected to {HOST}:{PORT}")

        try:
            while True:
                # message = input("Enter message: ")
                # if message.lower() == 'quit':
                #     break

                # s.sendall(b'\n')
                data = s.recv(2048)
                # print(f"Received: {data.decode()}")

        finally:
            print("Closing connection")
            s.close()

if __name__ == '__main__':
    main()
