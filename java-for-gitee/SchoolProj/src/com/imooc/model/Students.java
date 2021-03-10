package com.imooc.model;

public class Students {
	private String studentNO;
	private String studentName;
	private String studentSex;
	private int studentAgs;
	private Subject studentSubject;

	public Students() {

	}

	
	public Students(String studentNO, String studentName, String studentSex, int studentAgs) {
		this.setStudentNO(studentNO);
		this.setStudentName(studentName);
		this.setStudentSex(studentSex);
//		this.setStudentAgs(studentAgs);
		this.studentAgs = studentAgs;
		
	}
	
	
	public Students(String studentNO, String studentName, String studentSex, int studentAgs,Subject studentSubject) {
		this.setStudentNO(studentNO);
		this.setStudentName(studentName);
		this.setStudentSex(studentSex);
//		this.setStudentAgs(studentAgs);
		this.studentAgs = studentAgs;
		this.setStudentSubject(studentSubject);
	}

	public String getStudentNO() {
		return studentNO;
	}

	public void setStudentNO(String studentNO) {
		this.studentNO = studentNO;
	}

	public String getStudentName() {
		return studentName;
	}

	public void setStudentName(String studentName) {
		this.studentName = studentName;
	}

	public String getStudentSex() {
		return studentSex;
	}

	public void setStudentSex(String studentSex) {
		if (studentSex.equals("男") || studentSex.equals("女"))
			this.studentSex = studentSex;
		else
			this.studentSex = "男";
	}

	public int getStudentAgs() {
	
		return studentAgs;
	}
	
	/**
	 * 获取专业对象，如果没有实例化，先实例化后再返回
	 * @return 专业对象信息
	 */
	public Subject getStudentSubject() {
		if(this.studentSubject==null)
			return this.studentSubject = new Subject();
		return studentSubject;
	}

	public void setStudentSubject(Subject studentSubject) {
		this.studentSubject = studentSubject;
	}

	/**
	 * 给年龄赋值，限定必须在10-100之间，反之赋值为18
	 * 
	 * @param studentAgs 传入的年龄
	 */
	public void setStudentAgs(int studentAgs) {
		if (studentAgs < 10 || studentAgs > 100)
			this.studentAgs = 18;
		else
			this.studentAgs = studentAgs;
	}

	/**
	 * 學生自我介紹的方法
	 * 
	 * @return 自我介绍的信息，包括姓名、学号、性别、年龄
	 */
	public String introduction() {
		String str = "学生信息如下：\n姓名" + this.getStudentName() + "\n学号：" + this.getStudentNO() + "\n性别："
				+ this.getStudentSex() + "\n年龄：" + this.getStudentAgs()+ "\n所报的专业名称:" + this.getStudentSubject().getSubjectName() + "\n学制年限:"
						+ this.getStudentSubject().getSubjectLife();
		return str;
	}
	/**
	 * 学生自我介绍的方法
	 * @param subjectName 所学专业名称
	 * @param subjectLife 学制年限
	 * @return 自我介绍的信息，包括姓名、学号、性别、年龄、所学专业名称、学制年限
	 */
	public String introduction(String subjectName, int subjectLife) {
		String str = "学生信息如下：\n姓名" + this.getStudentName() + "\n学号：" + this.getStudentNO() + "\n性别："
				+ this.getStudentSex() + "\n年龄：" + this.getStudentAgs() + "\n所报的专业名称:" + subjectName + "\n学制年限:"
				+ subjectLife;
		return str;
	}
	/**
	 * 学生自我介绍的方法
	 * @param mySubject 所选专业的对象
	 * @return return 自我介绍的信息，包括姓名、学号、性别、年龄、所学专业名称、学制年限
	 */
	public String introduction(Subject mySubject) {
		String str = "学生信息如下：\n姓名" + this.getStudentName() + "\n学号：" + this.getStudentNO() + "\n性别："
				+ this.getStudentSex() + "\n年龄：" + this.getStudentAgs() + "\n所报的专业名称:" + mySubject.getSubjectName() + "\n学制年限:"
				+ mySubject.getSubjectLife()+"\n专业编号："+mySubject.getSubjectNo();
		return str;
	}

}
