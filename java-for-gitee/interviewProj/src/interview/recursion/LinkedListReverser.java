package interview.recursion;

import java.util.ArrayList;
import java.util.List;

import interview.common.Node;

public class LinkedListReverser {

		
	public static Node reverseLinkedList(Node head) {
		
		if(head == null || head.getNext()==null) 
			
			return head;
		Node newNode = reverseLinkedList(head.getNext());
		
		head.getNext().setNext(head);
		head.setNext(null);
		
		return newNode; 
	
	}
	

	
	public static void main(String[] args) {
		
	}
	
	
	

}
