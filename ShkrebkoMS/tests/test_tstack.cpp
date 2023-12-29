#include "tstack.h"

#include <gtest.h>

TEST(TStack, can_create_a_stack_of_positive_lengths)
{
	ASSERT_NO_THROW(Stack<int> stack(5));
}

TEST(TStack, cant_create_a_stack_of_negative_lengths)
{
	ASSERT_ANY_THROW(Stack<int> stack(-5));
}

TEST(TStack, cant_create_a_stack_of_zero_lengths)
{
	ASSERT_ANY_THROW(Stack<int> stack(0));
}

TEST(TStack, checking_the_copy_constructor)
{
	Stack<int> stack(5);
	ASSERT_NO_THROW(Stack<int> stack1(stack));
}

TEST(TStack, can_push_element)
{
	Stack<int> stack(5);
	ASSERT_NO_THROW(stack.Push(1));
}

TEST(TStack, can_pop_element)
{
	Stack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	ASSERT_NO_THROW(stack.Pop()); 
}

TEST(TStack, can_show_top_element)
{
	Stack<int> stack(5);
	stack.Push(1);
	stack.Push(2);
	EXPECT_EQ(2, stack.Top());
}

TEST(TStack, cant_show_top_element_in_empty_stack)
{
	Stack<int> stack(5);
	ASSERT_ANY_THROW(stack.Top());
}

TEST(TStack, cant_pop_element_in_empty_stack)
{
	Stack<int> stack(5);
	ASSERT_ANY_THROW(stack.Pop());
}

TEST(TStack, checking_whether_the_stack_is_full1)
{
	Stack<int> stack(5);
	EXPECT_EQ(0, stack.IsFull());
}

TEST(TStack, checking_whether_the_stack_is_full2)
{
	Stack<int> stack(2);
	stack.Push(1);
	stack.Push(1);
	EXPECT_EQ(1, stack.IsFull());
}

TEST(TStack, checking_whether_the_stack_is_empty1)
{
	Stack<int> stack(5);
	EXPECT_EQ(1, stack.IsEmpty());
}

TEST(TStack, checking_whether_the_stack_is_empty2)
{
	Stack<int> stack(2);
	stack.Push(1);
	stack.Push(1);
	EXPECT_EQ(0, stack.IsEmpty());
}
