#include "array_stack.h"
#include <gtest.h>

TEST(array_stack, can_create_empty_array_stack)
{
    ASSERT_NO_THROW(array_stack<int> a());
}

TEST(array_stack, can_create_array_stack_with_maxSize)
{
    ASSERT_NO_THROW(array_stack<int> a(3));
}

TEST(array_stack, created_array_stack_is_empty)
{
    array_stack<int> a(2);
    EXPECT_TRUE(a.is_empty());
}

TEST(array_stack, cant_create_array_stack_with_negative_size)
{
    ASSERT_ANY_THROW(array_stack<int> a(-3));
}

TEST(array_stack, can_copy_arr_stack)
{
    array_stack<int> a(3);
    ASSERT_NO_THROW(array_stack<int> b(a));
}

TEST(array_stack, copied_array_stack_are_equal)
{
    array_stack<int> a(2);
    a.push(2);
    a.push(3);
    array_stack<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(array_stack, copied_array_stack_have_different_memory)
{
    array_stack<int> a(2);
    a.push(2);
    a.push(3);
    array_stack<int> b(a);
    b.pop();
    EXPECT_FALSE(a == b);
}

TEST(array_stack, can_push_in_arr_stack)
{
    array_stack<int> a(2);
    ASSERT_NO_THROW(a.push(2));
}

TEST(array_stack, cant_push_in_full_arr_stack)
{
    array_stack<int> a(2);
    a.push(2);
    a.push(4);
    ASSERT_ANY_THROW(a.push(8));
}

TEST(array_stack, pushed_elem_is_in_arr_stack)
{
    array_stack<int> a(2);
    a.push(2);
    EXPECT_EQ(2, a.show_top());
}

TEST(array_stack, can_show_first_in_arr_stack)
{
    array_stack<int> a(2);
    a.push(2);
    ASSERT_NO_THROW(a.show_top());
}

TEST(arr_stack, shows_correct_first_in_arr_stack)
{
    array_stack<int> a(2);
    a.push(2);
    a.push(7);
    EXPECT_EQ(7, a.show_top());
}

TEST(array_stack, cant_show_first_in_empty_arr_stack)
{
    array_stack<int> a(1);
    ASSERT_ANY_THROW(a.show_top());
}

TEST(array_stack, can_pop_from_arr_stack)
{
    array_stack<int> a(2);
    a.push(2);
    ASSERT_NO_THROW(a.pop());
}

TEST(array_stack, popped_element_is_no_longer_in_arr_stack)
{
    array_stack<int> a(2);
    a.push(2);
    a.push(9);
    a.pop();
    EXPECT_NE(9, a.show_top());
}

TEST(array_stack, cant_pop_from_empty_arr_stack)
{
    array_stack<int> a(1);
    ASSERT_ANY_THROW(a.pop());
}

TEST(arr_stack, can_show_if_arr_stack_is_full)
{
    array_stack<int> a(2);
    a.push(2);
    a.push(8);
    EXPECT_TRUE(a.is_full());
}

TEST(array_stack, can_show_if_arr_stack_is_empty)
{
    array_stack<int> a(2);
    EXPECT_TRUE(a.is_empty());
}

TEST(array_stack, can_assign_arr_stack_with_same_size)
{
    array_stack<int> a(2), b(2);
    ASSERT_NO_THROW(a = b);
}

TEST(array_stack, can_assign_arr_stack_to_itself)
{
    array_stack<int> a(2);
    ASSERT_NO_THROW(a = a);
}

TEST(array_stack, can_assign_arr_stack_with_differend_size)
{
    array_stack<int> a(2), b(9);
    ASSERT_NO_THROW(a = b);
}

TEST(array_stack, assigned_arr_stack_are_equal)
{
    array_stack<int> a(2), b(9);
    a = b;
    EXPECT_TRUE(a == b);
}

TEST(array_stack, compare_equal_arr_stack_is_true)
{
    array_stack<int> a(2), b(a);
    EXPECT_TRUE(a == b);
}

TEST(array_stack, compare_not_equal_arr_stack_is_false)
{
    array_stack<int> a(2), b(2);
    a.push(2);
    b.push(8);
    EXPECT_FALSE(a == b);
}