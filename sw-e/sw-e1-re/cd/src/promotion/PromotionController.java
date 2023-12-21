package promotion;

import java.util.ArrayList;
import java.util.List;

public class PromotionController {

    private Promotion promotion;

    public Customer RappleLottery(){return new Customer();}

    public List<Product> makeRecommendProductList(){
        List<Product> l = new ArrayList<>();
        return l;
    }


    // 비슷한 상품 추천하기
    public List<Product> getRecommendProduct(Seller seller, String sortByQuery){
        List<Product> list = new ArrayList<>();
        return list;
    }

    // 래플 응모 진행하기
    public List<Customer> choseCustomer(Customer customer){
        List<Customer> customers= new ArrayList<>();
        return customers;
    }

    // 래플 응모하기
    public void applyRaffle(Customer customer){}




}
