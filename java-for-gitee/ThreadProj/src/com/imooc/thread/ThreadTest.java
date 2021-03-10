package com.imooc.thread;
class MyThread  extends Thread{
	
	public void run() {
		while(true)
		System.out.println(getName()+"该线程正在运行！");
	
		
	}
	
}
public class ThreadTest {

	public static void main(String[] args) {
		
		MyThread myThread = new MyThread();
		myThread.start();
		while(true) {
			System.out.println("主线程1");
			System.out.println("主线程2");
			
		}
	}

}
