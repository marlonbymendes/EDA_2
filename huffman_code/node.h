#include <cstdlib>

#ifndef NODE_H
#define NODE_H

enum CHILD_TYPE{LEFT, RIGHT};

struct Node {

    char c;
    int frequency;

    Node* left_child;
    Node* right_child;

    Node(const char c = 0,
         const int frequency = 0,
         Node* left_child = NULL,
         Node* right_child = NULL);

    inline void print();
    inline bool has_child(CHILD_TYPE child);
    inline bool is_leaf();

    bool operator<(const Node& node) const;
};

void print_tree(Node node);

#endif
