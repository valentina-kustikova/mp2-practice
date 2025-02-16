#include "list.h"
#include <gtest.h>

TEST(TNode, can_create_node)
{
    ASSERT_NO_THROW(TNode<int> Node);
}

TEST(TNode, can_create_node_with_entered_value)
{
    TNode<int> Node(2);
    EXPECT_EQ(Node.value, 2);
}

TEST(TNode, can_assign_nodes)
{
    TNode<int> Node(2);
    TNode<int> Node1(2);
    ASSERT_NO_THROW(Node = Node1);
}

TEST(TNode, assigned_nodes_are_the_same)
{
    TNode<int> Node(2);
    TNode<int> Node1(5);
    Node = Node1;
    EXPECT_EQ(Node.value, Node1.value);
}

// TList

TEST(TList, can_create_list)
{
    ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_create_copied_list)
{
    TList<int> list;
    ASSERT_NO_THROW(TList<int> list1(list));
}

TEST(TList, copied_list_is_equal_to_source_one)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    list.push_front(Node);
    TList<int> list1(list);
    EXPECT_EQ(list, list1);
}

TEST(TList, copied_list_has_its_own_memory)
{
    TNode<int>* Node = new TNode<int>(2);
    TNode<int>* Node1 = new TNode<int>(5);
    TList<int> list;
    TList<int> list1(list);
    list.push_front(Node);
    list1.push_front(Node1);
    EXPECT_FALSE(list == list1);
}

TEST(TList, correctly_defines_emptiness_of_list)
{
    TList<int> list;
    TList<int> list1;
    TNode<int>* Node1 = new TNode<int>(5);
    list1.push_front(Node1);
    EXPECT_TRUE(list.isEmpty());
    EXPECT_FALSE(list1.isEmpty());
}

TEST(TList, can_get_first_elem)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    list.push_front(Node);
    EXPECT_EQ(list.first_value(), 12);
}

TEST(TList, cant_get_fist_elem_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.first_value());
}

TEST(TList, can_push_front)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    ASSERT_NO_THROW(list.push_front(Node));
}

TEST(TList, cant_push_front_nullptr)
{
    TList<int> list;
    TNode<int>* Node = nullptr;
    ASSERT_ANY_THROW(list.push_front(Node));
}

TEST(TList, pushed_front_node_is_in_list)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    list.push_front(Node);
    EXPECT_NE(list.search(12), nullptr);
}

TEST(TList, can_push_back)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    ASSERT_NO_THROW(list.push_back(Node));
}


TEST(TList, cant_push_back_nullptr)
{
    TList<int> list;
    TNode<int>* Node = nullptr;
    ASSERT_ANY_THROW(list.push_back(Node));
}

TEST(TList, pushed_back_node_is_in_list)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    list.push_back(Node);
    EXPECT_NE(list.search(12), nullptr);
}

TEST(TList, can_search_values)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(12);
    list.push_back(Node);
    EXPECT_EQ(list.search(12), Node);
}

TEST(TList, throws_when_entered_value_isnt_in_list)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(2);
    list.push_back(Node);
    ASSERT_ANY_THROW(list.search(12), Node);
}

TEST(TList, can_insert_before)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.insert_before(Node1, 1));
}

TEST(TList, cant_insert_before_because_value_doesnt_exist)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.insert_before(Node1, 2));
}

TEST(TList, inserted_before_elem_present_in_list)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.insert_before(Node1, 1);
    EXPECT_EQ(list.search(10), Node1);
}

TEST(TList, can_insert_after)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.insert_after(Node1, 1));
}

TEST(TList, cant_insert_after_because_value_doesnt_exist)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.insert_after(Node1, 2));
}

TEST(TList, inserted_after_elem_present_in_list)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.insert_after(Node1, 1);
    EXPECT_EQ(list.search(10), Node1);
}

TEST(TList, can_remove_node_with_entered_value)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_NO_THROW(list.remove(1));
}

TEST(TList, cant_remove_node_because_value_doesnt_exist)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.remove(2));
}

TEST(TList, removed_value_is_not_presented_in_list)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    list.remove(1);
    ASSERT_ANY_THROW(list.search(1));
}

TEST(TList, can_get_size)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_front(Node1);
    list.size();
    EXPECT_EQ(list.size(), 2);
}

TEST(TList, can_assign_lists)
{
    TList<int> list;
    TList<int> list1;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    ASSERT_NO_THROW(list = list1);
}

TEST(TList, assigned_lists_are_equal)
{
    TList<int> list;
    TList<int> list1;
    TNode<int>* Node = new TNode<int>(1);
    TNode<int>* Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    list = list1;
    EXPECT_TRUE(list == list1);
}