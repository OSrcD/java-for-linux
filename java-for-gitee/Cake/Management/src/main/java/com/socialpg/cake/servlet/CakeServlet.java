package com.opendevel.cake.servlet;

import com.opendevel.cake.entity.Cake;
import com.opendevel.cake.entity.Category;
import com.opendevel.cake.service.CakeService;
import com.opendevel.cake.service.CategoryService;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileItemFactory;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;

public class CakeServlet extends HttpServlet {

    private CakeService cakeService;
    private CategoryService categoryService;

    @Override
    public void init(ServletConfig config) throws ServletException {
        super.init(config);
        cakeService = new CakeService();
        categoryService = new CategoryService();
    }

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println(req.getServletPath());


        if("/cake/list.do".equals(req.getServletPath())){
            String categoryIdStr = req.getParameter("categoryId");

            try{
                Long categoryId = null;
                if(null != categoryIdStr){
                    categoryId = Long.valueOf(categoryIdStr);
                }
                if(categoryIdStr == null){
                    categoryId = 1L;
                }
                List<Cake>cakes = cakeService.getCakesByCategoryId(categoryId, 1, 5000);
                req.setAttribute("cakes",cakes);
                req.getRequestDispatcher("/WEB-INF/views/biz/cake_list.jsp").forward(req, resp);

                List<Category> categories = categoryService.getCategories();
                req.setAttribute("categories",categories);
                req.getRequestDispatcher("/WEB-INF/views/biz/cake_list.jsp").forward(req, resp);

            }catch (NumberFormatException e){
                req.getRequestDispatcher("/WEB-INF/views/biz/cake_list.jsp").forward(req, resp);

            }
        }else if("/cake/addPrompt.do".equals(req.getServletPath())){
            List<Category> categories = categoryService.getCategories();
            req.setAttribute("categories",categories);
            req.getRequestDispatcher("/WEB-INF/views/biz/add_list.jsp").forward(req, resp);
        }else if("/cake/add.do".equals(req.getServletPath())){
            req.setCharacterEncoding("utf-8");
            if(ServletFileUpload.isMultipartContent(req)){
                try{
                    FileItemFactory factory = new DiskFileItemFactory();

                    ServletFileUpload upload = new ServletFileUpload(factory);

                    List<FileItem> items = upload.parseRequest(req);
                    Iterator<FileItem>  ite = items.iterator();

                    Cake cake = new Cake();

                    while (ite.hasNext()){
                        FileItem item = ite.next();
                        if(item.isFormField()){
                            String fieldName = item.getFieldName();
                            if("categoryId".equals(fieldName)){
                                cake.setCategoryId(Long.valueOf(item.getString()));
                            }else if("level".equals(fieldName)){
                                cake.setLevel(Integer.valueOf(item.getString()));
                            }else if("name".equals(fieldName)){
                                cake.setName(item.getString());
                            }else if ("price".equals(fieldName)){
                                cake.setPrice(Integer.valueOf(item.getString()));
                            }
                        }else{
                            cake.setSmallImg(item.get());
                        }
                    }

                    cakeService.addCake(cake);
                    req.getRequestDispatcher("/cake/list.do").forward(req, resp);


                }catch (FileUploadException e){
                   e.printStackTrace();
                }
            }
        }
    }

    @Override
    public void destroy() {
        super.destroy();
        cakeService = null;
        categoryService = null;
    }




}
