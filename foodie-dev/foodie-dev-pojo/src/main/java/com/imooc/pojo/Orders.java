package com.imooc.pojo;

import javax.persistence.*;
import java.util.Date;

public class Orders {
    @Id
    private String id;

    @Column(name = "products_id")
    private String productsId;

    private Integer number;

    private Double price;

    @Column(name = "create_time")
    private Date createTime;

    @Column(name = "send_time")
    private Date sendTime;

    @Column(name = "confirm_time")
    private Date confirmTime;

    private String consignee;

    @Column(name = "consignee_phone")
    private String consigneePhone;

    @Column(name = "consignee_address")
    private String consigneeAddress;

    private String status;

    /**
     * @return id
     */
    public String getId() {
        return id;
    }

    /**
     * @param id
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * @return products_id
     */
    public String getProductsId() {
        return productsId;
    }

    /**
     * @param productsId
     */
    public void setProductsId(String productsId) {
        this.productsId = productsId;
    }

    /**
     * @return number
     */
    public Integer getNumber() {
        return number;
    }

    /**
     * @param number
     */
    public void setNumber(Integer number) {
        this.number = number;
    }

    /**
     * @return price
     */
    public Double getPrice() {
        return price;
    }

    /**
     * @param price
     */
    public void setPrice(Double price) {
        this.price = price;
    }

    /**
     * @return create_time
     */
    public Date getCreateTime() {
        return createTime;
    }

    /**
     * @param createTime
     */
    public void setCreateTime(Date createTime) {
        this.createTime = createTime;
    }

    /**
     * @return send_time
     */
    public Date getSendTime() {
        return sendTime;
    }

    /**
     * @param sendTime
     */
    public void setSendTime(Date sendTime) {
        this.sendTime = sendTime;
    }

    /**
     * @return confirm_time
     */
    public Date getConfirmTime() {
        return confirmTime;
    }

    /**
     * @param confirmTime
     */
    public void setConfirmTime(Date confirmTime) {
        this.confirmTime = confirmTime;
    }

    /**
     * @return consignee
     */
    public String getConsignee() {
        return consignee;
    }

    /**
     * @param consignee
     */
    public void setConsignee(String consignee) {
        this.consignee = consignee;
    }

    /**
     * @return consignee_phone
     */
    public String getConsigneePhone() {
        return consigneePhone;
    }

    /**
     * @param consigneePhone
     */
    public void setConsigneePhone(String consigneePhone) {
        this.consigneePhone = consigneePhone;
    }

    /**
     * @return consignee_address
     */
    public String getConsigneeAddress() {
        return consigneeAddress;
    }

    /**
     * @param consigneeAddress
     */
    public void setConsigneeAddress(String consigneeAddress) {
        this.consigneeAddress = consigneeAddress;
    }

    /**
     * @return status
     */
    public String getStatus() {
        return status;
    }

    /**
     * @param status
     */
    public void setStatus(String status) {
        this.status = status;
    }
}