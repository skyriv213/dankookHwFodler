package domain;

import java.util.ArrayList;
import java.util.List;

public class Promotion {

    private Long PromotionId;

    private String dateExpired;
//    private List<Coupon> coupons;

    private String statePromotion;

    private List<Seller> seller;
    private List<Customer> customers;

//    private List<Customer> customers;

    // 프로모션,이벤트 관리하기
    public void changePromotionState(String statePromotion){
    }

    // 비슷한 상품 추천하기
    public List<Product> getRecommendProduct(
        Seller seller, String sortByQuery){
        List<Product> list = new ArrayList<>();
        return list;
    }

    // 라이브 진행하기
    public String getLiveVideo(Seller seller){
        return "url";
    }
    // 상품 체험단 관리하기
    public void controlTryProductCustomer(Seller seller){

    }
    //상품 및 브랜드 홍보하기
    public List<Product> recommendBrand(Seller seller){
        List<Product> productList = new ArrayList<>();
        return productList;
    }

    // 래플 응모 진행하기
    public List<Customer> choseCustomer(
        Customer customer){
        List<Customer> customers= new ArrayList<>();
        return customers;
    }

    // 래플 응모하기
    public void applyRaffle(Customer customer){}


}