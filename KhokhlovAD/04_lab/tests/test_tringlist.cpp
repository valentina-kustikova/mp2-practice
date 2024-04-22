#include "tringlist.h"
#include <gtest.h>

//constructors
///////////////////////////////////////
TEST(TRingList, can_create_list)
{
	ASSERT_NO_THROW(TRingList<int> a);
}

TEST(TRingList, can_copy_ring_list)
{
	TRingList<int> a;
	ASSERT_NO_THROW(TRingList<int> b(a));
}

TEST(TRingList, can_copy_node)
{
	TNode<int>* a = new TNode<int>(2);
	ASSERT_NO_THROW(TRingList<int> b(a));
}
///////////////////////////////////////


//bool
///////////////////////////////////////
TEST(TRingList, empty_list_is_empty)
{
	TRingList<int> a;
	ASSERT_TRUE(a.IsEmpty());
}

TEST(TRingList, not_empty_list_isnt_empty)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	ASSERT_FALSE(b.IsEmpty());
}

TEST(TRingList, empty_list_isnt_fool)
{
	TRingList<int> a;
	ASSERT_FALSE(a.IsFool());
}

TEST(TRingList, not_empty_list_isnt_fool)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	ASSERT_FALSE(b.IsFool());
}

TEST(TRingList, empty_list_isend)
{
	TRingList<int> a;
	ASSERT_TRUE(a.IsEnd());
}

TEST(TRingList, one_elem_list_isntend)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	ASSERT_FALSE(b.IsEnd());
}

TEST(TRingList, one_elem_list_isend)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	b.Next();
	ASSERT_TRUE(b.IsEnd());
}
///////////////////////////////////////


//search
///////////////////////////////////////
TEST(TRingList, search)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	b.InsertLast(3);
	ASSERT_NO_THROW(b.search(2));
}
///////////////////////////////////////

//insert
///////////////////////////////////////
TEST(TRingList, insert_first)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	int c = 3;
	b.InsertFirst(c);
	ASSERT_EQ(b.get_pFirst(), c);
}

TEST(TRingList, insert_last)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	int c = 3;
	b.InsertLast(c);
	ASSERT_EQ(b.get_pLast(), c);
}

TEST(TRingList, insert_before)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertFirst(3);
	c.InsertBefore(4, c.search(a->data));
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}

TEST(TRingList, insert_after)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertLast(3);
	c.InsertAfter(4, c.search(a->data));
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}

TEST(TRingList, insert_before_current)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertLast(3);
	c.Next();
	c.InsertBeforeCurrent(4);
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}

TEST(TRingList, insert_after_current)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertLast(3);
	c.InsertAfterCurrent(4);
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}
///////////////////////////////////////

//delete
///////////////////////////////////////
TEST(TRingList, delete_first)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertFirst(3);
	ASSERT_NO_THROW(c.DeleteFirst());
}

TEST(TRingList, delete_first1)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertFirst(3);
	c.DeleteFirst();
	ASSERT_ANY_THROW(c.search(3));
}

TEST(TRingList, delete_last)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertLast(3);
	ASSERT_NO_THROW(c.DeleteLast());
}

TEST(TRingList, delete_last1)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertLast(3);
	c.DeleteLast();
	ASSERT_ANY_THROW(c.search(3));
}

TEST(TRingList, delete_before)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertLast(3);
	TNode<int>* d = c.search(3);
	ASSERT_NO_THROW(c.DeleteBefore(d));
}

TEST(TRingList, delete_before1)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertLast(3);
	TNode<int>* d = c.search(3);
	c.DeleteBefore(d);
	ASSERT_ANY_THROW(c.search(2));
}


TEST(TRingList, delete_after)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertFirst(3);
	TNode<int>* d = c.search(3);
	ASSERT_NO_THROW(c.DeleteAfter(d));
}

TEST(TRingList, delete_after1)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertFirst(3);
	TNode<int>* d = c.search(3);
	c.DeleteAfter(d);
	ASSERT_ANY_THROW(c.search(2));
}

TEST(TRingList, delete_data)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertFirst(3);
	ASSERT_NO_THROW(c.DeleteData(2));
}

TEST(TRingList, delete_data1)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> c(a);
	c.InsertFirst(3);
	c.DeleteData(2);
	ASSERT_ANY_THROW(c.search(2));
}
///////////////////////////////////////


//=
///////////////////////////////////////
TEST(TRingList, operato)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	ASSERT_NO_THROW(TRingList<int> c = b);
}
///////////////////////////////////////

//sort
///////////////////////////////////////
TEST(TRingList, sort)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	b.InsertFirst(3);
	ASSERT_NO_THROW(b.Sort());
}

TEST(TRingList, sort1)
{
	TNode<int>* a = new TNode<int>(2);
	TRingList<int> b(a);
	b.InsertFirst(3);
	b.Sort();
	ASSERT_TRUE(b.get_pFirst() <= b.get_pLast());
}
///////////////////////////////////////


