import socket

dns_records = {
    'example.com': '93.184.216.34',
    'test.com': '93.184.216.35',
    'example2.com': '93.184.212.34',
    'test2.com': '93.184.216.32'
}

def server_program():
    host = 'localhost'
    port = 5000

    server_socket = socket.socket()
    server_socket.bind((host, port))
    server_socket.listen(2)
    print("Server is listening...")

    conn, address = server_socket.accept()
    print("Connection from: " + str(address))

    while True:
        data = conn.recv(1024).decode()
        if not data:
            break
        print("Received from client: " + data)


        if data in dns_records:
            result = dns_records.get(data)
            result = str(result)
        else :
            result = "해당 도메인 이름은 존재하지않습니다.."

        print("Sending: " + result)
        conn.send(result.encode())

    conn.close()


if __name__ == '__main__':
    server_program()
