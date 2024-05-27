'''
1. client에게 원하는 주소를 입력받고 해당 주소의 IP 반환
2. low에 존재하지 않다면 high로 해당 주소 전달
3. high에 해당 주소 파악 후 low로 전달, low에서 client로 출력 전달
'''

import socket

dns_records = {
    'example0.com': '93.184.26.34',
    'test0.com': '93.184.26.35',
}

def client_program():
    host = 'localhost'  # 서버의 호스트 이름
    port = 5000  # 서버의 포트 번호

    client_socket = socket.socket()  # 소켓 객체 생성
    client_socket.connect((host, port))  # 서버에 연결

    message = input(" -> ")  # 사용자 입력 받기

    while message.lower().strip() != 'bye':
        if message in dns_records:
            print('check from LowDNS: ' + dns_records.get(message))  # 결과 출력
            message = input(" -> ")  # 사용자 입력 받기

        else:
            client_socket.send(message.encode())  # 메시지 전송
            data = client_socket.recv(1024).decode()  # 서버로부터의 응답 수신
            print('Received from HighDNS: ' + data)  # 결과 출력
            message = input(" -> ")  # 사용자 입력 받기

    client_socket.close()  # 소켓 종료

if __name__ == '__main__':
    client_program()
