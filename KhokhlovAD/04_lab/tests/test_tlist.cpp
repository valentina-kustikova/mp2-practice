#include "tlist.h"
#include <gtest.h>

//constructors
///////////////////////////////////////
TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> a);
}

TEST(TList, can_copy_list)
{
	TList<int> a;
	ASSERT_NO_THROW(TList<int> b(a));
}

TEST(TList, can_copy_node)
{
	TNode<int>* a = new TNode<int>(2);
	ASSERT_NO_THROW(TList<int> b(a));
}

TEST(TList, destructor)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	ASSERT_NO_THROW(b.clear());
}
///////////////////////////////////////


//bool
///////////////////////////////////////
TEST(TList, empty_list_is_empty)
{
	TList<int> a;
	ASSERT_TRUE(a.IsEmpty());
}

TEST(TList, not_empty_list_isnt_empty)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	ASSERT_FALSE(b.IsEmpty());
}

TEST(TList, empty_list_isnt_fool)
{
	TList<int> a;
	ASSERT_FALSE(a.IsFool());
}

TEST(TList, not_empty_list_isnt_fool)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	ASSERT_FALSE(b.IsFool());
}

TEST(TList, empty_list_isend)
{
	TList<int> a;
	ASSERT_TRUE(a.IsEnd());
}

TEST(TList, one_elem_list_isntend)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	ASSERT_FALSE(b.IsEnd());
}

TEST(TList, one_elem_list_isend)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	b.Next();
	ASSERT_TRUE(b.IsEnd());
}
///////////////////////////////////////


//search
///////////////////////////////////////
TEST(TList, search)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	b.InsertLast(3);
	ASSERT_NO_THROW(b.search(2));
}
///////////////////////////////////////

//insert
///////////////////////////////////////
TEST(TList, insert_first)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	int c = 3;
	b.InsertFirst(c);
	ASSERT_EQ(b.get_pFirst(), c);
}

TEST(TList, insert_last)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	int c = 3;
	b.InsertLast(c);
	ASSERT_EQ(b.get_pLast(), c);
}

TEST(TList, insert_before)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertFirst(3);
	c.InsertBefore(4, c.search(a->data));
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}

TEST(TList, insert_after)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertLast(3);
	c.InsertAfter(4, c.search(a->data));
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}

TEST(TList, insert_before_current)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertLast(3);
	c.Next();
	c.InsertBeforeCurrent(4);
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}

TEST(TList, insert_after_current)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertLast(3);
	c.InsertAfterCurrent(4);
	c.Next();
	ASSERT_EQ(4, c.get_pCurr());
}
///////////////////////////////////////

//delete
///////////////////////////////////////
TEST(TList, delete_first)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertFirst(3);
	ASSERT_NO_THROW(c.DeleteFirst());
}

TEST(TList, delete_first1)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertFirst(3);
	c.DeleteFirst();
	ASSERT_ANY_THROW(c.search(3));
}

TEST(TList, delete_last)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertLast(3);
	ASSERT_NO_THROW(c.DeleteLast());
}

TEST(TList, delete_last1)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertLast(3);
	c.DeleteLast();
	ASSERT_ANY_THROW(c.search(3));
}

TEST(TList, delete_before)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertLast(3);
	TNode<int>* d = c.search(3);
	ASSERT_NO_THROW(c.DeleteBefore(d));
}

TEST(TList, delete_before1)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertLast(3);
	TNode<int>* d = c.search(3);
	c.DeleteBefore(d);
	ASSERT_ANY_THROW(c.search(2));
}


TEST(TList, delete_after)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertFirst(3);
	TNode<int>* d = c.search(3);
	ASSERT_NO_THROW(c.DeleteAfter(d));
}

TEST(TList, delete_after1)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertFirst(3);
	TNode<int>* d = c.search(3);
	c.DeleteAfter(d);
	ASSERT_ANY_THROW(c.search(2));
}

TEST(TList, delete_data)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertFirst(3);
	ASSERT_NO_THROW(c.DeleteData(2));
}

TEST(TList, delete_data1)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> c(a);
	c.InsertFirst(3);
	c.DeleteData(2);
	ASSERT_ANY_THROW(c.search(2));
}
///////////////////////////////////////


//=
///////////////////////////////////////
TEST(TList, operato )
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	ASSERT_NO_THROW(TList<int> c = b);
}
///////////////////////////////////////

//sort
///////////////////////////////////////
TEST(TList, sort)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	b.InsertFirst(3);
	ASSERT_NO_THROW(b.Sort());
}

TEST(TList, sort1)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	b.InsertFirst(3);
	b.Sort();
	ASSERT_TRUE(b.get_pFirst() <= b.get_pLast());
}
///////////////////////////////////////
