package org.imooc.servlet;

import org.apache.poi.hwpf.HWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.imooc.service.WordService;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class ExportWordServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");
        WordService service = new WordService();
        Map<String,String> param = new HashMap<>();
        param.put("${name}", req.getParameter("name"));
        param.put("${age}", req.getParameter("age"));
        param.put("${time}",req.getParameter("time"));
        ServletOutputStream outputStream = resp.getOutputStream();
        if(req.getParameter("isDocx") !=null && !"".equals(req.getParameter("isDocx"))){
            XWPFDocument docx = service.export07(param);
            resp.setHeader("Content-Disposition","attachment;filename=export.doc");
            docx.write(outputStream);
            docx.close();
        }else{
            HWPFDocument doc = service.export03(param);
            resp.setHeader("Content-Disposition","attachment;filename=export.doc");
            doc.write(outputStream);
            doc.close();

        }



        outputStream.flush();
        outputStream.close();

    }
}