package com.imooc.test;
import com.imooc.model.Students;
import com.imooc.model.Subject;
public class SchoolTest {

	public static void main(String[] args) {
		Subject sub1 = new Subject("�������ѧ��Ӧ��","J0001",4);
		System.out.println(sub1.info());
		System.out.println("========================");
		Students stu1=new Students("S01","����","��",200,sub1);
		System.out.println(stu1.introduction());
		System.out.println("========================");
		Students stu2 = new Students("S02","����","Ů",17);
		System.out.println(stu2.introduction("�������ѧ��Ӧ��", 4));
		System.out.println("========================");
		Students stu3 = new Students("503","����","��",18);
		System.out.println(stu3.introduction(sub1));
		System.out.println("========================");
		sub1.addStudent(stu1);
		sub1.addStudent(stu2);
//		sub1.addStudent(stu3);
		System.out.println(sub1.getSubjectName()+"��רҵ������ "+sub1.getStudentNum()+"ѧ�������˱���");
		
		
		
	}

}
