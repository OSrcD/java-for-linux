package interview.tree;

public class InOrder {
	
	public TreeNode next(TreeNode node) {
		if(node == null) {
			return null;
		}
		
		if(node.getRight()!=null) {
			
			return first(node.getRight());
		}else {
			while(node.getParent() !=null &&
					node.getParent().getRight()==node) {		
				node = node.getParent();
			}
			
			return node.getParent();
		}
	}
	
	public TreeNode first(TreeNode node) {
		if(node == null) {
			return null;
		}
		TreeNode curNode = node;
		while(curNode.getLeft()!=null) {
			curNode = curNode.getLeft();
		}
		return curNode;
	}

	public void traverse(TreeNode root) {
		for(TreeNode node =first(root);
				node != null;
				node = next(node)) {
			System.out.print(node.getValue());
			
		}
		System.out.println();
	}
	
	
	
	
	public static void main(String[] args) {
		TreeCreator creator = new TreeCreator();
		InOrder inOrder = new InOrder();
		
		TreeNode sampleTree = creator.createSampleTree();
		
		inOrder.traverse(sampleTree);
		inOrder.traverse(creator.createTree("",""));

		inOrder.traverse(creator.createTree("A","A"));
	
		inOrder.traverse(creator.createTree("AB","BA"));
		
		inOrder.traverse(creator.createTree("ABCD","DCBA"));
		
		inOrder.traverse(creator.createTree("ABCD","ABCD"));
		
	}

}
