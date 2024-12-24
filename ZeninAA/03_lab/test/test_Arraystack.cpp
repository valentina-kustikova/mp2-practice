#include "Arraystack.h"
#include <gtest.h>

TEST(Arraystack, can_create_empty_Arraystack)
{
    ASSERT_NO_THROW(Arraystack<int> a());
}

TEST(Arraystack, can_create_Arraystack_with_maximum_size)
{
    ASSERT_NO_THROW(Arraystack<int> a(3));
}

TEST(Arraystack, created_Astack_is_empty)
{
    Arraystack<int> a(2);
    EXPECT_TRUE(a.is_empty());
}

TEST(Astack, cant_create_Arraystack_with_negative_size)
{
    ASSERT_ANY_THROW(Arraystack<int> a(-5));
}

TEST(Arraystack, can_copy_Arraystack)
{
    Arraystack<int> a(6);
    ASSERT_NO_THROW(Arraystack<int> b(a));
}

TEST(Arraystack, copied_Arraystacks_are_equal)
{
    Arraystack<int> a(2);
    a.push(2);
    a.push(3);
    Arraystack<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(Arraystack, copied_Arraystacks_have_different_memory)
{
    Arraystack<int> a(2);
    a.push(2);
    a.push(3);
    Arraystack<int> b(a);
    b.pop();
    EXPECT_FALSE(a == b);
}

TEST(Arraystack, can_push_in_Arraystack)
{
    Arraystack<int> a(2);
    ASSERT_NO_THROW(a.push(2));
}

TEST(Arraystack, cant_push_in_full_Arraystack)
{
    Arraystack<int> a(2);
    a.push(2);
    a.push(4);
    ASSERT_ANY_THROW(a.push(8));
}

TEST(Arraystack, can_show_top_in_Arraystack)
{
    Arraystack<int> a(2);
    a.push(2);
    ASSERT_NO_THROW(a.show_top());
}

TEST(Arraystack, shows_correct_top_in_Arraystack)
{
    Arraystack<int> a(2);
    a.push(2);
    a.push(7);
    EXPECT_EQ(7, a.show_top());
}

TEST(Arraystack, cant_show_top_in_empty_Arraystack)
{
    Arraystack<int> a(1);
    ASSERT_ANY_THROW(a.show_top());
}

TEST(Arraystack, can_pop_from_Arraystack)
{
    Arraystack<int> a(2);
    a.push(2);
    ASSERT_NO_THROW(a.pop());
}

TEST(Arraystack, cant_pop_from_empty_Arraystack)
{
    Arraystack<int> a(1);
    ASSERT_ANY_THROW(a.pop());
}

TEST(Arraystack, can_show_if_Arraystack_is_full)
{
    Arraystack<int> a(2);
    a.push(2);
    a.push(8);
    EXPECT_TRUE(a.is_full());
}

TEST(Arraystack, can_show_if_Arraystack_is_empty)
{
    Arraystack<int> a(2);
    EXPECT_TRUE(a.is_empty());
}

TEST(Arraystack, can_assign_Arraystacks_with_equal_size)
{
    Arraystack<int> a(2), b(2);
    ASSERT_NO_THROW(a = b);
}

TEST(Arraystack, can_assign_Arraystacks_with_different_size)
{
    Arraystack<int> a(2), b(9);
    ASSERT_NO_THROW(a = b);
}

TEST(Arraystack, assigned_Arraystacks_are_equal)
{
    Arraystack<int> a(2), b(9);
    a = b;
    EXPECT_TRUE(a == b);
}

TEST(Arraystack, compare_equal_Arraystacks_is_true)
{
    Arraystack<int> a(2), b(a);
    EXPECT_TRUE(a == b);
}

TEST(Arraystack, compare_not_equal_Arraystacks_is_false)
{
    Arraystack<int> a(2), b(2);
    a.push(2);
    b.push(8);
    EXPECT_FALSE(a == b);
}