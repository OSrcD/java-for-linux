package com.opendev.config;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.opendev.domain.Users;
import com.opendev.domain.manager.UserManager;
import com.opendev.filter.CustomAuthenticationFilter;
import com.opendev.utils.IMOOCJSONResult;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.authentication.CredentialsExpiredException;
import org.springframework.security.authentication.DisabledException;
import org.springframework.security.authentication.LockedException;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.crypto.password.NoOpPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.web.authentication.AuthenticationFailureHandler;
import org.springframework.security.web.authentication.AuthenticationSuccessHandler;
import org.springframework.security.web.authentication.UsernamePasswordAuthenticationFilter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@Configuration
public class SecurityConfig extends WebSecurityConfigurerAdapter {


    @Bean
    public PasswordEncoder passwordEncoder() {
        return NoOpPasswordEncoder.getInstance();
    }


    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.inMemoryAuthentication()
                .withUser("admin").password("123").roles("ADMIN")
                .and()
                .withUser("user").password("123").roles("USER");
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http.cors()
                .and()
                .csrf()
                .disable()
                .authorizeRequests()
                .anyRequest()
                .authenticated()
                .and()
                .formLogin()
                .loginPage("https://192.168.43.15:8081/#/login")
                .permitAll();
        http.addFilterAt(customAuthenticationFilter(), UsernamePasswordAuthenticationFilter.class);
    }

    @Bean
    CustomAuthenticationFilter customAuthenticationFilter() throws Exception {
        CustomAuthenticationFilter filter = new CustomAuthenticationFilter();
        filter.setAuthenticationSuccessHandler(new AuthenticationSuccessHandler() {
            @Override
            public void onAuthenticationSuccess(HttpServletRequest req, HttpServletResponse resp, Authentication auth) throws IOException, ServletException, IOException {

                User principal = (User) auth.getPrincipal();
                resp.setContentType("application/json;charset=utf-8");
                PrintWriter out = resp.getWriter();
                Users user = new Users();
                user.setUsername(principal.getUsername());
                UserManager.users.put(principal.getUsername(),user);
                ObjectMapper om = new ObjectMapper();
                out.write(om.writeValueAsString(IMOOCJSONResult.ok(user)));
                out.flush();
                out.close();

            }
        });

        filter.setAuthenticationFailureHandler(new AuthenticationFailureHandler() {
            @Override
            public void onAuthenticationFailure(HttpServletRequest req, HttpServletResponse resp, AuthenticationException e) throws IOException, ServletException {
                resp.setContentType("application/json;charset=utf-8");
                PrintWriter out = resp.getWriter();
                String errorMsg = null;

                if(e instanceof LockedException){
                    errorMsg = "账户被锁定，登录失败！";
                } else if (e instanceof BadCredentialsException) {
                    errorMsg = "账户名或密码输入错误，登录失败！";
                } else if (e instanceof DisabledException) {
                    errorMsg = "账户被禁用，登录失败！";
                } else if (e instanceof CredentialsExpiredException) {
                    errorMsg = "密码已过期，登录失败";
                } else {
                    errorMsg = "登录失败";
                }
                ObjectMapper om = new ObjectMapper();
                out.write(om.writeValueAsString(IMOOCJSONResult.errorMsg(errorMsg)));
                out.flush();
                out.close();
            }
        });
        filter.setAuthenticationManager(authenticationManagerBean());
        return filter;
    }
}
