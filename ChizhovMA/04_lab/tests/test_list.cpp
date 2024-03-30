#include "ListHeader.h"

#include <gtest.h>

//Default
TEST(TList, create_list)
{
    ASSERT_NO_THROW(TList<int> list());
}
//With parametr
TEST(TList, create_list_with_parametr)
{
    TNode<int>* pFirst = nullptr;
    TList<int> list(pFirst);
    ASSERT_TRUE(list.IsEmpty());
}
TEST(TList, create_list_with_parametr_check)
{
    TNode<int>* pFirst = new TNode<int>(10);
    TList<int> list(pFirst);
    TNode<int>* tmp = list.Search(10);
    EXPECT_EQ(10, tmp->data);
}
//Copy
TEST(TList, copies_list_correctly)
{
    TList<int>* list = new TList<int>();
    list->InsertEnd(1);
    list->InsertEnd(2);
    list->InsertEnd(3);

    TList<int>* copyList = new TList<int>(*list);
    EXPECT_EQ(list->GetSize(), copyList->GetSize());
}
TEST(TList, copies_list_correctly_change_memory) 
{
    TList<int>* list = new TList<int>();
    list->InsertEnd(1);
    list->InsertEnd(2);
    list->InsertEnd(3);

    TList<int>* copyList = new TList<int>(*list);
    list->InsertEnd(4);
    EXPECT_NE(list->GetSize(), copyList->GetSize());
}
//Search
TEST(TList, search_list_test_true)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    TNode<int>* searchResult = list.Search(5);
    EXPECT_NE(nullptr, searchResult);
}
TEST(TList, search_list_test_false)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    TNode<int>* searchResult = list.Search(2);
    EXPECT_EQ(nullptr, searchResult);
}
//InsertFirst
TEST(TList, insert_first_test)
{
    TList<int> list;
    list.InsertFirst(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TList, insert_first_test_before_test)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertFirst(5);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, insert_first_test_before_test_pnext)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertFirst(5);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
//InsertEnd
TEST(TList, insert_end_list)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TList, insert_end_list_first_element)
{
    TList<int> list;
    list.InsertEnd(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TList, insert_end_list_first_element_pnext)
{
    TList<int> list;
    list.InsertEnd(10);
    list.InsertEnd(5);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
//InsertBefore
TEST(TList, insert_before_list)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBefore(5, 10);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, insert_before_list_pnext)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBefore(5, 10);
    list.Next();
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TList, insert_before_list_error)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    ASSERT_ANY_THROW(list.InsertBefore(5, 1));
}
TEST(TList, insert_before_list_first)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBefore(5, 42);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, insert_before_list_first_pnext)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBefore(5, 42);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(42, Node->data);
}
//InsertAfter
TEST(TList, insert_after_list)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertAfter(5, 42);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, insert_after_list_pnext)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertAfter(5, 42);
    list.Next();
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TList, insert_after_list_error)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    ASSERT_ANY_THROW(list.InsertAfter(5, 2));
}
//InsertBeforeCurrent
TEST(TList, insert_before_current_list_first)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBeforeCurr(5);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, insert_before_current_list_first_pnext)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertBeforeCurr(5);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(42, Node->data);
}
TEST(TList, insert_before_current_list)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();//current is 10
    list.InsertBeforeCurr(5);
    list.Reset();
    list.Next();// 2 element
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, insert_before_current_list_pnext)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();//current is 10
    list.InsertBeforeCurr(5);
    list.Reset();
    list.Next();// 2 element
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
//InsertAfterCurrent
TEST(TList, insert_after_current_first_list)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertAfterCurr(5);
    list.Next();//2 element
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, insert_after_current_first_list_pnext)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.InsertAfterCurr(5);
    list.Next();//2 element
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TList, insert_after_current_last_list)
{
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();
    list.InsertAfterCurr(5);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
//IsEmpty
TEST(TList, is_empty_list_test_true)
{
    TList<int> list;
    EXPECT_TRUE(list.IsEmpty());
}
TEST(TList, is_empty_list_test_false)
{
    TList<int> list;
    list.InsertFirst(10);
    EXPECT_FALSE(list.IsEmpty());
}
//IsFull
TEST(TList, is_full_list_test_false)
{
    TList<int> list;
    EXPECT_FALSE(list.IsFull());
}
TEST(TList, is_full_list_test_true)
{
    TList<int> list;
    list.InsertFirst(10);
    EXPECT_TRUE(list.IsFull());
}
//Remove
TEST(TList, remove_node_middle_test)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);
    list.Remove(5);
    EXPECT_EQ(3, list.GetSize());
}
TEST(TList, remove_node_end_test)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);
    list.Remove(4);
    EXPECT_EQ(3, list.GetSize());
}
TEST(TList, remove_node_first_test)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);

    list.Remove(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TList, remove_node_non_existent)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);
    list.InsertEnd(6);
    list.InsertEnd(4);
    ASSERT_ANY_THROW(list.Remove(9));
}
TEST(TList, remove_node_from_empty_list)
{
    TList<int> list;
    ASSERT_ANY_THROW(list.Remove(9));
}
//GetCurrent
TEST(TList, get_current_data)
{
    TList<int> list;
    list.InsertEnd(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TList, get_current_data_pnext)
{
    TList<int> list;
    list.InsertEnd(10);
    list.InsertEnd(5);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
//GetStop
TEST(TList, get_stop_data)
{
    TList<int> list;
    list.InsertEnd(10);
    TNode<int>* Node = list.GetStop();
    EXPECT_EQ(NULL, Node);
}
//Next
TEST(TList, next_element)
{
    TList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);
    list.InsertEnd(3);

    list.Next();

    TNode<int>* current = list.GetCurrent();
    EXPECT_EQ(2, current->data);
}
//IsEnded
TEST(TList, is_ended_test_false)
{
    TList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    EXPECT_FALSE(list.IsEnded());
}
TEST(TList, is_ended_test_true)
{
    TList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Next();
    list.Next();

    EXPECT_TRUE(list.IsEnded());
}
//Reset
TEST(TList, reset_test_false) {
    TList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Next();
    TNode<int>* current = list.GetCurrent();

    EXPECT_NE(1, current->data);
}
TEST(TList, reset_test_true) {
    TList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Next();
    list.Reset();
    TNode<int>* current = list.GetCurrent();

    EXPECT_EQ(1, current->data);
}
//GetSize
TEST(TList, get_size_test)
{
    TList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);
    list.InsertEnd(3);

    EXPECT_EQ(3, list.GetSize());
}
//Clear
TEST(TList, list_clear_test)
{
    TList<int> list;
    list.InsertEnd(1);
    list.InsertEnd(2);

    list.Clear();

    EXPECT_TRUE(list.IsEmpty());
}