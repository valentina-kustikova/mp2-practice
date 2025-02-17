#include <gtest.h>
#include "stackArray.h"

TEST(stackArray, can_create_empty_stackArray) {
    ASSERT_NO_THROW(stackArray<int> a());
}

TEST(stackArray, can_create_stackArray_with_maxSize) {
    ASSERT_NO_THROW(stackArray<int> a(5));
}

TEST(stackArray, created_stackArray_is_empty) {
    stackArray<int> a(2);
    EXPECT_TRUE(a.IsEmpty());
}

TEST(stackArray, cant_create_stackArray_with_negative_size) {
    ASSERT_ANY_THROW(stackArray<int> a(-2));
}

TEST(stackArray, can_copy_stackArray) {
    stackArray<int> a(5);
    ASSERT_NO_THROW(stackArray<int> b(a));
}

TEST(stackArray, copied_stackArray_are_equal) {
    stackArray<int> a(2);
    a.Push(1);
    a.Push(2);
    stackArray<int> b(a);
    EXPECT_EQ(a, b);
}

TEST(stackArray, copied_stackArray_have_different_memory) {
    stackArray<int> a(2);
    a.Push(1);
    a.Push(2);
    stackArray<int> b(a);
    b.Pop();
    EXPECT_NE(a, b);
}

TEST(stackArray, can_push_in_stackArray) {
    stackArray<int> a(2);
    ASSERT_NO_THROW(a.Push(2));
}

TEST(stackArray, pushed_elem_is_in_stackArray) {
    stackArray<int> a(2);
    a.Push(2);
    EXPECT_EQ(2, a.Top());
}

TEST(stackArray, can_show_top_in_stackArray) {
    stackArray<int> a(2);
    a.Push(2);
    ASSERT_NO_THROW(a.Top());
}

TEST(stackArray, shows_correct_top_in_stackArray) {
    stackArray<int> a(2);
    a.Push(2);
    a.Push(7);
    EXPECT_EQ(7, a.Top());
}

TEST(stackArray, cant_show_top_in_empty_stackArray) {
    stackArray<int> a(1);
    ASSERT_ANY_THROW(a.Top());
}

TEST(stackArray, can_pop_from_stackArray) {
    stackArray<int> a(2);
    a.Push(2);
    ASSERT_NO_THROW(a.Pop());
}

TEST(stackArray, popped_element_is_no_longer_in_stackArray) {
    stackArray<int> a(2);
    a.Push(2);
    a.Push(9);
    a.Pop();
    EXPECT_NE(9, a.Top());
}

TEST(stackArray, cant_pop_from_empty_stackArray) {
    stackArray<int> a(1);
    ASSERT_ANY_THROW(a.Pop());
}

TEST(stackArray, can_show_if_stackArray_is_full) {
    stackArray<int> a(2);
    a.Push(2);
    a.Push(8);
    EXPECT_TRUE(a.IsFull());
}

TEST(stackArray, can_show_if_stackArray_is_empty) {
    stackArray<int> a(2);
    EXPECT_TRUE(a.IsEmpty());
}

TEST(stackArray, can_assign_stackArray_with_same_size) {
    stackArray<int> a(2), b(2);
    ASSERT_NO_THROW(a = b);
}

TEST(stackArray, can_assign_stackArray_to_itself) {
    stackArray<int> a(2);
    ASSERT_NO_THROW(a = a);
}

TEST(stackArray, can_assign_stackArray_with_different_size) {
    stackArray<int> a(2), b(9);
    ASSERT_NO_THROW(a = b);
}

TEST(stackArray, assigned_stackArray_are_equal) {
    stackArray<int> a(2), b(9);
    a = b;
    EXPECT_EQ(a, b);
}

TEST(stackArray, compare_equal_stackArray_is_true) {
    stackArray<int> a(2), b(a);
    EXPECT_EQ(a, b);
}

TEST(stackArray, compare_not_equal_stackArray_is_false) {
    stackArray<int> a(2), b(2);
    a.Push(2);
    b.Push(8);
    EXPECT_NE(a, b);
}
