#include "Lstack.h"
#include <gtest.h>

TEST(Lstack, can_create_empty_Lstack)
{
    ASSERT_NO_THROW(Lstack<int> a());
}

TEST(Lstack, created_Lstack_is_empty)
{
    Lstack<int> a;
    EXPECT_TRUE(a.is_empty());
}

TEST(Lstack, can_copy_Lstack)
{
    Lstack<int> a;
    ASSERT_NO_THROW(Lstack<int> b(a));
}

TEST(Lstack, copied_Lstack_are_equal)
{
    Lstack<int> a;
    a.push(2);
    a.push(3);
    Lstack<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(Lstack, copied_Lstack_have_different_memory)
{
    Lstack<int> a;
    a.push(2);
    a.push(3);
    Lstack<int> b(a);
    b.pop();
    EXPECT_FALSE(a == b);
}

TEST(Lstack, can_push_in_Lstack)
{
    Lstack<int> a;
    ASSERT_NO_THROW(a.push(2));
}


TEST(Lstack, pushed_elem_is_in_Lstack)
{
    Lstack<int> a;
    a.push(2);
    EXPECT_EQ(2, a.show_top());
}

TEST(Lstack, can_show_first_in_Lstack)
{
    Lstack<int> a;
    a.push(2);
    ASSERT_NO_THROW(a.show_top());
}

TEST(Lstack, shows_correct_first_in_Lstack)
{
    Lstack<int> a;
    a.push(2);
    a.push(7);
    EXPECT_EQ(7, a.show_top());
}

TEST(Lstack, cant_show_first_in_empty_Lstack)
{
    Lstack<int> a;
    ASSERT_ANY_THROW(a.show_top());
}

TEST(Lstack, can_pop_from_Lstack)
{
    Lstack<int> a;
    a.push(2);
    ASSERT_NO_THROW(a.pop());
}

TEST(Lstack, popped_element_is_no_longer_in_Lstack)
{
    Lstack<int> a;
    a.push(2);
    a.push(9);
    a.pop();
    EXPECT_NE(9, a.show_top());
}

TEST(Lstack, cant_pop_from_empty_Lstack)
{
    Lstack<int> a;
    ASSERT_ANY_THROW(a.pop());
}

TEST(Lstack, can_show_if_Lstack_is_empty)
{
    Lstack<int> a;
    EXPECT_TRUE(a.is_empty());
}

TEST(Lstack, can_assign_Lstacks)
{
    Lstack<int> a, b;
    ASSERT_NO_THROW(a = b);
}

TEST(Astack, can_assign_Lstacks_to_itself)
{
    Lstack<int> a;
    ASSERT_NO_THROW(a = a);
}

TEST(Lstack, assigned_Lstacks_are_equal)
{
    Lstack<int> a, b;
    b.push(9);
    a = b;
    EXPECT_TRUE(a == b);
}

TEST(Lstack, compare_equal_Lstacks_is_true)
{
    Lstack<int> a, b;
    a.push(9);
    b.push(9);
    EXPECT_TRUE(a == b);
}

TEST(Lstack, compare_not_equal_Lstacks_is_false)
{
    Lstack<int> a, b;
    a.push(2);
    b.push(8);
    EXPECT_FALSE(a == b);
}