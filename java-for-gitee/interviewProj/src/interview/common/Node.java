package interview.common;

public class Node {
	final private int value;
	private Node next;
	
	
	
	public Node(Integer value) {
		this.value = value;
		this.next=null;
	}
	public Node getNext() {
		return next;
	}
	public void setNext(Node next) {
		this.next = next;
	}
	public int getValue() {
		return value;
	}
	
	public static void printLinkedList(Node node) {
		while(node!=null) {
			System.out.print(node.getValue()+" ");
			node=node.next;
		}
		System.out.println();
		
	}
	
	
	
	
	
	
	
}
