package com.opendevel.cart.servlet;

import com.opendevel.cart.data.LocalCache;
import com.opendevel.cart.data.Product;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Objects;

public class DetailInfoServlet extends HttpServlet {

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if(Objects.equals(request.getServletPath(), "/detail/detail.do")){
            String productId = request.getParameter("productId");

            if(null != productId){
////                Cookie existCookie = null;
////
////                for(Cookie cookie : request.getCookies()){
////                    if(Objects.equals("productIds", cookie.getName())){
////                        existCookie = cookie;
////                        break;
////                    }
////                }
//
//                if(null == existCookie){
//                    existCookie = new Cookie("productIds","/");
//                }


//                existCookie.setValue(existCookie.getValue() + "," + productId);
//                response.addCookie(cookie);
                 //判断Cookie是否存在，若存在则使用已有的，并读出原有数据
                 //若不存在,则新建
                Product product = LocalCache.getProduct(Long.valueOf(productId));
                request.setAttribute("product", product);
                LocalCache.addBrowseLog(product);
            }
        }

        request.getRequestDispatcher("/WEB-INF/views/biz/detail.jsp").forward(request, response);





    }
}
