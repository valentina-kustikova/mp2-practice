#include "theadringlist.h"
#include <gtest.h>

TEST(THeadRingList, can_create_ring_list) {
	ASSERT_NO_THROW(THeadRingList<int> ringlist);
}

TEST(TList, can_insert_last_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_NO_THROW(ringlist.InsertLast(4));
}

TEST(TList, can_insert_first_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_NO_THROW(ringlist.InsertFirst(0));
}

TEST(TList, can_insert_before_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_NO_THROW(ringlist.InsertBefore(5, 2));
}

TEST(TList, throws_when_there_is_no_element_to_insert_before_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_ANY_THROW(ringlist.InsertBefore(6, 5));
}

TEST(TList, can_insert_after_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_NO_THROW(ringlist.InsertAfter(5, 2));
}

TEST(TList, throws_when_there_is_no_element_to_insert_after_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_ANY_THROW(ringlist.InsertAfter(6, 5));
}

TEST(TList, can_search_element_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	EXPECT_EQ(2, ringlist.Search(2)->data);
}

TEST(TList, return_nullptr_when_there_is_no_searching_element_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	EXPECT_EQ(nullptr, ringlist.Search(6));
}

TEST(TList, can_get_current_element_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	EXPECT_EQ(2, ringlist.GetCurrent()->data);;
}

TEST(TList, can_remove_element_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_NO_THROW(ringlist.Remove(2));;
}

TEST(TList, throws_when_there_is_no_removing_element_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_ANY_THROW(ringlist.InsertAfter(6, 5));
}

TEST(TList, can_clear_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_NO_THROW(ringlist.Clear());;
}

TEST(TList, can_reset_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ASSERT_NO_THROW(ringlist.Reset());;
}

TEST(TList, can_sort_ringlist) {
	TList<int> ringlist;
	ringlist.InsertLast(3);
	ringlist.InsertLast(1);
	ringlist.InsertLast(2);
	ASSERT_NO_THROW(ringlist.Sort());;
}

TEST(TList, can_move_to_the_next_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ringlist.Reset();
	ASSERT_NO_THROW(ringlist.Next());;
}

TEST(TList, throws_when_end_of_the_ringlist) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ringlist.Next();
	ASSERT_ANY_THROW(ringlist.Next());;
}

TEST(TList, can_determine_if_ringlist_is_empty) {
	THeadRingList<int> ringlist;
	EXPECT_TRUE(ringlist.IsEmpty());;
}

TEST(TList, can_determine_if_ringlist_is_full) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ringlist.Next();
	EXPECT_FALSE(ringlist.IsFull());;
}

TEST(TList, can_determine_if_ringlist_is_ended) {
	THeadRingList<int> ringlist;
	for (int i = 0; i < 3; i++)
		ringlist.InsertLast(i);
	ringlist.Next();
	EXPECT_TRUE(ringlist.IsEnded());;
}