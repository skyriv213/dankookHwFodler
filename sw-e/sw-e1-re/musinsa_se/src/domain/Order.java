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

    public String getOrderState() {
        return OrderState;
    }

    public String getOrderdate() {
        return Orderdate;
    }

    public int getOrderPrice() {
        return OrderPrice;
    }

    public Delivery getDelivery() {
        return delivery;
    }

    public void setOrderdate(String orderdate) {
        Orderdate = orderdate;
    }

    public void setOrderPrice(int orderPrice) {
        OrderPrice = orderPrice;
    }

    public void setOrderState(String orderState) {
        OrderState = orderState;
    }

    public void setDelivery(Delivery delivery) {
        this.delivery = delivery;
    }
}