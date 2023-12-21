package promotion;

public class User {

    private String userId;
    private String password;
    private String name;
    private String birth;
    private String email;
    private String phoneNumber;
//
//    public void change_name(String name){
//    }
//    public void change_id_pw(String changePassword, String password){
//    }
//    public void change_birth(String birth){
//    }
//    public void find_id_pw(String checkInfo){
//    }


    public String getUserId() {
        return userId;
    }

    public String getPassword() {
        return password;
    }

    public String getName() {
        return name;
    }

    public String getBirth() {
        return birth;
    }

    public String getEmail() {
        return email;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setBirth(String birth) {
        this.birth = birth;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
}
