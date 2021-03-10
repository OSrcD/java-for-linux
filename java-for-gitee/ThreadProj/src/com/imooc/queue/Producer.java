package com.imooc.queue;

public class Producer implements Runnable {
	 Queue queue;
	 Producer(Queue queue){
		 this.queue=queue;
	 }
	@Override
	public void run() {
		int i=0;
		while(true) {
			queue.set(i++);
//			try {
//				Thread.sleep(1000);
//			} catch (InterruptedException e) {
//				e.printStackTrace();
//			}
		}
	}

}
