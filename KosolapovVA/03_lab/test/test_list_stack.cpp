#include <gtest.h>
#include "stack.h"
#include "list_stack.h"

//TEST(test_arrstack,)

TEST(test_liststack, can_create_arr_stack)
{
    ASSERT_NO_THROW(ListStack<int> s);
}

TEST(test_liststack, can_create_copied_list_stack)
{
    ListStack<int> a;
    a.Push(8);
    ASSERT_NO_THROW(ListStack<int> s(a));
}
TEST(test_liststack, correct_create_copied_stack)
{
    ListStack<int> a;
    a.Push(8);
    ListStack<int> s(a);
    EXPECT_TRUE(a == s);
}

TEST(test_liststack, correct_use_the_assignment_operator)
{
    ListStack<int> a;
    a.Push(8);
    ListStack<int> s;
    s = a;
    EXPECT_TRUE(s == a);
}

TEST(test_liststack, can_top_from_no_empty_stack)
{
    ListStack<int> st;
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    ASSERT_NO_THROW(st.Top());
}
TEST(test_liststack, correct_top_from_no_empty_stack)
{
    ListStack<int> st;
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    int res = st.Top();
    EXPECT_EQ(res, 4);
}

TEST(test_liststack, can_pop_from_no_empty_stack)
{
    ListStack<int> st;
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    ASSERT_NO_THROW(st.Pop());
}

TEST(test_liststack, cant_pop_from_empty_stack)
{
    ListStack<int> st;
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        st.Pop();
    }
    ASSERT_ANY_THROW(st.Pop());
}