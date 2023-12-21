package domain;

public class Product {

    private Customer customer;
    private Seller seller;
    private String productName;
    private String productCategory;
    private double productPrice;
    private String productSize;
    private String productColor;
    private String productInfo;
    private int productStock;
    private String productReview;

    public String getProductName() {
        return productName;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public double getProductPrice() {
        return productPrice;
    }

    public void setProductPrice(double productPrice) {
        this.productPrice = productPrice;
    }

    public String getProductSize() {
        return productSize;
    }

    public void setProductSize(String productSize) {
        this.productSize = productSize;
    }

    public String getProductColor() {
        return productColor;
    }

    public void setProductColor(String productColor) {
        this.productColor = productColor;
    }

//
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


