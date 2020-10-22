package com.imooc.service.impl;

import com.github.pagehelper.PageInfo;
import com.imooc.utils.PagedGridResult;

import java.util.List;

public class BaseService {


    public PagedGridResult setterPagedGrid(List<?> list, Integer page) {

        PageInfo<?> pageInfo = new PageInfo<>(list);
        PagedGridResult grid = new PagedGridResult();
        grid.setPage(page);
        grid.setRows(list);
        grid.setTotal(pageInfo.getPages());
        grid.setRecords(pageInfo.getTotal());
        return grid;

    }

}
