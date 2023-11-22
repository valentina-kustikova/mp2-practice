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
TEST(TStack, IsEmptyTest_Empty) {
	TStack<int> s(3);
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, IsEmptyTest_NotEmpty) {
	TStack<int> s(3);
	s.Push(1);
	EXPECT_EQ(false, s.IsEmpty());
}

// IsFullTest
TEST(TStack, IsFullTest_Empty) {
	TStack<int> s(2);
	EXPECT_EQ(false, s.IsFull());
}

TEST(TStack, IsFullTest_NotEmpty) {
	TStack<int> s(2);
	s.Push(1);
	EXPECT_EQ(false, s.IsFull());
}

TEST(TStack, IsFullTest_Full) {
	TStack<int> s(2);
	s.Push(1);
	s.Push(2);
	EXPECT_EQ(true, s.IsFull());
}

// PushAndTopTests
TEST(TStack, PushAndTopTest_TopIfEmpty) {
	TStack<int> s(3);
	ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, throw_PushTest_StackIsEmpty) {
	TStack<int> s(2);

	ASSERT_NO_THROW(s.Push(1));
}

TEST(TStack, throw_PushTest_StackIsNotEmpty) {
	TStack<int> s(2);

	s.Push(1);
	ASSERT_NO_THROW(s.Push(2));
}

TEST(TStack, throw_PushTest_StackIsFull) {
	TStack<int> s(2);

	s.Push(1);
	s.Push(2);
	ASSERT_NO_THROW(s.Push(3));
}

TEST(TStack, PushAndTopTest_PushIfEmpty) {
	TStack<int> s(3);
	
	s.Push(1);
	EXPECT_EQ(1, s.Top());
}

TEST(TStack, PushAndTopTest_PushIfNotEmpty) {
	TStack<int> s(3);

	s.Push(1);
	s.Push(2);
	EXPECT_EQ(2, s.Top());

}

TEST(TStack, PushAndTopTest_PushIfFull) {
	TStack<int> s(3);

	s.Push(1);
	s.Push(2);
	s.Push(3);
	EXPECT_EQ(3, s.Top());
}


// PopTest
// –¿«ƒ≈À»“‹ “≈—“€
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