package ex_interface_abstract;


/**
 * interface 구현
 * 주어진 interface에서 정의가 된 printLength를 구현하기위해 override를 사용
 * 해당 방식을 사용하면 interface에서 구현이 된 printLength를 구현하는 클래스에 맞게 재정의할 수 있다.
 * 또한 똑같은 이름의 메서드를 선언을 하였는데 이 때는 interface에서 사용한 것과 다르게
 * String 라는 변수를 인자로 받는 방식으로 하나 더 구현해서 overloading(다형성)을 만들어보았다.
 *
 * 또한 interfaceImpl의 경우 해당 프로그램이 동작할 때 클래스 로딩 시 초기화 되어 해당 메모리에 올라가게 된다.
 *
 *
 */
public class InterfaceImpl implements ExiInterface{

    private static int num = 1;

    @Override
    public void printSomething() {
        System.out.println("숫자 출력 : "+num);
    }

    @Override
    public void printSomething(String s) {
        System.out.println("주어진 문자열의 값은 " +s
            +"이며 길이는 "+s.length()+"입니다.");
    }

}
