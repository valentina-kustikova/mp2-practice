#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack) {
	ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, throws_when_create_stack_with_zero_size) {
	ASSERT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, can_not_delete_if_stack_is_empty)
{
	TStack<int> s;
	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, stack_is_full_check) {
	TStack<int> s(1);
	s.Push(1);
	EXPECT_EQ(true, s.IsFull());
}

TEST(TStack, stack_is_empty_check) {
	TStack<int> s(1);
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, can_pop_elements)
{
	TStack<int> s(2);
	s.Push(100);
	s.Push(42);
	s.Pop();
	EXPECT_EQ(100, s.Top());
}

TEST(TStack, throws_when_top_element_is_empty) {
	TStack<int> s(1);
	ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, throws_when_pop_element_is_empty) {
	TStack<int> s(1);
	ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, stack_full_check_is_correct) {
	TStack<int> s(1);
	s.Push(1);
	EXPECT_EQ(true, s.IsFull());
}

TEST(TStack, throws_when_stak_is_full) {
	TStack<int> s(1);
	s.Push(1);
	ASSERT_ANY_THROW(s.Push(2));
}

TEST(TStack, can_top_and_push_elements)  {
	TStack<int> s(1);
	s.Push(-22);
	EXPECT_EQ(-22, s.Top());
}
