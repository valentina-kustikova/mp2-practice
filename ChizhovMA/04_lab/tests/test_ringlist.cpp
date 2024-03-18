#include "Ringlist.h"

#include <gtest.h>

//Default
TEST(TRingList, create_ringlist)
{
    ASSERT_NO_THROW(TRingList<int> list());
}
//With parametr
TEST(TRingList, create_ring_list_with_parametr)
{
    TNode<int>* pFirst = nullptr;
    ASSERT_NO_THROW(TRingList<int>* list = new TRingList<int>(pFirst));
}
TEST(TRingList, create_list_with_parametr_data_check)
{
    TNode<int>* pFirst = new TNode<int>(10);
    TRingList<int>* list = new TRingList<int>(pFirst);
    TNode<int>* tmp = list->Search(10);
    EXPECT_EQ(10, tmp->data);
}
TEST(TRingList, create_ringlist_with_parametr_list)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    ASSERT_NO_THROW(TRingList<int> rlist(list));
}
TEST(TRingList, create_ringlist_with_parametr_list_data)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    TRingList<int> rlist(list);
    EXPECT_EQ(10, rlist.GetCurrent()->data);
}
TEST(TRingList, create_ringlist_with_parametr_list_data_data)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    TRingList<int> rlist(list);
    rlist.Next();
    EXPECT_EQ(5, rlist.GetCurrent()->data);
}
TEST(TRingList, create_ringlist_with_parametr_ringlist)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);

    TRingList<int> rlist(list);
    ASSERT_NO_THROW(TRingList<int> rlist2(list));
}
TEST(TRingList, create_ringlist_with_parametr_ringlist_data)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);

    TRingList<int> rlist(list);
    TRingList<int> rlist2(rlist);
    int k = rlist2.GetCurrent()->data;
    EXPECT_EQ(10, k);
}
//Search
TEST(TRingList, search_list_test_true)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    TNode<int>* searchResult = list.Search(5);
    EXPECT_NE(nullptr, searchResult);
}
TEST(TRingList, search_list_test_false)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    TNode<int>* searchResult = list.Search(2);
    EXPECT_EQ(nullptr, searchResult);
}
//InsertFirst
TEST(TRingList, insert_first_test)
{
    TRingList<int> list;
    list.InsertFirst(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
//InsertEnd
TEST(TRingList, insert_end_list)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TRingList, insert_end_list_first_element)
{
    TRingList<int> list;
    list.InsertEnd(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
//InsertBefore
TEST(TRingList, insert_before_list)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBefore(5, 10);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TRingList, insert_before_list_error)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    ASSERT_ANY_THROW(list.InsertBefore(5, 1));
}
TEST(TRingList, insert_before_list_first)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBefore(5, 42);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
//InsertAfter
TEST(TRingList, insert_after_list)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertAfter(5, 42);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TRingList, insert_after_list_error)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    ASSERT_ANY_THROW(list.InsertAfter(5, 2));
}
//InsertBeforeCurrent
TEST(TRingList, insert_before_current_list_first)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBeforeCurr(5);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TRingList, insert_before_current_list)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();//current is 10
    list.InsertBeforeCurr(5);
    list.Reset();
    list.Next();// 2 element
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
//InsertAfterCurrent
TEST(TRingList, insert_after_current_list)
{
    TRingList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();//current is 10
    list.InsertAfterCurr(5);
    list.Next();//3 element
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
//IsEmpty
TEST(TRingList, is_empty_list_test_true)
{
    TRingList<int> list;
    EXPECT_TRUE(list.IsEmpty());
}
TEST(TRingList, is_empty_list_test_false)
{
    TRingList<int> list;
    list.InsertFirst(10);
    EXPECT_FALSE(list.IsEmpty());
}
//IsFull
TEST(TRingList, is_full_list_test_false)
{
    TRingList<int> list;
    EXPECT_FALSE(list.IsFull());
}
TEST(TRingList, is_full_list_test_true)
{
    TRingList<int> list;
    list.InsertFirst(10);
    EXPECT_TRUE(list.IsFull());
}
//Remove
TEST(TRingList, remove_node_middle_test)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);
    list.Remove(5);
    EXPECT_EQ(3, list.GetSize());
}
TEST(TRingList, remove_node_end_test)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);
    list.Remove(4);
    EXPECT_EQ(3, list.GetSize());
}
TEST(TRingList, remove_node_first_test)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);

    list.Remove(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TRingList, remove_node_non_existent)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);
    ASSERT_ANY_THROW(list.Remove(9));
}
TEST(TRingList, remove_node_from_empty_list)
{
    TRingList<int> list;
    ASSERT_ANY_THROW(list.Remove(9));
}
//GetCurrent
TEST(TRingList, get_current_data)
{
    TRingList<int> list;
    list.InsertEnd(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TRingList, get_stop_data)
{
    TRingList<int> list;
    list.InsertEnd(10);
    TNode<int>* Node = list.GetStop();
    EXPECT_EQ(NULL, Node);
}
//Set_Stop
TEST(TRingList, set_stop_data)
{
    TRingList<int> list;
    list.InsertEnd(10);
    list.InsertEnd(5);
    list.InsertEnd(12);
    TNode<int>* pN = list.Search(12);
    list.SetPStop(pN);
    TNode<int>* Node = list.GetStop();
    EXPECT_EQ(12, Node->data);
}
//Set_Last
TEST(TRingList, get_last_data)
{
    TNode<int>* pNode = new TNode<int>(10);
    TRingList<int>* list = new TRingList<int>(pNode);
    TNode<int>* tmp = list->GetLast();
    EXPECT_EQ(tmp->data, pNode->data);
}
//Set_Last
TEST(TRingList, set_last_data)
{
    TNode<int>* pNode = new TNode<int>(10);
    TRingList<int>* list = new TRingList<int>(pNode);
    TNode<int>* pN = new TNode<int>(11);
    list->SetPLast(pN);
    TNode<int>* tmp = list->GetLast();
    EXPECT_EQ(tmp->data, pN->data);
}
//Next
TEST(TRingList, next_element)
{
    TRingList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);
    list.InsertEnd(3);

    list.Next();

    TNode<int>* current = list.GetCurrent();
    EXPECT_EQ(2, current->data);
}
//IsEnded
TEST(TRingList, is_ended_test_false)
{
    TRingList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    EXPECT_FALSE(list.IsEnded());
}
TEST(TRingList, is_ended_test_true)
{
    TRingList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Next();
    list.Next();

    EXPECT_TRUE(list.IsEnded());
}
//Reset
TEST(TRingList, reset_test_false) {
    TRingList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Next();
    TNode<int>* current = list.GetCurrent();

    EXPECT_NE(1, current->data);
}
TEST(TRingList, reset_test_true) {
    TRingList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Next();
    list.Reset();
    TNode<int>* current = list.GetCurrent();

    EXPECT_EQ(1, current->data);
}
//GetSize
TEST(TRingList, get_size_test)
{
    TRingList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);
    list.InsertEnd(3);

    EXPECT_EQ(3, list.GetSize());
}
//Clear
TEST(TRingList, list_clear_test) {
    TRingList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Clear();

    EXPECT_TRUE(list.IsEmpty());
}