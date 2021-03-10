package wrap;

public class WrapTestOne {

	public static void main(String[] args) {
		int t1 = 2;
		Integer t2 = t1;
		Integer t3 = new Integer(t1);
		System.out.println("int类型变量t1="+t1);
		System.out.println("Integer类型对象t2="+t2);
		System.out.println("Integer类型对象t3="+t3);
		System.out.println("*************************");
		
		int t4 = t2;
		int t5 = t2.intValue();
		System.out.println("Integer类型对象t2="+t2);
		System.out.println("自动拆箱后，int类型变量t4="+t4);
		System.out.println("手动拆箱后，int类型变量t5="+t5);
		double t6 = t2.doubleValue();
		System.out.println("手动拆箱后,double类型变量t6="+t6);
	

		
	}
  
}
