#include "List_stack.h"
#include <gtest.h>



TEST(liststack, can_create_liststack)
{
    ASSERT_NO_THROW(ListStack<int> s);
}

TEST(listStack, can_push) {
    ListStack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    EXPECT_EQ(s.Top(), 3);
}

TEST(listStack, isnt_empty_after_push) {
    ListStack<int> s;
    s.Push(1);
    EXPECT_FALSE(s.IsEmpty());
}

TEST(ListStack, can_pop) {
    ListStack<int> s;
    s.Push(1);
    s.Push(2);
    s.Pop();
    EXPECT_EQ(s.Top(), 1);
}

TEST(ListStack, is_empty_after_popping_all_elements) {
    ListStack<int> s;
    s.Push(1);
    s.Pop();
    EXPECT_TRUE(s.IsEmpty());
}

TEST(ListStack, liststack_isnt_full) {
    ListStack<int> s;
    EXPECT_FALSE(s.IsFull());
}
TEST(ListStack, can_create_copied_liststack)
{
    ListStack<int> s;
    ASSERT_NO_THROW(ListStack<int> s1(s));
}
TEST(liststack, can_assign_liststack)
{
    ListStack<int> s;
    s.Push(1);
    ListStack<int> s1;
    s1 = s;
    EXPECT_TRUE(s == s1);
}