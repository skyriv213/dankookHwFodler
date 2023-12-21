import ex_interface_abstract.AbstractImpl;
import ex_interface_abstract.InterfaceImpl;
import ex_interface_abstract.ExiInterface;

public class Main {

    public static void main(String[] args) {
        String t = "world";

        // InterfaceImpl이라는 클래스를 사용하여서 ex라는 객체, 인스턴스를 생성하였다.
        ExiInterface ex = new InterfaceImpl();

        AbstractImpl anAbstract = new AbstractImpl();
        anAbstract.setA(5);
        anAbstract.setS(t);
        ex.printSomething();
        ex.printSomething(t);
        anAbstract.printLength();
    }
}