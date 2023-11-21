#include "tstack.h"

#include <gtest.h>
//11
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> bf(3));
}

TEST(TStack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> bf(-3));
}

TEST(TStack, can_set_and_get_val)
{
	TStack<int> bf(10);
	bf.Push(0);
	EXPECT_EQ(0, bf.Top());
}

TEST(TStack, cannot_get_empty_stack)
{
	TStack<int> bf(10);
	ASSERT_ANY_THROW(bf.Pop());
}

TEST(TStack, cannot_set_full_stack)
{
	TStack<int> bf(0);
	ASSERT_ANY_THROW(bf.Push(1));
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
	ASSERT_EQ(5, S.Top());
	ASSERT_EQ(4, S.Top());
	ASSERT_EQ(3, S.Top());
}

TEST(TStack, is_full_false)
{
	TStack <int> S(3);
	ASSERT_FALSE(S.isFull());
}

TEST(TStack, is_full_true)
{
	TStack <int> S(3);
	S.Push(3);
	S.Push(4);
	S.Push(5);
	ASSERT_TRUE(S.isFull());
}

TEST(TStack, is_empty_false)
{
	TStack <int> S(3);
	S.Push(3);
	S.Push(4);
	ASSERT_FALSE(S.isEmpty());
}

TEST(TStack, is_empty_true)
{
	TStack <int> S(3);
	ASSERT_TRUE(S.isEmpty());
}