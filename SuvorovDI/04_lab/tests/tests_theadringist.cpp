#include "tlist.h"
#include "theadringlist.h"
#include <gtest.h>

TEST(THeadRingList, can_create_THeadRingList) {
	ASSERT_NO_THROW(THeadRingList<int> hr_hr_list);
}

TEST(THeadRingList, can_Reset_hr_list)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(2);
	hr_list.Reset();
	EXPECT_EQ(1, hr_list.GetCurr()->data);
}

TEST(THeadRingList, can_copy_hr_list)
{
	THeadRingList<int> hr_list1;
	hr_list1.InsertLast(1);
	THeadRingList<int> hr_list2(hr_list1);
	hr_list1.Reset();
	EXPECT_EQ(hr_list1.GetCurr()->data, hr_list2.GetCurr()->data);
}

TEST(THeadRingList, can_assign_hr_list)
{
	THeadRingList<int> hr_list1;
	hr_list1.InsertLast(1);
	hr_list1.InsertLast(2);
	THeadRingList<int> hr_list2;
	hr_list2.InsertLast(3);
	hr_list2 = hr_list1;
	hr_list1.Reset();
	EXPECT_EQ(hr_list1.GetCurr()->data, hr_list2.GetCurr()->data);
}

// insert tests:
TEST(THeadRingList, can_insert_element_into_last) {
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	EXPECT_EQ(1, hr_list.GetCurr()->data);
  EXPECT_TRUE(hr_list.GetCurr()->pNext->data == TNode<int>().data);
}

TEST(THeadRingList, can_insert_element_instead_last) {
  THeadRingList<int> hr_list;
  hr_list.InsertLast(1);
  hr_list.InsertLast(24);
  EXPECT_EQ(24, hr_list.GetCurr()->data);
  EXPECT_TRUE(hr_list.GetCurr()->pNext->data == TNode<int>().data);
}

TEST(THeadRingList, can_insert_element_at_beginning)
{
  THeadRingList<int> hr_list;
  hr_list.InsertLast(1);
  hr_list.InsertFirst(2);
  EXPECT_EQ(2, hr_list.GetCurr()->data);
  EXPECT_EQ(1, hr_list.GetCurr()->pNext->data);
}

TEST(THeadRingList, can_insert_element_in_middle)
{
  THeadRingList<int> hr_list;
  hr_list.InsertLast(1);
  hr_list.InsertLast(3);
  hr_list.Reset();
  hr_list.InsertAfter(2, hr_list.GetCurr()->data);
  EXPECT_EQ(2, hr_list.GetCurr()->data);
}

TEST(THeadRingList, can_get_Next_elemet)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(2);
	EXPECT_EQ(2, hr_list.GetCurr()->data);
}

TEST(THeadRingList, check_hr_list_cannot_do_Next_method_at_Head)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(2);
	hr_list.Next();
	ASSERT_ANY_THROW(hr_list.Next());
}

TEST(THeadRingList, can_remove_first_element)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(2);
	hr_list.Remove(1);
	hr_list.Reset();
	EXPECT_EQ(2, hr_list.GetCurr()->data);
}

TEST(THeadRingList, can_remove_last_element)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(2);
	hr_list.Remove(2);
	hr_list.Reset();
	hr_list.Next();
	EXPECT_TRUE(hr_list.IsEnded());
}

TEST(THeadRingList, can_clear_hr_list)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(2);
	hr_list.InsertLast(3);
	hr_list.Clear();
	EXPECT_TRUE(hr_list.IsEmpty());
}

TEST(THeadRingList, can_insert_element_before_current)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(3);
	hr_list.InsertBefore(2, hr_list.GetCurr()->data);
	hr_list.Reset();
	hr_list.Next();
	EXPECT_EQ(2, hr_list.GetCurr()->data);
}

TEST(THeadRingList, can_insert_element_after_current)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(3);
	hr_list.InsertAfter(2, hr_list.GetCurr()->data);
	EXPECT_EQ(2, hr_list.GetCurr()->data);
}

TEST(THeadRingList, can_check_if_hr_list_is_empty)
{
	THeadRingList<int> hr_list;
	EXPECT_TRUE(hr_list.IsEmpty());
	hr_list.InsertLast(1);
	EXPECT_FALSE(hr_list.IsEmpty());
}

TEST(THeadRingList, can_find_element_by_value)
{
	THeadRingList<int> hr_list;
	hr_list.InsertLast(1);
	hr_list.InsertLast(2);
	hr_list.InsertLast(3);
	EXPECT_EQ(2, hr_list.Search(2)->data);
}
