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

TEST(array_stack, can_get_element_in_not_empty_stack)
{
	array_stack<int> m(5);
	m.Push(10);
	ASSERT_NO_THROW(m.Top());
}

TEST(array_stack, cant_get_element_in_empty_stack)
{
	array_stack<int> m(5);
	ASSERT_ANY_THROW(m.Top());
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

TEST(array_stack, can_assight_stacks_with_not_eq_size)
{
	array_stack<int> m1(1);
	array_stack<int> m2(2);
	m1.Push(5);
	ASSERT_NO_THROW(m2 = m1);
}

TEST(array_stack, compare_stacks_with_not_eq_size_return_false)
{
	array_stack<int> m1(1);
	array_stack<int> m2(2);
	m1.Push(5);
	EXPECT_FALSE(m2 == m1);
}

TEST(array_stack, compare_not_eq_stacks_return_false)
{
	array_stack<int> m1(2);
	m1.Push(1);
	m1.Push(1);
	array_stack<int> m2(2);
	m2.Push(1);
	m2.Push(2);
	EXPECT_FALSE(m2 == m1);
}
