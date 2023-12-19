//����� ��� �������� ������������ ������ ������ ����
#include <gtest.h>

#include "tstack.h"

TEST(TStack, can_create_stack_without_maxsize)
{
	ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, can_create_stack_with_posirive_maxsize)
{
	ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, throws_when_create_stack_with_negative_maxsize)
{
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, empty_stack_is_epmty) {
	TStack<int> st(3);
	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, not_empty_stack_is_not_epmty) {
	TStack<int> st(3);
	st.Push(1);
	EXPECT_EQ(false, st.IsEmpty());
}


TEST(TStack, full_stack_is_full) {
	TStack<int> st(3);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	EXPECT_EQ(true, st.IsFull());
}


TEST(TStack, empty_stack_if_not_full) {
	TStack<int> st(3);
	EXPECT_EQ(false, st.IsFull());
}


TEST(TStack, top_for_empty_stack) {
	TStack<int> st(3);
	ASSERT_ANY_THROW(st.Top());
}

TEST(TStack, correct_work_top_for_not_empty_stack) {
	TStack<int> st(3);
	st.Push(3);
	EXPECT_EQ(3, st.Top());
}

TEST(TStack, top_for_not_empty_stack) {
	TStack<int> st(3);
	st.Push(3);
	ASSERT_NO_THROW(st.Top());
}




