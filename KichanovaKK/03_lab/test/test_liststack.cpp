#include "list_stack.h"

#include <gtest.h>


TEST(liststack, can_create_liststack)
{
    ASSERT_NO_THROW(liststack<int> s);
}

TEST(liststack, can_push_and_isnt_empty) {
    liststack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    EXPECT_FALSE(s.IsEmpty());
    EXPECT_EQ(s.Top(), 3);
}
TEST(liststack, can_pop_and_is_empty) {
    liststack<int> s;
    s.Push(1);
    s.Push(2);
    s.Pop();
    EXPECT_EQ(s.Top(), 1);
    s.Pop();
    EXPECT_TRUE(s.IsEmpty());
}
TEST(liststack, liststack_isnt_full) {
    liststack<int> s;
    EXPECT_FALSE(s.IsFull());
}
TEST(liststack, can_create_copied_liststack)
{
    liststack<int> s;
    ASSERT_NO_THROW(liststack<int> s1(s));
}
TEST(liststack, can_assign_liststack)
{
    liststack<int> s;
    s.Push(1);
    liststack<int> s1;
    s1 = s;
    EXPECT_TRUE(s == s1);
}


