#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> stack);
}

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> stack(5));
}

TEST(TStack, can_create_stack_with_maximum_length)
{
	ASSERT_NO_THROW(TStack<int> stack(100000000));
}

TEST(TStack, throws_when_create_stack_with_zero_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(0));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(-5));
}

TEST(TStack, throws_when_create_stack_with_too_large_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(100000001));
}

TEST(TStack, can_get_stack_size)
{
	TStack<int> stack(5);

	EXPECT_EQ(0, stack.size());
}

TEST(TStack, new_stack_is_empty)
{
	TStack<int> stack(5);

	EXPECT_TRUE(stack.IsEmpty());
}

TEST(TStack, can_push_element)
{
	TStack<int> stack;

	stack.Push(10);

	EXPECT_EQ(1, stack.size());
	EXPECT_EQ(10, stack.Top());
}

TEST(TStack, can_push_many_elements)
{
	TStack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);

	EXPECT_EQ(3, stack.size());
	EXPECT_EQ(30, stack.Top());
}

TEST(TStack, can_get_top_element)
{
	TStack<int> stack;

	stack.Push(10);
	stack.Push(20);

	EXPECT_EQ(20, stack.Top());
	EXPECT_EQ(2, stack.size());
}

TEST(TStack, can_pop_element)
{
	TStack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Pop();

	EXPECT_EQ(1, stack.size());
	EXPECT_EQ(10, stack.Top());
}

TEST(TStack, can_pop_all_elements)
{
	TStack<int> stack;

	stack.Push(10);
	stack.Push(20);

	stack.Pop();
	stack.Pop();

	EXPECT_TRUE(stack.IsEmpty());
	EXPECT_EQ(0, stack.size());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Clear();

	EXPECT_TRUE(stack.IsEmpty());
	EXPECT_EQ(0, stack.size());
}

TEST(TStack, can_check_full_stack)
{
	TStack<int> stack(2);

	stack.Push(10);
	stack.Push(20);

	EXPECT_TRUE(stack.IsFull());
}

TEST(TStack, throws_when_push_to_full_stack)
{
	TStack<int> stack(2);

	stack.Push(10);
	stack.Push(20);

	ASSERT_ANY_THROW(stack.Push(30));
}

TEST(TStack, throws_when_get_top_from_empty_stack)
{
	TStack<int> stack;

	ASSERT_ANY_THROW(stack.Top());
}

TEST(TStack, throws_when_pop_from_empty_stack)
{
	TStack<int> stack;

	ASSERT_ANY_THROW(stack.Pop());
}

TEST(TStack, can_copy_stack)
{
	TStack<int> stack1;

	stack1.Push(10);
	stack1.Push(20);

	TStack<int> stack2(stack1);

	EXPECT_EQ(2, stack2.size());
	EXPECT_EQ(20, stack2.Top());
}

TEST(TStack, can_copy_empty_stack)
{
	TStack<int> stack1;
	TStack<int> stack2(stack1);

	EXPECT_TRUE(stack2.IsEmpty());
	EXPECT_EQ(0, stack2.size());
}

TEST(TStack, copy_constructor_creates_independent_stack)
{
	TStack<int> stack1;

	stack1.Push(10);
	stack1.Push(20);

	TStack<int> stack2(stack1);

	stack1.Pop();

	EXPECT_EQ(1, stack1.size());
	EXPECT_EQ(2, stack2.size());
	EXPECT_EQ(20, stack2.Top());
}

TEST(TStack, can_assign_stack)
{
	TStack<int> stack1;

	stack1.Push(10);
	stack1.Push(20);

	TStack<int> stack2;
	stack2 = stack1;

	EXPECT_EQ(2, stack2.size());
	EXPECT_EQ(20, stack2.Top());
}

TEST(TStack, assign_operator_changes_stack_size)
{
	TStack<int> stack1(2);
	TStack<int> stack2(5);

	stack1.Push(10);
	stack1.Push(20);

	stack2 = stack1;

	EXPECT_EQ(2, stack2.size());
	EXPECT_EQ(20, stack2.Top());
}

TEST(TStack, can_assign_stacks_of_non_equal_capacity)
{
	TStack<int> stack1(2);
	TStack<int> stack2(5);

	stack1.Push(10);
	stack1.Push(20);

	stack2.Push(100);

	stack2 = stack1;

	EXPECT_EQ(2, stack2.size());
	EXPECT_EQ(20, stack2.Top());
}

TEST(TStack, assign_operator_creates_independent_stack)
{
	TStack<int> stack1;

	stack1.Push(10);
	stack1.Push(20);

	TStack<int> stack2;
	stack2 = stack1;

	stack1.Pop();

	EXPECT_EQ(1, stack1.size());
	EXPECT_EQ(2, stack2.size());
	EXPECT_EQ(20, stack2.Top());
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> stack;

	stack.Push(10);
	stack.Push(20);

	stack = stack;

	EXPECT_EQ(2, stack.size());


	EXPECT_EQ(20, stack.Top());
}





