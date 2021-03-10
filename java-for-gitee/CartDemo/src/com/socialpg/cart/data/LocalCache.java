package com.opendevel.cart.data;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public final class LocalCache {

    private static Map<Long,Product> productMap = new HashMap<Long,Product>();

    private static Map<Long,Cart> cartMap = new HashMap<>();

    private  static Map<Long,Product> favoriteMap = new HashMap<>();

    private  static Map<Long,Product> browseLogMap = new HashMap<>();

    private LocalCache(){

    }



    static {
        productMap.put(1l, new Product(1l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(2l, new Product(2l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(3l, new Product(3l, "JAVA", "JAVA基础课程-基本语法", "介绍java基本语法特性及编写规范", "初级", 219));
        productMap.put(4l, new Product(4l, "JAVA", "JAVA基础课程-JDBC", "介绍JDBC方式连接数据库", "初级", 219));
        productMap.put(5l, new Product(5l, "JAVA", "JAVA基础课程—Socket", "介绍Java网络编程Socket", "初级", 219));
        productMap.put(6l, new Product(6l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(7l, new Product(7l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(8l, new Product(8l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(9l, new Product(9l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(10l, new Product(10l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(11l, new Product(11l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(12l, new Product(12l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(13l, new Product(13l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(14l, new Product(14l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(15l, new Product(15l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(16l, new Product(16l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(17l, new Product(17l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(18l, new Product(18l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(19l, new Product(19l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(20l, new Product(20l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(21l, new Product(21l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(22l, new Product(22l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(23l, new Product(23l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(24l, new Product(24l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
        productMap.put(25l, new Product(25l, "HTML/CSS", "HTML+CSS基础课程", "HTML+CSS基础教程8小时带领大家步步深入学习标签用法和意义", "初级", 219));
    }

    public static List<Product> getProducts(){

        return new ArrayList<>(productMap.values());

    }

    public static Product getProduct(Long id){
        return productMap.get(id);
    }


    public  static void addCart(Product product){
        if(!cartMap.containsKey(product.getId())) {

            cartMap.put(product.getId(), new Cart
                    (product.getId(), product.getId(),
                            product.getName(), product.getPrice(), 1));
        }else {
            incrCart(product.getId());
        }
    }


    public static List<Cart> getCarts(){
        return new ArrayList<>(cartMap.values());
    }


    public static void delCart(Long productId){
        cartMap.remove(productId);
    }

    public  static void incrCart(Long productId){
        cartMap.get(productId).incrCount();
    }


    public  static void decrCart(Long productId){
       boolean  result = cartMap.get(productId).decrCount();
        if(result){
            cartMap.remove(productId);

        }
    }


    public static Cart getCart(Long id){
        return cartMap.get(id);
    }


    public static void addFavorite(Product product){
        if(!favoriteMap.containsKey(product.getId())) {
            favoriteMap.put(product.getId(), product);
        }

    }


    public static void delFavorite(Long productId){
        if(favoriteMap.containsKey(productId)) {
            favoriteMap.remove(productId);
        }

    }

    public static  List<Product> getFavorites(){

        return  new ArrayList<>(favoriteMap.values());


    }


   public static void  addBrowseLog(Product product){
        browseLogMap.put(product.getId(), product);
    }


    public static void  deleteBrowseLog(Long productId){
       browseLogMap.remove(productId);
    }

    public static List<Product> getBrowseLogs(){
        return new ArrayList<>(browseLogMap.values());
    }


    public static List<Product> getProducts(int page,int size,String name){
        List<Product> products = new ArrayList<>();

        if(null != name && !"".equals(name)){
            productMap.values().forEach(product ->{
                if(product.getName().contains(name)) {
                    products.add(product);
                }
            });

        }else{
            products.addAll(productMap.values());
        }


        int start = (page - 1) * size;

        int end = products.size() >= page * size ? page * size:products.size();

        return products.subList(start, end);


    }


    public static int  getProductsCount(String name){
        List<Product> products = new ArrayList<>();

        if(null != name && !"".equals(name)){
            productMap.values().forEach(product ->{
                if(product.getName().contains(name)) {
                    products.add(product);
                }
            });

        }else{
            products.addAll(productMap.values());
        }

        return products.size();



    }

}
