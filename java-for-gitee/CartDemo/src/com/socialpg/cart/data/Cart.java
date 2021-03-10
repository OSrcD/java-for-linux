package com.opendevel.cart.data;

public class Cart {

    public  Cart(Long id,Long productId,String name,int price,int count){
        this.id = id;
        this.productId = productId;
        this.name = name;
        this.price = price;
        this.count = count;
        this.totalPrice =   price * count;
    }


    public void incrCount(){
        count++;
        this.totalPrice = price * count;
    }


    public boolean decrCount(){
        count--;
        this.totalPrice = price * count;

        if(0 == count){
            return true;
        }

        return false;

    }



    private  Long id;

    private Long productId;

    private String name;

    private int price;

    private int count;

    private int totalPrice;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Long getProductId() {
        return productId;
    }

    public void setProductId(Long productId) {
        this.productId = productId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public int getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(int totalPrice) {
        this.totalPrice = totalPrice;
    }
}
