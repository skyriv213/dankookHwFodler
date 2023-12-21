package domain;

import java.util.ArrayList;
import java.util.List;

public class OrderResultBoundary extends OrderBoundary{

    public List<Product> ResponseConfirmProductsInfo(Customer customer){
        ArrayList<Product> list = new ArrayList<>();
        return list;
    }

    public String checkShippingAddress(){
        return "address";
    }

}
