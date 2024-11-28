#include <gtest.h>
#include "stack.h"
#include "arr_stack.h"

//TEST(test_arrstack,)

TEST(test_arrstack, can_create_arr_stack)
{
    ASSERT_NO_THROW(ArrStack<int> s(5));
}

TEST(test_arrstack, cant_create_arr_stack_with_negative_index)
{
    ASSERT_ANY_THROW(ArrStack<int> s(-1));
}

TEST(test_arrstack, can_top_from_no_empty_stack)
{
    ArrStack<int> st(5);
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    ASSERT_NO_THROW(st.Top());
    int res = st.Top();
    EXPECT_EQ(res, 4);
}

TEST(test_arrstack, can_pop_from_no_empty_stack)
{
    ArrStack<int> st(5);
    for (int i = 0; i < 5; i++)
    {
        st.Push(i);
    }
    ASSERT_NO_THROW(st.Pop());
}

TEST(test_arrstack, cant_pop_from_empty_stack)
{
    ArrStack<int> st(5);
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
