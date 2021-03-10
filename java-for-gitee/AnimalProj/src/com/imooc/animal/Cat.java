package com.imooc.animal;

public class Cat extends Animal {


    public String testString="54";

    {
        System.out.println("helloworld");

    }
    public double weight=5;



    public void method(){
        System.out.println("subclassOveried");
    }

    @Override
    public boolean equals(Object object){
        if(object == null)
            return false;
        Animal temp = (Animal)object;

        if(this.getName().equals(temp.getName()) && this.getMonth() == temp.getMonth()){
            return true;
        }else{
            return false;
        }

    }


    public Cat(){
        super();

        System.out.println("this关键字");
        System.out.println(this.testString);
        System.out.println(this.testString);
        System.out.println(this.name);
        System.out.println(this.getName());
        System.out.println("this关键字");
        System.out.println(this.weight);

    }





    {
        System.out.println("构造代码块");
    }

    private String myString = "1";

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    // 跑动的方法
    public void run(){
        System.out.println(this.getName() + "是一只" + this.getSpecies() +
                "它在快乐的奔跑"
        );

    }
}
