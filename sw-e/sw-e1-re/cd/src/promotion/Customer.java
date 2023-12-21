package promotion;


import java.util.List;

public class Customer extends User {

    private List<Product> products; // 최근 본 상품으로 취급

    private String grade;

    public List<Product> getProducts() {
        return products;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }
}
