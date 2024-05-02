#include "tlist.h"
#include <gtest.h>

TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_insert_last) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_NO_THROW(list.InsertLast(4));
}

TEST(TList, can_insert_first) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_NO_THROW(list.InsertFirst(0));
}

TEST(TList, can_insert_before) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_NO_THROW(list.InsertBefore(5, 2));
}

TEST(TList, throws_when_there_is_no_element_to_insert_before) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_ANY_THROW(list.InsertBefore(6, 5));
}

TEST(TList, can_insert_after) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_NO_THROW(list.InsertAfter(5, 2));
}

TEST(TList, throws_when_there_is_no_element_to_insert_after) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_ANY_THROW(list.InsertAfter(6, 5));
}

TEST(TList, can_search_element) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	EXPECT_EQ(2, list.Search(2)->data);
}

TEST(TList, return_nullptr_when_there_is_no_searching_element) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	EXPECT_EQ(nullptr, list.Search(6));
}

TEST(TList, can_get_current_element) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	EXPECT_EQ(2, list.GetCurrent()->data);;
}

TEST(TList, can_remove_element) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_NO_THROW(list.Remove(2));;
}

TEST(TList, throws_when_remove_element_from_empty_list) {
	TList<int> list;
	ASSERT_ANY_THROW(list.Remove(2));;
}

TEST(TList, throws_when_there_is_no_removing_element) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_ANY_THROW(list.InsertAfter(6, 5));
}

TEST(TList, can_clear_list) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_NO_THROW(list.Clear());;
}

TEST(TList, can_reset_list) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	ASSERT_NO_THROW(list.Reset());;
}

TEST(TList, can_sort_list) {
	TList<int> list;
	list.InsertLast(3);
	list.InsertLast(1);
	list.InsertLast(2);
	ASSERT_NO_THROW(list.Sort());;
}

TEST(TList, can_move_to_the_next) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	list.Reset();
	ASSERT_NO_THROW(list.Next());;
}

TEST(TList, throws_when_end_of_the_list) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	list.Next();
	ASSERT_ANY_THROW(list.Next());;
}

TEST(TList, can_determine_if_list_is_empty) {
	TList<int> list;
	EXPECT_TRUE(list.IsEmpty());;
}

TEST(TList, can_determine_if_list_is_full) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	list.Next();
	EXPECT_FALSE(list.IsFull());;
}

TEST(TList, can_determine_if_list_is_ended) {
	TList<int> list;
	for (int i = 0; i < 3; i++)
		list.InsertLast(i);
	list.Next();
	EXPECT_TRUE(list.IsEnded());;
}