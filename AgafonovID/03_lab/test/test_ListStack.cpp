#include <gtest.h>
#include "ListStack.h"

TEST(ListStack, can_create_empty_stack) {
    ASSERT_NO_THROW(ListStack<int> s);
}

TEST(ListStack, created_stack_is_empty) {
    ListStack<int> s;
    EXPECT_TRUE(s.IsEmpty());
}

TEST(ListStack, can_push_element_to_stack) {
    ListStack<int> s;
    ASSERT_NO_THROW(s.Push(5));
}

TEST(ListStack, pushed_element_is_on_top) {
    ListStack<int> s;
    s.Push(5);
    EXPECT_EQ(5, s.Top());
}

TEST(ListStack, can_pop_element_from_stack) {
    ListStack<int> s;
    s.Push(5);
    ASSERT_NO_THROW(s.Pop());
}

TEST(ListStack, pop_removes_top_element) {
    ListStack<int> s;
    s.Push(5);
    s.Push(10);
    s.Pop();
    EXPECT_EQ(5, s.Top());
}

TEST(ListStack, top_throws_when_stack_is_empty) {
    ListStack<int> s;
    ASSERT_THROW(s.Top(), std::exception);
}

TEST(ListStack, pop_throws_when_stack_is_empty) {
    ListStack<int> s;
    ASSERT_THROW(s.Pop(), std::exception);
}

TEST(ListStack, can_assign_stacks) {
    ListStack<int> s1;
    s1.Push(5);
    ListStack<int> s2;
    ASSERT_NO_THROW(s2 = s1);
}

TEST(ListStack, assigned_stack_is_equal_to_original) {
    ListStack<int> s1;
    s1.Push(5);
    ListStack<int> s2;
    s2 = s1;
    EXPECT_TRUE(s1 == s2);
}

TEST(ListStack, can_copy_stack) {
    ListStack<int> s1;
    s1.Push(5);
    ASSERT_NO_THROW(ListStack<int> s2(s1));
}

TEST(ListStack, copied_stack_is_equal_to_original) {
    ListStack<int> s1;
    s1.Push(5);
    ListStack<int> s2(s1);
    EXPECT_TRUE(s1 == s2);
}

TEST(ListStack, stacks_with_different_elements_are_not_equal) {
    ListStack<int> s1, s2;
    s1.Push(5);
    s2.Push(10);
    EXPECT_FALSE(s1 == s2);
}

TEST(ListStack, is_empty_returns_true_for_empty_stack) {
    ListStack<int> s;
    EXPECT_TRUE(s.IsEmpty());
}

TEST(ListStack, is_empty_returns_false_for_non_empty_stack) {
    ListStack<int> s;
    s.Push(5);
    EXPECT_FALSE(s.IsEmpty());
}

TEST(ListStack, is_full_always_returns_false) {
    ListStack<int> s;
    EXPECT_FALSE(s.IsFull());
}
