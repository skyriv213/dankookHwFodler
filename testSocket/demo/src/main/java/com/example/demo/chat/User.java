package com.example.demo.chat;


import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.EnumType;
import jakarta.persistence.Enumerated;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;
import java.util.ArrayList;
import java.util.List;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;

@Getter
@Builder
@NoArgsConstructor
@AllArgsConstructor

@Table(name = "users")
@Entity
public class User {


    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "user_id")
    private Long id;

    private String username;

    private String password;

    private String userImg;

    private String nickname;

    private String email;

    @Enumerated(EnumType.STRING)
    private userType userType;

    public enum userType {
        ADMIN, COMMON
    }

//    // 연관관계 작성
//
//    @OneToMany(mappedBy = "user", cascade = CascadeType.ALL, orphanRemoval = true)
//    @Builder.Default
//    private List<UserChatRoom> userChatRooms = new ArrayList<>();
//    public void updatePassword(String password) {
//        this.password = password;
//    }
//
//    public void updateUserInfo(UserUpdateRequest userUpdateRequest){
//        this.nickname = userUpdateRequest.getNickname();
//    }

}
