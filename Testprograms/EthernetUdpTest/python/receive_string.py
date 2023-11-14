import socket

UDP_IP = "192.168.33.30"
UDP_PORT = 8888

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

while True:
    try:
        data, addr = sock.recvfrom(1024)       
        decoded_data = data.decode('utf-8')
        print("Received message:", decoded_data)
    except KeyboardInterrupt:
        sock.close()
        break
    except Exception as e:
        print("Error:", str(e))