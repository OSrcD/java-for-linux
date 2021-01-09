package com.imooc.service;

import com.imooc.utils.PagedGridResult;

public interface ItemsESService {

    public PagedGridResult searchItems(String keyword,
                                       String sort,
                                       Integer page,
                                       Integer pageSize);

}
