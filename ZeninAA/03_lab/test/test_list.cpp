#include <gtest.h>
#include "list.h"

TEST(test_list, can_create_list)
{
    ASSERT_NO_THROW(List<int> s);
}

TEST(test_list, can_create_copied_list)
{
    List<int> a;
    a.PushBack(8);
    ASSERT_NO_THROW(List<int> s(a));
}

TEST(test_list, check_comparison_operator)
{
    List<int> a;
    a.PushBack(8);
    List<int> s(a);
    EXPECT_EQ(true, s == a);
}

TEST(test_list, correct_create_copied_list)
{
    List<int> a;
    a.PushBack(8);
    List<int> s(a);
    EXPECT_TRUE(a == s);
}
TEST(test_list, can_use_the_assignment_operator)
{
    List<int> a;
    a.PushBack(8);
    List<int> s;
    ASSERT_NO_THROW(s = a);
}
TEST(test_list, correct_use_the_assignment_operator)
{
    List<int> a;
    a.PushBack(8);
    List<int> s;
    s = a;
    EXPECT_TRUE(s == a);
}
TEST(test_list, correct_push_front)
{
    List<int> a;
    a.PushFront(8);
    a.PushFront(10);
    EXPECT_EQ(10, a[0]);
}

TEST(test_list, correct_push_back)
{
    List<int> a;
    a.PushBack(8);
    a.PushBack(10);
    EXPECT_EQ(10, a[a.GetSize() - 1]);
}

TEST(test_list, correct_pop_back)
{
    List<int> a;
    a.PushBack(8);
    a.PushBack(10);
    a.PopBack();
    EXPECT_EQ(8, a[0]);
}

TEST(test_list, correct_pop_front)
{
    List<int> a;
    a.PushBack(8);
    a.PushBack(10);
    a.PopFront();
    EXPECT_EQ(10, a[0]);
}

TEST(test_list, cant_popback_from_empty_list)
{
    List<int> st;
    ASSERT_ANY_THROW(st.PopBack());
}
TEST(test_list, cant_popfront_from_empty_list)
{
    List<int> st;
    ASSERT_ANY_THROW(st.PopFront());
}
TEST(test_list, correct_get_size)
{
    List<int> a;
    a.PushBack(8);
    a.PushBack(10);
    EXPECT_EQ(2, a.GetSize());
}
TEST(test_list, is_empty_false_when_list_no_empty)
{
    List<int> a;
    a.PushBack(8);
    a.PushBack(10);
    EXPECT_EQ(false, a.IsEmpty());
}
TEST(test_list, is_empty_true_when_list_empty)
{
    List<int> a;
    EXPECT_EQ(true, a.IsEmpty());
}