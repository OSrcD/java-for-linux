package com.imooc.model;

public class Subject {
	private String subjectName;
	private String subjectNo;
	private int subjectLife;
	private Students [] myStudents;//无论存放的什么类型 都是引用类型 默认为null
	private int studentNum;
	public Subject() {

	}

	public Subject(String subjectName, String subjectNo, int subjectLife) {
		this.setSubjectName(subjectName);
		this.setSubjectNo(subjectNo);
		this.setSubjectLife(subjectLife);
	}
	
	public Subject(String subjectName, String subjectNo, int subjectLife,Students[] myStudents) {
		this.setSubjectName(subjectName);
		this.setSubjectNo(subjectNo);
		this.setSubjectLife(subjectLife);
		this.setMyStudents(myStudents);
	}

	public void setSubjectName(String subjectName) {
		this.subjectName = subjectName;
	}

	public String getSubjectName() {
		return this.subjectName;
	}

	public String getSubjectNo() {
		return subjectNo;
	}

	public void setSubjectNo(String subjectNo) {
		this.subjectNo = subjectNo;
	}

	public int getSubjectLife() {
		return subjectLife;
	}

	public void setSubjectLife(int subjectLife) {
		if (subjectLife <= 0)
			return;
		this.subjectLife = subjectLife;
	}
	/**
	 * 获取选修专业的学生信息 如果保存学生信息的数组未被初始化，则先初始化长度200
	 * @return 保存学生信息的数组
	 */
	public Students[] getMyStudents() {
		if(this.myStudents == null)
			this.myStudents = new Students[200];
		return myStudents;
	}

	public void setMyStudents(Students[] myStudents) {
		this.myStudents = myStudents;
	}

	public int getStudentNum() {
		return studentNum;
	}

	public void setStudentNum(int studentNum) {
		this.studentNum = studentNum;
	}

	/**
	 * 专业介绍的方法
	 * @return 专业介绍的相关信息，包括名称、编号、年限
	 */
	public String info() {
		String str = "专业信息如下：\n专业名称：" + this.getSubjectName() + "\n专业编号：" + this.getSubjectNo() + "\n学制年限:"
				+ this.getSubjectLife() + "年";
		return str;
	}
	
	public void addStudent(Students stu) {
		/*
		 * 1.将学生保存到数组中
		 * 2.将学生个数保存到studentNum中
		 * */
		
		//1.将学生保存到数组种
		for(int i=0;i<this.getMyStudents().length;i++) {
			if(this.getMyStudents()[i]==null) {
				this.getMyStudents()[i]=stu;
				this.studentNum=i+1;
				return;
			}
		}
		//2.将学生个数保存到studentNum
	
	}

}
