#include <gtest.h>

#include "tlist.h"

/*
TEST(TList, TEST_NAME) {

}
*/


// DefaultConstructorTest
TEST(TList, DefaultConstructorTest) {
	ASSERT_NO_THROW(TList<int> list);
}

// InsertionFirstTest
TEST(TList, InsertionFirstTest) {
	TList<int> list;

	ASSERT_NO_THROW(list.InsertFirst(1));
}

TEST(TList, InsertionFirstTest_EmptyList) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertFirst(1);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(nullptr, tmp->pNext);
}

TEST(TList, InsertionFirstTest_NotEmptyList) {
	TList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

// SearchTest
TEST(TList, SearchTest_EmptyList) {
	TList<int> list;

	EXPECT_EQ(nullptr, list.Search(1));
}

TEST(TList, SearchTest_NotFound) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	EXPECT_EQ(nullptr, list.Search(4));
}

TEST(TList, SearchTest_FirstInList) {
	TList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);
	
	tmp = list.Search(1);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

TEST(TList, SearchTest_SecondInList) {
	TList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(2);
	EXPECT_EQ(2, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

TEST(TList, SearchTest_ThirdInList) {
	TList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(3);
	EXPECT_EQ(3, tmp->key);
	EXPECT_EQ(nullptr, tmp->pNext);
}

// InsertionLastTest
TEST(TList, InsertionLastTest) {
	TList<int> list;

	ASSERT_NO_THROW(list.InsertFirst(1));
}

TEST(TList, InsertionLastTest_EmptyList) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(nullptr, tmp->pNext);
}

TEST(TList, InsertionLastTest_NotEmptyList) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

// IsEmptyTest
TEST(TList, IsEmptyTest_Empty) {
	TList<int> list;

	EXPECT_EQ(true, list.IsEmpty());

}

TEST(TList, IsEmptyTest_NotEmpty) {
	TList<int> list;
	list.InsertFirst(1);

	EXPECT_EQ(false, list.IsEmpty());

}

// GetSizeTest
TEST(TList, GetSizeTest_Empty) {
	TList<int> list;

	EXPECT_EQ(0, list.GetSize());
}

TEST(TList, GetSizeTest_NotEmpty) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_EQ(3, list.GetSize());
}

// ClearTest
TEST(TList, GetSizeTest) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_NO_THROW(list.Clear());
}

TEST(TList, GetSizeTest_SizeCheck) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Clear();

	EXPECT_EQ(0, list.GetSize());
}


// InsertionBeforeTest
TEST(TList, InsertionBeforeTest_NotFound) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_ANY_THROW(list.InsertBefore(10, 4));
}

