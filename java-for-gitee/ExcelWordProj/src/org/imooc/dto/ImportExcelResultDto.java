package org.imooc.dto;

import org.apache.commons.fileupload.FileItem;
import org.imooc.entity.Student;

import java.util.List;

public class ImportExcelResultDto {
    private String title;
    private List<Student> studentList;
    private String msg;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public List<Student> getStudentList() {
        return studentList;
    }

    public void setStudentList(List<Student> studentList) {
        this.studentList = studentList;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }
}
