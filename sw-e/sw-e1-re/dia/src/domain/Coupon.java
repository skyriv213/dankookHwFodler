package domain;

import java.util.Date;

public class Coupon {
    private Long couponId;
    private Seller seller;
    private String couponName;

    private String couponProduct;

    //쿠폰 기간 관리하기
    public void stateExpiredCoupon(boolean checkValue){}

    // 쿠폰 사용 관리하기
    public void useCoupon(boolean use){}

    // 쿠폰 사용시 가격 조회하기
    public int calculatePrice(int price){
        return 0;
    }





}
