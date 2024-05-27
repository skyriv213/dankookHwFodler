import socket

def client_program():
    host = 'localhost'  # 서버의 호스트 이름
    port = 5000  # 서버의 포트 번호

    client_socket = socket.socket()  # 소켓 객체 생성
    client_socket.connect((host, port))  # 서버에 연결

    message = input(" -> ")  # 사용자 입력 받기

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())  # 메시지 전송
        data = client_socket.recv(1024).decode()  # 서버로부터의 응답 수신

        print('Received from server: ' + data)  # 결과 출력
        message = input(" -> ")  # 사용자 입력 받기

    client_socket.close()  # 소켓 종료

if __name__ == '__main__':
    client_program()
