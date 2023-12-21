package domain;

public class CustomerService{
    private Customer customer;
    private Seller seller;
    private String content_type;
    private String content;

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
}