package main;

import java.util.Scanner;

import huffman_code.HuffmanCode;

public class Main {

	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		while(scanner.hasNextLine()) {
			String text = scanner.nextLine();
	        HuffmanCode huffmanCode = new HuffmanCode(text);
			huffmanCode.printCodes();
			
			System.out.println("\n");
		}
		scanner.close();
	}
}
