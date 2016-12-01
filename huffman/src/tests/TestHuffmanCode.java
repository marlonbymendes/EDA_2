package tests;

import huffman_code.HuffmanCode;
import tree.HuffmanLeaf;
import tree.HuffmanNode;

public class TestHuffmanCode {

	public static void testNode() {
		
		HuffmanNode l = new HuffmanNode(2, null, null);
		HuffmanNode r = new HuffmanNode(3, null, null);
		
		HuffmanNode root = new HuffmanNode(5, l, r);
		HuffmanNode.printTree(root);
	}
	
	public static void testNeaf() {
		HuffmanLeaf a = new HuffmanLeaf('a', 7);
		HuffmanLeaf b = new HuffmanLeaf('b', 11);
		
		
		HuffmanLeaf c = new HuffmanLeaf('c', 13);
		HuffmanLeaf d = new HuffmanLeaf('d', 17);
		
		HuffmanNode ab = new HuffmanNode(18, a, b);
		HuffmanNode cd = new HuffmanNode(30, c, d);
		
		HuffmanNode abcd = new HuffmanNode(48, ab, cd);
	    HuffmanNode.printTree(abcd);
	}
	
	public static void testHuffmanFrequency() {
		final String text = "Universidade";
		HuffmanCode huffmanCode = new HuffmanCode(text);
		huffmanCode.printFrequencyTable();
	}
	
	public static void testHuffmanTree() {
		final String text = "Universidade";
		HuffmanCode huffmanCode = new HuffmanCode(text);
		huffmanCode.printCodes();
	}
}
