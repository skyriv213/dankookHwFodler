package ex_interface_abstract;

public class AbstractImpl extends ExAbstract{

    @Override
    public void setA(int a) {
        super.setA(a);
    }

    @Override
    public void setS(String s) {
        super.setS(s);
    }

    @Override
    public void printLength() {
        System.out.println("문자의 길이와 수를 더하는 메서드: "+ (this.s.length()+this.a));
    }

}
