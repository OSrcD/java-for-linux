package com.imooc.generic;

import java.util.ArrayList;
import java.util.List;

public class GoodTest {
    public static void main(String[] args) {
        List<Book> books = new ArrayList<>();
        books.add(new Book());
        books.add(new Book());
        List<Clothes> clothes = new ArrayList<Clothes>();
        clothes.add(new Clothes());
        clothes.add(new Clothes());
        List<Shoes> shoes = new ArrayList<>();
        shoes.add(new Shoes());
        shoes.add(new Shoes());

        GoodsSeller goodsSeller = new GoodsSeller();
//        goodsSeller.sellGoods(shoes);
    }
}
