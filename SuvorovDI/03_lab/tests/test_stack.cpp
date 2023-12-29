#include "stack.h"
#include <gtest.h>

TEST(Stack, create_normal_double_stack) {
	ASSERT_NO_THROW(Stack<double> a);
}

TEST(Stack, create_normal_integer_stack) {
	ASSERT_NO_THROW(Stack<int> a);
}

TEST(Stack, create_normal_char_stack) {
	ASSERT_NO_THROW(Stack<char> a);
}

TEST(Stack, create_stack_with_another_stack) {
	Stack<double> st;
	st.Push(3.5);
	st.Push(32);
	st.Push(-3.1);
	ASSERT_NO_THROW(Stack<double>::Stack(st));
}

TEST(Stack, check_is_new_stack_empty) {
	Stack<double> a;
	ASSERT_TRUE(a.isEmpty());
}

TEST(Stack, check_is_stack_empty_after_deleting_all_elements) {
	Stack<double> a;
	a.Push(4.2);
	a.Push(4.2);

	a.Pop(); 
	a.Pop();

	ASSERT_TRUE(a.isEmpty());
}

TEST(Stack, check_is_stack_empty_after_deleting_not_all_elements) {
	Stack<double> a;
	a.Push(4.2);
	a.Push(4.2);

	a.Pop();

	ASSERT_FALSE(a.isEmpty());
}

TEST(Stack, compare_lengths_of_two_equal_stacks) {
	Stack<double> st;
	st.Push(3.5);
	st.Push(32);
	st.Push(-3.1);

	int length_st = 0;
	int length_a = 0;

	Stack<double> a(st);
	while (!st.isEmpty()) {
		length_st++;
		st.Pop();
	}

	while (!a.isEmpty()) {
		length_a++;
		a.Pop();
	}

	ASSERT_TRUE(length_st == length_a);
}

TEST(Stack, compare_two_equal_stacks) {
	Stack<double> st;
	st.Push(3.5);
	st.Push(32);
	st.Push(-3.1);

	Stack<double> a(st);

	ASSERT_TRUE(st == a);
}

TEST(Stack, check_push_operation) {
	Stack<double> a;
	a.Push(3);
	EXPECT_EQ(a.Top(), 3);
}

TEST(Stack, check_pop_operation_for_empty_stack) {
	Stack<double> a;
	ASSERT_ANY_THROW(a.Pop());
}

TEST(Stack, check_top_operation_for_empty_stack) {
	Stack<double> a;
	ASSERT_ANY_THROW(a.Top());
}