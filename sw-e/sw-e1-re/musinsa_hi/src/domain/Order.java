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

    public String getOrderdate() {
        return Orderdate;
    }

    public void setOrderdate(String orderdate) {
        Orderdate = orderdate;
    }

    public int getOrderPrice() {
        return OrderPrice;
    }

    public void setOrderPrice(int orderPrice) {
        OrderPrice = orderPrice;
    }

    public String getOrderState() {
        return OrderState;
    }

    public void setOrderState(String orderState) {
        OrderState = orderState;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public List<Product> getProducts() {
        return products;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }

    public Delivery getDelivery() {
        return delivery;
    }

    public void setDelivery(Delivery delivery) {
        this.delivery = delivery;
    }

    //
//    public void searchProduct() {
//        // 상품을 검색하는 코드
//    }
//
//    public void purchaseProduct(Product product) {
//        // 상품을 구매하는 코드
//    }
//
//    public void leaveInquiry() {
//        // 상품 문의를 남기는 코드
//    }
//
//    public void replyToInquiry() {
//        // 상품 문의에 답변하는 코드
//    }
//    public void refund_change(){
//
//    }
//    public void search_buyingInfo() {
//
//    }

}