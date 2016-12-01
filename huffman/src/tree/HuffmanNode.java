package tree;

public class HuffmanNode implements Comparable<HuffmanNode> {
	
	private int frequency;
	private HuffmanNode left;
	private HuffmanNode right;
	
	public static enum CHILD_TYPES {LEFT, RIGHT};
	
	public HuffmanNode(int frequency, HuffmanNode left, HuffmanNode right) {
		this.frequency = frequency;
		this.left = left;
		this.right = right;
	}
	
	public HuffmanNode(HuffmanNode left, HuffmanNode right) {
		this.frequency = left.getFrequency() + right.getFrequency();
		
		this.left = left;
		this.right = right;
	}
	
	public static void printTree(final HuffmanNode node) {
		if(node != null) {
			System.out.printf("frequency = %d\n", node.frequency);
			if(node.isLeaf()) {
				System.out.printf("letter = %c\n", ((HuffmanLeaf) node).getLetter());
			}
			System.out.println("");
			
			printTree(node.getLeft());
			printTree(node.getRight());
		}
	}
	
	public boolean isLeaf() {
		return !hasChild(CHILD_TYPES.LEFT) &&
			   !hasChild(CHILD_TYPES.RIGHT);
	}
	
	public int getFrequency() {
		return frequency;
	}
	public void setFrequency(int frequency) {
		this.frequency = frequency;
	}
	public HuffmanNode getLeft() {
		return left;
	}
	public void setLeft(HuffmanNode left) {
		this.left = left;
	}
	public HuffmanNode getRight() {
		return right;
	}
	public void setRight(HuffmanNode right) {
		this.right = right;
	}
	
	public int compareTo(final HuffmanNode node) {
		return frequency - node.getFrequency();
	}
	
	public boolean hasChild(CHILD_TYPES child) {
		boolean has = false;
		if(child == CHILD_TYPES.LEFT) {
			has = left != null;
		}
		else if(child == CHILD_TYPES.RIGHT) {
			has = right != null;
		}
		return has;
	}
}

