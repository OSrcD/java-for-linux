package com.itmuch.usercenter;


import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.extern.slf4j.Slf4j;



@Slf4j
public class LombokTest {

//    public static final Logger LOGGER = LoggerFactory.getLogger(LombokTest.class);

    public static void main(String[] args){

        UserRegisterDTO userRegisterDTO = UserRegisterDTO.builder()
                .email("xxx@xxx.com")
                .password("123")
                .confiredPassword("123")
                .agreement(true)
                .build();

        log.info("构造出来的对象:" + userRegisterDTO);
    }




}

@Data
//@NoArgsConstructor
@AllArgsConstructor
//@RequiredArgsConstructor
@Builder
class UserRegisterDTO{

    private String email;
    private String password;
    private String confiredPassword;
    private boolean agreement;


}


