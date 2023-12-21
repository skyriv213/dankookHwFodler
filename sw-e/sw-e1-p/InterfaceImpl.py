from ExInterface import ExInterface


class InterfaceImpl(ExInterface):
    num = 100

    def print_some(self,*some):
        if len(some)==0:
            print("주어진 기본값 출력",self.num)
        elif len(some)==1:
            print("주어진 단어는 ",some[0])
