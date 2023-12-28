#include "tstack.h"
#include <gtest.h>

TEST(TStack, can_create_stack) {
	ASSERT_NO_THROW(TStack<double> S(3));
}
TEST(TStack, can_create_stack_with_no_argument) {
	ASSERT_NO_THROW(TStack<double> S());
}
TEST(TStack, cant_create_stack_with_0_length) {
	ASSERT_ANY_THROW(TStack<double> S(0));
}
TEST(TStack, cant_create_stack_with_negative_length) {
	ASSERT_ANY_THROW(TStack<double> S(-1));
}
TEST(TStack, full_is_full) {
	TStack<double> S(1);
	S.add(1.1);
	EXPECT_TRUE(S.is_full());
}
TEST(TStack, not_full_is_not_full) {
	TStack<double> S(2);
	S.add(1.1);
	EXPECT_FALSE(S.is_full());
}
TEST(TStack, empty_is_empty) {
	TStack<double> S(1);
	EXPECT_TRUE(S.is_empty());
}
TEST(TStack, not_empty_is_not_empty) {
	TStack<double> S(1);
	S.add(1.1);
	EXPECT_FALSE(S.is_empty());
}
TEST(TStack, cant_add_if_full) {
	TStack<double> S(1);
	S.add(1.1);
	ASSERT_ANY_THROW(S.add(1.1));
}
TEST(TStack, cant_delete_if_empty) {
	TStack<double> S(1);
	ASSERT_ANY_THROW(S.del());
}
TEST(TStack, cant_get_top_if_empty) {
	TStack<double> S(1);
	ASSERT_ANY_THROW(S.top());
}
TEST(TStack, right_size) {
	TStack<double> S(1);
	EXPECT_EQ(S.get_size(), -1);
}