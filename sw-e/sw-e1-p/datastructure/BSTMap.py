import BSTNode

class BSTMap(): # 이진 탐색트리를 이용한 맵
    def __int__(self): # 생성자
        self.root =  None # 트리의 루트 노드

    def isEmpty(self):
        return self.root ==None

    def clear(self):
        self.root = None

    def count_node(self,node):
        if node is None:
            return 0
        else:
            return 1+self.count_node(node.left)+self.count_node(node.right)


    def size(self):
        return self.count_node(self.root)

    def search (self, key):
        return self.search(self.root, key)

    def searchValue(self,key):
        return self.searchValue(self,key)

    def findMax(self):
        return self.findMax()

    def findMin(self):
        return self.findMin()

    def insert(self, key, value= None):
        n =  BSTNode(key, value)
        if self.isEmpty():
            self.root =  n
        else:
            self.insert(self.root,n)

    def delete(self,key):
        self.root = self.delete_BST(self.root, key)
        


