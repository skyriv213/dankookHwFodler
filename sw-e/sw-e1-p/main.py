# This is a sample Python script.

'''


파이썬에서는 메서드의 오버로딩이 동작하지 않는다고 한다.

그렇기에 자바와는 다르게 메서드의 오버라이딩과 구현을 구현했다.

구현의 경우 주어진 interface를 Ex->Impl의 방식으로 구현을 하였으며
Ex의 경우 가지고 있어야만 하는 특성을 메서드로 입력하였다. 그렇기에 해당 인터페이스를 구현하는 클래스는
반드시 인터페이스에서 작성이 된 메서드를 구현해햐아기에 IntefaceImpl에 해당 메서드를 구현을 했다.

또한 해당 main 코드파일에서 InterfaceImpl이라는 클래스를 사용하여 인스턴스, 객체를 선언하여
주어진 객체를 사용하여 클래스에서 구현이 된 print_some이라는 메서드를 사용하였다.


'''

from InterfaceImpl import InterfaceImpl

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    t = "hello sw"
    ex = InterfaceImpl()

    ex.print_some()
    ex.print_some(t)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
