package com.opendevel.cake.servlet;


import com.opendevel.cake.entity.Cake;
import com.opendevel.cake.entity.Category;
import com.opendevel.cake.service.CakeService;
import com.opendevel.cake.service.CategoryService;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

public class CakeServlet extends HttpServlet {

    private CakeService cakeService;

    private CategoryService categoryService;

    @Override
    public void init() throws ServletException {
        super.init();
        cakeService = new CakeService();
        categoryService = new CategoryService();
    }

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if ("/cake/list.do".equals(req.getServletPath())) {
            String pageStr = req.getParameter("page");
            String categoryIdStr = req.getParameter("categoryId");
            try {
                Long categoryId = 1L;
                if (null != categoryIdStr && !"".equals(categoryIdStr.trim())) {
                    categoryId = Long.valueOf(categoryIdStr);
                }
                int page = 1;
                if (null != pageStr && !"".equals(pageStr.trim())) {
                    page = Integer.valueOf(pageStr);
                }
                List<Cake> cakes = cakeService.getCakesByCategoryId(categoryId, page, 8);
                int count = cakeService.countCakesByCategoryId(categoryId);
                int last = count % 8 == 0 ? (count / 8) : ((count / 8) + 1);

                List<Category> categories = categoryService.getCategories();

                req.setAttribute("cakes", cakes);
                req.setAttribute("categories", categories);
                req.setAttribute("page", page);
                req.setAttribute("last", last);
                req.setAttribute("categoryId", categoryId);
                req.getRequestDispatcher("/WEB-INF/views/index.jsp").forward(req, resp);
            } catch (NumberFormatException e) {
                req.getRequestDispatcher("/WEB-INF/views/index.jsp").forward(req, resp);
            }
        } else if ("/cake/getImg.do".equals(req.getServletPath())) {
            String idStr = req.getParameter("id");
            Cake cake = cakeService.getCakeImg(Long.valueOf(idStr));
            try {
                resp.setContentType("multipart/form-data");
                if (null != cake && null != cake.getSmallImg()) {
                    InputStream in = new ByteArrayInputStream(cake.getSmallImg());
                    ServletOutputStream out = resp.getOutputStream();
                    byte[] b = new byte[1024];
                    int length = in.read(b);
                    while (length != -1) {
                        out.write(b);
                        length = in.read(b);
                    }
                    out.flush();
                    out.close();
                    in.close();resp.flushBuffer();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void destroy() {

        cakeService = null;
        categoryService = null;
    }


}
