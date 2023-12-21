package promotion;


public class Product {

    private Customer customer;
//    private Seller seller;
    private String productName;
    private String productCategory;
    private double productPrice;
    private String productSize;
    private String productColor;
    private String productInfo;
    private int productStock;
    private String productReview;


    public Customer getCustomer() {
        return customer;
    }

    public String getProductName() {
        return productName;
    }

    public String getProductCategory() {
        return productCategory;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public void setProductCategory(String productCategory) {
        this.productCategory = productCategory;
    }

    //-----
//    public void addProduct() {
//        // 상품을 등록하는 코드
//    }
//
//    public void addToWishlist() {
//        // 상품을 찜 목록에 추가하는 코드
//    }
//    public void checkProduct(){
//
//    }
//    public void managemaentPage(){
//
//    }
//    public void managementproductState(){
//
//    }
//
//    public void sortCategory(String query){
//
//    }


}


