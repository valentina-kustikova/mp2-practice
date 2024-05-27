#include "tlist.h"

#include <gtest.h>

TEST(TList, test_constructor)
{
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, test_constructor_with_param)
{
	TNode<int>* tmp = new TNode<int>(1, 0);
	ASSERT_NO_THROW(TList<int>* list=new TList<int>(tmp));
}

TEST(TList, test_constructor_copy)
{
	TList<int> list;
	ASSERT_NO_THROW(TList<int>*list_copy = new TList<int>(list));
}

TEST(TList, test_InsertFirst) {
	TList<int> list;

	ASSERT_NO_THROW(list.InsertFirst(5));
}

TEST(TList, test_InsertFirstSearch_test1) {
	TList<int> list;
	list.InsertFirst(5);

	TNode<int>* tmp = list.Search(5);

	EXPECT_EQ(5, tmp->key);
}

TEST(TList, test_InsertFirstSearch_test2) {
	TList<int> list;
	list.InsertFirst(3);

	TNode<int>* tmp = list.Search(5);

	EXPECT_EQ(nullptr, tmp);
}

TEST(TList, test_InsertFirstSearch_test3) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(5);

	TNode<int>* tmp = list.Search(5);

	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

TEST(TList, test_InsertFirstSearch_emptyList) {

	TList<int> list;
	EXPECT_EQ(nullptr, list.Search(5));

}

TEST(TList, test_InsertLast_emptyList) {

	TList<int> list;
	ASSERT_NO_THROW(list.InsertLast(5));
}

TEST(TList, test_InsertLastSearch_not_emptyList) {

	TList<int> list;
	list.InsertLast(5);

	TNode<int>* tmp = list.Search(5);
	EXPECT_EQ(5, tmp->key);
	EXPECT_EQ(nullptr, tmp->pNext);
}

TEST(TList, test_IsEmpty) {

	TList<int> list;
	EXPECT_EQ(true, list.IsEmpty());
}

TEST(TList, test_IsEmpty_notEmpty) {

	TList<int> list;
	list.InsertLast(5);
	EXPECT_EQ(false, list.IsEmpty());
}

TEST(TList, test_GetSize_IsEmpty) {

	TList<int> list;
	EXPECT_EQ(0, list.GetSize());
}

TEST(TList, test_GetSize_IsNotEmpty1) {

	TList<int> list;
	list.InsertLast(5);
	EXPECT_EQ(1, list.GetSize());
}

TEST(TList, test_GetSize_IsNotEmpty2) {

	TList<int> list;
	list.InsertLast(5);
	list.InsertLast(5);
	list.InsertLast(5);
	EXPECT_EQ(3, list.GetSize());
}

TEST(TList, test_Clear) {

	TList<int> list;
	list.InsertLast(5);
	list.InsertLast(5);
	list.InsertLast(5);
	ASSERT_NO_THROW(list.Clear());
}

TEST(TList, test_Clear_checkSize) {

	TList<int> list;
	list.InsertLast(5);
	list.InsertLast(5);
	list.InsertLast(5);
	list.Clear();
	EXPECT_EQ(0, list.GetSize());
}

TEST(TList, test_INsertAfter_NotFound) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_ANY_THROW(list.InsertAfter(5, 10));
}

TEST(TList, test_INsertAfter_Found) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_NO_THROW(list.InsertAfter(5, 1));
}

TEST(TList, test_INsertAfter_Found_Search) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertAfter(5, 1);
	TNode<int>* tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(5, tmp->pNext->key);
}

TEST(TList, test_INsertBefore_NotFound) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_ANY_THROW(list.InsertBefore(5, 10));
}

TEST(TList, test_INsertBefore_Found) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_NO_THROW(list.InsertBefore(5, 2));
}

TEST(TList, test_INsertBefore_Found_Search) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertBefore(5, 2);
	TNode<int>* tmp = list.Search(5);
	EXPECT_EQ(5, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
}

TEST(TList, test_INsertBefore_two_arguments_empty_list) {

	TList<int> list;
	ASSERT_ANY_THROW(list.InsertBefore(2, 5));
}

TEST(TList, test_INsertBefore_two_arguments_not_empty_list) {

	TList<int> list;
	list.InsertLast(1);
	ASSERT_NO_THROW(list.InsertBefore(5, 1));
}

TEST(TList, test_INsertBefore_two_arguments_not_empty_list1) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertBefore(5, 1);
	TNode<int>* tmp = list.Search(5);
	EXPECT_EQ(5, tmp->key);
	EXPECT_EQ(1, tmp->pNext->key);
	EXPECT_EQ(2, tmp->pNext->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

TEST(TList, test_INsertBefore_two_arguments_not_empty_list_not_found) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(1);
	list.InsertLast(2);
	ASSERT_ANY_THROW(list.InsertBefore(5, 4));
}

TEST(TList, test_Remove_IsEmpty) {

	TList<int> list;
	ASSERT_ANY_THROW(list.Remove(5));
}

TEST(TList, test_Remove_NotFound) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);
	list.InsertLast(6);
	ASSERT_ANY_THROW(list.Remove(5));
}

TEST(TList, test_Remove_Middle) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);
	list.InsertLast(5);
	ASSERT_NO_THROW(list.Remove(3));
}

TEST(TList, test_Remove_Middle_Search) {

	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(2);
	TNode<int>* tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(nullptr, list.Search(2));
}

TEST(TList, test_GetCurrent) {

	TList<int> list;
	ASSERT_NO_THROW(list.GetCurrent());
}

TEST(TList, test_GetCurrent_pointer) {

	TList<int> list;
	TNode<int>* tmp = list.GetCurrent();
	EXPECT_EQ(nullptr, tmp);
}

TEST(TList, test_GetCurrent_key) {

	TList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(2);
	TNode<int>* tmp = list.GetCurrent();
	EXPECT_EQ(2, tmp->key);
	EXPECT_EQ(1, tmp->pNext->key);
}

TEST(TList, test_Reset) {

	TList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	ASSERT_NO_THROW(list.Reset());
}

TEST(TList, test_GetCurrent_key_Reset) {

	TList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	list.Reset();
	TNode<int>* tmp=list.GetCurrent();
	EXPECT_EQ(3, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
}

TEST(TList, test_GetCurrent_key_Reset_Next) {

	TList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	list.Reset();
	TNode<int>* tmp1 = list.GetCurrent();
	EXPECT_EQ(3, tmp1->key);
	list.Next();
	TNode<int>* tmp2 = list.GetCurrent();
	EXPECT_EQ(2, tmp2->key);
}

TEST(TList, test_removeCurrentNode) {

	TList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	list.Reset();
	ASSERT_NO_THROW(list.removeCurrentNode());
	
}

TEST(TList, test_removeCurrentNode1) {

	TList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	list.InsertLast(4);
	list.InsertLast(5);
	list.Reset();
	list.Next();
	list.removeCurrentNode();
	TNode<int>* tmp = list.GetCurrent();
	EXPECT_EQ(4, tmp->key);
}

TEST(TList, test_removeCurrentNode2) {

	TList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	list.InsertLast(4);
	list.InsertLast(5);
	list.Reset();
	list.Next();
	list.removeCurrentNode();
	TNode<int>* tmp = list.Search(3);
	EXPECT_EQ(3, tmp->key);
	EXPECT_EQ(4, tmp->pNext->key);
	EXPECT_EQ(5, tmp->pNext->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}









