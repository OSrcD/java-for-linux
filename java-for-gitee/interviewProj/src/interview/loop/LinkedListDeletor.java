package interview.loop;

import java.util.ArrayList;
import java.util.List;

import interview.common.Node;
import interview.recursion.LinkedListCreator;
import interview.recursion.LinkedListReverser;

public class LinkedListDeletor {

	public static Node deleteIfEquals(Node head,int value) {
	
		
	
		
		while(head != null && head.getValue() == value ){
		
			head = head.getNext();
		}

		if(head==null) {
			return null;
		}
		
		
		Node prev = head;
		
		while(prev.getNext()!=null) {
		
		
				if(prev.getNext().getValue()== value){
					prev.setNext(prev.getNext().getNext());
					
				}else {
					prev=prev.getNext();
					
				}
			}
		return head;
		}
		

		
	
	public static void main(String[] args) {
	
		LinkedListCreator linkedListCreator = new LinkedListCreator();
		List list = new ArrayList<>();
		list.add(1);
		list.add(2);
		list.add(2);
		list.add(4);
		list.add(2);
		list.add(2);
		list.add(2);
		list.add(6);
		Node node = linkedListCreator.createLinkedList(list);
		
		node.printLinkedList(LinkedListDeletor.deleteIfEquals(node, 2));
	}

}
