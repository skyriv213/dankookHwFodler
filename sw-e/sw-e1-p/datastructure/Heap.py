'''
힙은 여러 개의 값들 중에서 가장 큰(또는 가장 작은) 값을 빠르게 찾아내도록 만들어진 자료구조
가장 큰 값만 빨리 찾으면 되기에 모든 자료를 힘들게 정렬할 필요는 없다
이진 트리 구조를 갖고, 큰 값이 상위 레벨, 작은 값이 하위레벨에 있도록 하는 느슨한 정렬 상태만 유지

최대 힙
    - 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진트리
    (key(부모노드)) >= (key(자식노드))
최소 힙
    - 부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진트리
        (key(부모노드)) <= (key(자식노드))


힙에 새로운 항목을 삽입하더라도 힙의 순서 특성(최대/최소 힙)과 트리의 형태적 특성을 유지

삽입 연산
- 1 : 새로운 항목이 들어오면 힙의 마지막 노드의 다음 위치에 삽입한다. 이렇게 하면 완전 이진트리 조건은 만족하지만
    힙의 순서 특성을 만족하지 않는다
- 2 : 마지막에 삽입된 새로운 노드를, 부모 노드들과 교환해서 힙의 순서 특징을 만족시켜주는 과정을 처리
    최대 트리의 높이만큼 이동이 필요

해당 과정을 시프트업, 업힙이라고 부른다.

삭제 연산
- 1 : 루트 노드에 마지막 노드를 올린다.
    완전이진트리 조건은 만족하지만 힙의 순서 특성은 만족하지 않는다
- 2 : 루트 노드를 자식과 비교하여 자식이 더 크면 교환
    자식 중 ㅇ더 큰 자식이 교환 후보가 된다. 자식이 없거나 더 작을 때까지 반복

배열을 이용한 힙의 표현
- 힙은 완전이진트리이기 때문에 중간에 비어 있는 요소가 없음
- 힙을 표현하기에 가장 효과적인 자료구조는 배열
- 부모 i
- 왼쪽 자식 : i*2 / 우측 자식 i*2+1

'''

class MaxHeap:
    def __int__(self):
        self.heap = []
        self.heap.append(0)

    def size(self):
        return len(self.heap)-1
    def isEmpty(self):
        return self.size()==0
    def Parent(self,i):
        return self.heap[i//2]
    def left(self,i):
        return self.heap[i*2]
    def right(self, i):
        return self.heap[i*2+1]
    def display(self):
        print(self.heap[1:])

    def insert(self,n):
        self.heap.append(n)
        i =  self.size()
        while (i!=1 and n>self.Parent(i)):
            self.heap[i] =  self.Parent(i)
            i = i//2
        self.heap[i]=n

    def delete(self):
        parent = 1
        child = 2
        if not self.isEmpty():
            hroot =  self.heap[self.size()]
            last = self.heap[self.size()]
            while(child<= self.size()):
                if child<self.size() and self.left(parent)<self.right(parent):
                    child +=1
                if last >= self.heap[child]:
                    break
                self.heap[parent] = self.heap[child]
                parent = child
                child*=2
        self.heap[parent]= last
        self.heap.pop(-1)
        return hroot

'''
우선 순위 큐
데이터를 저장할 때 각 데이터에 우선 순위를 부여하고, 해당 우선순위에 따라 데이터를 처리하는 자료구조
우선 순위 큐는 각 원소가 특정한 순서로 정렬되어 있어 우선순위가 높은 원소가 먼저 나오는 특징이 존재 

사용 범위
작업 스케줄링, 네트워크 라우팅, 데이터 압축 분야

사용 연산
삽입 : 원소를 큐에 추가하면서 해당 원소에 우선순위 지정
삭제 : 가장 우선순위가 높은 원소를 큐에서 제거
최우선 순위 원소 얻기(peek / top) : 큐에서 가장 우선순위가 높은 원소를 반환하지만 제거를 하지는 않습니다.

힙으로 구현
이진 힙(binary heap)을 사용하여 구현
    - 이진 트리 구조를 가지며, 최대 힙, 최소 힙의 형태로 구성
- 최대 힙 기준 구현
    - 배열을 사용 : 배열의 인덱스를 사용하여 구현한다.
        - 0번째 인덱스는 사용하지않고, 인덱스 1부터 루트노드로 하여 구현
        - 특정 노드를 i라고 할 때 해당 노드의 부모 노드는 i//2, 왼쪽 자식 i*2, 오른쪽 자식 i*2+1
    - 삽입 연산
        - 새로운 원소를 힙에 삽입하면, 힙의 가장 아래 레벨에 삽입
        - 삽입된 노드를 부모와 비교하여 부모보다 크다면 서로 값을 교환하고 해당 과정 반복
    - 삭제 연산
        - 최대 힙에서는 루트 노드가 최대값을 가지므로, 루트 노드를 삭제하면 최우선 순위의 원소를 얻게 된다
        - 삭제된 루트 노드를 힙의 가장 마지막 노드로 옮겨옴
        - 옮겨진 노드를 자식 노드와 비교하며 자식 노드보다 크다면 서로 값을 교환하고, 이를 반복
        
'''
