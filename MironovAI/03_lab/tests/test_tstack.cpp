#include <gtest.h>
#include "tstack.h"


TEST(TStack, create_stack) {
	ASSERT_NO_THROW(TStack<int> s);
	ASSERT_NO_THROW(TStack<int> s1(3));
	
}

TEST(TStack, create_empty_stack) {
	ASSERT_ANY_THROW(TStack<int> s2(0));
}

TEST(TStack, create_stack_with_negative_number) {
	ASSERT_ANY_THROW(TStack<int> s3(-3));
}

TEST(TStack, push_top_test) {
	TStack<int> stack(5);
	stack.Push(0);
	EXPECT_EQ(0, stack.Top());
	stack.Push(110);
	EXPECT_EQ(110, stack.Top());
}

TEST(TStack, pop_top_test) {
	TStack<int> stack(5);
	stack.Push(0); stack.Push(5);
	EXPECT_EQ(5, stack.Top());
	stack.Pop();
	EXPECT_EQ(0, stack.Top());
}


TEST(TStack, empty_test) {
	TStack<int> stack(5);
	EXPECT_EQ(true, stack.IsEmpty());
	stack.Push(0);
	EXPECT_EQ(false, stack.IsEmpty());
}

TEST(TStack, full_test) {
	TStack<int> stack(5);
	EXPECT_EQ(false, stack.IsFull());
	for (int i = 0; i < 4; i++) stack.Push(1);
	EXPECT_EQ(false, stack.IsFull());
	stack.Push(0);
	EXPECT_EQ(true, stack.IsFull());
}

TEST(TStack, push_to_full_stack) {
	TStack<int> stack(5);
	for (int i = 0; i < 5; i++) ASSERT_NO_THROW(stack.Push(i));
	ASSERT_ANY_THROW(stack.Push(5));
}

TEST(TStack, pop_from_empty_stack)
{
	TStack<int> stack(5);
	ASSERT_ANY_THROW(stack.Pop());
}

TEST(TStack, top_from_empty_stack) {
	
	TStack<int> stack(5);
	ASSERT_ANY_THROW(stack.Top());
}
