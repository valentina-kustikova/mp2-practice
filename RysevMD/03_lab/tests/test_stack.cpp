#include "tstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack) {
	ASSERT_NO_THROW(TStack<int> stack(5));
}

TEST(TStack, throw_when_try_to_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> stack(-1));
}

TEST(TStack, can_check_empty) {
	TStack<int> stack;
	EXPECT_EQ(true, stack.IsEmpty());
	stack.Push(1);
	EXPECT_NE(true, stack.IsEmpty());
}

TEST(TStack, can_check_full) {
	TStack<int> stack(1);
	EXPECT_NE(true, stack.IsFull());
	stack.Push(1);
	EXPECT_EQ(true, stack.IsFull());
}


TEST(TStack, can_push_to_not_full_stack) {
	TStack<int> stack;
	ASSERT_NO_THROW(stack.Push(1));
}

TEST(TStack, throw_when_try_to_push_element_on_top_of_full_stack) {
	TStack<int> stack(2);
	stack.Push(1);
	stack.Push(2);
	ASSERT_ANY_THROW(stack.Push(3));
}

TEST(TStack, can_pop_from_not_empty_stack) {
	TStack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	EXPECT_EQ(3, stack.Pop());
}

TEST(TStack, throw_when_try_to_pop_from_empty_stack) {
	TStack <int> stack;
	stack.Push(1);
	EXPECT_EQ(1, stack.Pop());
	ASSERT_ANY_THROW(stack.Pop());
}

TEST(TStack, can_check_element_on_top_of_stack) {
	TStack<int> stack;
	stack.Push(5);
	EXPECT_EQ(5, stack.Top());
}

TEST(TStack, throw_when_try_to_check_element_on_top_of_empty_stack) {
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.Top());
}