package com.opendevel.thread.threadmain;

import com.opendevel.thread.customer.Customer;
import com.opendevel.thread.procumqueue.Queue;
import com.opendevel.thread.product.Product;

public class ThreadMain {

	public static void main(String[] args) {
		Queue queue = Queue.getQueue();
	
		Product product = Product.getProduct();
		Customer customer = Customer.getCustomer(queue);
		
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		 
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		
		 new Thread(customer).start();
		 new Thread(product).start();
		 new Thread(product).start();
 new Thread(product).start();
		 
		 new Thread(customer).start();
		 
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		
		 new Thread(customer).start();
		 new Thread(product).start();
		 new Thread(product).start();
 new Thread(product).start();
		 
		 new Thread(customer).start();
		 
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		
		 new Thread(customer).start();
		 new Thread(product).start();
		 new Thread(product).start();
 new Thread(product).start();
		 
		 new Thread(customer).start();
		 
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		
		 new Thread(customer).start();
		 new Thread(product).start();
		 new Thread(product).start();
 new Thread(product).start();
		 
		 new Thread(customer).start();
		 
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		
		 new Thread(customer).start();
		 new Thread(product).start();
		 new Thread(product).start();
 new Thread(product).start();
		 
		 new Thread(customer).start();
		 
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		
		 new Thread(customer).start();
		 new Thread(product).start();
		 new Thread(product).start();
 new Thread(product).start();
		 
		 new Thread(customer).start();
		 
		 new Thread(product).start();
		 
		 new Thread(customer).start();
		
		 new Thread(customer).start();
		 new Thread(product).start();
		 new Thread(product).start();
	}

}
