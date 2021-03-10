package com.imooc.model;

public class Subject {
	private String subjectName;
	private String subjectNo;
	private int subjectLife;
	private Students [] myStudents;//���۴�ŵ�ʲô���� ������������ Ĭ��Ϊnull
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
	 * ��ȡѡ��רҵ��ѧ����Ϣ �������ѧ����Ϣ������δ����ʼ�������ȳ�ʼ������200
	 * @return ����ѧ����Ϣ������
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
	 * רҵ���ܵķ���
	 * @return רҵ���ܵ������Ϣ���������ơ���š�����
	 */
	public String info() {
		String str = "רҵ��Ϣ���£�\nרҵ���ƣ�" + this.getSubjectName() + "\nרҵ��ţ�" + this.getSubjectNo() + "\nѧ������:"
				+ this.getSubjectLife() + "��";
		return str;
	}
	
	public void addStudent(Students stu) {
		/*
		 * 1.��ѧ�����浽������
		 * 2.��ѧ���������浽studentNum��
		 * */
		
		//1.��ѧ�����浽������
		for(int i=0;i<this.getMyStudents().length;i++) {
			if(this.getMyStudents()[i]==null) {
				this.getMyStudents()[i]=stu;
				this.studentNum=i+1;
				return;
			}
		}
		//2.��ѧ���������浽studentNum
	
	}

}
