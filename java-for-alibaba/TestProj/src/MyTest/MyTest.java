package MyTest;

import java.util.Scanner;

public class MyTest {
	
	public static void main(String[] args) {
		
		 int h;
	        System.out.println("���������Ӹ�����");
	        Scanner in=new Scanner(System.in);
	        h=in.nextInt();
	        System.out.println("�ƶ�"+h+"�����ӵĲ������£�");
	        move(h,'a','b','c');
	
		
	/*
	 
	 */
		

	}
	
	 private static void move(int n, char x, char y, char z) {
	        // TODO Auto-generated method stub
	        if(n==1){
	            System.out.println(x+"-->"+z+" ���һ��");
	        }
	        else{
	            move(n-1,x,z,y);//��n-1���̴�x�Ƶ�y������z
	            System.out.println(x+"-->"+z);
	            System.out.println("x="+x+" y="+y+" z="+z);
	            move(n-1,y,x,z);
	            System.out.println();
	        }
	    }
	
	
	
}
