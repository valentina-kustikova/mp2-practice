#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> S(3));
}

TEST(TStack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> S(-3));
}

TEST(TStack, cannot_create_stack_with_zero_length)
{
	ASSERT_ANY_THROW(Stack<int> S(0));
}

// test isEmpty
TEST(TStack, stack_is_empty)
{
	Stack<int> S(3);
	EXPECT_EQ(true, S.isEmpty());
}

TEST(TStack, stack_is_not_empty)
{
	Stack<int> S(3);
	S.push(1);
	EXPECT_EQ(false, S.isEmpty());
}

//  test isFull
TEST(TStack, stack_is_not_empty_and_not_full)
{
	Stack<int> S(2);
	S.push(1);
	EXPECT_EQ(false, S.isFull());
}

TEST(TStack, stack_is_not_full_its_empty)
{
	Stack<int> S(3);
	EXPECT_EQ(false, S.isFull());
}

TEST(TStack, stack_is_full)
{
	Stack<int> S(2);
	S.push(1);
	S.push(2);
	EXPECT_EQ(true, S.isFull());
}
// Top and Push
TEST(TStack, cannot_top_if_stack_is_empty)
{
	Stack<int> S(3);
	ASSERT_ANY_THROW(S.top());
}

TEST(TStack, can_top_if_stack_is_not_empty)
{
	Stack<int> S(3);
	S.push(1);
	EXPECT_EQ(1, S.top());
}


TEST(TStack, can_push_if_stack_is_empty)
{
	Stack<int> S(2);
	ASSERT_NO_THROW(S.push(1));
}

TEST(TStack, can_push_if_stack_is_not_empty)
{
	Stack<int> S(2);
	S.push(1);
	ASSERT_NO_THROW(S.push(2));
}

TEST(TStack, right_value_push_if_stack_is_not_empty)
{
	Stack<int> S(3);
	S.push(1);
	S.push(2);
	EXPECT_EQ(2, S.top());
}

TEST(TStack, right_value_push_if_stack_is_full)
{
	Stack<int> S(3);
	S.push(1);
	S.push(2);
	S.push(3);
	EXPECT_EQ(3, S.top());
}
// Pop
TEST(TStack, cannot_pop_if_stack_is_empty)
{
	Stack<int> S(3);
	ASSERT_ANY_THROW(S.pop());
}

TEST(TStack, can_pop_if_stack_is_full)
{
	Stack<int> S(3);
	S.push(1);
	S.push(2);
	S.push(3);
	ASSERT_NO_THROW(S.pop());
}

TEST(TStack, can_pop_if_stack_is_not_full) {
	Stack<int> s(3);

	s.push(1);
	s.push(2);

	ASSERT_NO_THROW(s.pop());
}

TEST(TStack, right_value_of_top_after_pop)
{
	Stack<int> S(3);
	S.push(1);
	S.push(2);
	S.push(3);
	S.pop();
	EXPECT_EQ(2, S.top());
}


TEST(TStack, right_value_after_pop_if_stack_is_not_full) {
	Stack<int> s(3);

	s.push(1);
	s.push(2);

	s.pop();
	EXPECT_EQ(1, s.top());

}
TEST(TStack, can_set_and_get_val)
{
	Stack<int> S(10);
	S.push(0);
	EXPECT_EQ(0, S.top());
}


TEST(TStack, can_copy_stack)
{
	Stack<int> S(3);
	S.push(3);
	ASSERT_NO_THROW(Stack<int> S1(S));
}

TEST(TStack, correct_order_of_return_values)
{
	Stack <int> S(3);
	S.push(3);
	S.push(4);
	S.push(5);
	ASSERT_EQ(5, S.pop());
	ASSERT_EQ(4, S.pop());
	ASSERT_EQ(3, S.pop());
}