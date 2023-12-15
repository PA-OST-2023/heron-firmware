import socket

# Set the server's IP address and port
HOST = '192.168.33.30'  # Standard loopback interface address (localhost)
PORT = 6666       # Port to listen on (non-privileged ports are > 1023)

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()

        print(f"Server started, listening on {HOST}:{PORT}")

        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            while True:
                data = conn.recv(2048)
                length = len(data)
                if not data:
                    break
                message = data.decode('utf-8')
                print(f"Received message ({length}): {message}")

if __name__ == '__main__':
    main()
