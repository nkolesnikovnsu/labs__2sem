#include "LinkedList.h"
#include <stdexcept>

using std::logic_error;

LinkedList::LinkedList() {
    tail = new Node();
    tail -> prev = tail;
    tail -> next = tail;
}

LinkedList::LinkedList(const LinkedList &other) {
    tail = new Node();
    tail -> prev = tail;
    tail -> next = tail;
    for (LinkedList::const_iterator it = other.cbegin(); it != other.cend(); it++) {
        push_back(*it);
    }
}

LinkedList::LinkedList(LinkedList &&other) noexcept {
    tail = other.tail;
    count = other.count;
    other.tail = nullptr;
    other.count = 0;
}

LinkedList::~LinkedList() {
    clear();
    delete tail;
}

LinkedList &LinkedList::operator=(const LinkedList &other) {
    if (this == &other) return *this;
    clear();
    for (LinkedList::const_iterator it = other.cbegin(); it != other.cend(); it++) {
        push_back(*it);
    }
    return *this;
}

LinkedList &LinkedList::operator=(LinkedList &&other) {
    if (this == &other) return *this;
    clear();
    delete tail;

    tail = other.tail;
    other.tail = nullptr;
    count = other.count;
    other.count = 0;

    return *this;
}

int LinkedList::size() const {
    return count;
}

bool LinkedList::empty() const {
    return count == 0;
}

LinkedList::iterator LinkedList::begin() {
    return LinkedList::iterator(tail -> next);
}

LinkedList::const_iterator LinkedList::begin() const {
    return LinkedList::const_iterator(tail -> next);
}

LinkedList::const_iterator LinkedList::cbegin() const {
    return LinkedList::const_iterator(tail -> next);
}

LinkedList::iterator LinkedList::end() {
    return LinkedList::iterator(tail);
}

LinkedList::const_iterator LinkedList::end() const {
    return LinkedList::const_iterator(tail);
}

LinkedList::const_iterator LinkedList::cend() const {
    return LinkedList::const_iterator(tail);
}

value_type &LinkedList::front() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return tail -> next -> val;
}

const value_type &LinkedList::front() const {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return tail -> next -> val;
}

value_type &LinkedList::back() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return tail -> prev -> val;
}

const value_type &LinkedList::back() const {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return tail -> prev -> val;
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator pos) {
    Node* beforePos = (pos - 1).currentList;
    Node* afterPos = (pos + 1).currentList;

    beforePos -> next = afterPos;
    afterPos -> prev = beforePos;

    delete pos.currentList;
    return LinkedList::iterator(beforePos);
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {
    LinkedList::iterator it = begin;
    while (it != end) {
        it = erase(it);
    }
    return it;
}

int LinkedList::remove(const value_type &val) {
    int count = 0;
    LinkedList::iterator it = begin();
    while (it != end()) {
        if (*it == val) {
            it = erase(it);
            count++;
        } else {
            it++;
        }
    }
    return count;
}

void LinkedList::clear() {
    while (!empty()) {
        pop_back();
    }
}

void LinkedList::pop_back() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    erase(end() - 1);
    count--;
}

void LinkedList::pop_front() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }

    erase(begin());
    count--;
}

void LinkedList::push_back(const value_type &val) {
    insert(end(), val);
    count++;
}

void LinkedList::push_front(const value_type &val) {
    insert(begin(), val);
    count++;
}

LinkedList::iterator LinkedList::insert(LinkedList::iterator before, const value_type &value) {
    Node* last = (before - 1).currentList;
    Node* after = before.currentList;
    Node* toInsert = new Node(value, last, after);

    last -> next = toInsert;
    after -> prev = toInsert;
    return LinkedList::iterator(toInsert);
}

LinkedList &LinkedList::operator+=(const LinkedList &other) {
    for (LinkedList::const_iterator it = other.cbegin(); it != other.cend(); it++) {
        push_back(*it);
    }
    return *this;
}

bool operator!=(const LinkedList &left, const LinkedList &right) {
    return !(left == right);
}

bool operator==(const LinkedList &left, const LinkedList &right) {
    LinkedList::const_iterator it1 = left.cbegin();
    LinkedList::const_iterator it2 = right.cbegin();

    for (; it1 != left.cend() && it2 != right.cend(); it1++, it2++) {
        if (*it1 != *it2) {
            return false;
        }
    }
    return !(it1 != left.cend() || it2 != right.cend());
}

LinkedList operator+(const LinkedList & left, const LinkedList & right) {
    return LinkedList(left) += LinkedList(right);
}
