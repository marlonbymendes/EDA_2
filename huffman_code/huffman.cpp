#include <cstring>

#include "node.h"
#include "huffman.h"

Huffman::Huffman(const std::string& str) {
    this->str = str;
    build_histogram();
}

void Huffman::build_histogram() {
    memset(this->histogram, 0, sizeof (this->histogram)); // fill array with 0

    for(char c : this->str) {
        int c_ascii_value = c;
        this->histogram[c_ascii_value]++;
    }
}

void Huffman::print_histogram() {
    for(int i = 0; i < ASCII_TABLE_SIZE; ++i) {
        if(histogram[i] > 0) {
            printf("histogram[%c] = %d\n", (char) i, histogram[i]);
        }
    }
}
