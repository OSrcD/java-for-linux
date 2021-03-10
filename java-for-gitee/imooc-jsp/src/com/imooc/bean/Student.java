package com.imooc.bean;

public class Student {
	String stuNumber;
	String name;
	float score;
	public String getStuNumber() {
		return stuNumber;
	}
	public void setStuNumber(String stuNumber) {
		this.stuNumber = stuNumber;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public float getScore() {
		return score;
	}
	public void setScore(float score) {
		this.score = score;
	}
	public Student(String stuNumber, String name, float score) {
		super();
		this.stuNumber = stuNumber;
		this.name = name;
		this.score = score;
	}
	@Override
	public String toString() {
		return "Student [stuNumber=" + stuNumber + ", name=" + name + ", score=" + score + "]";
	}
	
	
}
