package com.imooc.sleep;


class MyThread implements Runnable{
	

	@Override
	public void run() {
		for(int i=1;i<31;i++) {
			System.out.println(Thread.currentThread().getName()+"Ö´ÐÐµÚ"+i+"´Î");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	
}

public class SleepDemo {

	public static void main(String[] args) {
		MyThread mt = new MyThread();
		Thread t = new Thread(mt);
		t.start();
		MyThread mt1 = new MyThread();
		Thread t1= new Thread(mt);
		
		t1.start();
	}

}
