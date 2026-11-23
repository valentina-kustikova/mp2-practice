#include"stack.h"
#include<gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> s(4));
}

TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> s(-4));
}

TEST(Stack, can_push_element)
{
	Stack<int> s(4);
	ASSERT_NO_THROW(s.push(1));
}

TEST(Stack, stack_is_not_empty_after_push)
{
	Stack<int> s(4);
	s.push(1);
	EXPECT_FALSE(s.is_empty());
}

TEST(Stack, top_returns_last_pushed_element)
{
	Stack<int> s(4);
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.top());
}

TEST(Stack, can_pop_element)
{
	Stack<int> s(4);
	s.push(1);
	ASSERT_NO_THROW(s.pop());
}

TEST(Stack, elements_are_popped_in_reverse_order)
{
	Stack<int> s(4);
	s.push(1);
	s.push(2);
	s.push(3);

	EXPECT_EQ(3, s.top());
	s.pop();
	EXPECT_EQ(2, s.top());
	s.pop();
	EXPECT_EQ(1, s.top());
}

TEST(Stack, stack_is_empty_after_popping_all_elements)
{
	Stack<int> s(4);
	s.push(1);
	s.push(2);
	s.pop();
	s.pop();
	EXPECT_TRUE(s.is_empty());
}

TEST(Stack, cant_pop_from_empty_stack)
{
	Stack<int> s(4);
	ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, cant_pop_after_all_elements_are_popped)
{
	Stack<int> s(4);
	s.push(1);
	s.pop();
	ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, cant_get_top_of_empty_stack)
{
	Stack<int> s(4);
	ASSERT_ANY_THROW(s.top());
}

TEST(Stack, stack_is_full_when_filled)
{
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	EXPECT_TRUE(s.is_full());
}

TEST(Stack, stack_is_not_full_when_not_filled)
{
	Stack<int> s(3);
	s.push(1);
	s.push(2);
	EXPECT_FALSE(s.is_full());
}

TEST(Stack, cant_push_to_full_stack)
{
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	ASSERT_ANY_THROW(s.push(3));
}

TEST(Stack, stack_is_not_full_after_pop_from_full_stack)
{
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	s.pop();
	EXPECT_FALSE(s.is_full());
}

TEST(Stack, can_push_after_pop_from_full_stack)
{
	Stack<int> s(2);
	s.push(1);
	s.push(2);
	s.pop();
	ASSERT_NO_THROW(s.push(3));
}

TEST(Stack, can_create_copied_stack)
{
	Stack<int> s(4);
	ASSERT_NO_THROW(Stack<int> c(s));
}

TEST(Stack, copied_stack_is_equal_to_original)
{
	Stack<int> s(4);
	Stack<int> c(s);
	ASSERT_EQ(s, c);
}

TEST(Stack, copied_stack_has_its_own_memory)
{
	Stack<int> s(4);
	s.push(1);
	s.push(2);
	Stack<int> c(s);
	s.pop();
	s.push(5);          
	ASSERT_NE(s, c);
}

TEST(Stack, can_assign_stack_of_equal_size)
{
	Stack<int> a(4), b(4);
	a = b;
	ASSERT_EQ(a, b);
}

TEST(Stack, can_assign_stack_of_different_size)
{
	Stack<int> a(2), b(5);
	a = b;
	ASSERT_EQ(a, b);
}

TEST(Stack, assigned_stack_has_its_own_memory)
{
	Stack<int> a(4), b(4);
	a = b;
	b.push(1);
	ASSERT_NE(a, b);
}

TEST(Stack, can_assign_stack_to_itself)
{
	Stack<int> s(4);
	ASSERT_NO_THROW(s = s);
}