package domain;

public class User {

    private String userId;
    private String password;
    private String name;
    private String birth;
    private String email;
    private String phoneNumber;



//    public void change_name(String name){
//    }
//    public void change_id_pw(String changePassword, String password){
//    }
//    public void change_birth(String birth){
//    }
//    public void find_id_pw(String checkInfo){
//    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
}
