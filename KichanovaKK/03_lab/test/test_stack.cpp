#include "stack.h"

#include <gtest.h>


TEST(stack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(stack<int> s(5));
}

TEST(stack, throws_when_create_stack_with_negative_length)
{
    ASSERT_ANY_THROW(stack<int> s(-5));
}

TEST(stack, can_push_and_pop) {
    stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    EXPECT_FALSE(s.IsEmpty());
    EXPECT_EQ(s.Top(), 3);
    s.Pop();
    EXPECT_EQ(s.Top(), 2);
    s.Pop();
    s.Pop();
    EXPECT_TRUE(s.IsEmpty());
}
TEST(stack, stack_is_full) {
    stack<int> s(2);
    s.Push(1);
    s.Push(2);
    EXPECT_TRUE(s.IsFull());
    s.Push(3); 
    EXPECT_FALSE(s.IsFull());
}
TEST(stack, can_create_copied_stack)
{
    stack<int> s(10);
    ASSERT_NO_THROW(stack<int> s1(s));
}

TEST(stack, copied_stack_has_its_own_memory)
{
    stack<int> s;
    s.Push(1);
    s.Push(2);
    stack<int> s1(s);
    s.Pop();
    EXPECT_NE(s, s1);
}
TEST(stack, can_assign_stack_to_itself)
{
    stack<int> s;
    s.Push(1);
    s.Push(2);
    ASSERT_NO_THROW(s = s);
}

TEST(stack, can_assign_stacks_of_equal_size)
{
    stack<int> s1;
    s1.Push(1);
    s1.Push(2);
    stack<int> s2;
    s2.Push(1);
    s2.Push(2);
    s2 = s1;
    EXPECT_EQ(s1, s2);
}
TEST(stack, can_assign_stacks_of_different_size)
{
    stack<int> s1;
    s1.Push(1);
    s1.Push(2);
    stack<int> s2;
    s2.Push(1);
    s2 = s1;
    EXPECT_EQ(s1, s2);
}

