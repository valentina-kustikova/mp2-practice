#include "array_stack.h"
#include <gtest.h>

TEST(array_stack, can_create_Astack_with_positive_size)
{
	ASSERT_NO_THROW(array_stack<int> m(5));
}

TEST(array_stack, cant_create_Astack_with_ToLarge_size)
{
	ASSERT_ANY_THROW(array_stack<int> m(MAX_STACK_SIZE+1));
}
TEST(array_stack, cant_create_Astack_with_negative_size)
{
	ASSERT_ANY_THROW(array_stack<int> m(-5));
}
TEST(array_stack, created_Astack_is_empty)
{
	array_stack<int> m(5);
	EXPECT_TRUE(m.is_empty());
}

TEST(array_stack, copied_stack_eq_original)
{
	array_stack<int> st1(5);
	st1.Push(3);
	st1.Push(2);
	st1.Push(1);
	array_stack<int> st2(st1);
	EXPECT_EQ(st1, st2);
}

TEST(array_stack, can_push_element)
{
	array_stack<int> m(5);
	ASSERT_NO_THROW(m.Push(5));
}
TEST(array_stack, cant_push_element_in_full_stack)
{
	array_stack<int> m(2);
	m.Push(5);
	m.Push(5);
	ASSERT_ANY_THROW(m.Push(5));
}
TEST(array_stack, correct_push_and_top_element)
{
	array_stack<int> m(5);
	m.Push(5);
	EXPECT_EQ(5, m.Top());
}
TEST(array_stack, can_pop_element)
{
	array_stack<int> m(5);
	m.Push(5);
	ASSERT_NO_THROW(m.pop());
}
TEST(array_stack, cant_pop_element_in_empty_stack)
{
	array_stack<int> m(5);
	ASSERT_ANY_THROW(m.pop());
}
TEST(array_stack, empty_stack_is_empty)
{
	array_stack<int> m(5);
	array_stack<int> m1(5);
	ASSERT_NO_THROW(m.Push(5));
	EXPECT_NE(m, m1);
}
TEST(array_stack, can_assight_stack)
{
	array_stack<int> m(5);
	array_stack<int> m1(5);
	m.Push(5);
	ASSERT_NO_THROW(m1=m);
}
TEST(array_stack, can_assight_stack_to_itself)
{
	array_stack<int> m(5);
	m.Push(5);
	ASSERT_NO_THROW(m=m);
}
