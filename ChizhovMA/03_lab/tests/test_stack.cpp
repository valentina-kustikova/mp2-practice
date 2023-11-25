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
    EXPECT_EQ(5, s.Length());
}

//length
TEST(TStack, stack_length_zero)
{
    TStack<int> s(3);
    EXPECT_EQ(0, s.Length());
}

TEST(TStack, stack_length)
{
    TStack<int> s(3);
    for (int i = 1; i < 3; i++)
        s.Push(i);
    EXPECT_EQ(2, s.Length());
}

//get_element
TEST(TStack, stack_get_element_with_zero_length)
{
    TStack<int> s(3);
    ASSERT_ANY_THROW(s.GetElement(0));
}

TEST(TStack, stack_get_element_more_than_top)
{
    TStack<int> s(3);
    for (int i = 1; i < 3; i++)
        s.Push(i);
    ASSERT_ANY_THROW(s.GetElement(2));
}

TEST(TStack, stack_get_element_with_negative_index)
{
    TStack<int> s(3);
    for (int i = 1; i < 3; i++)
        s.Push(i);
    ASSERT_ANY_THROW(s.GetElement(-1));
}

TEST(TStack, stack_get_element)
{
    TStack<int> s(3);
    for (int i = 1; i < 3; i++)
        s.Push(i);
    EXPECT_EQ(2, s.GetElement(1));
}

//opersator=
TEST(TStack, stack_assignment)
{
    TStack<int> s1(3);
    TStack<int> s2(3);
    for (int i = 1; i < 3; i++)
    {
        s1.Push(i);
        s2.Push(i + 1);
    }
    s2 = s1;
    EXPECT_EQ(s1.GetElement(1), s2.GetElement(1));
}

TEST(TStack, stack_assignment_with_different_length)
{
    TStack<int> s1(3);
    TStack<int> s2(4);
    for (int i = 1; i < 3; i++)
        s1.Push(i);
    for(int j = 0; j<3;j++)
        s2.Push(j);
    s2 = s1;
    EXPECT_EQ(s1.Length(), s2.Length());
}

TEST(TStack, stack_assignment_to_empty_stack)
{
    TStack<int> s1(3);
    TStack<int> s2(4);
    for (int i = 1; i < 3; i++)
        s1.Push(i);
    s2 = s1;
    EXPECT_EQ(s1.Top(), s2.Top());
}