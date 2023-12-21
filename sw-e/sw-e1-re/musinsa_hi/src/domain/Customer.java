package domain;

import java.util.List;

public class Customer extends User{

    private List<CustomerService> customerServices;

//    private List<Coupon> coupons;

    private List<Order> orders;

    private List<Product> products; // 최근 본 상품으로 취급

//    private String grade;

    public List<CustomerService> getCustomerServices() {
        return customerServices;
    }

    public void setCustomerServices(List<CustomerService> customerServices) {
        this.customerServices = customerServices;
    }

    public List<Order> getOrders() {
        return orders;
    }

    public void setOrders(List<Order> orders) {
        this.orders = orders;
    }

    public List<Product> getProducts() {
        return products;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }

//    public List<CustomerService> getCustomerServices() {
//        return customerServices;
//    }
//
//    public List<Product> getProducts() {
//        return products;
//    }
//
////    public List<Coupon> getCoupons() {
////        return coupons;
////    }
//
//
//    public List<Order> getOrders() {
//        return orders;
//        // 주문목록 조회하기
//    }
//
//    public void changeGrade(String grade) {
//
//    }
}
