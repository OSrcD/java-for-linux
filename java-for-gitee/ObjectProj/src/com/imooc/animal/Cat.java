package com.imooc.animal;
/**
 * ����è�� 
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
		System.out.println("���Ǿ�̬�����1");
	}
	
	public Cat(int month) {
		this.setMonth(month);
	}
	public Cat() {
		
		System.out.println("���ǳ���è");
	}
	
	{
		name="��";
		price=130;
		
		System.out.println("���ǹ�������1");
	}
	
	static{
		price = 290;
		Cat temp = new Cat();
		temp.name="С��";
		
		System.out.println("���Ǿ�̬�����2");
	}
	
	public int getMonth() {
		return month;
	}
	public void setMonth(int month) {
		if(month <=0)
			System.out.println("������󣬳���è������������0");
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
		
		return "����һֻ��"+this.name+"è��";
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
		this.name="��";
		this.price=20;
		System.out.println("�ۼ���"+Cat.price+"��"+this.name+"����");
	}
	public static void eat() {
		Cat temp = new Cat();
		temp.run();
		temp.name="С��";
		temp.price=100;
		
	}
	public void run(String name) {
		
		{ 
			int temp=12;
			System.out.println("������ͨ�����1,temp="+temp);
		}
	
		System.out.println();

		{ 
			int temp=13;
			System.out.println("������ͨ�����2,temp="+temp);
		}
	}
}
