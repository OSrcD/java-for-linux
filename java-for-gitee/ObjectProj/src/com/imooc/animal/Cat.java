package com.imooc.animal;
/**
 * 宠物猫类 
 * @author LattePanda
 *
 */
public class Cat {
	private String name;
	private int month;
	private double weight;
	private String species;
	
	public static int price;
	
	static {
		System.out.println("我是静态代码块1");
	}
	
	public Cat(int month) {
		this.setMonth(month);
	}
	public Cat() {
		
		System.out.println("我是宠物猫");
	}
	
	{
		name="妞妞";
		price=130;
		
		System.out.println("我是构造代码块1");
	}
	
	static{
		price = 290;
		Cat temp = new Cat();
		temp.name="小胖";
		
		System.out.println("我是静态代码块2");
	}
	
	public int getMonth() {
		return month;
	}
	public void setMonth(int month) {
		if(month <=0)
			System.out.println("输入错误，宠物猫的年龄必须大于0");
		else
			this.month = month;
	}
	public double getWeight() {
		return weight;
	}
	public void setWeight(double weight) {
		this.weight = weight;
	}
	public String getSpecies() {
		return species;
	}
	public void setSpecies(String species) {
		this.species = species;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		
		return "我是一只叫"+this.name+"猫咪";
	}
	
	
	
	public Cat(String name,int month,double weight,String species) {
		
		this();
		this.name = name;
		this.month = month;
		this.weight = weight;
		this.species = species;
	}
	public void run()  {
	
		eat();
		this.name="妞妞";
		this.price=20;
		System.out.println("售价是"+Cat.price+"的"+this.name+"快跑");
	}
	public static void eat() {
		Cat temp = new Cat();
		temp.run();
		temp.name="小胖";
		temp.price=100;
		
	}
	public void run(String name) {
		
		{ 
			int temp=12;
			System.out.println("我是普通代码块1,temp="+temp);
		}
	
		System.out.println();

		{ 
			int temp=13;
			System.out.println("我是普通代码块2,temp="+temp);
		}
	}
}
