package com.imooc.service;

import org.springframework.web.multipart.MultipartFile;

public interface FdfsService {
    public String upload(MultipartFile file,String fileExName) throws Exception;
}
