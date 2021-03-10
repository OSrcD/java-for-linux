package com.imooc.priority;


class MyThread extends Thread{
	private String name;

	public MyThread(String name) {
		this.name=name;
		
	}
	
	@Override
	public void run() {
		for(int i=1;i<=50;i++) {
			System.out.println("线程"+name+"正在运行"+i);
		
		}
	}
}

public class PriorityDemo {
	
	public static void main(String[] args) {
		
		int mainPriority=Thread.currentThread().getPriority();
//		System.out.println("主线程的优先级为:"+mainPriority);
		MyThread mt1= new MyThread("线程1");
		MyThread mt2 = new MyThread("线程2");
//		mt1.setPriority(10);
		mt1.setPriority(Thread.MAX_PRIORITY);
		mt2.setPriority(Thread.MIN_PRIORITY);
		mt2.start();
		mt1.start();
//		System.out.println("线程1的优先级为："+mt1.getPriority());
	}

}
