package promotion;


import java.util.ArrayList;
import java.util.List;

public class Promotion {

    private Long PromotionId;

    private String dateExpired;

    private String statePromotion;

    private List<Seller> seller;
    private List<Customer> customers;

    public Long getPromotionId() {
        return PromotionId;
    }

    public String getDateExpired() {
        return dateExpired;
    }

    public String getStatePromotion() {
        return statePromotion;
    }

    public List<Seller> getSeller() {
        return seller;
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public void setPromotionId(Long promotionId) {
        PromotionId = promotionId;
    }

    public void setDateExpired(String dateExpired) {
        this.dateExpired = dateExpired;
    }

    public void setStatePromotion(String statePromotion) {
        this.statePromotion = statePromotion;
    }

    public void setSeller(List<Seller> seller) {
        this.seller = seller;
    }

    public void setCustomers(List<Customer> customers) {
        this.customers = customers;
    }
}