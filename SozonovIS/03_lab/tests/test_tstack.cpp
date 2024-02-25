#include "tstack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_max_size) {
	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, throws_when_create_stack_with_negative_max_size) {
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack) {
	TStack<int> st(5);

	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, can_free_up_memory) {
	TStack<int>* st = new TStack<int>(5);

	ASSERT_NO_THROW(delete st);
}

TEST(TStack, can_push_element) {
	TStack<int> st(5);

	ASSERT_NO_THROW(st.Push(10));
}

TEST(TStack, can_pop_element) {
	TStack<int> st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);

	ASSERT_NO_THROW(st.Pop());
}

TEST(Stack, throws_when_pop_element_from_empty_stack) {
	TStack<int> st(3);

	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, can_top_element) {
	TStack<int> st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);

	EXPECT_EQ(3, st.Top());
}

TEST(TStack, throws_when_top_element_from_empty_stack) {
	TStack<int> st(3);

	ASSERT_ANY_THROW(st.Top());
}

TEST(TStack, can_check_if_stack_is_empty) {
	TStack<int> st(3);

	ASSERT_NO_THROW(st.IsEmpty());
}