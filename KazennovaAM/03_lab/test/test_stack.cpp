
#include "stack_array.h"
#include <gtest.h>

TEST(Array_Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Array_Stack<int> v(5));
}

TEST(Array_Stack, can_create_stack_with_zero_size)
{
	ASSERT_NO_THROW(Array_Stack<int> v(0));
}

TEST(Array_Stack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Array_Stack<int> v(-5));
}



TEST(Array_Stack, can_create_copied_stack)
{
	Array_Stack<int> v(10);

	ASSERT_NO_THROW(Array_Stack<int> v1(v));
}


TEST(Array_Stack, IsFull)
{
	Array_Stack<int>q(1);
	int m = 2;
	q.Push(m);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(Array_Stack, IsEmpty)
{
	Array_Stack<int>q(1);
	int m = 2;
	q.Push(m);
	q.Pop();
	EXPECT_EQ(q.IsEmpty(), 1);
}
TEST(Array_Stack, can_assign_stack)
{
	Array_Stack<int> q(3);
	q.Push(1);
	Array_Stack<int> q1;
	q1 = q;
	EXPECT_TRUE(q == q1);
}