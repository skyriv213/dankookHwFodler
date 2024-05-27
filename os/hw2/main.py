# This is a sample Python script.

# Press ⇧F10 to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

'''
구현은 파이썬으로 진행하였다.
이때 파이썬에서는 해시테이블을 사용한 자료구조인 딕셔너리가 존재한다.
그렇기에 파일 시스템의 디렉터리 구현은 해시 테이블, 딕셔너리를 사용하고자 한다.

파일 시스템 할당의 경우 인덱스 할당을 사용하고자 한다.
해당 시스템 할당이 단편화 문제를 해결할 수 있기에 해당 조건을 사용하고자한다.

여유공간 관리의 경우 연결리스트를 통해 관리하고자 한다.
구현시 사용한 구조

'''

from fileSimulator import FileSystemSimulator
from fileType import FileType

def start():
    # Use a breakpoint in the code line below to debug your script.
    fs = FileSystemSimulator()
    while True:
        command = input("Enter a command: ").strip().split()
        if not command:
            continue

        cmd = command[0]
        if cmd == 'create':
            if len(command) < 3:
                print("Usage: create <filename> <content> [file_type]")
                continue
            filename = command[1]
            content = ' '.join(command[2:])
            file_type = FileType.TEXT  # Default file type
            if len(command) > 3:
                try:
                    file_type = FileType(command[3].upper())
                except ValueError:
                    print(f"Unknown file type '{command[3]}'. Using default 'txt'.")
            fs.create(filename, content, file_type)
        elif cmd == 'delete':
            if len(command) != 2:
                print("Usage: delete <filename>")
                continue
            filename = command[1]
            fs.delete(filename)
        elif cmd == 'read':
            if len(command) != 2:
                print("Usage: read <filename>")
                continue
            filename = command[1]
            fs.read(filename)
        elif cmd == 'write':
            if len(command) < 3:
                print("Usage: write <filename> <content>")
                continue
            filename = command[1]
            content = ' '.join(command[2:])
            fs.write(filename, content)
        elif cmd == 'mkdir':
            if len(command) != 2:
                print("Usage: mkdir <dirname>")
                continue
            dirname = command[1]
            fs.mkdir(dirname)
        elif cmd == 'rmdir':
            if len(command) != 2:
                print("Usage: rmdir <dirname>")
                continue
            dirname = command[1]
            fs.rmdir(dirname)
        elif cmd == 'cd':
            if len(command) != 2:
                print("Usage: cd <dirname>")
                continue
            dirname = command[1]
            fs.cd(dirname)
        elif cmd == 'search':
            if len(command) != 2:
                print("Usage: search <filename>")
                continue
            filename = command[1]
            fs.search(filename)
        elif cmd == 'list':
            fs.list()
        elif cmd == 'exit':
            break
        else:
            print(
                "Unknown command. Available commands: create, delete, read, write, mkdir, rmdir, cd, search, list, exit")

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    start()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
