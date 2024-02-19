#include "tlist.h"
#include <gtest.h>

//TNode<T>
TEST(TNode, can_create_node_w_param) {
	ASSERT_NO_THROW(TNode<int> tmp(1,nullptr));
}

TEST(TNode, can_create_copy_node) {
	TNode<int> Node(1, nullptr);
	ASSERT_NO_THROW(TNode<int> tmp(Node));
}

//TList<T>
TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int> list);
}
TEST(TList, can_create_list_w_param) {
	const TNode<int>* tmp = new TNode<int>(1, nullptr);
	ASSERT_NO_THROW(TList<int>* list = new TList<int>(tmp));
}

TEST(TList, can_create_copy_list) {
	TList<int> list;
	ASSERT_NO_THROW(TList<int> list_copy(list));
}

TEST(TList, can_clean_list) {
	TList<int> list;
	list.InsertFirst(2);
	list.Clear();
	EXPECT_EQ(true, list.is_Empty());
}

TEST(TList, can_delete_list) {
	TList<int> list;
	list.InsertFirst(2);
	list.~TList();
	EXPECT_EQ(true, list.is_Empty());
}

TEST(TList, can_check_empty_true)
{
	TList<int> list;
	ASSERT_TRUE(list.is_Empty());
}

TEST(TList, can_check_empty_false)
{
	TList<int> list;
	list.InsertFirst(1);
	ASSERT_FALSE(list.is_Empty());
}

TEST(TList, can_check_full_false)
{
	TList<int> list;
	ASSERT_FALSE(list.is_Full());
}
//INSERT_FIRST
TEST(TList, can_insert_first) {
	TList<int> list;
	list.InsertFirst(1);
	EXPECT_EQ(list.GetCurrent()->key, 1);
}

//INSERT_LAST
TEST(TList, can_insert_last_list_is_not_empty) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	EXPECT_EQ(list.GetCurrent()->pNext->key, 2);
}

TEST(TList, can_insert_last_list_is_empty) {
	TList<int> list;
	list.InsertFirst(1);
	EXPECT_EQ(list.GetCurrent()->key, 1);
}

//INSERT_BEFORE
TEST(TList, can_insert_before_w_NextKey) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	list.InsertBefore(3, 2);
	EXPECT_EQ(list.GetCurrent()->pNext->key, 3);
}

TEST(TList, cant_insert_before_w_NextKey_Key_not_found) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	ASSERT_ANY_THROW(list.InsertBefore(3, 0));
}

TEST(TList, cant_insert_before_w_NextKey_Key_not_found) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	ASSERT_ANY_THROW(list.InsertBefore(3, 0));
}