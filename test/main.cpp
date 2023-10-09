#include "gtest/gtest.h"

#include "linked_list.h"
#include "linked_list.cpp"

#include "stack.h"
#include "stack.cpp"

TEST(LL, size) {
    LL<int> list;
    EXPECT_EQ (list.size(), 0);
    list.add(1);
    list.add(2);
    list.add(3);
    EXPECT_EQ (list.size(), 3);
}

TEST(LL, add) {
    LL<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    
    EXPECT_EQ (list.get(0), 1);
    EXPECT_EQ (list.get(1), 2);
    EXPECT_EQ (list.get(2), 3);
}

TEST(LL, prepend) {
    LL<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.prepend(55);
    
    EXPECT_EQ (list.get(0), 55);
    EXPECT_EQ (list.get(1), 1);
    EXPECT_EQ (list.get(2), 2);
}

TEST(LL, del) {
    LL<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.del(0);
    
    EXPECT_EQ (list.get(0), 2);
    EXPECT_EQ (list.get(1), 3);
}

TEST(STACK, order) {
    Stack<int> stack(10);
    EXPECT_TRUE(stack.empty());
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ (stack.pop(), 3);
    EXPECT_EQ (stack.pop(), 2);
    EXPECT_EQ (stack.pop(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}