package interview.tree;

public class TreeTraversal {

	public void  preOrder(TreeNode root) {
		if(root==null) {
			return;
		}
		
		System.out.print(root.getValue());
		preOrder(root.getLeft());
		preOrder(root.getRight());
	}
	
	public void inOrder(TreeNode root) {
		if(root ==null) {
			return;
		}
		
		
		inOrder(root.getLeft());
		System.out.print(root.getValue());
		inOrder(root.getRight());
		
	}
	
	public void postOrder(TreeNode root) {
		if(root ==null) {
			return;
		}
		
		
	
		
		postOrder(root.getLeft());
		postOrder(root.getRight());
		System.out.print(root.getValue());
	}
	
	
	public String postOrder(String preOrder,String inOrder) {
		if(preOrder.isEmpty()) {
			return "";
		}
			char preStarIndexRoot = preOrder.charAt(0);
			int  inOrderIndexRoot = inOrder.indexOf(preStarIndexRoot);
		 
			return
				postOrder(
					preOrder.substring(1,inOrderIndexRoot+1),
					inOrder.substring(0,inOrderIndexRoot))+
			postOrder(
					preOrder.substring(inOrderIndexRoot+1),
					inOrder.substring(inOrderIndexRoot+1))+preStarIndexRoot;
		
			
		
				
		
		
		}
	
	
	
	
	public static void main(String[] args) {
		TreeCreator creator = new TreeCreator();
		
		TreeTraversal traversal = new TreeTraversal();
		
		TreeNode sampleTree  = creator.createSampleTree();
		
		traversal.preOrder(sampleTree);
		System.out.println("Sample tree traversal");
		traversal.inOrder(sampleTree);
		System.out.println();
		traversal.postOrder(sampleTree);
		System.out.println("Creating tree from preOrder and in Order");
		System.out.println("=====");
		TreeNode tree =  creator.createTree("ABDEGCF", "DBGEACF");
		traversal.postOrder(tree);
		System.out.println();
		
		traversal.postOrder(creator.createTree("",""));
		System.out.println();
		traversal.postOrder(creator.createTree("A","A"));
		System.out.println();
		traversal.postOrder(creator.createTree("AB","BA"));
		System.out.println();
		
		System.out.println("Generationg postOrder directly");
		System.out.println("=====");
		System.out.println(traversal.postOrder("ABDEGCF", "DBGEACF"));
		System.out.println(traversal.postOrder("", ""));
		System.out.println(traversal.postOrder("A", "A"));
		System.out.println(traversal.postOrder("AB", "BA"));
	
	}

}
