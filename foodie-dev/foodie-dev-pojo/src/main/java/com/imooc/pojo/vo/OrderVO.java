package com.imooc.pojo.vo;

import com.imooc.pojo.bo.ShopcartBO;

import java.util.List;

public class OrderVO {
    private String orderId;
    private MerchantOrdersVO merchantOrdersVO;
    private List<ShopcartBO> toBeRemovedShopcartList;

    public List<ShopcartBO> getToBeRemovedShopcartList() {
        return toBeRemovedShopcartList;
    }

    public void setToBeRemovedShopcartList(List<ShopcartBO> toBeRemovedShopcartList) {
        this.toBeRemovedShopcartList = toBeRemovedShopcartList;
    }

    public String getOrderId() {
        return orderId;
    }

    public void setOrderId(String orderId) {
        this.orderId = orderId;
    }

    public MerchantOrdersVO getMerchantOrdersVO() {
        return merchantOrdersVO;
    }

    public void setMerchantOrdersVO(MerchantOrdersVO merchantOrdersVO) {
        this.merchantOrdersVO = merchantOrdersVO;
    }
}
