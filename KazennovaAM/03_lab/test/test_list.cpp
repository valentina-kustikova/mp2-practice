#include "List.h"
#include <gtest.h>


TEST(test_list, can_create_list)
{
    ASSERT_NO_THROW(List<int> l);
}

TEST(test_list, push_front)
{
    List<int> l;
    ASSERT_NO_THROW(l.PushFront(1));
}

TEST(test_list, pop_front)
{
    List<int> l;
    l.PushFront(1);
    l.PushFront(2);
    l.PopFront();
    EXPECT_EQ(1, l.GetSZ());
}

TEST(test_list, pop_back)
{
    List<int> l;
    l.PushFront(1);
    l.PushFront(2);
    l.PopBack();
    EXPECT_EQ(1, l.GetSZ());
}

TEST(test_list, push_back)
{
    List<int> l;
    ASSERT_NO_THROW(l.PushBack(1));
}

TEST(test_list, isnt_empty)
{
    List<int> l;    
    l.PushBack(1);
    EXPECT_EQ(false, l.IsEmpty());
}
TEST(test_list, is_empty)
{
    List<int> l;
    EXPECT_EQ(true, l.IsEmpty());
}

TEST(test_list, comparison_operator)
{
    List<int> l, l1;
    l.PushBack(1);
    l1.PushBack(1);
    EXPECT_TRUE(l1 == l);
}


TEST(test_list, can_copy_list) {
    List<int> l1;
    l1.PushBack(1);
    List<int> l2;
    l2 = l1;
    EXPECT_TRUE(l1 == l2);
}