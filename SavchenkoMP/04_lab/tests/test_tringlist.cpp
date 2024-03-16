#include <gtest.h>

#include "tringlist.h"

/*
TEST(TRingList, TEST_NAME) {

}
*/






// DefaultConstructorTest
TEST(TRingList, DefaultConstructorTest) {
	ASSERT_NO_THROW(TRingList<int> list);
}

// InsertionFirstTest
TEST(TRingList, InsertionFirstTest) {
	TRingList<int> list;

	ASSERT_NO_THROW(list.InsertFirst(1));
}

TEST(TRingList, InsertionFirstTest_EmptyList) {
	TRingList<int> list;
	TNode<int>* tmp;
	TNode<int>* stop = list.stop();

	list.InsertFirst(1);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(stop, tmp->pNext);
}

TEST(TRingList, InsertionFirstTest_NotEmptyList) {
	TRingList<int> list;
	TNode<int>* tmp;
	TNode<int>* stop = list.stop();

	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(stop, tmp->pNext->pNext);
}

// SearchTest
TEST(TRingList, SearchTest_EmptyList) {
	TRingList<int> list;
	TNode<int>* stop = list.stop();

	EXPECT_EQ(stop, list.Search(1));
}

TEST(TRingList, SearchTest_NotFound) {
	TRingList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	EXPECT_EQ(list.stop(), list.Search(4));
}

TEST(TRingList, SearchTest_FirstInList) {
	TRingList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext->pNext);
}

TEST(TRingList, SearchTest_SecondInList) {
	TRingList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(2);
	EXPECT_EQ(2, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext);
}

TEST(TRingList, SearchTest_ThirdInList) {
	TRingList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(3);
	EXPECT_EQ(3, tmp->key);
	EXPECT_EQ(list.stop(), tmp->pNext);
}

// InsertionLastTest
TEST(TRingList, InsertionLastTest) {
	TRingList<int> list;

	ASSERT_NO_THROW(list.InsertFirst(1));
}

TEST(TRingList, InsertionLastTest_EmptyList) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(list.stop(), tmp->pNext);
}

TEST(TRingList, InsertionLastTest_NotEmptyList) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext->pNext);
}

// IsEmptyTest
TEST(TRingList, IsEmptyTest_Empty) {
	TRingList<int> list;

	EXPECT_EQ(true, list.IsEmpty());

}

TEST(TRingList, IsEmptyTest_NotEmpty) {
	TRingList<int> list;
	list.InsertFirst(1);

	EXPECT_EQ(false, list.IsEmpty());

}

// GetSizeTest
TEST(TRingList, GetSizeTest_Empty) {
	TRingList<int> list;

	EXPECT_EQ(0, list.GetSize());
}

TEST(TRingList, GetSizeTest_NotEmpty) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_EQ(3, list.GetSize());
}

// ClearTest
TEST(TRingList, GetSizeTest) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_NO_THROW(list.Clear());
}

TEST(TRingList, GetSizeTest_SizeCheck) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Clear();

	EXPECT_EQ(0, list.GetSize());
}

TEST(TRingList, ClearTest_pHeadCheck) {
	TRingList<int> list;
	TNode<int>* stop = list.stop();
	
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	
	list.Clear();

	EXPECT_EQ(stop, list.stop());
}


// InsertionBeforeTest
TEST(TRingList, InsertionBeforeTest_NotFound) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_ANY_THROW(list.InsertBefore(10, 4));
}

TEST(TRingList, InsertionBeforeTest_Found) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertBefore(10, 2);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(10, tmp->pNext->key);
	EXPECT_EQ(2, tmp->pNext->pNext->key);
}

TEST(TRingList, InsertionBeforeTest_FoundFirst) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertBefore(10, 1);
	tmp = list.Search(10);

	EXPECT_EQ(10, tmp->key);
	EXPECT_EQ(1, tmp->pNext->key);
	EXPECT_EQ(2, tmp->pNext->pNext->key);
}

// InsertionAfterTest
TEST(TRingList, InsertionAfterTest_NotFound) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_ANY_THROW(list.InsertAfter(10, 4));
}

TEST(TRingList, InsertionAfterTest_Found) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertAfter(10, 2);
	tmp = list.Search(2);

	EXPECT_EQ(2, tmp->key);
	EXPECT_EQ(10, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
}

TEST(TRingList, InsertionAfterTest_FoundLast) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertAfter(10, 3);
	tmp = list.Search(3);

	EXPECT_EQ(3, tmp->key);
	EXPECT_EQ(10, tmp->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext);
}

// CopyConstructorTest
TEST(TRingList, CopyConstructorTest_List_Empty) {
	TRingList<int> expl;
	TNode<int>* exp;

	TRingList<int> list(expl);

	EXPECT_EQ(true, list.IsEmpty());
}

TEST(TRingList, CopyConstructorTest_List_NotEmpty) {
	TRingList<int> expl;

	expl.InsertLast(1);
	expl.InsertLast(2);
	expl.InsertLast(3);

	TRingList<int> list(expl);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext->pNext);
}
 
TEST(TRingList, CopyConstructorTest_Node_Empty) {
	TNode<int>* pFirst = nullptr;

	TRingList<int> list(pFirst);

	EXPECT_EQ(true, list.IsEmpty());
}

TEST(TRingList, CopyConstructorTest_Node_NotEmpty) {
	TNode<int>* pFirst = new TNode<int>(1);
	pFirst->pNext = new TNode<int>(2);
	pFirst->pNext->pNext = new TNode<int>(3);

	TRingList<int> list(pFirst);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext->pNext);
}

// RemovalTest
TEST(TRingList, RemovalTest_First) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(1);

	tmp = list.Search(2);

	EXPECT_EQ(list.stop(), list.Search(1));
	EXPECT_EQ(2, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext);
}

TEST(TRingList, RemovalTest_Middle) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);
	list.Remove(2);

	tmp = list.Search(1);

	EXPECT_EQ(list.stop(), list.Search(2));
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(4, tmp->pNext->pNext->key);
}

TEST(TRingList, RemovalTest_Last) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(3);

	tmp = list.Search(1);

	EXPECT_EQ(list.stop(), list.Search(3));
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(list.stop(), tmp->pNext->pNext);
}
