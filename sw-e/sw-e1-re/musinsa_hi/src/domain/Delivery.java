package domain;

public class Delivery {
    private Customer customer;
    private String shippingAddress;
    private String pamentMethod;
    private Order order;

//

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public String getShippingAddress() {
        return shippingAddress;
    }

    public void setShippingAddress(String shippingAddress) {
        this.shippingAddress = shippingAddress;
    }
}

