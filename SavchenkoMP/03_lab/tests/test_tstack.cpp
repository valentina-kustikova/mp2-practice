#include <gtest.h>

#include "tstack.h"

// DefaultConstructorTest
TEST(TStack, DefaultConstructorTest) {
	ASSERT_NO_THROW(TStack<int> s);
}

// ParameterizedConstructorTests
TEST(TStack, ParameterizedConstructorTest) {
	ASSERT_NO_THROW(TStack<int> s(3));
}

TEST(TStack, throw_ParameterizedConstructorTest_ZeroSize) {
	ASSERT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, throw_ParameterizedConstructorTest_NegativeSize) {
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

// IsEmptyTest
TEST(TStack, IsEmptyTest) {
	TStack<int> s(3);
	EXPECT_EQ(true, s.IsEmpty());

	s.Push(1);
	EXPECT_EQ(false, s.IsEmpty());
}

// IsFullTest
TEST(TStack, IsFullTest) {
	TStack<int> s(2);
	EXPECT_EQ(false, s.IsFull());

	s.Push(1);
	EXPECT_EQ(false, s.IsFull());

	s.Push(2);
	EXPECT_EQ(true, s.IsFull());
}

// PushAndTopTests
TEST(TStack, PushAndTopTest) {
	TStack<int> s(3);
	
	s.Push(1);
	EXPECT_EQ(1, s.Top());

	s.Push(2);
	EXPECT_EQ(2, s.Top());

	s.Push(3);
	EXPECT_EQ(3, s.Top());
}

TEST(TStack, throw_PushTest_StackIsFull) {
	TStack<int> s(2);
	
	ASSERT_NO_THROW(s.Push(1));
	
	ASSERT_NO_THROW(s.Push(2));
	
	ASSERT_ANY_THROW(s.Push(3));
}

TEST(TStack, throw_TopElementTest_StackIsEmpty) {
	TStack<int> s(3);

	ASSERT_ANY_THROW(s.Top());
}

// PopTest
TEST(TStack, PopTest) {
	TStack<int> s(3);

	s.Push(1);
	s.Push(2);
	s.Push(3);

	ASSERT_NO_THROW(s.Pop());
	EXPECT_EQ(2, s.Top());

	ASSERT_NO_THROW(s.Pop());
	EXPECT_EQ(1, s.Top());

}

TEST(TStack, throw_PopTest_StackIsEmpty) {
	TStack<int> s(3);
	ASSERT_ANY_THROW(s.Pop());
}