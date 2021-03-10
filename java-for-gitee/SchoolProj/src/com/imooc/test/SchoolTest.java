package com.imooc.test;
import com.imooc.model.Students;
import com.imooc.model.Subject;
public class SchoolTest {

	public static void main(String[] args) {
		Subject sub1 = new Subject("计算机科学与应用","J0001",4);
		System.out.println(sub1.info());
		System.out.println("========================");
		Students stu1=new Students("S01","张三","男",200,sub1);
		System.out.println(stu1.introduction());
		System.out.println("========================");
		Students stu2 = new Students("S02","李四","女",17);
		System.out.println(stu2.introduction("计算机科学与应用", 4));
		System.out.println("========================");
		Students stu3 = new Students("503","王五","男",18);
		System.out.println(stu3.introduction(sub1));
		System.out.println("========================");
		sub1.addStudent(stu1);
		sub1.addStudent(stu2);
//		sub1.addStudent(stu3);
		System.out.println(sub1.getSubjectName()+"的专业种已有 "+sub1.getStudentNum()+"学生进行了报名");
		
		
		
	}

}
