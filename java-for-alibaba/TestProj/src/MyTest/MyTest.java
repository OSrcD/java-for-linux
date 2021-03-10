package MyTest;

import java.util.Scanner;

public class MyTest {
	
	public static void main(String[] args) {
		
		 int h;
	        System.out.println("请输入盘子个数：");
	        Scanner in=new Scanner(System.in);
	        h=in.nextInt();
	        System.out.println("移动"+h+"个盘子的步骤如下：");
	        move(h,'a','b','c');
	
		
	/*
	 
	 */
		

	}
	
	 private static void move(int n, char x, char y, char z) {
	        // TODO Auto-generated method stub
	        if(n==1){
	            System.out.println(x+"-->"+z+" 最后一个");
	        }
	        else{
	            move(n-1,x,z,y);//将n-1个盘从x移到y，借助z
	            System.out.println(x+"-->"+z);
	            System.out.println("x="+x+" y="+y+" z="+z);
	            move(n-1,y,x,z);
	            System.out.println();
	        }
	    }
	
	
	
}
