package tree;

public class HuffmanLeaf extends HuffmanNode {
	private char letter;
	
	public HuffmanLeaf(char letter,
			    int frequency) {
		super(frequency, null, null);
		this.letter = letter;
	}

	public char getLetter() {
		return letter;
	}

	public void setLetter(char letter) {
		this.letter = letter;
	}

	
}
