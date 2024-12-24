#include "list.h"
#include <gtest.h>

TEST(TNode, can_create_Node)
{
    ASSERT_NO_THROW(TNode<int> Node);
}

TEST(TNode, can_create_Node_with_Key)
{
    TNode<int> Node(9);
    EXPECT_EQ(Node.key, 9);
}

TEST(TNode, can_assign_nodes)
{
    TNode<int> Node(8);
    TNode<int> Node1(10);
    ASSERT_NO_THROW(Node = Node1);
}

TEST(TList, can_create_list)
{
    ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_find_existing_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(TList, cant_find_key_that_doesnt_exist)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_EQ(list.search(10), nullptr);
}

TEST(TList, can_push_front)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_front(Node));
}

TEST(TList, can_push_back)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_back(Node));
}

TEST(TList, can_push_after)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_after(Node1, 1));
}

TEST(TList, cant_push_after_non_existed_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(TList, pushed_after_node_is_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(TList, can_push_before)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_before(Node1, 1));
}

TEST(TList, cant_push_before_non_existed_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(TList, can_remove_existing_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_NO_THROW(list.remove(1));
}

TEST(TList, cant_remove_non_existing_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.remove(10));
}

TEST(TList, can_get_size)
{
    TList<int> list;
    TNode<int>* Node1 = new TNode<int>(1), * Node2 = new TNode<int>(10);
    list.push_front(Node1);
    list.push_front(Node2);
    list.size();
    EXPECT_EQ(list.size(), 2);
}

TEST(TList, can_get_first_elem)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(20);
    list.push_front(Node);
    EXPECT_EQ(list.first(), 20);
}

TEST(TList, can_assign_lists)
{
    TList<int> list1;
    TList<int> list2;
    TNode<int>* Node1 = new TNode<int>(1), * Node2 = new TNode<int>(10);
    list1.push_front(Node1);
    list2.push_front(Node2);
    ASSERT_NO_THROW(list1 = list2);
}

TEST(TList, assigned_lists_are_equal)
{
    TList<int> list1;
    TList<int> list2;
    TNode<int>* Node1 = new TNode<int>(1), * Node2 = new TNode<int>(10);
    list1.push_front(Node1);
    list2.push_front(Node1);
    list1 = list2;
    EXPECT_TRUE(list1 == list2);
}