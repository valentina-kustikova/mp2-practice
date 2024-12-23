#include "Astack.h"
#include <gtest.h>

TEST(Astack, can_create_empty_Astack)
{
    ASSERT_NO_THROW(Astack<int> a());
}

TEST(Astack, can_create_Astack_with_maxSize)
{
    ASSERT_NO_THROW(Astack<int> a(3));
}

TEST(Astack, created_Astack_is_empty)
{
    Astack<int> a(2);
    EXPECT_TRUE(a.is_empty());
}

TEST(Astack, cant_create_Astack_with_negative_size)
{
    ASSERT_ANY_THROW(Astack<int> a(-3));
}

TEST(Astack, can_copy_Astack)
{
    Astack<int> a(3);
    ASSERT_NO_THROW(Astack<int> b(a));
}

TEST(Astack, copied_Astack_are_equal)
{
    Astack<int> a(2);
    a.push(2);
    a.push(3);
    Astack<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(Astack, copied_Astack_have_different_memory)
{
    Astack<int> a(2);
    a.push(2);
    a.push(3);
    Astack<int> b(a);
    b.pop();
    EXPECT_FALSE(a == b);
}

TEST(Astack, can_push_in_Astack)
{
    Astack<int> a(2);
    ASSERT_NO_THROW(a.push(2));
}

TEST(Astack, cant_push_in_full_Astack)
{
    Astack<int> a(2);
    a.push(2);
    a.push(4);
    ASSERT_ANY_THROW(a.push(8));
}

TEST(Astack, pushed_elem_is_in_Astack)
{
    Astack<int> a(2);
    a.push(2);
    EXPECT_EQ(2, a.show_top());
}

TEST(Astack, can_show_first_in_Astack)
{
    Astack<int> a(2);
    a.push(2);
    ASSERT_NO_THROW(a.show_top());
}

TEST(Astack, shows_correct_first_in_Astack)
{
    Astack<int> a(2);
    a.push(2);
    a.push(7);
    EXPECT_EQ(7, a.show_top());
}

TEST(Astack, cant_show_first_in_empty_Astack)
{
    Astack<int> a(1);
    ASSERT_ANY_THROW(a.show_top());
}

TEST(Astack, can_pop_from_Astack)
{
    Astack<int> a(2);
    a.push(2);
    ASSERT_NO_THROW(a.pop());
}

TEST(Astack, popped_element_is_no_longer_in_Astack)
{
    Astack<int> a(2);
    a.push(2);
    a.push(9);
    a.pop();
    EXPECT_NE(9, a.show_top());
}

TEST(Astack, cant_pop_from_empty_Astack)
{
    Astack<int> a(1);
    ASSERT_ANY_THROW(a.pop());
}

TEST(Astack, can_show_if_Astack_is_full)
{
    Astack<int> a(2);
    a.push(2);
    a.push(8);
    EXPECT_TRUE(a.is_full());
}

TEST(Astack, can_show_if_Astack_is_empty)
{
    Astack<int> a(2);
    EXPECT_TRUE(a.is_empty());
}

TEST(Astack, can_assign_Astacks_with_same_size)
{
    Astack<int> a(2), b(2);
    ASSERT_NO_THROW(a = b);
}

TEST(Astack, can_assign_Astacks_to_itself)
{
    Astack<int> a(2);
    ASSERT_NO_THROW(a = a);
}

TEST(Astack, can_assign_Astacks_with_differend_size)
{
    Astack<int> a(2), b(9);
    ASSERT_NO_THROW(a = b);
}

TEST(Astack, assigned_Astacks_are_equal)
{
    Astack<int> a(2), b(9);
    a = b;
    EXPECT_TRUE(a == b);
}

TEST(Astack, compare_equal_Astacks_is_true)
{
    Astack<int> a(2), b(a);
    EXPECT_TRUE(a == b);
}

TEST(Astack, compare_not_equal_Astacks_is_false)
{
    Astack<int> a(2), b(2);
    a.push(2);
    b.push(8);
    EXPECT_FALSE(a == b);
}



