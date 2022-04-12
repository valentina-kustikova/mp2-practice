#include <gtest.h>
#include "headlist.h"
#include "monom.h"

TEST(THeadList, can_create_list)
{
	THeadList list;
	ASSERT_NO_THROW();
}

TEST(THeadList, can_copy_list)
{
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	THeadList list;
	list.InsertToTail(monom1->data);
	THeadList list2 = list;
	ASSERT_TRUE(list == list2);
}

TEST(THeadList, can_search_element)
{
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	TMonom* monom2 = new TMonom(4, 5, 6, 7.0f);
	THeadList list;
	list.InsertToTail(monom1->data);
	list.InsertToTail(monom2->data);
	TNode* node = new TNode();
	node = list.Search(monom2->data);
	ASSERT_TRUE(monom2->data == node->data);
}

TEST(THeadList, can_insert_element_in_begin)
{
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	TMonom* monom2 = new TMonom(4, 4, 4, 5.0f);
	THeadList list;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	TNode* node2 = new TNode();
	node2 = list.GetFirst();
	ASSERT_TRUE(node2->data == monom1->data);
}

TEST(THeadList, can_insert_element_in_end)
{
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	TMonom* monom2 = new TMonom(4, 4, 4, 5.0f);
	THeadList list;
	list.InsertToTail(monom1->data);
	list.InsertToTail(monom2->data);
	TNode* node = new TNode();
	node = list.GetLast();
	ASSERT_TRUE(node->data == monom2->data);
}

TEST(THeadList, can_insert_element_after_this)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	TMonom* monom3 = new TMonom(6, 6, 6, 10.0f);
	TNode* node = new TNode();
	THeadList list;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.InsertAfter(monom1->data, monom3->data);
	node = list.GetNext();
	ASSERT_TRUE(node->data == monom3->data);
}

TEST(THeadList, can_delete_first_element)
{
	TMonom* monom1 = new TMonom(2, 2, 5, 6.0f);
	TMonom* monom2 = new TMonom(3, 5, 8, 7.0f);
	THeadList list;
	THeadList list2;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.RemoveFirst();
	list2.InsertToTail(monom2->data);
	ASSERT_TRUE(list == list2);
}

TEST(THeadList, can_delete_last_element)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(1, 1, 1, 3.0f);
	THeadList list;
	THeadList list2;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.RemoveLast();
	list2.InsertToTail(monom1->data);
	ASSERT_TRUE(list == list2);
}

TEST(THeadList, can_delete_this_element)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	TMonom* monom3 = new TMonom(6, 5, 4, 1.0f);
	THeadList list;
	THeadList list2;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.InsertToTail(monom3->data);
	list2.InsertToTail(monom1->data);
	list2.InsertToTail(monom3->data);
	list.Remove(monom2->data);
	ASSERT_TRUE(list == list2);
}

TEST(THeadList, can_get_size_of_list)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	THeadList list;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	int size = list.GetLenght();
	ASSERT_TRUE(size == 2);
}

TEST(THeadList, can_clear_list)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	THeadList list;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.Clear();
	ASSERT_TRUE(list.IsEmpty());
}
