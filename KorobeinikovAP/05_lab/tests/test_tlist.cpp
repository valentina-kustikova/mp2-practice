#include "tlist.h"

#include <gtest.h>

TEST(TList, can_create_empty_list)
{
	ASSERT_NO_THROW(TList<int> s() );
}


TEST(TList, can_create_list_from_pfirst)
{
	TNode<int> *c = new TNode<int>(54, nullptr);
	TNode<int> *b = new TNode<int>(53, c);
	TNode<int> *a = new TNode<int>(52, b);

	ASSERT_NO_THROW(TList<int> l(a));
}

TEST(TList, copied_list_from_pfirst_has_its_own_memory)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	EXPECT_NE(b, l.Search(53));
}


TEST(TList, can_copied_list)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	
	ASSERT_NO_THROW(TList<int> l1(l));
}


TEST(TList, copied_list_has_its_own_memory)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);

	TList<int> l1(l);

	EXPECT_NE(l.Search(53), l1.Search(53));
}



TEST(TList, can_search_node_in_list)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);

	EXPECT_EQ(b->data, l.Search(53)->data);

}

TEST(TList, can_search_last_node_in_list)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);

	EXPECT_EQ(c->data, l.Search(54)->data);
}


TEST(TList, throw_when_search_non_existan_node)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);

	ASSERT_ANY_THROW(l.Search(55));
}



TEST(TList, can_insert_pFirst)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.InsertFirst(51));
}

TEST(TList, correct_work_insert_pFirst)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	l.InsertFirst(51);
	TNode<int>* tmp = l.Search(51);
	EXPECT_EQ(tmp->data, 51);
}

TEST(TList, can_insert_before)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(51, b);

	TList<int> l(a);
	ASSERT_NO_THROW (l.InsertBefore(52, 53));
}

TEST(TList, can_insert_before_pFirst)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.InsertBefore(51, 52));
}

TEST(TList, correct_work_insert_before_pFirst)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	l.InsertBefore(51, 52);

	TNode<int>* tmp = l.GetCurrent();
	EXPECT_EQ(51, tmp->data);
}

TEST(TList, throw_when_insert_before_non_existant_node)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_ANY_THROW(l.InsertBefore(51, 100));

}



TEST(TList, can_insert_after)
{
	TNode<int>* c = new TNode<int>(55, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.InsertAfter(54, 53));
}



TEST(TList, correct_work_insert_after)
{
	TNode<int>* c = new TNode<int>(55, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	l.InsertAfter(54, 53);
	EXPECT_EQ(55, l.Search(54)->pNext->data);
}

TEST(TList, can_insert_after_first)
{
	TNode<int>* c = new TNode<int>(55, nullptr);
	TNode<int>* b = new TNode<int>(54, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.InsertAfter(53, 52));
}


TEST(TList, can_insert_after_last)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.InsertAfter(55, 54));
}


TEST(TList, can_insert_before_current)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.InsertBefore(51));
}


TEST(TList, correct_work_insert_before_current)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	l.InsertBefore(51);
	EXPECT_EQ(52, l.Search(51)->pNext->data);
}

TEST(TList, can_insert_after_current)
{
	TNode<int>* c = new TNode<int>(55, nullptr);
	TNode<int>* b = new TNode<int>(54, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.InsertAfter(53));
}


TEST(TList, correct_work_insert_after_current)
{
	TNode<int>* c = new TNode<int>(55, nullptr);
	TNode<int>* b = new TNode<int>(54, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	l.InsertAfter(53);
	EXPECT_EQ(54, l.Search(53)->pNext->data);
}

TEST(TList, can_remove_node) {
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.Remove(53));
}

TEST(TList, can_remove_first_node) {
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.Remove(52));
}


TEST(TList, can_remove_last_node) {
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(l.Remove(54));
}

TEST(TList, throw_when_remove_non_existant_node) {
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_ANY_THROW(l.Remove(100));
}

TEST(TList, correct_work_GetSize) {
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);


	TNode<int>* a5 = new TNode<int>(5, nullptr);
	TNode<int>* a4 = new TNode<int>(4, a5);
	TNode<int>* a3 = new TNode<int>(3, a4);
	TNode<int>* a2 = new TNode<int>(2, a3);
	TNode<int>* a1 = new TNode<int>(1, a2);

	TList<int> l1(a);
	TList<int> l2(a1);

	EXPECT_EQ(l1.GetSize(), 3);
	EXPECT_EQ(l2.GetSize(), 5);
}