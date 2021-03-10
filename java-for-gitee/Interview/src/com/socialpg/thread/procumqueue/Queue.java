package com.opendevel.thread.procumqueue;



public class Queue {
	private int n;
	private boolean flag =false;
	private static Queue queue;
	
	private Queue() {

	}
	
	public synchronized static Queue  getQueue() {
		if(queue==null) {
			queue = new Queue();
		}
		
		
		return queue;
	}
	
	
	
	
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
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("������"+n);
		this.n=n;
		flag = true;
		notifyAll();
		
	}
	

	
}
