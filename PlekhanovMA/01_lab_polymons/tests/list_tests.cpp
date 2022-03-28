#include <gtest.h>
#include "list.h"
#include "monom.h"

TEST(TList, can_create_list)
{
	TList list;
	ASSERT_NO_THROW();
}

TEST(TList, can_copy_list)
{
	TList list;
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	TMonom* monom2 = new TMonom(2, 7, 4, 6.0f);
	list.InsertToTail(monom1->data);
	list.InsertToTail(monom2->data);
	TList list2 = list;
	ASSERT_NO_THROW();
}

TEST(TList, can_search_element)
{
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	TMonom* monom2 = new TMonom(1, 2, 3, 5.0f);
	TList list(monom1);
	TMonom* monom3 = new TMonom();
	monom3 = list.Search(monom1->data);
	ASSERT_TRUE(monom3->data == monom2->data);
}

TEST(TList, can_insert_element_in_begin)
{
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	TMonom* monom2 = new TMonom(4, 4, 4, 5.0f);
	TList list;
	list.InsertToHead(monom1->data);
	list.InsertToHead(monom2->data);
	TMonom* monom3 = new TMonom();
	monom3 = list.Search(monom2->data);
	ASSERT_TRUE(monom3->data == monom2->data);
}

TEST(TList, can_insert_element_in_end)
{
	TMonom* monom1 = new TMonom(1, 2, 3, 5.0f);
	TMonom* monom2 = new TMonom(4, 4, 4, 5.0f);
	TList list;
	list.InsertToTail(monom1->data);
	list.InsertToTail(monom2->data);
	TMonom* monom3 = new TMonom();
	monom3 = list.Search(monom2->data);
	ASSERT_TRUE(monom3->data == monom2->data);
}

TEST(TList, can_insert_element_after_this)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	TMonom* monom3 = new TMonom(6, 6, 6, 10.0f);
	TMonom* monom4 = new TMonom();
	TList list;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.InsertAfter(monom1->data, monom3->data);
	monom4 = list.Search(monom3->data);
	ASSERT_TRUE(monom4->data == monom3->data);
}

TEST(TList, can_delete_first_element)
{
	TMonom* monom1 = new TMonom(2, 2, 5, 6.0f);
	TMonom* monom2 = new TMonom(3, 5, 8, 7.0f);
	TList list;
	TList list2;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.RemoveFirst();
	list2.InsertToTail(monom2->data);
	ASSERT_TRUE(list == list2);
}

TEST(TList, can_delete_last_element)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(1, 1, 1, 3.0f);
	TList list;
	TList list2;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.RemoveLast();
	list2.InsertToTail(monom1->data);
	ASSERT_TRUE(list == list2);
}

TEST(TList, can_delete_this_element)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	TMonom* monom3 = new TMonom(6, 5, 4, 1.0f);
	TList list;
	TList list2;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.InsertToTail(monom3->data);
	list2.InsertToTail(monom1->data);
	list2.InsertToTail(monom3->data);
	list.Remove(monom2);
	ASSERT_TRUE(list == list2);
}

TEST(TList, can_get_size_of_list)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	TList list;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	int size = list.GetLenght();
	ASSERT_TRUE(size == 2);
}

TEST(TList, can_clear_list)
{
	TMonom* monom1 = new TMonom(3, 2, 1, 6.0f);
	TMonom* monom2 = new TMonom(5, 5, 5, 7.0f);
	TList list;
	list.InsertToHead(monom1->data);
	list.InsertToTail(monom2->data);
	list.Clear();
	ASSERT_TRUE(list.IsEmpty());
}
