#include "stack.h"

#include <gtest.h>

TEST(TStack, create_stack)
{
    ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, create_stack_with_zero_length)
{
    ASSERT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, create_stack_with_negative_length)
{
    ASSERT_ANY_THROW(TStack<int> s(-2));
}

TEST(TStack, copy_constructor_test)
{
    TStack<int> s(3);
    ASSERT_NO_THROW(TStack<int> s2(s));
}

//is_empty
TEST(TStack, stack_is_empty_true)
{
    TStack<int> s(3);
    EXPECT_EQ(1,s.IsEmpty());
}

TEST(TStack, stack_is_empty_false)
{
    TStack<int> s(3);
    s.Push(1);
    EXPECT_EQ(0, s.IsEmpty());
}

//is_full
TEST(TStack, stack_is_full_false)
{
    TStack<int> s(3);
    s.Push(1);
    EXPECT_EQ(0, s.IsFull());
}

TEST(TStack, stack_is_full_true)
{
    TStack<int> s(3);
    for (int i = 0; i < 3; i++)
        s.Push(i);
    EXPECT_EQ(1, s.IsFull());
}

//top
TEST(TStack, exception_get_top)
{
    TStack<int> s(3);
    ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, stack_get_top)
{
    TStack<int> s(3);
    s.Push(10);
    EXPECT_EQ(10, s.Top());
}
