package com.opendevel.classreflect;

public class ClassReflect {

	public static void main(String[] args) {
		Class <?> myClass = String.class;
		String  str = "Hello";
		System.out.println(str.getClass());
		System.out.println(myClass);
		Class myInt = int.class;
		System.out.println(myInt);
		Class myInteger = Integer.class;
		System.out.println(myInteger);
		System.out.println("myInt �����ƣ�"+myInt.getName());
		System.out.println("myInt �Ƿ�Ϊ�ӿ�"+myInt.isInterface());
		System.out.println("myInt �Ƿ�Ϊ�������"+myInt.isArray());
		System.out.println("myInt ��������"+myInt.getSuperclass());
		System.out.println("myInt �Ƿ�Ϊ��������"+myInt.isPrimitive());
		System.out.println("myInteer �Ƿ�Ϊ��������"+myInteger.isPrimitive());
		System.out.println("myInteger ��������"+myInteger.getSuperclass());
		Class myNumber = Number.class;
		System.out.println("myNumber ��������"+myNumber.getSuperclass());
		
		
	}

}
