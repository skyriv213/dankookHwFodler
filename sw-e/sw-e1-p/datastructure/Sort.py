'''
탐색
    - 많은 자료(record) 중에서 무언가(key)를 찾는 작업
    - record의 집합을 table이라 함
    - map || dictionary : 자료를 저장하고 탐색키를 이용해 원하는 자료를 빠르게 찾을 수 있도록 하는 탐색을 위한 자료구조
        - map : entry라고 불리는 키를 가진 레코드의 집합
            key : 레코드를 구분할 수 있는 탐색키
            value : 탐색키와 관련이 된 값
        - dictionary : 자료구조 맵을 구현한 하나의 예

    - 순차 탐색
        - 각 레코드를 처음부터 하나씩 순서대로 검사하여 원하는 레코드를 찾음
        - 탐색 함수는 팀색 대상인 리스트 A와 탐색 키 key, 그리고 탐색범위 low, high를 매개변수로 가지고 있음
        - low 위치에서 탐색을 시작하여 탐색이 성공하면 항목의 위치를 반환, high까지 탐색을 진행했을 때 나타나지 않으면 None을 반환
        def sequentiol_search(A,key,low,high):
            for i in range(len(A)):
                if A[i].key == key:
                    return i
            return None

    - 이진 탐색
        - 키 값을 기준으로 정렬되어 있다면 개선된 탐색 가능
        - 테이블의 중앙에 있는 값을 조사하여 찾는 항목이 왼쪽에 있는지 오른쪽에 있는지를 판단
        - 찾는 항목이 왼쪽에 있다면 이제 오른쪽은 탐색 범위에서 제외되며, 해당 방식을 통해 단계마다 검색해야할 범위가 반으로 줄어든다.
        - 데이터의 삽입이나 삭제가 빈번한 응용에는 적합하지 않음

        # 순환구조로 구현
        def binary_search(A, key, low, high):
            if low<=high:
                middle = (low + high)//2
                if key < A[middle]:
                    return binary_search(A,key,low, middle-1)
                elif key == A[middle]:
                    return middle
                else:
                    return binary_seach(A,key, middle+1, high)
            return None

        # 반복 구조
        def binary_Search(A,key):
            low = 0;
            high = len(A)
            while low <=high:
                middle = (low+high)//2
                if key == A[middle].key:
                    return middle
                elif key < A[middle].key:
                    high =middle-1
                else:
                    low = middle+1
            return None

    - 보간 탐색(interpolation search)
        - 이진 탐색의 일종
        - 탐색키가 존재할 위치를 예측하여 탐색
            - 찾고자 하는 키값과 현재의 low, high 위치의 값을 고려하여 탐색위치 결정
            - 탐색 값과 위치는 비례한다는 가정으로 진행
        - middle = int(low + (high -low)*(key-A[low].key)/(A[high].key-A[low].key)) 로 변경
        # 반복 구조
        def binary_Search(A,key):
            low = 0;
            high = len(A)
            while low <=high:
                middle = (low+high)//2
                if key == A[middle].key:
                    return middle
                elif key < A[middle].key:
                    high =middle-1
                else:
                    low = middle+1
            return None

    - 해싱
        - 세대별 우편함과 비슷
        - 키값에 산술적인 연산을 적용하여 레코드가 저장되어야할 위치를 직접 계산
        - 탐색키로부터 레코드가 있어야할 이치를 계산하고, 그 위치에 레코드가 있는지 확인
        - 해싱에서 키값으로부터 레코드가 저장될 위치를 계산하는 함수를 해시 함수라고 함
        - 해시 함수를 통해 계산될 위치에 레코드를 저장한 테이블을 해시 테이블이라고 함
            - M개의 버킷으로 이루어지는 테이블
                - 충돌
                    - 버킷이 충분하지 않으면 서로 다른 키가 해시함수에 의해 같은 주소로 계산되는 상황
                    - 충돌을 일으키는 키들을 동의어라고 함
            - 하나의 버킷은 여러 개의 슬롯을 가짐
            - 하나의 슬롯에서는 하나의 레코드 저장

        - 선형 조사법
            - 해싱 함수로 계산된 버킷에 빈 슬롯이 없으면 다음 버킷에서 빈 슬롯이 있는지 찾음
            - 비어있는 공간을 찾는 것을 조사(probing)이라고 함
            - 해시 테이블의 k번째 위치인 ht[k]에서 충돌이 발생한다면, 다음 위치인 ht[k+1]부터 순서대로 비어있는지 살피고(조사), 빈공간이 있으면 저장
            - 충돌이 발생한 위치에서 항목들이 집중되는 것을 알 수 있음 -> 오버 플로가 자주 발생하면 군집화 현상에 의해 탐색의 효율 저하

        -



정렬
    - 데이터를 순서대로 재배열하는 것을 말함
    - 사물들을 서로 비교할 수 있어야 함
    - 비교할 수 있는 모든 속성들은 정렬의 기준 오름차순/내림차순
    - 정렬의 대상 = record -> 여러 개의 필드로 이루어짐 -> 정렬의 기준이 되는 필들를 키, 정렬키라고 함
    - 정렬 장소에 따른 분류
        - 내부 정렬 : 모든 데이터가 메인 메모리에 올라와 있는 정렬을 의미
        - 외부 정렬 : 외부 기억장치에 대부분의 데이터가 있고 일부만 메모리에 올려 정렬하는 방법 -> 대용량 자료를 정렬하기 위해 사용

    - 단순 비효율 : 삽입, 선택, 버블
    - 복잡 효율 : 퀵, 힙, 병합, 기수

    - 선택 정렬
        - 리스트에서 가장 작은 숫자를 선택해서 앞쪽으로 옮기는 방법
        - 두개의 리스트가 존재
            - 정렬이 되지 않은 리스트에서 정렬이 된 리스토로 가장 작은 숫자를 골라 이동 시키는 것
        - 하나의 리스트의 경우
            - 해당 리스트의 값을 교환하는 방식으로 진행
        def select_sort(list):
            for i in range(len(list)):
                 min = i
                 for j in range(i+1, len(list)):
                    if list[min] < list[j]:
                        min = j
                list[i],list[min] = list[min],list[i]

    - 삽입 정렬
        - 정렬이 안 된 부분의 숫자를 하나씩 정렬된 부분의 적절한 위치를 찾아 끼워 넣음
        - 만약에 중간에 끼워 넣게 된다면 해당 숫자보다 큰 값들은 모두 한 칸씩 뒤로 이동
        def insert_sort(list):
            n = len(list)
            for i in range(1,n):
                key = list[i]
                j = i-1
                while j>=0 and list[j] >key:
                    list[j+1] = list[j]
                    j-=1
                list[j+1] = key

    - 버블 정렬
        - 인접한 2개의 레코드를 비교하여 크기가 순서대로가 아니면 서로 교환하는 방식
            - 비교-교환 과정은 리스트의 왼쪽 끝에서 시작하여 오른쪽 끝까지 진행
        def bubble_sort(a):
            n = len(a)
            for i in range(n-1, 0,-1):
                beChanged = False
                for j in range(i):
                    if a[j] > a[j+1]:
                        a[j], a[j+1] = a[j+1],a[j]
                        beChanged = True
                if not beChanged : break

    - 응용
        - 집합의 원소를 정렬된 원소 순으로 저장
        - 원소들이 정렬이 되어 있으면 집합의 비교나 합집합, 차집합, 교집합 등을 훨씬 효율적으로 구현

        def insert(self, elem):
            if elem in self.items: return
            for idx in range(len(self.items)):
                if elem< self.itmes[idx]:
                    self.items.insert(idx, elem) // insert 원하는 위치의 idx를 찾아서 해당 위치에 원소 넣기
                    return
            self.items.append(elem) // 맨 뒤에 원소 삽입


        def union(self,B):
            newSet = Set()
            a = 0
            b =0
            while a < len(self.items) and b< len(B.items):
                va =  self.itmes[a]
                vb =  B.items[b]
                if va < vb :
                    newSet.items.append(va)
                    a+=1
                elif va > vb :
                    newSet.items.append(vb)
                    b+=1
                else:
                    newSet.items.append(va)
                    a+=1
                    b+=1 // 중복되는 원소 발생 시 하나만 추가하기
            while a < len(self.itmes):
                newSet.items.append(self.items[a])
                a+=1
            while b< len(B.items):
                newSet.items.append(B.items[b])
                b+=1
            return newSet

'''