TEST(TList, InsertionBeforeTest_Found) {
	TList<int> list;
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

TEST(TList, InsertionBeforeTest_FoundFirst) {
	TList<int> list;
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
TEST(TList, InsertionAfterTest_NotFound) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_ANY_THROW(list.InsertAfter(10, 4));
}

TEST(TList, InsertionAfterTest_Found) {
	TList<int> list;
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

TEST(TList, InsertionAfterTest_FoundLast) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertAfter(10, 3);
	tmp = list.Search(3);

	EXPECT_EQ(3, tmp->key);
	EXPECT_EQ(10, tmp->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

// CopyConstructorTest
TEST(TList, CopyConstructorTest_List_Empty) {
	TList<int> expl;
	TNode<int>* exp;

	TList<int> list(expl);

	EXPECT_EQ(true, list.IsEmpty());
}

TEST(TList, CopyConstructorTest_List_NotEmpty) {
	TList<int> expl;

	expl.InsertLast(1);
	expl.InsertLast(2);
	expl.InsertLast(3);

	TList<int> list(expl);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

TEST(TList, CopyConstructorTest_Node_Empty) {
	TNode<int>* pFirst = nullptr;

	TList<int> list(pFirst);

	EXPECT_EQ(true, list.IsEmpty());
}

TEST(TList, CopyConstructorTest_Node_NotEmpty) {
	TNode<int>* pFirst = new TNode<int>(1);
	pFirst->pNext = new TNode<int>(2);
	pFirst->pNext->pNext = new TNode<int>(3);

	TList<int> list(pFirst);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

// RemovalTest
TEST(TList, RemovalTest_First) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(1);

	tmp = list.Search(2);

	EXPECT_EQ(nullptr, list.Search(1));
	EXPECT_EQ(2, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

TEST(TList, RemovalTest_Middle) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);
	list.Remove(2);

	tmp = list.Search(1);

	EXPECT_EQ(nullptr, list.Search(2));
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(3, tmp->pNext->key);
	EXPECT_EQ(4, tmp->pNext->pNext->key);
}

TEST(TList, RemovalTest_Last) {
	TList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(3);

	tmp = list.Search(1);

	EXPECT_EQ(nullptr, list.Search(3));
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}


// NOVOGATION
// GetCurrentTest
TEST(TList, GetCurrentTest) {
	TList<int> list;

	EXPECT_NO_THROW(list.GetCurrent());
}

TEST(TList, GetCurrentTest_NullptrInEmpty) {
	TList<int> list;
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(nullptr, tmp);
}

TEST(TList, GetCurrentTest_BeforeReset) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(1, tmp->key);
}

TEST(TList, GetCurrentTest_AfterReset) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.Reset();
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(1, tmp->key);
}

// ResetTest
TEST(TList, ResetTest) {
	TList<int> list;
	list.InsertLast(1);
	
	EXPECT_NO_THROW(list.Reset());
}

TEST(TList, ResetTest_Empty) {
	TList<int> list;
	
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(nullptr, tmp);
}

TEST(TList, ResetTest_NotEmpty) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(1, tmp->key);
}

// NextTest
TEST(TList, NextTest_BeforeReset) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.Next();
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(2, tmp->key);
}

TEST(TList, NextTest_AfterReset) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.Reset();
	list.Next();
	list.Next();
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(3, tmp->key);
}

TEST(TList, NextTest_MultipleNext) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);

	list.Next(3);
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(4, tmp->key);
}

// IsEndedTest
TEST(TList, IsEnded_NotEnded_BeforeReset) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);

	EXPECT_EQ(false, list.IsEnded());
}

TEST(TList, IsEnded_NotEnded_AfterReset) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.Reset();

	EXPECT_EQ(false, list.IsEnded());
}

TEST(TList, IsEnded_Ended) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.Reset();
	list.Next();

	EXPECT_EQ(true, list.IsEnded());
}

// InsertBeforeTest
TEST(TList, InsertBeforeTest_BeforeNext) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertBefore(10);
	TNode<int>* curr = list.GetCurrent();
	TNode<int>* tmp = list.Search(10);

	EXPECT_EQ(1, curr->key);
	EXPECT_EQ(10, tmp->key);
	EXPECT_EQ(1, tmp->pNext->key);
	EXPECT_EQ(2, tmp->pNext->pNext->key);
}

TEST(TList, InsertBeforeTest_AfterNext) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Next();

	list.InsertBefore(10);
	TNode<int>* curr = list.GetCurrent();
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(2, curr->key);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(10, tmp->pNext->key);
	EXPECT_EQ(2, tmp->pNext->pNext->key);
}

// InsertAfterTest
TEST(TList, InsertAfterTest_BeforeNext) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertAfter(10);
	TNode<int>* curr = list.GetCurrent();
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, curr->key);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(10, tmp->pNext->key);
	EXPECT_EQ(2, tmp->pNext->pNext->key);
}

TEST(TList, InsertAfterTest_AfterNext_AtMiddle) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Next();

	list.InsertAfter(10);
	TNode<int>* curr = list.GetCurrent();
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(2, curr->key);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(10, tmp->pNext->pNext->key);
}

TEST(TList, InsertAfterTest_AfterNext_AtEnd) {
	TList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Next();
	list.Next();

	list.InsertAfter(10);
	TNode<int>* curr = list.GetCurrent();
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(3, curr->key);
	EXPECT_EQ(1, tmp->key);
	EXPECT_EQ(2, tmp->pNext->key);
	EXPECT_EQ(3, tmp->pNext->pNext->key);
	EXPECT_EQ(10, tmp->pNext->pNext->pNext->key);
}

