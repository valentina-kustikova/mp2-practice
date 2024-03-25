#include "tstack.h"

#include <gtest.h>
/*
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> S(3));
}

TEST(TStack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> S(-3));
}

TEST(TStack, cannot_create_stack_with_zero_length)
{
	ASSERT_ANY_THROW(TStack<int> S(0));
}

// test isEmpty
TEST(TStack, stack_is_empty)
{
	TStack<int> S(3);
	EXPECT_EQ(true, S.isEmpty());
}

TEST(TStack, stack_is_not_empty)
{
	TStack<int> S(3);
	S.Push(1);
	EXPECT_EQ(false, S.isEmpty());
}

//  test isFull
TEST(TStack, stack_is_not_empty_and_not_full)
{
	TStack<int> S(2);
	S.Push(1);
	EXPECT_EQ(false, S.isFull());
}

TEST(TStack, stack_is_not_full_its_empty)
{
	TStack<int> S(3);
	EXPECT_EQ(false, S.isFull());
}

TEST(TStack, stack_is_full)
{
	TStack<int> S(2);
	S.Push(1);
	S.Push(2);
	EXPECT_EQ(true, S.isFull());
}
// Top and Push
TEST(TStack, cannot_top_if_stack_is_empty)
{
	TStack<int> S(3);
	ASSERT_ANY_THROW(S.Top());
}

TEST(TStack, can_top_if_stack_is_not_empty)
{
	TStack<int> S(3);
	S.Push(1);
	EXPECT_EQ(1, S.Top());
}


TEST(TStack, can_push_if_stack_is_empty)
{
	TStack<int> S(2);
	ASSERT_NO_THROW(S.Push(1));
}

TEST(TStack, can_push_if_stack_is_not_empty)
{
	TStack<int> S(2);
	S.Push(1);
	ASSERT_NO_THROW(S.Push(2));
}

TEST(TStack, cannot_push_if_stack_is_full)
{
	TStack<int> S(2);
	S.Push(1);
	S.Push(2);
	ASSERT_ANY_THROW(S.Push(3));
}

TEST(TStack, right_value_push_if_stack_is_not_empty)
{
	TStack<int> S(3);
	S.Push(1);
	S.Push(2);
	EXPECT_EQ(2, S.Top());
}

TEST(TStack, right_value_push_if_stack_is_full)
{
	TStack<int> S(3);
	S.Push(1);
	S.Push(2);
	S.Push(3);
	EXPECT_EQ(3, S.Top());
}
// Pop
TEST(TStack, cannot_pop_if_stack_is_empty)
{
	TStack<int> S(3);
	ASSERT_ANY_THROW(S.Pop());
}

TEST(TStack, can_pop_if_stack_is_full)
{
	TStack<int> S(3);
	S.Push(1);
	S.Push(2);
	S.Push(3);
	ASSERT_NO_THROW(S.Pop());
}

TEST(TStack, can_pop_if_stack_is_not_full) {
	TStack<int> s(3);

	s.Push(1);
	s.Push(2);

	ASSERT_NO_THROW(s.Pop());
}

TEST(TStack, right_value_of_top_after_pop)
{
	TStack<int> S(3);
	S.Push(1);
	S.Push(2);
	S.Push(3);
	S.Pop();
	EXPECT_EQ(2, S.Top());
}


TEST(TStack, right_value_after_pop_if_stack_is_not_full) {
	TStack<int> s(3);

	s.Push(1);
	s.Push(2);

	s.Pop();
	EXPECT_EQ(1, s.Top());

}
TEST(TStack, can_set_and_get_val)
{
	TStack<int> S(10);
	S.Push(0);
	EXPECT_EQ(0, S.Top());
}


TEST(TStack, can_copy_stack)
{
	TStack<int> S(3);
	S.Push(3);
	ASSERT_NO_THROW(TStack<int> S1(S));
}

TEST(TStack, correct_order_of_return_values)
{
	TStack <int> S(3);
	S.Push(3);
	S.Push(4);
	S.Push(5);
	ASSERT_EQ(5, S.Pop());
	ASSERT_EQ(4, S.Pop());
	ASSERT_EQ(3, S.Pop());
}*/