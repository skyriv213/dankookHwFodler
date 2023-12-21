package domain;

import java.util.List;

public class Community {

    private Seller seller;
    private List<Customer> customers;

    private String title;

    private String contents;

    public void createBoard(){}

    public void createBrandBoard(Seller seller){}
    public void writeBoard(Customer customer, String title, String contents){}

    public void updateBoard(User user, String password, String updatePart){}
    public void deleteBoard(User user, String password){}


}
