#include "tringlist.h"

#include <gtest.h>

TEST(TRingList, test_constructor)
{
	ASSERT_NO_THROW(TRingList<int> list);
}

TEST(TRingList, test_constructor_with_param)
{
	TNode<int>* tmp = new TNode<int>(1, 0);
	ASSERT_NO_THROW(TRingList<int>*list = new TRingList<int>(tmp));
}

TEST(TRingList, test_constructor_copy)
{
	TRingList<int> list;
	ASSERT_NO_THROW(TRingList<int>*list_copy = new TRingList<int>(list));
}

TEST(TRingList, test_InsertFirst) {
	TRingList<int> list;

	ASSERT_NO_THROW(list.InsertFirst(5));
}

TEST(TRingList, test_InsertFirstSearch_test1) {
	TRingList<int> list;
	list.InsertFirst(5);

	TNode<int>* tmp = list.Search(5);

	EXPECT_EQ(5, tmp->key);
}

TEST(TRingList, test_InsertFirstSearch_test2) {
	TRingList<int> list;
	list.InsertFirst(3);

	TNode<int>* tmp = list.Search(5);

	EXPECT_EQ(nullptr, tmp);
}

TEST(TRingList, test_InsertFirstSearch_test3) {
	TRingList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(5);

	TNode<int>* tmp = list.Search(5);

	EXPECT_EQ(5, tmp->key);
}

TEST(TRingList, test_InsertLast_emptyList) {

	TRingList<int> list;
	ASSERT_NO_THROW(list.InsertLast(5));
}

TEST(TRingList, test_IsEmpty) {

	TRingList<int> list;
	EXPECT_EQ(true, list.IsEmpty());
}

TEST(TRingList, test_IsEmpty_notEmpty) {

	TRingList<int> list;
	list.InsertLast(5);
	EXPECT_EQ(false, list.IsEmpty());
}

TEST(TRingList, test_GetSize_IsEmpty) {

	TRingList<int> list;
	EXPECT_EQ(0, list.GetSize());
}

TEST(TRingList, test_GetSize_IsNotEmpty1) {

	TRingList<int> list;
	list.InsertLast(5);
	EXPECT_EQ(1, list.GetSize());
}

TEST(TRingList, test_GetSize_IsNotEmpty2) {

	TRingList<int> list;
	list.InsertLast(5);
	list.InsertLast(5);
	list.InsertLast(5);
	EXPECT_EQ(3, list.GetSize());
}

TEST(TRingList, test_Clear) {

	TRingList<int> list;
	list.InsertLast(5);
	list.InsertLast(5);
	list.InsertLast(5);
	ASSERT_NO_THROW(list.Clear());
}

TEST(TRingList, test_Clear_checkSize) {

	TRingList<int> list;
	list.InsertLast(5);
	list.InsertLast(5);
	list.InsertLast(5);
	list.Clear();
	EXPECT_EQ(0, list.GetSize());
}

TEST(TRingList, test_INsertAfter_NotFound) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_ANY_THROW(list.InsertAfter(5, 10));
}

TEST(TRingList, test_INsertAfter_Found) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_NO_THROW(list.InsertAfter(5, 1));
}

TEST(TRingList, test_INsertAfter_Found_Search) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertAfter(5, 1);
	TNode<int>* tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(5, tmp->pNext->key);
}

TEST(TRingList, test_INsertBefore_NotFound) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_ANY_THROW(list.InsertBefore(5, 10));
}

TEST(TRingList, test_INsertBefore_Found) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	ASSERT_NO_THROW(list.InsertBefore(5, 2));
}

TEST(TRingList, test_INsertBefore_Found_Search) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertBefore(5, 2);
	TNode<int>* tmp = list.Search(5);
	EXPECT_EQ(5, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
}

TEST(TRingList, test_Remove_IsEmpty) {

	TRingList<int> list;
	ASSERT_ANY_THROW(list.Remove(5));
}

TEST(TRingList, test_Remove_NotFound) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);
	list.InsertLast(6);
	ASSERT_ANY_THROW(list.Remove(5));
}

TEST(TRingList, test_Remove_Middle) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);
	list.InsertLast(5);
	ASSERT_NO_THROW(list.Remove(3));
}

TEST(TRingList, test_Remove_Middle_Search) {

	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(2);
	TNode<int>* tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(nullptr, list.Search(2));
}

TEST(TRingList, test_GetCurrent) {

	TRingList<int> list;
	ASSERT_NO_THROW(list.GetCurrent());
}

TEST(TRingList, test_GetCurrent_key) {

	TRingList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(2);
	TNode<int>* tmp = list.GetCurrent();
	EXPECT_EQ(2, tmp->key);
	EXPECT_EQ(1, tmp->pNext->key);
}

TEST(TRingList, test_Reset) {

	TRingList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	ASSERT_NO_THROW(list.Reset());
}

TEST(TRingList, test_GetCurrent_key_Reset) {

	TRingList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	list.Reset();
	TNode<int>* tmp = list.GetCurrent();
	EXPECT_EQ(3, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
}

TEST(TRingList, test_GetCurrent_key_Reset_Next) {

	TRingList<int> list;
	list.InsertLast(3);
	list.InsertLast(2);
	list.Reset();
	TNode<int>* tmp1 = list.GetCurrent();
	EXPECT_EQ(3, tmp1->key);
	list.Next();
	TNode<int>* tmp2 = list.GetCurrent();
	EXPECT_EQ(2, tmp2->key);
}




