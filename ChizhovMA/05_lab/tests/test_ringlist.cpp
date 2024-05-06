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
    TNode<int>* pFirst = new TNode<int>(10);
    ASSERT_NO_THROW(TRingList<int>*list = new TRingList<int>(pFirst));
}
TEST(TRingList, create_list_with_parametr_data_check)
{
    TNode<int>* pFirst = new TNode<int>(10);
    TRingList<int> list(pFirst);
    TNode<int>* tmp = list.Search(10);
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
TEST(TRingList, create_ringlist_with_parametr_ringlist_data_data)
{
    TList<int> list;
    list.InsertFirst(10);
    list.InsertEnd(5);

    TRingList<int> rlist(list);
    TRingList<int> rlist2(rlist);
    rlist2.Next();
    int k = rlist2.GetCurrent()->data;
    EXPECT_EQ(5, k);
}
//InsertFirst
TEST(TRingList, insert_first_test)
{
    TRingList<int> list;
    list.InsertFirst(10);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(10, Node->data);
}
TEST(TRingList, insert_first_test_before_test)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertFirst(5);
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
}
TEST(TRingList, insert_first_test_before_test_pnext)
{
    TRingList<int> list;
    list.InsertFirst(10);
    list.InsertFirst(5);
    list.Next();
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
TEST(TRingList, insert_end_list_first_element_pnext)
{
    TRingList<int> list;
    list.InsertEnd(10);
    list.InsertEnd(5);
    list.Next();
    TNode<int>* Node = list.GetCurrent();
    EXPECT_EQ(5, Node->data);
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