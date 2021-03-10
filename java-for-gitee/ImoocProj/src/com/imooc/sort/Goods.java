package com.imooc.sort;

public class Goods implements Comparable<Goods> {

    private String id;
    private String name;
    private double price;

    public Goods(String id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Goods{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", price=" + price +
                '}';
    }

    @Override
    public int compareTo(Goods o){
        double price1 = this.getPrice();
        double price2 = o.getPrice();
        int n = new Double(price2 - price1).intValue();
        return n;
    }
}
