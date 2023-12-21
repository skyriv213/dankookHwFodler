# 항상 균형을 보장
'''
항상 균형 트리를 보장하기에 탐색과 삽입, 삭제 연산에서 O(logn)의 처리 시간 보장
트리를 정의하기 위해서는 균형인수를 정의해야함
노드의 균형인수는 왼쪽 서브트리의 노드와 오른쪽 서브트리의 높이 차로 결정
해당 트리는 비균형 상태가 되면 스스로 노드를 재배치하여 균형상태로 변경

그렇기에 균형이 깨질수 있는 연산은 삽입과 삭제이다.

삽입연산
- 노드가 삽입이 되면 삽입되는 위치에서 루트까지의 경로에 있는 모든 조상 노드들의 균횽 인수가 영향을 받음
    - 불균형 상태로 변한 가장 가ㅏㄲ운 조상 노드의 서브트리들에 대해 다시 균형을 잡아야함
    LL / RR은 대칭
        - 회전을 한번만 시켜서 단순회전

    LR과 RL도 대칭이다.
        - 두 번의 회전이 필요하여 이중 회전이라고 한다

    이때의 회전은 루트와 자식의 관계를 바꾼다

'''

class AVLTree:
    def __int__(self, key):
        self.key = key
        self.height = 1
        self.left = None
        self.right = None


    # def rotateLL(self, A):
    #     B = A.left # 시계방향 회전
    #     A.left = B.right
    #     B.right = A
    #     return B # 새로운 루트 B를 반환

    def rotateRR(A):
        B =  A.right
        A.right = B.left
        B.left = A
        return B