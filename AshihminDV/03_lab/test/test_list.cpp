#include "list.h"
#include <gtest.h>

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> l);
}

TEST(TList, can_create_list_with_firs_elem)
{
	ASSERT_NO_THROW(TList<int> l(123));
}

TEST(TList, can_insert_back_elem_in_empty_list)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	ASSERT_NO_THROW(l.insert_Back(n1));
}

TEST(TList, can_insert_front_elem_in_empty_list)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	ASSERT_NO_THROW(l.insert_Front(n1));
}

TEST(TList, cant_insert_front_nullptr_in_not_empty_list)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	l.insert_Front(n1);
	ASSERT_ANY_THROW(l.insert_Front(nullptr));
}

TEST(TList, can_find_an_existing_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	l.insert_Front(n1);
	ASSERT_NO_THROW(l.search(123));
}

TEST(TList, cant_find_an_not_existing_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	l.insert_Front(n1);
	ASSERT_ANY_THROW(l.search(321));
}

TEST(TList, can_insert_after_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	ListNode<int>* n2 = new ListNode<int>(213);
	ASSERT_NO_THROW(l.insert_After(n2, 123));
}

TEST(TList, cant_insert_after_not_existing_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	ListNode<int>* n2 = new ListNode<int>(213);
	ASSERT_ANY_THROW(l.insert_After(n2, 888));
}

TEST(TList, can_insert_before_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	ListNode<int>* n2 = new ListNode<int>(213);
	ASSERT_NO_THROW(l.insert_Before(n2, 123));
}

TEST(TList, cant_insert_before_not_existing_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	ListNode<int>* n2 = new ListNode<int>(213);
	ASSERT_ANY_THROW(l.insert_Before(n2, 888));
}

TEST(TList, can_remove_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	ASSERT_NO_THROW(l.remove(123));
}

TEST(TList, cant_remove_not_existing_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	ASSERT_ANY_THROW(l.remove(888));
}

TEST(TList, can_remove_first_element)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	ASSERT_NO_THROW(l.Remove_First());
}

TEST(TList, cant_remove_first_element_in_empty_list)
{
	TList<int> l;
	ASSERT_ANY_THROW(l.Remove_First());
}

/*TEST(TList, equal_lists_are_equal)
{
	TList<int> l;
	ListNode<int>* n1 = new ListNode<int>(123);
	n1->next = new ListNode<int>(321);
	l.insert_Front(n1);
	TList<int> l2;
	l2.insert_Front(n1);
	EXPECT_EQ(l ,l2);

}*/ //?