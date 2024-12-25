#include "list.h"

#include <gtest.h>

TEST(LIST, can_create_list)
{
    ASSERT_NO_THROW(List<int> list);
}

TEST(LIST, can_create_list_by_elem)
{
    ASSERT_NO_THROW(List<int> list(5));
}

TEST(LIST, can_pushBack_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(list.pushBack(node));
}

TEST(LIST, cant_pushFront_nullptr_in_not_empty_list)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    list.pushBack(node);
    ASSERT_ANY_THROW(list.pushFront(nullptr));
}

TEST(LIST, can_pushFront_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(list.pushFront(node));
}

TEST(LIST, can_search_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ASSERT_NO_THROW(list.search(5));
}

TEST(LIST, cant_search_not_existing_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    EXPECT_EQ(list.search(7),nullptr);
}


TEST(LIST, can_InsertAfter_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    list.InsertAfter(add, 5); 
    ASSERT_EQ(list.search(5)->next->val,7);
    ASSERT_EQ(list.search(7)->next->val, 6);
}

TEST(LIST, cant_InsertAfter_not_existing_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(list.InsertAfter(add, 7));
}

TEST(LIST, can_InsertBefore_elem)
{

    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    list.InsertBefore(add, 6);
    EXPECT_EQ(list.search(5)->next->val, 7);
    EXPECT_EQ(list.search(7)->next->val, 6); // ;


}

TEST(LIST, cant_InsertBefore_not_existing_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(list.InsertBefore(add, 7)); // todo
}

TEST(LIST, can_remove_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);
    list.pushBack(node);
    list.remove(6);
    EXPECT_EQ(list.search(5)->next->val,7); // todo
    EXPECT_EQ(list.search(6), nullptr);
}

TEST(LIST, cant_remove_not_existing_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(list.remove(7));
}


TEST(LIST, can_RemoveFirst_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    list.RemoveFirst();
    ASSERT_EQ(list.get_head()->val, 6); // todo
}

TEST(LIST, cant_RemoveFirst_not_existing_elem)
{
    List<int> list;
    ASSERT_ANY_THROW(list.RemoveFirst());
}

TEST(LIST, equal_lists_are_equal)
{
    List<int> list1;
    List<int> list2;
    list1.push(1);
    list2.push(1);
    EXPECT_TRUE(list1 == list2);

}
