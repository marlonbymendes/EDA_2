#include <iostream>
#include "node.h"

#ifndef HUFFMAN_U
#define HUFFMAN_U

const int ASCII_TABLE_SIZE = 300;

struct Huffman {
    int histogram[ASCII_TABLE_SIZE]; // histogram[i] = ammount of characters in str with ascii value = i
    std::string str;

    Huffman(const std::string& str);

    void build_histogram();
    void print_histogram();
};

#endif
