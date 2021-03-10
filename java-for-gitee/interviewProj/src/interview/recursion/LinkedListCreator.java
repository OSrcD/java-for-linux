package interview.recursion;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import interview.common.Node;



public class LinkedListCreator {
	/**
	 * Create a linked list.
	 * @param data the data to create the list
	 * @return head of the linked list. The returned linked list
	 * ends with last node with getNext() == null.
	 */
	public Node createLinkedList(List<Integer> data) {
		//特殊情况当传进为空的时候
		if(data.isEmpty()) {
			return null;
		}
		
		//创建一个节点 假设
		Node firstNode  = new Node(data.get(0));
		//自动减一特性 推导 当我null的时候 给headNode接收就为空了
		Node headNode =  createLinkedList(data.subList(1, data.size()));
		firstNode.setNext(headNode);
		
		return firstNode;
	}
	
	
	public Node createLargeLinkedList(int size) {
		Node prev = null;
		Node head = null;
		for(int i=0;i<=size;i++) {
			Node newNode = new Node(i);
			if(prev!=null) {
				
				prev.setNext(newNode);
			}else {
				head=newNode;
			}
			prev=newNode;
		}
		
		return head;
		
		
		
	}
	
	
	public static void main(String[] args) {
		LinkedListCreator linkedListCreator = new LinkedListCreator();
		Node node = linkedListCreator.createLinkedList(Arrays.asList(1,2,3,4,5,6,7,8,9));

		
		
	}

}
