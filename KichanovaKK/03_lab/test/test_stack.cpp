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


