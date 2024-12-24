#include "Liststack.h"
#include <gtest.h>

TEST(Liststack, can_create_empty_Liststack)
{
    ASSERT_NO_THROW(Liststack<int> a());
}

TEST(Lstack, created_Liststack_is_empty)
{
    Liststack<int> a;
    EXPECT_TRUE(a.is_empty());
}

TEST(Lstack, can_copy_Liststack)
{
    Liststack<int> a;
    ASSERT_NO_THROW(Liststack<int> b(a));
}

TEST(Lstack, copied_Liststacks_are_equal)
{
    Liststack<int> a;
    a.push(3);
    a.push(4);
    Liststack<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(Lstack, copied_Liststacks_have_different_memory)
{
    Liststack<int> a;
    a.push(3);
    a.push(4);
    Liststack<int> b(a);
    b.pop();
    EXPECT_FALSE(a == b);
}

TEST(Lstack, can_push_in_Liststack)
{
    Liststack<int> a;
    ASSERT_NO_THROW(a.push(2));
}

TEST(Lstack, pushed_elem_is_in_Liststack)
{
    Liststack<int> a;
    a.push(2);
    EXPECT_EQ(2, a.show_top());
}

TEST(Liststack, can_show_first_in_Liststack)
{
    Liststack<int> a;
    a.push(2);
    ASSERT_NO_THROW(a.show_top());
}

TEST(Liststack, shows_correct_first_in_Liststack)
{
    Liststack<int> a;
    a.push(2);
    a.push(7);
    EXPECT_EQ(7, a.show_top());
}

TEST(Liststack, cant_show_first_in_empty_Liststack)
{
    Liststack<int> a;
    ASSERT_ANY_THROW(a.show_top());
}

TEST(Liststack, can_pop_from_Liststack)
{
    Liststack<int> a;
    a.push(2);
    ASSERT_NO_THROW(a.pop());
}

TEST(Liststack, popped_element_is_no_longer_in_Liststack)
{
    Liststack<int> a;
    a.push(2);
    a.push(9);
    a.pop();
    EXPECT_NE(9, a.show_top());
}

TEST(Liststack, cant_pop_from_empty_Liststack)
{
    Liststack<int> a;
    ASSERT_ANY_THROW(a.pop());
}

TEST(Liststack, can_show_if_Liststack_is_empty)
{
    Liststack<int> a;
    EXPECT_TRUE(a.is_empty());
}

TEST(Arraystack, can_assign_Liststacks_to_itself)
{
    Liststack<int> a;
    ASSERT_NO_THROW(a = a);
}

TEST(Liststack, assigned_Liststacks_are_equal)
{
    Liststack<int> a, b;
    b.push(9);
    a = b;
    EXPECT_TRUE(a == b);
}

TEST(Liststack, compare_equal_Liststack_is_true)
{
    Liststack<int> a, b;
    a.push(9);
    b.push(9);
    EXPECT_TRUE(a == b);
}

TEST(Liststack, compare_not_equal_Liststacks_is_false)
{
    Liststack<int> a, b;
    a.push(3);
    b.push(10);
    EXPECT_FALSE(a == b);
}