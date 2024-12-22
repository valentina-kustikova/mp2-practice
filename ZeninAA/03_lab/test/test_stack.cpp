#include <gtest.h>
#include "stack.h"
#include "arraystack.h"

TEST(test_arraystack, can_create_array_stack)
{
    ASSERT_NO_THROW(ArrayStack<int> s(5));
}

TEST(test_arraystack, cant_create_array_stack_with_negative_index)
{
    ASSERT_ANY_THROW(ArrayStack<int> s(-1));
}

TEST(test_arraystack, can_create_copied_stack)
{
    ArrayStack<int> a(5);
    a.Push(8);
    ASSERT_NO_THROW(ArrayStack<int> s(a));
}

TEST(test_arraystack, correct_create_copied_stack)
{
    ArrayStack<int> a(5);
    a.Push(8);
    ArrayStack<int> s(a);
    EXPECT_TRUE(a == s);
}

TEST(test_arraystack, correct_use_the_assignment_operator)
{
    ArrayStack<int> a(5);
    a.Push(8);
    ArrayStack<int> s;
    s = a;
    EXPECT_TRUE(s == a);
}

TEST(test_arraystack, can_top_from_no_empty_stack)
{
    ArrayStack<int> st(5);
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    ASSERT_NO_THROW(st.Top());
}

TEST(test_arraystack, correct_top_from_no_empty_stack)
{
    ArrayStack<int> st(5);
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    int res = st.Top();
    EXPECT_EQ(res, 4);
}

TEST(test_arraystack, can_pop_from_no_empty_stack)
{
    ArrayStack<int> st(5);
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    ASSERT_NO_THROW(st.Pop());
}

TEST(test_arraystack, cant_pop_from_empty_stack)
{
    ArrayStack<int> st(5);
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        st.Pop();
    }
    ASSERT_ANY_THROW(st.Pop());
}