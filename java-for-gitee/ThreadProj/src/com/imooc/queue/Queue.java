package com.imooc.queue;

public class Queue {
	private int n;
	boolean flag=false;
	public synchronized int get() {
		if(!flag) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("���ѣ�"+n);
		flag=false;
		notifyAll();
		return n;
	}

	public synchronized void set(int n) {
		if(flag) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("������"+n);
		this.n = n;
		flag=true;
		notifyAll();	
	}
	
}
