package huffman_code;

import java.util.*;

import tree.HuffmanLeaf;
import tree.HuffmanNode;

public class HuffmanCode {
	private String text;
	private Map<Character, Integer> frequencyTable;
	private HuffmanNode huffmanRoot;

	public HuffmanCode(String text) {
		this.text = text;
		frequencyTable = new HashMap<Character, Integer>();

		buildHuffmanCode();
	}

	private void buildHuffmanCode() {
		buildFrequencyTable();
		buildHuffmanTree();
	}

	private void buildFrequencyTable() {
		for (char letter : text.toCharArray()) {
			// Character letter = new Character(c);
			int charCount = 1;
			if (frequencyTable.containsKey(letter)) {
				charCount += frequencyTable.get(letter);
			}
			frequencyTable.put(letter, charCount);
		}
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

	public void printFrequencyTable() {
		for (Map.Entry<Character, Integer> entry : frequencyTable.entrySet()) {
			final Character letter = entry.getKey();
			final Integer charCount = entry.getValue();
			System.out.printf("count[%c] = %d\n", letter, charCount);
		}
	}

	private void buildHuffmanTree() {
		PriorityQueue<HuffmanNode> pq = new PriorityQueue<HuffmanNode>();

		for (Map.Entry<Character, Integer> entry : frequencyTable.entrySet()) {
			final Character letter = entry.getKey();
			final Integer charCount = entry.getValue();

			final HuffmanLeaf leaf = new HuffmanLeaf(letter, charCount);
			pq.offer(leaf);
		}

		while (pq.size() > 1) {
			HuffmanNode leftNode = pq.poll();
			HuffmanNode rightNode = pq.poll();

			HuffmanNode nextNode = new HuffmanNode(leftNode, rightNode);
			pq.offer(nextNode);
		}

		huffmanRoot = pq.poll();
	}

	public void printCodes() {
		System.out.printf("%10s %7s %12s\n\n", "[LETTER]", "[CODE]", "[FREQUENCY]");
		StringBuffer prefixCode = new StringBuffer("");
		printCodes(prefixCode, huffmanRoot);
	}

	public void printCodes(StringBuffer prefixCode, final HuffmanNode node) {
		if (node.isLeaf()) {
			final HuffmanLeaf leaf = (HuffmanLeaf) node;
			final Character letter = leaf.getLetter();
			final int frequency = leaf.getFrequency();

			System.out.printf("%8s%c %7s %13d\n", "", letter, prefixCode, frequency);
		} else {
			if (node.hasChild(HuffmanNode.CHILD_TYPES.LEFT)) {
				prefixCode.append('0');
				printCodes(prefixCode, node.getLeft());
				prefixCode.deleteCharAt(prefixCode.length() - 1);
			}
			if (node.hasChild(HuffmanNode.CHILD_TYPES.RIGHT)) {
				prefixCode.append('1');
				printCodes(prefixCode, node.getRight());
				prefixCode.deleteCharAt(prefixCode.length() - 1);
			}
		}
	}
}
