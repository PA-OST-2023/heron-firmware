import requests
import json
import time

def get_json_from_server(ip, port):
    url = f"http://{ip}:{port}"
    try:
        response = requests.get(url)
        response.raise_for_status()
        return response.json()
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")
        return None

def send_json_to_server(ip, port, json_data):
    url = f"http://{ip}:{port}"
    headers = {'Content-Type': 'application/json'}
    try:
        response = requests.post(url, data=json.dumps(json_data), headers=headers)
        response.raise_for_status()
        return response.text
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")

def main():
    ip = "192.168.40.80"
    port = "6667"
    index = 0

    while True:
        try:
            # Get JSON data from the Arduino
            json_data = get_json_from_server(ip, port)
            if json_data:
                millis = json_data.get("millis")
                if millis is not None:
                    print(f"Millis from Arduino: {millis}")
                else:
                    print("Field 'millis' not found in the received JSON.")

            # Send JSON data to the Arduino
            send_data = {"index": index}
            send_json_to_server(ip, port, send_data)

            index += 1
            time.sleep(1)  # Wait for one second before next iteration
        except requests.exceptions.RequestException as e:
            print(f"Network error: {e}")
            time.sleep(1)  # Wait before retrying

if __name__ == "__main__":
    main()