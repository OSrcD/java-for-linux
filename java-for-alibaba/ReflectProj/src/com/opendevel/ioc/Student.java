package com.opendevel.ioc;

public class Student {
	String str;
	int i;
	String mystr;
	
	
	public Student(String str,int i,String mystr) {
		this.str=str;
		this.i=i;
		this.mystr=mystr;
		
	}


	public String getStr() {
		return str;
	}


	public void setStr(String str) {
		this.str = str;
	}


	public int getI() {
		return i;
	}


	public void setI(int i) {
		this.i = i;
	}


	public String getMystr() {
		return mystr;
	}


	@Override
	public String toString() {
		return "Student [str=" + str + ", i=" + i + ", mystr=" + mystr + "]";
	}


	public void setMystr(String mystr) {
		this.mystr = mystr;
	}
	
	
	
	
}
