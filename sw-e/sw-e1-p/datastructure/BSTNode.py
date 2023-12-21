'''
루트 :  계층적인 구조에서 가장 높은 곳에 있는 노드
    모든 노드는 자신의 서브 트리의 루트 노드

간선 or edge : 노드와 노드를 연결하는 선

부모(parent), 자식(child) : 간선으로 직접 연결된 노드 중 상위 노드와 하위 노드

형제 : 같은 부모노드를 가진 노드

조상, 자손 : 어떤 노드에서 루트 노드까지의 경로상에 있는 모든 노드들과, 어떤 노드 하위에 연결된 모든 노드

단말, 리프 : 자식 노드가 없는 노드. 자식이 있으면 비단말 노드

노드의 차수 : 어떤 노드가 가지고 있는 자식의 수

트리의 차수 : 트리가 가지고 있는 노드의 차수 중에서 가장 큰 차수

레벨 : 트리의 각 층에 번호를 매기는 것. 루트의 레벨은 1이 되고 한 층씩 내려갈수록 1씩 증가

트리의 높이 : 트리가 가지고 있는 최대 레벨

포리스트 : 트리들의 집합
'''

class BSTNode:
    def __init__(self,key,value):
        self.key =  key
        self.value = value
        self.left = None
        self.right = None

    def searchBST(self, n,key):
        if n == None:
            return None
        elif key == n.key:
            return n
        elif key < n.key:
            return self.searchBST(n.left, key)
        else:
            return self.searchBST(n.right, key)

    def searchBSTIter(self, n,key):
        while n !=None:
            if key == n.key:
                return n
            elif key< n.key:
                n = n.left
            else:
                n = n.right
        return None

    # 값을 이용한 탐색
    # 전위, 중위, 후위, 레벨, etc / 모든 노드 탐색으로 인한 효율 감소
    def searchBSTValue(self, n, value):
        if n  == None:
            return None
        elif value == n.value:
            return n
        res = self.searchBSTValue(n.left, value)
        if res is not None:
            return res
        else:
            return self.searchBSTValue(n.right, value)


    #최대 키와 최소 키 찾는 메서드
    def findMaxKey(self,n):  # 최대 키는 트리의 가장 우측에 존재
        while n != None and n.right !=None:
            n = n.right
        return n
    def findMinKey(self, n):
        while n != None and n.left !=None:
            n =  n.left
        return n

    # 삽입연산
    def inset_bst(self,r,n):
        if n.key < r.key:
            if r.left is None:
                r.left = n
                return True
            else:
                return self.insert_bst(r.left,n)
        elif  n.key > r.key:
            if r.right is None:
                r.right =n
                return True
            else:
                return self.inset_bst(r.right, n)
        else :
            return False

    # 단말노드의 삭제
    # 자식노드가 없기에 그 노드만 지우면 되므로 가장 간단
    def deleteBSTcase1(self, parent, node, root):
        if parent is None:
            root = None
        else:
            if parent.left == node:
                parent.left =None
            else:
                parent.right =None
        return root

    # 자식이 하나인 노드 삭제
    # 삭제할 노드의 자식이 하나뿐이면 자신 대신에 유일한 자식을 부모 노드에 연결
    def deleteBSTcase2(self, parent, node, root):
        if node.left is not None:
            child = node.left
        else:
            child = node.right
        if node == root:
            root = child
        else:
            if node is parent.left:
                parent.left = child
            else:
                parent.right = child

        return root

    # 두 개의 자식을 모두 갖는 노드의 삭제
    # 왼쪽 서브트리의 가장 큰 값 / 오른쪽 서브트리의 가장 작은 값
    '''
    if succp.left == succ::
    이 조건은 후계자가 그 부모 노드의 왼쪽 자식인 경우를 검사합니다. 즉, 후계자가 왼쪽 서브트리에서 가장 작은 값을 가진 노드일 경우입니다.
    
    이 경우, 후계자의 부모 노드의 left 포인터를 후계자의 오른쪽 자식으로 변경합니다. 
    왜냐하면 후계자는 오른쪽 서브트리에서 가장 작은 값을 가지므로 그보다 큰 값들만 가진 서브트리가 남아있을 것이기 때문에, 후계자의 오른쪽 서브트리를 후계자의 부모 노드의 왼쪽 자리로 이동시키는 것입니다.
    
    else::
    이 경우는 후계자가 그 부모 노드의 오른쪽 자식인 경우를 검사합니다. 
    후계자가 오른쪽 서브트리에서 가장 작은 값을 가진 경우와 그 부모 노드의 오른쪽 자식인 경우를 나타냅니다.
    
    이 경우, 후계자의 부모 노드의 right 포인터를 후계자의 왼쪽 자식으로 변경합니다. 
    이 역시 후계자의 왼쪽 서브트리가 가장 큰 값들을 가지고 있기 때문에, 이 서브트리를 후계자의 부모 노드의 오른쪽 자리로 이동시키는 것입니다.
    '''
    def deleteBSTcase3(self,parent, node, root):
        succp = node # 후계자의 부모 노드
        succ = node.right # 후계자 노드
        while(succ!=None): # 후계자와 부모 노드 탐색
            succp = succ
            succ = succ.left
        if succp.left == succ: # 후계자의 부모 노드의 왼쪽 자식이 후계자 노드와 동일하다면
            succp.left = succ.right #
        else:
            succp.right = succ.left
        node.key =  succ.key
        node.value = succ.value
        return root

    def delete_BST(self,root, key):
        if root == None : return None
        parent = None
        node = root
        while node!=None and node.key != key:
            parent  = node
            if key < node.key : node = node.left
            else: node = node.right

        if node == None : return None
        if node.left == None and node.right ==None:
            root = self.deleteBSTcase1(parent, node, root)
        elif node.left == None or node.right == None:
            root = self.deleteBSTcase2(parent, node, root)
        else:
            root = self.deleteBSTcase3(parent,node, root)
        return root
