#include <gtest.h>
#include "list.h"

TEST(test_list, can_create_list)
{
    ASSERT_NO_THROW(TList<int> l);
}

TEST(test_list, push_front)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(1);
    ASSERT_NO_THROW(l.PushFront(node));
}

TEST(test_list, push_back)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(1);
    ASSERT_NO_THROW(l.PushBack(node));
}
TEST(test_list, insert_after)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(1);
    l.PushBack(node);
    TNode<int>* node2 = new TNode <int>(2);
    ASSERT_NO_THROW(l.insertAfter(node2,1));
}
TEST(test_list, insert_before)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(2);
    l.PushBack(node);
    TNode<int>* node2 = new TNode <int>(1);
    ASSERT_NO_THROW(l.insertBefore(node2, 2));
}
TEST(test_list, can_remove)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(1);
    node->pNext = new TNode<int>(2);
    l.PushBack(node);
    ASSERT_NO_THROW(l.remove(2));
}

TEST(test_list, isnt_empty)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(1);
    l.PushBack(node);
    EXPECT_EQ(false, l.IsEmpty());
}
TEST(test_list, is_empty)
{
    TList<int> l;
    EXPECT_EQ(true, l.IsEmpty());
}
TEST(test_list, isnt_full)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(1);
    l.PushBack(node);
    EXPECT_EQ(false, l.IsFull());
}
TEST(test_list, can_get_size)
{
    TList<int> l;
    TNode<int>* node = new TNode<int>(1);
    node->pNext = new TNode<int>(2);
    l.PushBack(node);
    EXPECT_EQ(2, l.Size());
}
TEST(test_list, comparison_operator)
{
    TList<int> l;
    TNode<int>* node1 = new TNode<int>(1);
    l.PushBack(node1);
    TList<int> l1;
    TNode<int>* node2 = new TNode<int>(1);
    l1.PushBack(node2);
    EXPECT_TRUE(l1 == l);
}
TEST(test_list, can_copy_list) {
    TList<int> l1;
    TNode<int>* node = new TNode<int>(1);
    node->pNext = new TNode<int>(2);
    l1.PushBack(node);
    TList<int> l2;
    l2 = l1;
    EXPECT_TRUE(l1 == l2);
}