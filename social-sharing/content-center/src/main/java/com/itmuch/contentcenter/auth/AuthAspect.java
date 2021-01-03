package com.itmuch.contentcenter.auth;

import com.itmuch.contentcenter.util.JwtOperator;
import io.jsonwebtoken.Claims;
import lombok.RequiredArgsConstructor;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.reflect.MethodSignature;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.context.request.RequestAttributes;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.servlet.http.HttpServletRequest;
import java.lang.annotation.Annotation;
import java.lang.reflect.Method;
import java.util.Objects;

@Aspect
@Component
@RequiredArgsConstructor(onConstructor = @__(@Autowired))
public class AuthAspect {

    public final JwtOperator jwtOperator;

    @Around("@annotation(com.itmuch.contentcenter.auth.CheckLogin)")
    public Object checkLoing(ProceedingJoinPoint point) throws Throwable {
            //try cach被改造在方法里面
            checkToken();
            /**
             * 合法继续执行
             * return 的地方执行完，如果有异常还是会进入catch块，放到这里抛给上层处理
             * 不要认它进入上面的catch块,这里不会捕获自己写的业务异常，因为它不包含try catch块
             * 抛出的Throwable是这个方法的相关的异常
             */
            return point.proceed();


    }

    private void checkToken() {
        try {
            // 1.从Header里面获取token
            HttpServletRequest request = getHttpServletRequest();

            // 获得token
            String token = request.getHeader("X-Token");

            // 2.校验token是否合法&是否过期；如果不合法或已过期直接抛异常；如果合法就放行
            Boolean isVolid = jwtOperator.validateToken(token);

            if(!isVolid){
                // 不合法
                throw new SecurityException("Token不合法");
            }

            // 3.如果校验成功，那么就将用户的信息设置到request的attribute里面
            Claims claims = jwtOperator.getClaimsFromToken(token);
            request.setAttribute("id",claims.get("id"));
            request.setAttribute("wxNickname",claims.get("wxNickname"));
            request.setAttribute("role",claims.get("role"));
        } catch (Throwable throwable) {
            throw new SecurityException("Token不合法");
        }
    }

    private HttpServletRequest getHttpServletRequest() {
        RequestAttributes requestAttributes = RequestContextHolder.getRequestAttributes();

        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes) requestAttributes;

        return (HttpServletRequest)servletRequestAttributes.getRequest();
    }

    @Around("@annotation(com.itmuch.contentcenter.auth.CheckAuthorization)")
    public Object checkAuthorization(ProceedingJoinPoint point) throws Throwable {
        try {
            // 1.验证token是否合法，里面的方法抛异常也被捕获到里面的状态码
            this.checkToken();

            // 2.验证用户角色是否匹配
            HttpServletRequest request = getHttpServletRequest();

            // 从请求里拿到角色值
            String role = (String)request.getAttribute("role");

            // 反射操作

            // 相当于拿到类定义
            MethodSignature signature = (MethodSignature)point.getSignature();

            // 反射方法
            Method method = signature.getMethod();

            // 得到CheckAuthorization反射
            CheckAuthorization  checkAuthorization = method.getAnnotation(CheckAuthorization.class);

            // 反射值
            String value = checkAuthorization.value();

            // 无权限抛异常
            if(!Objects.equals(role,value)){
                throw new SecurityException("用户无权访问！");
            }


        } catch (Throwable throwable) {
            throw new SecurityException("用户无权访问！",throwable);
        }

        /**
         * return 的地方执行完，如果有异常还是会进入catch块，放到这里抛给上层处理
         * 不要认它进入上面的catch块,这里不会捕获自己写的业务异常，因为它不包含try catch块
         * 抛出的Throwable是这个方法的相关的异常
         */
         return point.proceed();


    }

}
