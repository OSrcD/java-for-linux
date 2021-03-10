package com.opendevel.thread.product;

import com.opendevel.thread.procumqueue.Queue;

public class Product implements  Runnable {
	
	private static Queue queue = Queue.getQueue();
	
	private static Product product = new Product(queue);
	
	private int i;
	private  Product (Queue queue) {
		this.queue =queue;
	}
	
	
	public synchronized static Product getProduct() {
		return product;
	}
	
	
	@Override
	public void run() {
		synchronized (product) {
			while(true) {
				try {
					queue.set(i++);
					Thread.sleep(1);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			
		}
		
	}

}
