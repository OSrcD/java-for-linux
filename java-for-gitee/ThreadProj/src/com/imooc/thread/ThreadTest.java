package com.imooc.thread;
class MyThread  extends Thread{
	
	public void run() {
		while(true)
		System.out.println(getName()+"���߳��������У�");
	
		
	}
	
}
public class ThreadTest {

	public static void main(String[] args) {
		
		MyThread myThread = new MyThread();
		myThread.start();
		while(true) {
			System.out.println("���߳�1");
			System.out.println("���߳�2");
			
		}
	}

}
