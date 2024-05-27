import socket


def is_operator(c):
    return c in ['+', '-', '*', '/']


def precedence(op):
    if op in ['+', '-']:
        return 1
    if op in ['*', '/']:
        return 2
    return 0


def apply_operation(a, b, op):
    if op == '+': return a + b
    if op == '-': return a - b
    if op == '*': return a * b
    if op == '/': return a / b


def evaluate(expression):
    # 스택을 두 개 준비: 하나는 숫자용, 하나는 연산자용
    values = []
    ops = []
    i = 0

    while i < len(expression):
        if expression[i] == ' ':
            i += 1
            continue

        # 숫자인 경우
        elif expression[i].isdigit():
            val = 0

            # 숫자 읽기
            while (i < len(expression) and expression[i].isdigit()):
                val = (val * 10) + int(expression[i])
                i += 1

            values.append(val)
            i -= 1

        # 괄호 열림
        elif expression[i] == '(':
            ops.append(expression[i])

        # 괄호 닫힘: 괄호 안을 계산
        elif expression[i] == ')':
            while len(ops) != 0 and ops[-1] != '(':
                val2 = values.pop()
                val1 = values.pop()
                op = ops.pop()

                values.append(apply_operation(val1, val2, op))

            # 열린 괄호 제거
            ops.pop()

        # 연산자
        else:
            if not is_operator(expression[i]):
                return "잘못된 수식입니다."

            # 연산자의 우선순위가 스택의 맨 위 연산자보다 낮거나 같은 동안 계산
            while (len(ops) != 0 and precedence(ops[-1]) >= precedence(expression[i])):
                val2 = values.pop()
                val1 = values.pop()
                op = ops.pop()

                values.append(apply_operation(val1, val2, op))

            # 연산자를 연산자 스택에 푸시
            ops.append(expression[i])

        i += 1

    # 표현식이 끝나면 남은 연산 수행
    while len(ops) != 0:
        val2 = values.pop()
        val1 = values.pop()
        op = ops.pop()

        values.append(apply_operation(val1, val2, op))

    # 최종 결과 반환
    return values[-1]


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

        try:
            result = evaluate(data)
            result = str(result)
        except Exception as e:
            result = "잘못된 수식입니다."

        print("Sending: " + result)
        conn.send(result.encode())

    conn.close()


if __name__ == '__main__':
    server_program()
