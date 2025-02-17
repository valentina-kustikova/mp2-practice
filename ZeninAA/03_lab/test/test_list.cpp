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

TEST(TNode, assigned_nodes_have_equal_keys)
{
    TNode<int> Node(7);
    TNode<int> Node1(9);
    Node1 = Node;
    EXPECT_EQ(Node.key, Node1.key);
}

TEST(TList, can_create_list)
{
    ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_copy_list)
{
    TList<int> list;
    ASSERT_NO_THROW(TList<int> list1(list));
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

TEST(TList, cant_push_back_empty_node)
{
    TList<int> list;
    TNode<int>* node = nullptr;
    ASSERT_ANY_THROW(list.push_back(node));
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

TEST(TList, cant_push_before_non_existed_key)
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

TEST(TList, empty_false_for_not_empty_list)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    list.push_front(Node);
    EXPECT_FALSE(list.empty());
}

TEST(TList, empty_true_for_empty_list)
{
    TList<int> list;
    EXPECT_TRUE(list.empty());
}

TEST(TList, cant_get_first_elem_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.first());
}

TEST(TList, removed_key_is_not_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    list.remove(1);
    EXPECT_EQ(list.search(1), nullptr);
}

TEST(TList, pushed_before_node_is_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(TList, pushed_back_node_is_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_back(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(TList, copied_lists_have_different_memory)
{
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    TList<int> list;
    list.push_front(Node);
    TList<int> list1(list);
    list1.push_front(Node1);
    EXPECT_FALSE(list == list1);
}

TEST(TList, copied_lists_are_equal)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    TList<int> list1(list);
    EXPECT_TRUE(list == list1);
}