'''
OS -1
파이썬을 이용하여 프로세스 스케줄링 및 멀티 태스킹의 기본 시뮬레이션

기본 요구사항

1. 프로세스의 생성과 관리
2. 스케줄러의 구현
3. 메인 실행 루프 및 프로세스 생성

구현 가이드

1. 프로세스 모델링
    - 파이썬 클래스를 사용하여 프로세스 모델링
    - 프로세스는 실행 시간, 상태, 우선순위 등의 속성을 가짐

2. 스케줄러 구현
    - 프로세스 큐를 관리
    - 현재 실행할 프로세스를 결정하는 스케줄러 구현
    - 지정된 시간 동안만 실행 및 시간 종료 시 다음 프로세스로 교체

3. 시뮬레이션 루프
    - 모든 프로세스가 완료될 때까지 시뮬레이션 루프 실행
    - 각 루프에서는 스케줄러가 다음 프로세스를 선택하고 실행 상태 업데이트


라운드 로빈
프로세스들 사이에 우선순위를 두지않고, 여러 프로세스가 CPU 사용시간을 일정하게 할당하는 방식
1. 준비큐 : 프로세스들이 들어있는 큐
2. 타임 슬라이스 : CPU가 사용할 수 있는 시간, 해당 타임 슬라이스는 2로 지정할 예정
3. CPU 할당 : 현재 실행중인 타임 슬라이스가 끝나면, CPU는 준비큐에서 다음 프로세스에게 할당
4. 1-3 반복
'''
import random
from enum import Enum
from collections import deque


class ProcessState(Enum):
    RUNNING = "Running"
    READY = "Ready"
    FINISHED = "Finished"


class Process:
    def __init__(self, processId, executionTime, priorityNum):
        self.processId = processId  # 프로세스 식별자
        self.executionTime = executionTime  # 실행 시간
        self.priorityNum = priorityNum  # 우선순위
        self.state = ProcessState.READY  # 초기 상태는 준비(Ready) 상태로 설정

    def changeStateRunning(self):
        self.state = ProcessState.RUNNING

    def changeStateReady(self):
        self.state = ProcessState.READY

    def changeStateFinished(self):
        self.state = ProcessState.FINISHED

    def changeExecuteTime(self, timeslice):
        self.executionTime = self.executionTime - timeslice


# 프로세스 리스트 생성
def makeProcessors(ReadyQueue):
    for i in range(1, 10, 1):
        if(1<=i<5):
            execTime = random.randint(1, 8)
        else:
            execTime = random.randint(7,17)
        process = Process(processId=i, executionTime=execTime, priorityNum=10 - i)
        ReadyQueue.append(process)


def startRoundRobin(readyQueue,finishedQueue ):
    # 종료된 프로세스가 들어갈 큐
    # 타임 슬라이스 : 정해진 시간
    timeSlice = 2
    while True:
        if len(readyQueue)==0:
            break
        else:
            process = readyQueue.popleft()
            process.changeStateRunning()
            time = process.executionTime

            if (time - timeSlice) <= 0:
                process.executionTime = 0
                process.changeStateFinished()
                finishedQueue.append(process)

            else:
                process.changeExecuteTime(timeSlice)
                process.changeStateReady()
                readyQueue.append(process)

def startWorking():
    # Use a breakpoint in the code line below to debug your script.
    print("Processor simulation is start now")  # Press ⌘F8 to toggle the breakpoint.
    readyQueue = deque([])
    makeProcessors(readyQueue)
    print("check about processor")
    for i in readyQueue:
        print(i.processId, i.executionTime)
    print("We make processes and we start round robin scheduler")
    finishedQueue = deque([])
    startRoundRobin(readyQueue,finishedQueue)
    for i in finishedQueue:
        print(i.processId, i.executionTime)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    startWorking()
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
