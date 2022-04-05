#include "LinkedList.h"

LinkedList::const_iterator::const_iterator() {
    currentList = new Node();
}

LinkedList::const_iterator::const_iterator(LinkedList::Node *Node_) {
    currentList = Node_;
}

LinkedList::const_iterator &LinkedList::const_iterator::operator=(const LinkedList::const_iterator &other) {
    currentList = other.currentList;
    return *this;
}

bool LinkedList::const_iterator::operator!=(const LinkedList::const_iterator &other) const {
    return currentList != other.currentList;
}

bool LinkedList::const_iterator::operator==(const LinkedList::const_iterator &other) const {
    return currentList == other.currentList;
}

const value_type &LinkedList::const_iterator::operator*() const {
    return currentList -> val;
}

const value_type *LinkedList::const_iterator::operator->() const {
    return &(currentList -> val);
}

LinkedList::const_iterator &LinkedList::const_iterator::operator++() {
    currentList = currentList -> next;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int) {
    LinkedList::const_iterator it = *this;
    currentList = currentList -> next;
    return it;
}

LinkedList::const_iterator &LinkedList::const_iterator::operator--() {
    currentList = currentList -> prev;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int) {
    LinkedList::const_iterator it = *this;
    currentList = currentList -> next;
    return it;
}

LinkedList::const_iterator LinkedList::const_iterator::operator+(int shift) {
    LinkedList::const_iterator it = *this;
    for (int i = 0; i < shift; i++) {
        it++;
    }
    return it;
}

LinkedList::const_iterator LinkedList::const_iterator::operator-(int shift) {
    LinkedList::const_iterator it = *this;
    for (int i = 0; i < shift; i++) {
        it--;
    }
    return it;
}