#include "list_stack.h"
#include "array_stack.h"
#include <gtest.h>

TEST(list_stack, can_create_empty_list_stack)
{
    ASSERT_NO_THROW(list_stack<int> ls());
}

TEST(list_stack, can_copy_another_list_stack)
{
    list_stack<int> ls;
    ASSERT_NO_THROW(list_stack<int> ls1(ls));
}

TEST(list_stack, can_create_copied_list_stack)
{
    list_stack<int> ls;
    ls.push(10);
    ls.push(20);
    ls.push(30);
    list_stack<int> ls1(ls);
    EXPECT_EQ(ls, ls1);
}

TEST(list_stack, copied_list_stack_has_its_own_memory)
{
    list_stack<int> ls;
    ls.push(10);
    ls.push(20);
    ls.push(30);
    list_stack<int> ls1(ls);
    ls1.pop();
    EXPECT_NE(ls, ls1);
}

TEST(list_stack, correctly_defines_emptiness_of_list_stack)
{
    list_stack<int> ls;
    list_stack<int> ls1;
    ls.push(10);
    EXPECT_NE(ls.isEmpty(), ls1.isEmpty());
}

TEST(list_stack, can_push_in_list_stack)
{
    list_stack<int> ls;
    ASSERT_NO_THROW(ls.push(10));
}

TEST(list_stack, pushed_elem_presented_in_list_stack)
{
    list_stack<int> ls;
    ls.push(10);
    EXPECT_EQ(10, ls.showTop());
}

TEST(list_stack, can_pop_from_list_stack)
{
    list_stack<int> ls;
    ls.push(10);
    ASSERT_NO_THROW(ls.pop());
}

TEST(list_stack, cant_pop_from_empty_list_stack)
{
    list_stack<int> ls;
    ASSERT_ANY_THROW(ls.pop());
}

TEST(list_stack, poped_elem_not_presented_in_list_stack)
{
    list_stack<int> ls;
    ls.push(10);
    ls.push(20);
    ls.pop();
    EXPECT_EQ(10, ls.showTop());
}

TEST(list_stack, can_show_tops_list_stack)
{
    list_stack<int> ls;
    ls.push(10);
    EXPECT_EQ(10, ls.showTop());
}

TEST(list_stack, cant_show_top_empty_list_stack)
{
    list_stack<int> ls;
    ASSERT_ANY_THROW(ls.showTop());
}

TEST(list_stack, can_assign_list_stack)
{
    list_stack<int> ls;
    list_stack<int> ls1;
    ASSERT_NO_THROW(ls=ls1);
}

TEST(list_stack, can_assign_list_stack_to_itself)
{
    list_stack<int> ls;
    ASSERT_NO_THROW(ls = ls);
}

TEST(list_stack, assigned_list_stacks_are_equal)
{
    list_stack<int> ls;
    list_stack<int> ls1;
    ls.push(10);
    ls1 = ls;
    EXPECT_EQ(ls, ls1);
}

TEST(list_stack, correctly_defines_equality_of_list_stack)
{
    list_stack<int> ls;
    list_stack<int> ls1;
    EXPECT_EQ(ls, ls1);
    ls1.push(10);
    EXPECT_NE(ls, ls1);
}

// Array_Stack

TEST(array_stack, can_create_empty_array_stack)
{
    ASSERT_NO_THROW(array_stack<int> as());
}

TEST(array_stack, can_create_array_stack_with_entered_size)
{
    ASSERT_NO_THROW(array_stack<int> as(10));
}

TEST(array_stack, cant_create_array_stack_with_negative_size)
{
    ASSERT_ANY_THROW(array_stack<int> as(-10));
}

TEST(array_stack, created_array_stack_is_empty)
{
    array_stack<int> as(10);
    EXPECT_TRUE(as.isEmpty());
}

TEST(array_stack, can_copy_array_stack)
{
    array_stack<int> as(10);
    ASSERT_NO_THROW(array_stack<int> as1(as));
}

TEST(array_stack, copied_and_origin_array_stack_are_equal)
{
    array_stack<int> as(10);
    as.push(10);
    as.push(20);
    as.push(30);
    array_stack<int> as1(as);
    EXPECT_EQ(as, as1);
}

TEST(array_stack, copied_array_stack_has_its_own_memory)
{
    array_stack<int> as(10);
    as.push(10);
    as.push(20);
    as.push(30);
    array_stack<int> as1(as);
    as.pop();
    EXPECT_NE(as, as1);
}

TEST(array_stack, correctly_defines_emptiness_of_array_stack)
{
    array_stack<int> as(10);
    array_stack<int> as1(10);
    as.push(10);
    EXPECT_NE(as.isEmpty(), as1.isEmpty());
}

TEST(array_stack, correctly_defines_fullness_of_array_stack)
{
    array_stack<int> as(1);
    array_stack<int> as1(1);
    as.push(10);
    EXPECT_NE(as.isFull(), as1.isFull());
}

TEST(array_stack, can_push_in_array_stack)
{
    array_stack<int> as(2);
    ASSERT_NO_THROW(as.push(10));
}

TEST(array_stack, cant_push_in_array_stack_when_its_full)
{
    array_stack<int> as(2);
    as.push(10);
    as.push(10);
    ASSERT_ANY_THROW(as.push(10));
}

TEST(array_stack, pushed_elem_presented_in_array_stack)
{
    array_stack<int> as(2);
    as.push(10);
    EXPECT_EQ(10, as.showTop());
}


TEST(array_stack, can_pop_from_array_stack)
{
    array_stack<int> as(2);
    as.push(10);
    ASSERT_NO_THROW(as.pop());
}

TEST(array_stack, cant_pop_from_empty_array_stack)
{
    array_stack<int> as(2);
    ASSERT_ANY_THROW(as.pop());
}

TEST(array_stack, poped_elem_not_presented_in_array_stack)
{
    array_stack<int> as(2);
    as.push(10);
    as.push(20);
    as.pop();
    EXPECT_EQ(10, as.showTop());
}

TEST(array_stack, can_show_tops_array_stack)
{
    array_stack<int> as(2);
    as.push(10);
    EXPECT_EQ(10, as.showTop());
}

TEST(array_stack, cant_show_top_empty_array_stack)
{
    array_stack<int> as(2);
    ASSERT_ANY_THROW(as.showTop());
}

TEST(array_stack, can_assign_array_stack)
{
    array_stack<int> as(2);
    array_stack<int> as1(2);
    ASSERT_NO_THROW(as = as1);
}

TEST(array_stack, can_assign_array_stack_to_itself)
{
    array_stack<int> as(2);
    ASSERT_NO_THROW(as = as);
}

TEST(array_stack, assigned_array_stack_are_equal)
{
    array_stack<int> as(2);
    array_stack<int> as1(2);
    as.push(10);
    as1 = as;
    EXPECT_EQ(as, as1);
}

TEST(array_stack, correctly_defines_equality_of_array_stack)
{
    array_stack<int> as(2);
    array_stack<int> as1(2);
    EXPECT_EQ(as, as1);
    as1.push(10);
    EXPECT_NE(as, as1);
}