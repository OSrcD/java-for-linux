package org.imooc.servlet;

import org.apache.poi.ss.usermodel.Workbook;
import org.imooc.service.ExcelService;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class ExportExcelServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        ExcelService service = new ExcelService();
        Workbook workbook = service.export(true);
        resp.setHeader("content-Disposition","attachment;filename=export.xlsx");
        ServletOutputStream outputStream = resp.getOutputStream();
        FileOutputStream fileOutputStream = new FileOutputStream("d:/upload/export.xlsx");
        workbook.write(fileOutputStream);

        FileInputStream fileInputStream = new FileInputStream("d:/upload/export.xlsx");
        byte [] bytes = new byte[fileInputStream.available()];
        fileInputStream.read(bytes);
        outputStream.write(bytes);
        outputStream.flush();
        outputStream.close();
        workbook.close();
    }
}
