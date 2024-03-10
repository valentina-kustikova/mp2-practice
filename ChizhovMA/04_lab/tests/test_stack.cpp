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

TEST(TStack, copy_constructor_test_memory)
{
    TStack<int> s1(3);
    s1.Push(1);
    s1.Push(2);
    s1.Push(2);

    TStack<int> s2(s1);
    s2.Pop();
    s2.Push(4);

    EXPECT_NE(s2.Top(), s1.Top());
}

//is_empty
TEST(TStack, stack_is_empty_true)
{
    TStack<int> s(3);
    ASSERT_TRUE(s.IsEmpty());
}

TEST(TStack, stack_is_empty_false)
{
    TStack<int> s(3);
    s.Push(1);
    ASSERT_FALSE(s.IsEmpty());
}

//is_full
TEST(TStack, stack_is_full_false)
{
    TStack<int> s(3);
    s.Push(1);
    ASSERT_FALSE(s.IsFull());
}

TEST(TStack, stack_is_full_true)
{
    TStack<int> s(3);
    for (int i = 0; i < 3; i++)
        s.Push(i);
    ASSERT_TRUE(s.IsFull());
}

//top
TEST(TStack, exception_get_top)
{
    TStack<int> s(3);
    ASSERT_ANY_THROW(s.Top());
}

//push
TEST(TStack, stack_push_and_get_top)
{
    TStack<int> s(3);
    s.Push(10);
    EXPECT_EQ(10, s.Top());
}

//pop
TEST(TStack, stack_pop)
{
    TStack<int> s(3);
    for(int i = 1; i<3;i++)
        s.Push(i);
    s.Pop();
    EXPECT_EQ(1, s.Top());
}

//push
TEST(TStack, stack_push_with_resize)
{
    TStack<int> s(3);
    for (int i = 1; i < 6; i++)
        s.Push(i);
    EXPECT_EQ(5, s.Top());
}

//Reverse
TEST(TStack, reverse_stack)
{
    TStack<int> s1(3);
    TStack<int> s2(3);
    for (int i = 1; i < 4; i++)
        s1.Push(i);
    for (int i = 3; i > 0; i--)
        s2.Push(i);
    s1.ReverseStack();
    EXPECT_EQ(s1.Top(), s2.Top());
}

//opersator=
TEST(TStack, stack_assignment)
{
    TStack<int> s1(3);
    TStack<int> s2(3);
    for (int i = 1; i < 4; i++)
    {
        s1.Push(i);
        s2.Push(i + 1);
    }
    s2 = s1;
    EXPECT_EQ(s1.Top(), s2.Top());
}

TEST(TStack, stack_assignment_with_different_length)
{
    TStack<int> s1(3);
    TStack<int> s2(4);
    for (int i = 1; i < 4; i++)
        s1.Push(i);
    for(int j = 0; j<4;j++)
        s2.Push(j);
    s2 = s1;
    EXPECT_EQ(s1.Top(), s2.Top());
}

TEST(TStack, stack_assignment_to_empty_stack)
{
    TStack<int> s1(3);
    TStack<int> s2(4);
    for (int i = 1; i < 4; i++)
        s1.Push(i);
    s2 = s1;
    EXPECT_EQ(s1.Top(), s2.Top());
}