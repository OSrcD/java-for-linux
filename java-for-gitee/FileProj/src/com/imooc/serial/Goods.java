package com.imooc.serial;

import java.io.Serializable;

public class Goods implements Serializable{
	private String goodsId;
	private String goodsName;
	private double price;
	
	public Goods(String goodsId,String goodsName,double price) {
		this.goodsId=goodsId;
		this.goodsName=goodsName;
		this.price=price;
	}

	public String getId() {
		return goodsId;
	}

	public void setId(String goodsId) {
		this.goodsId = goodsId;
	}

	public String getName() {
		return goodsName;
	}

	public void setName(String goodsName) {
		this.goodsName = goodsName;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) { 
		this.price = price;
	}
	
	public String toString() {
		return "商品信息[编号："+goodsId+",名称："+goodsName+",价格："+price;
	}
	
}
