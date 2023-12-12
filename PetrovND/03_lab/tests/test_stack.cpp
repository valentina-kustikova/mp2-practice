#include "stack.h"
#include <gtest.h>

TEST(Stack, create_stack)
{
    ASSERT_NO_THROW(Stack<int> s(3));
}

TEST(Stack, cant_create_stack_with_zero_length)
{
    ASSERT_ANY_THROW(Stack<int> s(0));
}

TEST(Stack, cant_create_stack_with_negative_length)
{
    ASSERT_ANY_THROW(Stack<int> s(-2));
}

TEST(Stack, copy_constructor_test)
{
    Stack<int> s(3);
    ASSERT_NO_THROW(Stack<int> s2(s));
}

TEST(Stack, copy_constructor_test_memory)
{
    Stack<int> s1(3);
    s1.push(1);
    s1.push(2);
    s1.push(2);

    Stack<int> s2(s1);
    s2.pop();
    s2.push(4);

    EXPECT_NE(s2.top(), s1.top());
}

TEST(Stack, stack_is_empty_true)
{
    Stack<int> s(3);
    EXPECT_EQ(1,s.isEmpty());
}

TEST(Stack, stack_is_empty_false)
{
    Stack<int> s(3);
    s.push(1);
    EXPECT_EQ(0, s.isEmpty());
}

TEST(Stack, stack_is_full_false)
{
    Stack<int> s(3);
    s.push(1);
    EXPECT_EQ(0, s.isFull());
}

TEST(Stack, stack_is_full_true)
{
    Stack<int> s(3);
    for (int i = 0; i < 3; i++)
        s.push(i);
    EXPECT_EQ(1, s.isFull());
}

TEST(Stack, can_pop_elements)
{
	Stack<int> st(2);
	st.push(100);
	st.push(42);
	st.pop();
	EXPECT_EQ(100, st.top());
}

TEST(Stack, can_get_top)
{
    Stack<int> st(2);
	st.push(100);
	st.push(42);
    EXPECT_EQ(42, st.top());
}

TEST(Stack, throws_when_top_element_is_empty) 
{
	Stack<int> st(1);
	ASSERT_ANY_THROW(st.top());
}

TEST(Stack, throws_when_pop_element_is_empty) 
{
	Stack<int> st(1);
	ASSERT_ANY_THROW(st.pop());
}

TEST(Stack, push_in_full_stack) 
{
	Stack<int> st(1);
	st.push(1);
	ASSERT_NO_THROW(st.push(2));
}

