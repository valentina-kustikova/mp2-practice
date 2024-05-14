#include "tlist.h"
#include <gtest.h>

TEST(TList, can_create_new_list)
{
	ASSERT_NO_THROW(TList<int> new_list);
}

TEST(TList, list_is_empty_check)
{
	TList<int> list;
	EXPECT_TRUE(list.IsEmpty());
}

TEST(TList, check_non_empty)
{
	TList<int> list;
	list.InsertLast(2);
	EXPECT_FALSE(list.IsEmpty());
}

TEST(TList, can_InsertLast_in_the_list)
{
	TList<int> list;
	ASSERT_NO_THROW(list.InsertLast(1));
}

TEST(TList, can_insert_element_in_not_empty_list) 
{
	TList<int> list;
	list.InsertLast(1);
	ASSERT_NO_THROW(list.InsertLast(2));
}

TEST(TList, can_Remove_element)
{
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(3);
	EXPECT_TRUE(list.Search(3) == nullptr);
}

TEST(TList, can_get_current_elemet)
{
	TList<int> list;
	list.InsertLast(1);
	EXPECT_EQ(1, list.GetCurr()->data);
}

TEST(TList, can_clear_list)
{
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.Clear();
	EXPECT_TRUE(list.IsEmpty());
}

TEST(TList, error_when_Remove_from_empty_list) 
{
	TList<int> list;
	ASSERT_ANY_THROW(list.Remove(5));
}

TEST(TList, error_when_Remove_non_exist_elem) 
{
	TList<int> list;
	list.InsertLast(4);
	ASSERT_ANY_THROW(list.Remove(5));
}

TEST(TList, can_InsertFirst_element)
{
	TList<int> list;
	list.InsertFirst(1); 
	ASSERT_NO_THROW(list.InsertFirst(2));
}

TEST(TList, can_insert_after_element) // + 2
{
	TList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(2);
	ASSERT_NO_THROW(list.InsertAfter(3,2));
}

// tests for insert
TEST(TList, check_correct_insert_into_first)
{
  TList<int> list;
  list.InsertFirst(1);
  EXPECT_EQ(list.GetCurr()->data, 1);
}

TEST(TList, check_correct_insert_instead_first)
{
  TList<int> list;
  list.InsertFirst(2);
  list.InsertFirst(1);
  EXPECT_EQ(list.GetCurr()->data, 1);
  EXPECT_EQ(list.GetCurr()->pNext->data, 2);
}

TEST(TList, check_correct_insert_into_last)
{
  TList<int> list;
  list.InsertLast(6);
  EXPECT_EQ(list.GetCurr()->data, 6);
  EXPECT_TRUE(list.GetCurr()->pNext == nullptr);
}

TEST(TList, check_correct_insert_instead_last)
{
  TList<int> list;
  list.InsertLast(2);
  list.InsertLast(1);
  EXPECT_EQ(list.GetCurr()->data, 1);
  EXPECT_TRUE(list.GetCurr()->pNext == nullptr);
}

TEST(TList, check_correct_insert_before_first)
{
  TList<int> list;
  list.InsertFirst(1);
  list.InsertBefore(2, 1);
  EXPECT_EQ(list.GetCurr()->data, 2);
  EXPECT_EQ(list.GetCurr()->pNext->data, 1);
}

TEST(TList, check_correct_insert_before_some_element)
{
  TList<int> list;
  list.InsertFirst(1);
  list.InsertFirst(6);
  list.InsertBefore(2, 6);
  EXPECT_EQ(list.GetCurr()->data, 2);
  EXPECT_EQ(list.GetCurr()->pNext->data, 6);
}

TEST(TList, check_correct_insert_after_last)
{
  TList<int> list;
  list.InsertFirst(1);
  list.InsertFirst(6);
  list.InsertAfter(2, 1);
  EXPECT_EQ(list.GetCurr()->data, 2);
  EXPECT_TRUE(list.GetCurr()->pNext == nullptr);
}

TEST(TList, check_correct_insert_after_some_element)
{
  TList<int> list;
  list.InsertFirst(1);
  list.InsertFirst(6);
  list.InsertAfter(2, 6);
  EXPECT_EQ(list.GetCurr()->data, 2);
  EXPECT_EQ(list.GetCurr()->pNext->data, 1);
}

// Search tests:
TEST(TList, check_correct_search)
{
  TList<float> list;
  list.InsertLast(1.6f);
  list.InsertFirst(3.0f);
  TNode<float>* search_res = list.Search(1.6f);
  EXPECT_NEAR(1.6f, search_res->data, 0.001f);
}

TEST(TList, check_search_with_empty_list)
{
  TList<int> list;
  TNode<int>* search_res = list.Search(2);
  EXPECT_TRUE(search_res == nullptr);
}

TEST(TList, check_search_nonexistant_element)
{
  TList<float> list;
  list.InsertLast(1.6f);
  list.InsertFirst(3.0f);
  TNode<float>* search_res = list.Search(4.0f);
  EXPECT_TRUE(nullptr == search_res);
}

//Navigation tests:
TEST(TList, next_element)
{
	TList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(2);
	list.Next();
	EXPECT_EQ(1, list.GetCurr()->data);
}

TEST(TList, reset_test) 
{
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.Reset();
	EXPECT_EQ(1, list.GetCurr()->data);
}