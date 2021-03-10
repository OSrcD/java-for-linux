package org.imooc.servlet;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import org.imooc.dto.ImportExcelParamDto;
import org.imooc.dto.ImportExcelResultDto;
import org.imooc.dto.ParamDto;
import org.imooc.service.ExcelService;
import org.imooc.util.RequestUtil;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.util.List;

public class ImportExcelServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if(ServletFileUpload.isMultipartContent(req)){
            ParamDto dto = RequestUtil.parseParam(req);
            ImportExcelParamDto paramDto = new ImportExcelParamDto();
            paramDto.setTitle(dto.getParamMap().get("title"));
            paramDto.setExcel(dto.getFileMap().get("excel"));

            ExcelService service = new ExcelService();
            ImportExcelResultDto resultDto  = service.imp(paramDto);
            req.setAttribute("result",resultDto);

        }else{

        }
        req.getRequestDispatcher("/WEB-INF/jsp/importExcelResult.jsp").forward(req,resp);
    }
}
