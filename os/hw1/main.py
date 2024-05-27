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
import time
from enum import Enum
from collections import deque
import matplotlib.pyplot as plt

process_state_records = []

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
        time.sleep(0.1)


    def changeStateReady(self):
        self.state = ProcessState.READY
        time.sleep(0.1)


    def changeStateFinished(self):
        self.state = ProcessState.FINISHED
        time.sleep(0.1)


    def changeExecuteTime(self, timeslice):
        self.executionTime = self.executionTime - timeslice

    def record_state(self, time):
        process_state_records.append((self.processId, self.state.value, time))


# 프로세스 리스트 생성
def makeProcessors(ReadyQueue):
    for i in range(1, 10, 1):
        if (i % 2 == 0):
            execTime = i * i
        else:
            execTime = i
        process = Process(processId= i, executionTime=execTime, priorityNum=10 - i)
        ReadyQueue.append(process)


def startRoundRobin(readyQueue):
    timeSlice = 10
    time_count = 0
    while readyQueue:
        process = readyQueue.popleft()
        process.changeStateRunning()
        process.record_state(time_count)
        time_count += timeSlice
        if process.executionTime <= timeSlice:
            process.executionTime = 0
            process.changeStateFinished()
            process.record_state(time_count)
        else:
            process.changeExecuteTime(timeSlice)
            process.changeStateReady()
            process.record_state(time_count)
            readyQueue.append(process)


def plot_process_states(size_process):
    # 각 프로세스의 실행 상태를 그래프로 표현
    for processId, state, time in process_state_records:
        plt.plot([time, time + 10], [processId, processId],
                 color='blue'
                 if state == 'Running' else 'green' if state == 'Ready' else 'red',
                 linewidth=3)

    plt.xlabel('Time')
    plt.ylabel('Process ID')
    plt.title('Process Execution States')
    plt.yticks(range(1, size_process + 1), [f'P{i}' for i in range(1, size_process + 1)])
    plt.grid(axis='x')
    plt.legend()  # 범례 생성
    plt.show()


def startRoundRobinWorking():
    print("Processor simulation is start now")  # Press ⌘F8 to toggle the breakpoint.
    # ready, finish 큐 구현
    readyQueue = deque([])
    #
    makeProcessors(readyQueue)
    print("check about processor")
    size_process = len(readyQueue)

    for i in readyQueue:
        print(i.processId, i.executionTime)
    print("We make processes and we start round robin scheduler")
    startRoundRobin(readyQueue)
    plot_process_states(size_process)



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    startRoundRobinWorking()
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
