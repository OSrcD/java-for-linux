package interview.tree;

public class TreeCreator {
	public TreeNode createSampleTree() {
		TreeNode root = new TreeNode('A');
		root.setLeft(new TreeNode('B'));
		root.getLeft().setLeft(new TreeNode('D'));
		root.getLeft().setRight(new TreeNode('E'));
		root.getLeft().getRight().setLeft(new TreeNode('G'));
		root.setRight(new TreeNode('C'));
		root.getRight().setRight(new TreeNode('F'));
		return root;
	}
	
public TreeNode createTree(String preOrder,String inOrder) {
	if(preOrder.isEmpty() ) {
		return null;
	}
		char preStarIndexRoot = preOrder.charAt(0);
		int  inOrderIndexRoot = inOrder.indexOf(preStarIndexRoot);
		TreeNode root = new TreeNode(preStarIndexRoot);
	
		root.setLeft(
				createTree(
					preOrder.substring(1,inOrderIndexRoot+1),
					inOrder.substring(0,inOrderIndexRoot)));	
		root.setRight(
			createTree(
					preOrder.substring(inOrderIndexRoot+1), 
					inOrder.substring(inOrderIndexRoot+1)));
		
		return root;
	}
	
	
}
