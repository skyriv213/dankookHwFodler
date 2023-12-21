package domain;

import java.util.List;
public class Order {

    private String ProductInfo;
    private String Orderdate;
    private int OrderPrice;
    private String OrderState;

    private Seller seller;
    private Customer customer;

    private List<Product> products;

    private Delivery delivery;

    public void searchProduct() {
        // 상품을 검색하는 코드
    }

    public void purchaseProduct(Product product) {
        // 상품을 구매하는 코드
    }

    public void leaveInquiry() {
        // 상품 문의를 남기는 코드
    }

    public void replyToInquiry() {
        // 상품 문의에 답변하는 코드
    }
    public void refund_state(){

    }
    public void search_buyingInfo() {

    }

}