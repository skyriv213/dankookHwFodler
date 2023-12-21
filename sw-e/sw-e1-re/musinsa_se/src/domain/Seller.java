package domain;

import java.util.ArrayList;
import java.util.List;
public class Seller extends User {

    private boolean agreementBusiness;
    private List<Product> products;
    private List<Order> orders;

//    private List<Promotion> promotions;
//    private List<Coupon> coupons;

    private List<CustomerService> customerServices;


    public List<Product> getProductsList() {
        return products;
        // 전체 판매상품 조회하기
    }

    public List<Order> getOrders() {
        return orders;
        // 전체 주문 목록 조회하기
    }

    public List<CustomerService> getCustomerServices() {
        return customerServices;
        // 전체 고객 문의 사항 조회하기
    }

    public List<String> getCustomerReview() {
        ArrayList<String> review = new ArrayList<>();
        return review;
    }
}
