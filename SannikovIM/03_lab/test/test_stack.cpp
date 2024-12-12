#include <gtest.h>
#include "postform.h"

TEST(TStack, can_create_stack_with_positive_length) {
	ASSERT_NO_THROW(TStack<int> s(2));
}
TEST(TStack, cant_create_stack_with_negative_length) {
	ASSERT_ANY_THROW(TStack<int> s(-2));
}
TEST(TStack, can_create_copied_stack) {
	TStack<int> s(2);
	ASSERT_NO_THROW(TStack<int> s1(s));
}
TEST(TStack, can_push_and_get_top_element) {
	TStack<int> s(2);
	s.push(1);
	EXPECT_EQ(s.Top(), 1);
}
TEST(TStack, new_stack_is_empty) {
	TStack<int> s(2);
	ASSERT_TRUE(s.isEmpty());
}
TEST(TStack, stack_is_full) {
	TStack<int> s(2);
	for (int i = 0; i < 2; i++) {
		s.push(1);
	}
	ASSERT_TRUE(s.isFull());
}
TEST(TStack, can_pop_and_element) {
	TStack<int> s(2);
	s.push(1);
	s.pop();
	ASSERT_TRUE(s.isEmpty());
}
TEST(TStack, copied_stack_is_equal_to_source_one) {
	TStack<int> s(2);
	ASSERT_NO_THROW(TStack<int> s1(s));
}
TEST(TStack, cant_pop_from_empty_stack) {
	TStack<int> s(2);
	ASSERT_ANY_THROW(s.pop());
}
TEST(TStack, cant_push_from_full_stack) {
	TStack<int> s(2);
	for(int i = 0; i < 2; i++) {
		s.push(1);
	}
	ASSERT_ANY_THROW(s.push(1));
}