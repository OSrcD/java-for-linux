package org.imooc.dto;

import org.apache.commons.fileupload.FileItem;

public class ImportExcelParamDto {
    private String title;
    private FileItem excel;



    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public FileItem getExcel() {
        return excel;
    }

    public void setExcel(FileItem excel) {
        this.excel = excel;
    }
}
