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
		if (studentSex.equals("��") || studentSex.equals("Ů"))
			this.studentSex = studentSex;
		else
			this.studentSex = "��";
	}

	public int getStudentAgs() {
	
		return studentAgs;
	}
	
	/**
	 * ��ȡרҵ�������û��ʵ��������ʵ�������ٷ���
	 * @return רҵ������Ϣ
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
	 * �����丳ֵ���޶�������10-100֮�䣬��֮��ֵΪ18
	 * 
	 * @param studentAgs ���������
	 */
	public void setStudentAgs(int studentAgs) {
		if (studentAgs < 10 || studentAgs > 100)
			this.studentAgs = 18;
		else
			this.studentAgs = studentAgs;
	}

	/**
	 * �W�����ҽ�B�ķ���
	 * 
	 * @return ���ҽ��ܵ���Ϣ������������ѧ�š��Ա�����
	 */
	public String introduction() {
		String str = "ѧ����Ϣ���£�\n����" + this.getStudentName() + "\nѧ�ţ�" + this.getStudentNO() + "\n�Ա�"
				+ this.getStudentSex() + "\n���䣺" + this.getStudentAgs()+ "\n������רҵ����:" + this.getStudentSubject().getSubjectName() + "\nѧ������:"
						+ this.getStudentSubject().getSubjectLife();
		return str;
	}
	/**
	 * ѧ�����ҽ��ܵķ���
	 * @param subjectName ��ѧרҵ����
	 * @param subjectLife ѧ������
	 * @return ���ҽ��ܵ���Ϣ������������ѧ�š��Ա����䡢��ѧרҵ���ơ�ѧ������
	 */
	public String introduction(String subjectName, int subjectLife) {
		String str = "ѧ����Ϣ���£�\n����" + this.getStudentName() + "\nѧ�ţ�" + this.getStudentNO() + "\n�Ա�"
				+ this.getStudentSex() + "\n���䣺" + this.getStudentAgs() + "\n������רҵ����:" + subjectName + "\nѧ������:"
				+ subjectLife;
		return str;
	}
	/**
	 * ѧ�����ҽ��ܵķ���
	 * @param mySubject ��ѡרҵ�Ķ���
	 * @return return ���ҽ��ܵ���Ϣ������������ѧ�š��Ա����䡢��ѧרҵ���ơ�ѧ������
	 */
	public String introduction(Subject mySubject) {
		String str = "ѧ����Ϣ���£�\n����" + this.getStudentName() + "\nѧ�ţ�" + this.getStudentNO() + "\n�Ա�"
				+ this.getStudentSex() + "\n���䣺" + this.getStudentAgs() + "\n������רҵ����:" + mySubject.getSubjectName() + "\nѧ������:"
				+ mySubject.getSubjectLife()+"\nרҵ��ţ�"+mySubject.getSubjectNo();
		return str;
	}

}
