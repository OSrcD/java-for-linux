package com.imooc.thread1;

class MyThread extends Thread{
	public MyThread(String name) {
		super.setName(name);
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<11;i++) {
			System.out.println(getName()+"线程正在运行"+i);
			
		}
		
	}
}
public class ThreadTest {

	public static void main(String[] args) {
		MyThread  myThread = new MyThread("线程1");
		MyThread  myThread2 = new MyThread("线程2");
		myThread.start();
		myThread2.start();
		
	}

}
