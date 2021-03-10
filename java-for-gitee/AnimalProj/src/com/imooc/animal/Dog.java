package com.imooc.animal;

public class Dog extends Animal {

    private String sex; //性别

    public Dog(){

    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void sleep(){
        System.out.println(this.getName()+ "是一只" + this.getSpecies() + ",它在快乐的奔跑");
    }
}
