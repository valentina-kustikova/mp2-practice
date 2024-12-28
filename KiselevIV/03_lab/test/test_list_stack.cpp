#include "list_stack.h"
#include <gtest.h>

TEST(list_stack, can_create_empty_list_stack)
{
    ASSERT_NO_THROW(list_stack<int> a());
}

TEST(list_stack, created_list_stack_is_empty)
{
    list_stack<int> a;
    EXPECT_TRUE(a.is_empty());
}

TEST(list_stack, can_copy_list_stack)
{
    list_stack<int> a;
    ASSERT_NO_THROW(list_stack<int> b(a));
}

TEST(list_stack, copied_list_stack_are_equal)
{
    list_stack<int> a;
    a.push(2);
    a.push(3);
    list_stack<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(list_stack, copied_list_stack_have_different_memory)
{
    list_stack<int> a;
    a.push(2);
    a.push(3);
    list_stack<int> b(a);
    b.pop();
    EXPECT_FALSE(a == b);
}

TEST(list_stack, can_push_in_list_stack)
{
    list_stack<int> a;
    ASSERT_NO_THROW(a.push(2));
}


TEST(list_stack, pushed_elem_is_in_list_stack)
{
    list_stack<int> a;
    a.push(2);
    EXPECT_EQ(2, a.show_top());
}

TEST(list_stack, can_show_first_in_list_stack)
{
    list_stack<int> a;
    a.push(2);
    ASSERT_NO_THROW(a.show_top());
}

TEST(list_stack, shows_correct_first_in_list_stack)
{
    list_stack<int> a;
    a.push(2);
    a.push(7);
    EXPECT_EQ(7, a.show_top());
}

TEST(list_stack, cant_show_first_in_empty_list_stack)
{
    list_stack<int> a;
    ASSERT_ANY_THROW(a.show_top());
}

TEST(list_stack, can_pop_from_list_stack)
{
    list_stack<int> a;
    a.push(2);
    ASSERT_NO_THROW(a.pop());
}

TEST(list_stack, popped_element_is_no_longer_in_list_stack)
{
    list_stack<int> a;
    a.push(2);
    a.push(9);
    a.pop();
    EXPECT_NE(9, a.show_top());
}

TEST(list_stack, cant_pop_from_empty_list_stack)
{
    list_stack<int> a;
    ASSERT_ANY_THROW(a.pop());
}

TEST(list_stack, can_show_if_list_stack_is_empty)
{
    list_stack<int> a;
    EXPECT_TRUE(a.is_empty());
}

TEST(list_stack, can_assign_list_stacks)
{
    list_stack<int> a, b;
    ASSERT_NO_THROW(a = b);
}

TEST(list_stack, can_assign_list_stacks_to_itself)
{
    list_stack<int> a;
    ASSERT_NO_THROW(a = a);
}

TEST(list_stack, assigned_list_stacks_are_equal)
{
    list_stack<int> a, b;
    b.push(9);
    a = b;
    EXPECT_TRUE(a == b);
}

TEST(list_stack, compare_equal_list_stacks_is_true)
{
    list_stack<int> a, b;
    a.push(9);
    b.push(9);
    EXPECT_TRUE(a == b);
}

TEST(List_stack, compare_not_equal_list_stacks_is_false)
{
    list_stack<int> a, b;
    a.push(2);
    b.push(8);
    EXPECT_FALSE(a == b);
}