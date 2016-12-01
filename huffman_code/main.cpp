#include <iostream>

#include "node.h"
#include "huffman.h"

void test_Node();

int main() {

    std::string str;
    std::cin >> str;

    Huffman huffman(str);

    huffman.print_histogram();

	return 0;
}

void test_Node() {
    Node a('a', 1);
    Node b('b', 2);
    Node ab(0, 3, &a, &b);

    Node c('c', 3);
    Node d('d', 4);
    Node cd(0, 7, &c, &d);

    Node e('e', 5);
    Node f('f', 6);
    Node ef(0, 11, &e, &f);

    Node abcd(0, 10, &ab, &cd);

    Node abcdef(0, 21, &abcd, &ef);

    print_tree(abcdef);
}
