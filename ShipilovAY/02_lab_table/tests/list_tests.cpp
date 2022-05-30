#include <gtest.h>
#include "list.h"

TEST(TList, can_create_new_list)
{
	ASSERT_NO_THROW(TList<int> t);
}

TEST(TList, can_create_list_via_node_ptr)
{
	ASSERT_NO_THROW(TList<int>{new TNode<int>(5, nullptr)});
}

TEST(TList, new_created_list_IsEmpty)
{
	TList<int> t;
	ASSERT_TRUE(t.IsEmpty());
}

TEST(TList, can_add_elem_in_empty_list) {
	TList<int> list;
	ASSERT_NO_THROW(list.Insert(5));
}

TEST(TList, added_elem_in_empty_list_is_correct) {
	TList<int> list;
	list.Insert(5);
	list.Reset();
	EXPECT_EQ(5, list.get_current()->data);
}

TEST(TList, can_add_elem_in_not_empty_list) {
	TList<int> list;
	list.Insert(4);
	ASSERT_NO_THROW(list.Insert(5));
}

TEST(TList, added_elem_in_not_empty_list_is_correct) {
	TList<int> list;
	list.Insert(4);
	list.Insert(5);
	list.Reset();
	EXPECT_EQ(5, list.get_current()->data);
}

TEST(TList, no_error_when_delete_from_empty_list) {
	TList<int> list;
	ASSERT_NO_THROW(list.Delete(5));
}

TEST(TList, no_error_when_remove_non_exist_elem) {
	TList<int> list;
	list.Insert(4);
	ASSERT_NO_THROW(list.Delete(5));
}

TEST(TList, can_delete_elem) {
	TList<int> list;
	list.Insert(5);
	ASSERT_NO_THROW(list.Delete(5));
}

TEST(TList, delete_elem_is_correct) {
	TList<int> list;
	list.Insert(5);
	list.Delete(5);
	EXPECT_EQ(nullptr, list.get_current());
}

TEST(TList, delete_head_is_correct) {
	TList<int> list;
	list.Insert(4);
	list.Insert(5);
	list.Delete(5);
	list.Reset();
	EXPECT_EQ(4, list.get_current()->data);
}

TEST(TList, delete_tail_is_correct) {
	TList<int> list;
	list.Insert(5);
	list.Insert(4);
	list.Delete(5);
	list.Reset();
	EXPECT_EQ(nullptr, list.get_current()->pNext);
}

TEST(TList, can_assign_list) {
	TList<int> list;
	list.Insert(5);
	TList<int> list1;
	ASSERT_NO_THROW(list1 = list);
}

TEST(List, assigned_list_is_correct) {
	TList<int> list;
	list.Insert(5);
	TList<int> list1;
	list1 = list;
	list.Reset();
	list1.Reset();
	EXPECT_EQ(list.get_current()->data, list1.get_current()->data);
}

TEST(TList, not_empty_list_IsNotEmpty)
{
	TList<int> list;
	list.InsertInEnd(10);
	ASSERT_TRUE(!list.IsEmpty());
}

TEST(TList, can_InsFirst_element)
{
	TList<int> list;
	list.InsFirst(1); list.InsFirst(2);
	list.InsFirst(3);
	ASSERT_NO_THROW(list.InsFirst(4));
}

TEST(TList, can_InsLast_element)
{
	TList<int> list;
	list.InsFirst(1);
	list.InsFirst(3);
	list.Reset();
	list.GetNext();
	ASSERT_NO_THROW(list.InsLast(2));
}

TEST(TList, can_InsAfter_element)
{
	TList<int> list;
	list.InsFirst(1);
	list.InsFirst(2);
	list.Reset();
	list.GetNext();
	ASSERT_NO_THROW(list.InsAfter(3));
}

TEST(TList, can_InsertInEnd_element)
{
	TList<int> list;
	list.InsFirst(1);
	list.Reset();
	list.InsAfter(2);
	ASSERT_NO_THROW(list.InsertInEnd(3));
}

TEST(TList, can_DelFirst_one)
{
	TList<int> list;
	list.Reset();
	ASSERT_ANY_THROW(list.DelFirst());
}

TEST(TList, can_DelFirst_two)
{
	TList<int> list;
	list.Insert(1); list.Insert(2);
	list.Insert(3); list.Insert(4);
	list.Reset();
	ASSERT_NO_THROW(list.DelFirst());
}

TEST(TList, can_DelLast_one)
{
	TList<int> list;
	list.Insert(1);
	list.Reset();
	list.DelLast();
	ASSERT_ANY_THROW(list.DelLast());
}

TEST(TList, can_DelLast_two)
{
	TList<int> list;
	list.Insert(1); list.Insert(2);
	list.Insert(3); list.Insert(4);
	list.Reset();
	list.DelLast();
	ASSERT_NO_THROW(list.DelLast());
}

TEST(TList, can_DelAfter_one)
{
	TList<int> list;
	list.Insert(1);
	list.Reset();
	list.DelAfter();
	ASSERT_ANY_THROW(list.DelAfter());
}

TEST(TList, can_DelAfter_two)
{
	TList<int> list;
	list.Insert(1); list.Insert(2);
	list.Insert(3); list.Insert(4);
	list.Reset();
	list.DelAfter();
	ASSERT_NO_THROW(list.DelAfter());
}

TEST(TList, can_specific_delete)
{
	TList<int> list;
	list.Insert(1); list.Insert(2);
	list.Insert(3); list.Insert(4);
	list.Reset();
	ASSERT_NO_THROW(list.Delete(1));
}

TEST(TList, can_search_delete)
{
	TList<int> list;
	list.Insert(1); list.Insert(2);
	list.Insert(3); list.Insert(4);
	list.Reset();
	list.Delete(2);
	ASSERT_NO_THROW(list.Search(2));
}

TEST(TList, can_GetNext_and_Copy)
{
	TList<int> list;
	TList<int> list1;
	list.Insert(1); list.Insert(2);
	list.Insert(3); list.Insert(4);
	list1 = list;
	list.Reset();
	list1.Reset();
	list1.GetNext();
	list.Delete(4);
	ASSERT_NO_THROW(list.get_current()->data, list1.get_current()->data);
}

TEST(TList, can_search)
{
	TList<int> list;
	list.Insert(1); list.Insert(2);
	list.Insert(3); list.Insert(4);
	list.Reset();
	ASSERT_NO_THROW(list.Search(2));
}

TEST(TList, check_sheet_for_equality)
{
	TList<int> list;
	TList<int> list1;
	list.Insert(1);
	list.Insert(2);
	list1.Insert(1);
	list1.Insert(2);
	ASSERT_TRUE(list == list1);
}

TEST(TList, check_sheet_for_equality_1)
{
	TList<int> list;
	TList<int> list1;
	list.Insert(1);
	list.Insert(4);
	list1.Insert(1);
	list1.Insert(2);
	ASSERT_TRUE(list != list1);
}

TEST(TList, can_delete_not__empty_list)
{
	TList<int> list;
	list.Insert(1);
	list.Insert(2);
	list.Reset();
	list.Delete(1);
	list.Delete(2);
	ASSERT_TRUE(list.IsEmpty());
}