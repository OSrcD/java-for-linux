package com.imooc.animal;

 public class  Animal {

    public String name;
    private int month;
    private String species;

    public String testString="55";

    public String myname = "";

    public static void staticMethod(){

    }
    public Animal(){
        System.out.println(this.name);
    }


    public String getName() {
        return name;
    }

    public void method(){
        System.out.println("overied");
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public String getSpecies() {
        return species;
    }

    public void setSpecies(String species) {
        this.species = species;
    }

    //吃东西
    public void eat(){
        System.out.println(this.getName() +  "在吃东西");
    }
}
