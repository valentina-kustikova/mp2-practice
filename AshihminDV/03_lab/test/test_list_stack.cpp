#include "list_stack.h"
#include <gtest.h>

TEST(list_stack, can_create_Lstack)
{
	ASSERT_NO_THROW(list_stack<int> ls());
}

TEST(list_stack, can_push_elem)
{
	list_stack<int> m;
	m.Push(1);
	m.Push(2);
	EXPECT_EQ(2, m.Top());
}

TEST(list_stack, can_pop_elem_in_not_empty_lstack)
{
	list_stack<int> m;
	m.Push(1);
	m.Push(2);
	ASSERT_NO_THROW(m.pop());
}

TEST(list_stack, cant_pop_elem_in_empty_lstack)
{
	list_stack<int> m;
	ASSERT_ANY_THROW(m.pop());
}

TEST(list_stack, can_get_elem_in_not_empty_lstack)
{
	list_stack<int> m;
	m.Push(1);
	m.Push(2);
	ASSERT_NO_THROW(m.Top());
}

TEST(list_stack, cant_get_elem_in_empty_lstack)
{
	list_stack<int> m;
	ASSERT_ANY_THROW(m.Top());
}

TEST(list_stack, correct_get_elem_in_not_empty_lstack)
{
	list_stack<int> m;
	m.Push(1);
	m.Push(2);
	EXPECT_EQ(2, m.Top());
}

TEST(list_stack, can_assign_lstack_to_itself)
{
	list_stack<int> m;
	m.Push(1);
	m.Push(2);
	ASSERT_NO_THROW(m = m);
}

TEST(list_stack, compare_eq_stack_return_true)
{
	list_stack<int> m1;
	m1.Push(1);
	m1.Push(2);
	list_stack<int> m2;
	m2.Push(1);
	m2.Push(2);
	EXPECT_TRUE(m1 == m2);
}

TEST(list_stack, compare_not_eq_stack_return_false)
{
	list_stack<int> m1;
	m1.Push(1);
	m1.Push(2);
	list_stack<int> m2;
	m2.Push(1);
	m2.Push(3);
	EXPECT_FALSE(m1 == m2);
}

TEST(list_stack, compare_stacks_with_not_eq_size_return_false)
{
	list_stack<int> m1;
	m1.Push(1);
	m1.Push(2);
	list_stack<int> m2;
	m2.Push(1);
	m2.Push(3);
	m2.Push(4);
	EXPECT_FALSE(m1 == m2);
}