from fileType import FileType

class File:

    def __init__(self, title, content, file_type):
        self.title = title
        self.content = content
        self.size = len(content)
        self.file_type = file_type

    def __str__(self):
        return f"File(title={self.title}, size={self.size}, type={self.file_type.value})"

