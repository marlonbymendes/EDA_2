#include <iostream>
#include "node.h"

#define debug(x) std::cout << " >> " #x << " = " << x << std::endl

Node::Node(const char c,
           const int frequency,
           Node* left_child,
           Node* right_child) {
      
    this->c = c;
    this->frequency = frequency;
    this->left_child = left_child;
    this->right_child = right_child;
}

inline void Node::print() {
    debug(frequency);
    debug(c);
}

inline bool Node::has_child(CHILD_TYPE child) {
    bool has = false;
    if(child == LEFT) {
        has = left_child != NULL;
    }
    else if(child == RIGHT) {
        has = right_child != NULL;
    }
    return has;
}

inline bool Node::is_leaf() {
    return has_child(LEFT) and
           has_child(RIGHT);
}

bool Node::operator<(const Node& node) const {
    return frequency < node.frequency;
}

void print_tree(Node node) {
    node.print();
    if(node.has_child(LEFT)) {
        print_tree(*(node.left_child));
    }
    if(node.has_child(RIGHT)) {
        print_tree(*(node.right_child));
    }
}
