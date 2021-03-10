package com.opendevel.cart.servlet;

import com.opendevel.cart.data.LocalCache;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Objects;

public  class  FavoriteServlet extends HttpServlet {

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if(Objects.equals(req.getServletPath(), "/favorite/favorite.do")){
            String productId = req.getParameter("productId");

            if(null != productId){
                LocalCache.addFavorite(LocalCache.getProduct(Long.valueOf(productId)));

            }
            resp.sendRedirect("/favorite/list.do");
        }else if (Objects.equals(req.getServletPath(), "/favorite/delete.do")) {
           String productId = req.getParameter("productId");
           if(null != productId) {
               LocalCache.delFavorite(Long.valueOf(productId));
           }
            resp.sendRedirect("/favorite/list.do");
        } else if (Objects.equals(req.getServletPath(), "/favorite/list.do")){
            req.setAttribute("products", LocalCache.getFavorites());
            req.getRequestDispatcher("/WEB-INF/views/biz/favorite.jsp").forward(req, resp);
        }
    }
}
