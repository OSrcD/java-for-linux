package interview.loop;

import java.util.ArrayList;
import java.util.List;

import interview.common.Node;
import interview.recursion.LinkedListCreator;

public class LinkedListReverser {

	public Node reverseLinkedList(Node head) {
		Node newHead = null;
		Node curHead = head;
	
		while(curHead!=null) {
			Node next = curHead.getNext();
			curHead.setNext(newHead);
			newHead=curHead;
			curHead= next;
			
		}
		return newHead;
	}
	
	public static void main(String[] args) {
		
	}

}
