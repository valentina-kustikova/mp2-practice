#include "stack.h"

#include <gtest.h>



TEST(ArrayStack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(ArrayStack<int> m(5));
}

TEST(ArrayStack, cant_create_stack_with_negative_length)
{
    ASSERT_ANY_THROW(ArrayStack<int> m(-5));
}

TEST(ArrayStack, can_create_copied_stack)
{
    ArrayStack<int> m(2);
    ASSERT_NO_THROW(ArrayStack<int> m1(m));
}


TEST(ArrayStack, copied_stack_is_equal_to_source_one)
{
    ArrayStack<int> m(1);
    m.push(5);
    ArrayStack<int> m1(m);
    EXPECT_EQ(m.Top(), m1.Top());
}

TEST(ArrayStack, copied_stack_has_its_own_memory)
{
    ArrayStack<int> m(1);
    m.push(5);
    ArrayStack<int> m1(m);
    m1.pop();
    m1.push(6);
    EXPECT_NE(m.Top(), m1.Top());
}

TEST(ArrayStack, can_push_element_in_full_stack)
{
    ArrayStack<int> m(1);
    m.push(5);
    ASSERT_NO_THROW(m.push(6));
}

TEST(ArrayStack, can_pop_element_in_not_empty_stack)
{
    ArrayStack<int> m(1);
    m.push(5);
    ASSERT_NO_THROW(m.pop());
}

TEST(ArrayStack, cant_pop_element_in_empty_stack)
{
    ArrayStack<int> m;
    ASSERT_ANY_THROW(m.pop());
}

TEST(ArrayStack, can_get_element_in_not_empty_stack)
{
    ArrayStack<int> m(1);
    m.push(1);
    ASSERT_NO_THROW(m.Top());
}

TEST(ArrayStack, cant_get_element_in_empty_stack)
{
    ArrayStack<int> m;
    ASSERT_ANY_THROW(m.Top());
}

TEST(ArrayStack, can_assign_stack_to_itself)
{
    ArrayStack<int> m;
    m.push(5);
    m.push(6);
    ASSERT_NO_THROW(m = m);
}

TEST(ArrayStack, can_assign_stacks_with_diff_size)
{
    ArrayStack<int> m1(5);
    ArrayStack<int> m2(50);
    ASSERT_NO_THROW(m1 = m2);
}

TEST(ArrayStack, compare_equal_stacks_return_true)
{
    ArrayStack<int> m1(2);
    m1.push(1);
    m1.push(2);
    ArrayStack<int> m2(2);
    m2.push(1);
    m2.push(2);
    EXPECT_TRUE(m1==m2);
}

TEST(ArrayStack, compare_stacks_with_diff_size_return_false)
{
    ArrayStack<int> m1(1);
    ArrayStack<int> m2(2);
    EXPECT_FALSE(m1 == m2);
}

TEST(ArrayStack, compare_not_equal_stacks_return_false)
{
    ArrayStack<int> m1(2);
    m1.push(100);
    m1.push(2);
    ArrayStack<int> m2(2);
    m2.push(1);
    m2.push(2);
    EXPECT_FALSE(m1 == m2);
}