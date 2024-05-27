from file import File
from directory import Directory
from fileType import FileType

class FileSystemSimulator:
    def __init__(self):
        self.root = Directory('/')
        self.current_directory = self.root
        self.free_space = [i for i in range(100)]  # 인덱스 할당을 위한 여유 공간 리스트

    def create(self, filename, content, file_type=FileType.TEXT):
        if filename in self.current_directory.files:
            print(f"File '{filename}' already exists.")
        else:
            if self.free_space:
                index = self.free_space.pop(0)  # 인덱스 할당 방식
                new_file = File(filename, content, file_type)
                self.current_directory.files[filename] = new_file
                print(f"File '{filename}' created with content at index {index}.")
            else:
                print("No free space available to create file.")

    def delete(self, filename):
        if filename in self.current_directory.files:
            del self.current_directory.files[filename]
            self.free_space.append(len(self.free_space))  # 여유 공간 관리
            print(f"File '{filename}' deleted.")
        else:
            print(f"File '{filename}' not found.")

    def read(self, filename):
        if filename in self.current_directory.files:
            content = self.current_directory.files[filename].content
            print(f"Content of '{filename}':\n{content}")
        else:
            print(f"File '{filename}' not found.")

    def write(self, filename, content):
        if filename in self.current_directory.files:
            self.current_directory.files[filename].content += content
            print(f"Content written to '{filename}'.")
        else:
            print(f"File '{filename}' not found.")

    def mkdir(self, dirname):
        if dirname in self.current_directory.directories:
            print(f"Directory '{dirname}' already exists.")
        else:
            self.current_directory.directories[dirname] = Directory(dirname)
            print(f"Directory '{dirname}' created.")

    def rmdir(self, dirname):
        if dirname in self.current_directory.directories:
            del self.current_directory.directories[dirname]
            print(f"Directory '{dirname}' deleted.")
        else:
            print(f"Directory '{dirname}' not found.")

    def cd(self, dirname):
        if dirname == '..':
            self.current_directory = self.root
        elif dirname in self.current_directory.directories:
            self.current_directory = self.current_directory.directories[dirname]
            print(f"Changed directory to '{dirname}'.")
        else:
            print(f"Directory '{dirname}' not found.")

    def search(self, filename):
        if filename in self.current_directory.files:
            print(f"File '{filename}' found in current directory.")
        else:
            print(f"File '{filename}' not found.")

    def list(self):
        print("Directories:")
        for dirname in self.current_directory.directories:
            print(f"  {dirname}")
        print("Files:")
        for filename in self.current_directory.files:
            print(f"  {filename}")
