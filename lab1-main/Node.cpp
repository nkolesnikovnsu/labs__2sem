#include "LinkedList.h"

LinkedList::Node::Node() {
    val = value_type();
}

LinkedList::Node::Node(value_type val_) {
    val = val_;
}

LinkedList::Node::Node(value_type val_, LinkedList::Node* prev_, LinkedList::Node* next_) {
    val = val_;
    prev = prev_;
    next = next_;
}
