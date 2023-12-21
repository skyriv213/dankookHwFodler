package domain;

public class Delivery {
    private Customer customer;
    private String shippingAddress;
    private String pamentMethod;
    private Order order;

    public void productTrack() {
        // 상품 배송 추적하기
    }

    public void productReturn() {
        // 상품 반품하기
    }

    public void changeAddress(String address){
        // 상품 배송 주소 수정하기
    }

    public void productExchage(){
        // 상품 교환 하기
    }

}

