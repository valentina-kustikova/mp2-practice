#include "array_stack.h"

#include <gtest.h>

// Тесты для стэка на массивах 

TEST(TStackArray, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStackArray<int> s(5));
}

TEST(TStackArray, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStackArray<int> s(MAX_STACK_SIZE + 1));
}

TEST(TStackArray, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStackArray<int> s(-5));
}

TEST(TStackArray, can_create_copied_stack)
{
	TStackArray<int> s(3);
	ASSERT_NO_THROW(TStackArray<int> s1(s));
}

TEST(TStackArray, copied_stack_is_equal_to_source_one)
{
	TStackArray<int> s(3), s1(s);
	EXPECT_EQ(s, s1);
}

TEST(TStackArray, copied_stack_has_its_own_memory)
{
	TStackArray<int> s(3), s1(s);
	s.Push(15);
	s1.Push(1);
	EXPECT_NE(s.Top(), s1.Top());
}

TEST(TStackArray, stack_is_empty) {
	TStackArray<int> s(3);
	EXPECT_EQ(s.IsEmpty(),1);
}

TEST(TStackArray, stack_can_push_element) {
	TStackArray<int> s(1);
	ASSERT_NO_THROW(s.Push(15));
}

TEST(TStackArray, stack_is_full) {
	TStackArray<int> s(1);
	s.Push(15);
	EXPECT_EQ(s.IsFull(), 1);
}

TEST(TStackArray, stack_can_top_element) {
	TStackArray<int> s(1);
	s.Push(15);
	EXPECT_EQ(s.Top(), 15);
}

TEST(TStackArray, stack_can_pop_element) {
	TStackArray<int> s(1);
	s.Push(15);
	s.Pop();
	EXPECT_EQ(s.IsEmpty(), 1);
}

TEST(TStackArray, can_assign_stacks_of_equal_size)
{
	TStackArray<int> s(1), s1(1);
	s.Push(15);
	s1 = s;
	EXPECT_EQ(15, s1.Top());
}

TEST(TStackArray, can_assign_stacks_of_different_size)
{
	TStackArray<int> s(1), s1(2);
	s.Push(15);
	s.Push(15);
	s1 = s;
	EXPECT_EQ(s,s1);;
}

TEST(TStackArray, compare_equal_stacks_return_true)
{
	TStackArray<int> s(3), s1(3);
	s.Push(15);
	s1.Push(15);
	EXPECT_TRUE(s1 == s);
}

TEST(TStackArray, compare_stack_with_itself_return_true)
{
	TStackArray<int> s(3);
	s.Push(15);
	EXPECT_TRUE(s == s);
}

TEST(TStackArray, stacks_with_different_size_are_not_equal)
{
	TStackArray<int> s(3), s1(4);
	EXPECT_FALSE(s1 == s);
}
