#include <gtest.h>
#include "headlist.h"

TEST(THeadList, can_create_new_list)
{
	ASSERT_NO_THROW(THeadList<int> t);
}

TEST(THeadList, new_created_list_IsEmpty)
{
	THeadList<int> t;
	ASSERT_TRUE(t.IsEmpty());
}

TEST(THeadList, created_list_via_copy_ctor_is_correct) {
	THeadList<int> list;
	list.Insert(5);
	THeadList<int> list1(list);
	list.Reset();
	list1.Reset();
	EXPECT_EQ(list.get_current()->data, list1.get_current()->data);
}

TEST(THeadList, not_empty_list_IsNotEmpty)
{
	THeadList<int> t;
	t.InsertInEnd(10);
	ASSERT_TRUE(!t.IsEmpty());
}

TEST(THeadList, added_elem_in_empty_list_is_correct) {
	THeadList<int> list;
	list.Insert(10);
	list.Reset();
	EXPECT_EQ(10, list.get_current()->data);
}

TEST(THeadList, can_add_elem_in_not_empty_list) {
	THeadList<int> list;
	list.Insert(54);
	ASSERT_NO_THROW(list.Insert(5));
}

TEST(THeadList, can_copy_assign_list) {
	THeadList<int> list;
	list.Insert(5);
	THeadList<int> list1;
	ASSERT_NO_THROW(list1 = list);
}

TEST(THeadList, copy_assigned_list_is_correct) {
	THeadList<int> list;
	list.Insert(5);
	THeadList<int> list1;
	list1 = list;
	EXPECT_EQ(list, list1);
}

TEST(THeadList, can_InsFirst_element)
{
	THeadList<int> t;
	t.InsFirst(1); t.InsFirst(2);
	t.InsFirst(3);
	ASSERT_NO_THROW(t.InsFirst(4));
}

TEST(THeadList, can_DelFirst_empty_list)
{
	THeadList<int> t;
	t.Reset();
	ASSERT_ANY_THROW(t.DelFirst(););
}

TEST(THeadList, can_DelFirst)
{
	THeadList<int> t;
	t.Insert(1); t.Insert(2);
	t.Insert(3); t.Insert(4);
	t.Reset();
	ASSERT_NO_THROW(t.DelFirst(););
}

TEST(THeadList, can_Delete)
{
	THeadList<int> t;
	t.Insert(1); t.Insert(2);
	t.Insert(3); t.Insert(4);
	t.Reset();
	t.Delete(1);
	ASSERT_NO_THROW(t.Delete(1));
}

