package com.imooc.runnable;

class PrintRunable implements Runnable{

	int i=1;
	@Override
	public void run() {
		while(i<11) {
			System.out.println(Thread.currentThread().getName()+"线程正在运行！"+i++);
		}
		
	}
	
	
	
	
	
	
}

public class Test {

	public static void main(String[] args) {
		PrintRunable pr = new PrintRunable();
		Thread th = new Thread(pr);
		th.start();	
		Thread th2 = new Thread(pr);
		th2.start();
	}

}
