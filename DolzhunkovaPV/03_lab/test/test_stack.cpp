#include <gtest.h>
#include "stack.h"

TEST(test_stack, list_list_create)
{
    ASSERT_NO_THROW(List<int> st_l);
}

TEST(test_stack, list_list_push_empty)
{
    List<int> st_l;
    st_l.push(1);
    EXPECT_EQ(false, st_l.empty());
}

TEST(test_stack, listlist_push_top)
{
    List<int> st_l;
    st_l.push(123);
    EXPECT_EQ(123, st_l.front());
}

TEST(test_stack, list_push_pop_empty)
{
    List<int> st_l;
    st_l.push(123);
    st_l.pop();
    EXPECT_EQ(true, st_l.empty());
}

TEST(test_stack, list_many_pushes_pops_empty)
{
    List<int> st_l;

    for (int i = 0; i < 100; ++i) {
        st_l.push(i);
    }

    for (int i = 99; i >= 0; --i) {
        st_l.pop();

    }

    EXPECT_EQ(true, st_l.empty());
}

TEST(test_stack, list_many_pushes_pops_top)
{
    List<int> st_l;

    for (int i = 0; i < 100; ++i) {
        st_l.push(i);
    }

    for (int i = 99; i >= 0; --i) {
        EXPECT_EQ(i, st_l.front());
        st_l.pop();
    }
}

TEST(test_stack, stack_list_create)
{
    ASSERT_NO_THROW(StackList<int> st_l);
}

TEST(test_stack, stack_list_push_empty)
{
    StackList<int> st_l;
    st_l.push(1);
    EXPECT_EQ(false, st_l.empty());
}

TEST(test_stack, stack_list_push_top)
{
    StackList<int> st_l;
    st_l.push(123);
    EXPECT_EQ(123, st_l.top());
}

TEST(test_stack, stack_list_push_pop_empty)
{
    StackList<int> st_l;
    st_l.push(123);
    st_l.pop();
    EXPECT_EQ(true, st_l.empty());
}

TEST(test_stack, stack_list_many_pushes_pops_empty)
{
    StackList<int> st_l;

    for (int i = 0; i < 100; ++i) {
        st_l.push(i);
    }

    for (int i = 99; i >= 0; --i) {
        st_l.pop();

    }

    EXPECT_EQ(true, st_l.empty());
}

TEST(test_stack, stack_list_many_pushes_pops_top)
{
    StackList<int> st_l;

    for (int i = 0; i < 100; ++i) {
        st_l.push(i);
    }

    for (int i = 99; i >= 0; --i) {
        EXPECT_EQ(i, st_l.top());
        st_l.pop();
    }
}

TEST(test_stack, stack_array_create)
{
    ASSERT_NO_THROW(StackArray<int> st_l);
}

TEST(test_stack, stack_array_push_empty)
{
    StackArray<int> st_l;
    st_l.push(1);
    EXPECT_EQ(false, st_l.empty());
}

TEST(test_stack, stack_array_push_top)
{
    StackArray<int> st_l;
    st_l.push(123);
    EXPECT_EQ(123, st_l.top());
}

TEST(test_stack, stack_array_push_pop_empty)
{
    StackArray<int> st_l;
    st_l.push(123);
    st_l.pop();
    EXPECT_EQ(true, st_l.empty());
}

TEST(test_stack, stack_array_many_pushes_pops_empty)
{
    StackArray<int> st_l;

    for (int i = 0; i < 100; ++i) {
        st_l.push(i);
    }

    for (int i = 99; i >= 0; --i) {
        st_l.pop();
    }

    EXPECT_EQ(true, st_l.empty());
}

TEST(test_stack, stack_array_many_pushes_pops_tops)
{
    StackArray<int> st_l;

    for (int i = 0; i < 100; ++i) {
        st_l.push(i);
    }

    for (int i = 99; i >= 0; --i) {
        EXPECT_EQ(i, st_l.top());
        st_l.pop();
    }
}
