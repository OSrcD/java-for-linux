package com.opendevel.thread.customer;

import com.opendevel.thread.procumqueue.Queue;


public class Customer implements Runnable {
	private Queue queue;
	private volatile static Customer customer;
	private Customer(Queue queue) {
		this.queue = queue;
		
	}
	
	public synchronized static Customer getCustomer(Queue queue) {
		if(customer == null) {
			synchronized(Customer.class) {
				if(customer == null) {
					customer = new Customer(queue);
				}
			}
		}
		
		return customer;
	}
	
	
	@Override
	public void run() {
		while(true) {
			synchronized(this) {
				queue.get();
				try {
					Thread.sleep(1);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
	}
	
	
	
}
