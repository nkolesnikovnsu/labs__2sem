#include "LinkedList.h"
#include <gtest/gtest.h>

using namespace testing;

TEST(TestList, TestingList) {
    LinkedList List;
    ASSERT_TRUE(List.empty());

    EXPECT_ANY_THROW(List.front());
    EXPECT_ANY_THROW(List.back());
    EXPECT_ANY_THROW(List.pop_front());
    EXPECT_ANY_THROW(List.pop_back());

    List.push_back(value_type());
    List.push_back(value_type());
    List.push_back(value_type());
    List.push_back(value_type());

    EXPECT_EQ(List.size(), 4);

    List.push_front(value_type());
    List.push_front(value_type());
    List.push_front(value_type());
    List.push_front(value_type());

    EXPECT_EQ(List.size(), 8);

    List.clear();
    ASSERT_TRUE(List.empty());

    List.push_front(value_type());
    List.push_front(value_type());
    List.push_front(value_type());
    List.push_front(value_type());
    List.push_back(value_type());
    List.push_back(value_type());
    List.push_back(value_type());
    List.push_back(value_type());

    List.pop_back();
    List.pop_back();
    List.pop_back();
    List.pop_back();
    List.pop_back();
    List.pop_back();

    EXPECT_EQ(List.size(), 2);

    List.pop_front();
    List.pop_front();

    ASSERT_TRUE(List.empty());

    for (int i = 0; i < 15; i++) {
        List.push_back(i);
    }

    int val = 0;
    for (LinkedList::iterator it = List.begin(); it != List.end(); it++) {
        EXPECT_EQ(*it, val);
        ++val;
    }

    List.clear();

    for (int i = 0; i < 15; i++) {
        List.push_front(i);
    }

    val--;
    for (LinkedList::iterator it = List.begin(); it != List.end(); it++) {
        EXPECT_EQ(*it, val);
        val--;
    }

    List.clear();

    for (int i = 0; i < 15; i++) {
        List.push_front(i);
    }
    LinkedList secondList = List;
    EXPECT_TRUE(secondList == List);
    EXPECT_FALSE(secondList != List);

    LinkedList moveList = std::move(secondList);
    EXPECT_EQ(moveList, List);
}

TEST(TestList, TestingIterators) {
    LinkedList newList;
    for (int i = 0; i < 15; i++) {
        newList.push_back(i);
    }

    LinkedList::iterator it = newList.begin();
    it = it + 3;
    EXPECT_EQ(*it, 3);

    it = it - 5;
    EXPECT_EQ(*it, 14);

    LinkedList::const_iterator cIt = newList.cbegin();
    it = newList.begin();

    for (int i = 0; i < 15; i++) {
        EXPECT_EQ(*cIt, i);
        EXPECT_EQ(*it, i);
        cIt++;
        it++;
    }

    EXPECT_TRUE(newList.end() == it);
    EXPECT_TRUE(newList.cend() == cIt);
}

TEST(TestList, TestingListOperator) {
    LinkedList left;
    LinkedList right;
    LinkedList newList;

    ASSERT_TRUE(left.empty());
    ASSERT_TRUE(right.empty());
    ASSERT_TRUE(newList.empty());

    left.push_back(value_type());
    left.push_back(value_type());
    left.push_back(value_type());
    right.push_back(value_type());
    right.push_back(value_type());
    right.push_back(value_type());
    right.push_back(value_type());

    newList = left + right;
    EXPECT_EQ(newList.size(), 7);

    left.clear();
    EXPECT_EQ(left.size(), 0);

    right.clear();
    EXPECT_EQ(right.size(), 0);

    newList.clear();
    EXPECT_EQ(newList.size(), 0);
}