package cn.java.test;

public class RegextTest {

	public static void main(String[] args) {
		String  data = "1";
		String regex="\\D";
		boolean flag =	data.matches(regex);
//		System.out.println(flag);
		
		String data2 = " ";
		String regex2 = "\\s";
		boolean flag2 =  data2.matches(regex2);
//		System.out.println(flag2);
		
		String data3 = "a";
		String regex3 = "\\S";
		boolean flag3 =  data3.matches(regex3);
//		System.out.println(flag3);
		
		
		
		String data4 = "8";
		String regex4 = "\\w";
		boolean flag4 =  data4.matches(regex4);
//		System.out.println(flag4);
		String data5 = "#";
		String regex5 = "^\\W$";
		boolean flag5 =  data5.matches(regex5);
//		System.out.println(flag5);
		
		
		String data6 = "sin@k.q.q";
		String regex6 = "[a-zA-Z_0-9]{3,}@([a-zA-Z]+|\\d+)(\\.[a-zA-Z]+)+";
		boolean flag6 =  data6.matches(regex6);
		System.out.println(flag6);

	}

}
