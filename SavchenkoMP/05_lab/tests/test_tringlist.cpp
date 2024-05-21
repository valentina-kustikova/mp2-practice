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

	list.InsertFirst(1);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
}

TEST(TRingList, InsertionFirstTest_NotEmptyList) {
	TRingList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(1);
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
}

// SearchTest
TEST(TRingList, SearchTest_EmptyList) {
	TRingList<int> list;

	EXPECT_EQ(nullptr, list.Search(1));
}

TEST(TRingList, SearchTest_NotFound) {
	TRingList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	EXPECT_EQ(nullptr, list.Search(4));
}

TEST(TRingList, SearchTest_FirstInList) {
	TRingList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(1);
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
}

TEST(TRingList, SearchTest_SecondInList) {
	TRingList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(2);
	EXPECT_EQ(2, tmp->data);
	EXPECT_EQ(3, tmp->pNext->data);
}

TEST(TRingList, SearchTest_ThirdInList) {
	TRingList<int> list;
	TNode<int>* tmp;
	list.InsertFirst(3);
	list.InsertFirst(2);
	list.InsertFirst(1);

	tmp = list.Search(3);
	EXPECT_EQ(3, tmp->data);
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

	EXPECT_EQ(1, tmp->data);
}

TEST(TRingList, InsertionLastTest_NotEmptyList) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
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
TEST(TRingList, ClearTest) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	EXPECT_NO_THROW(list.Clear());
}

TEST(TRingList, ClearTest_SizeCheck) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Clear();

	EXPECT_EQ(0, list.GetSize());
}

TEST(TRingList, ClearTest_InsertAfterClear) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Clear();

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
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

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
}

TEST(TRingList, InsertionBeforeTest_FoundFirst) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertBefore(10, 1);
	tmp = list.Search(10);

	EXPECT_EQ(10, tmp->data);
	EXPECT_EQ(1, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
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

	EXPECT_EQ(2, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
}

TEST(TRingList, InsertionAfterTest_FoundLast) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertAfter(10, 3);
	tmp = list.Search(3);

	EXPECT_EQ(3, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
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

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
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

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
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

	EXPECT_EQ(nullptr, list.Search(1));
	EXPECT_EQ(2, tmp->data);
	EXPECT_EQ(3, tmp->pNext->data);
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

	EXPECT_EQ(nullptr, list.Search(2));
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(3, tmp->pNext->data);
	EXPECT_EQ(4, tmp->pNext->pNext->data);
}

TEST(TRingList, RemovalTest_Last) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Remove(3);

	tmp = list.Search(1);

	EXPECT_EQ(nullptr, list.Search(3));
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
}


// NAVIGATION
// GetCurrentTest
TEST(TRingList, GetCurrentTest) {
	TRingList<int> list;

	EXPECT_NO_THROW(list.GetCurrent());
}

TEST(TRingList, GetCurrentTest_BeforeReset) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(1, tmp->data);
}

TEST(TRingList, GetCurrentTest_AfterReset) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.Reset();
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(1, tmp->data);
}

// ResetTest
TEST(TRingList, ResetTest) {
	TRingList<int> list;
	list.InsertLast(1);

	EXPECT_NO_THROW(list.Reset());
}

TEST(TRingList, ResetTest_Empty) {
	TRingList<int> list;

	TNode<int>* tmp = list.GetCurrent();
}

TEST(TRingList, ResetTest_NotEmpty) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(1, tmp->data);
}

// NextTest
TEST(TRingList, NextTest_BeforeReset) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.Next();
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(2, tmp->data);
}

TEST(TRingList, NextTest_AfterReset) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.Reset();
	list.Next();
	list.Next();
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(3, tmp->data);
}

TEST(TRingList, NextTest_MultipleNext) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.InsertLast(4);

	list.Next(3);
	TNode<int>* tmp = list.GetCurrent();

	EXPECT_EQ(4, tmp->data);
}

// IsEndedTest
TEST(TRingList, IsEnded_NotEnded_BeforeReset) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);

	EXPECT_EQ(false, list.IsEnded());
}

TEST(TRingList, IsEnded_NotEnded_AfterReset) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.Reset();

	EXPECT_EQ(false, list.IsEnded());
}

TEST(TRingList, IsEnded_LastNode) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.Reset();
	list.Next();

	EXPECT_EQ(false, list.IsEnded());
}

TEST(TRingList, IsEnded_Ended) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.Reset();
	list.Next();
	list.Next();

	EXPECT_EQ(true, list.IsEnded());
}

// InsertBeforeTest
TEST(TRingList, InsertBeforeTest_BeforeNext) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertBefore(10);
	TNode<int>* tmp = list.Search(10);

	EXPECT_EQ(10, tmp->data);
	EXPECT_EQ(1, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
}

TEST(TRingList, InsertBeforeTest_AfterNext) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Next();

	list.InsertBefore(10);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
}

// InsertAfterTest
TEST(TRingList, InsertAfterTest_BeforeNext) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);

	list.InsertAfter(10);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
}

TEST(TRingList, InsertAfterTest_AfterNext_AtMiddle) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Next();

	list.InsertAfter(10);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(10, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
}

TEST(TRingList, InsertAfterTest_AfterNext_AtEnd) {
	TRingList<int> list;
	list.InsertLast(1);
	list.InsertLast(2);
	list.InsertLast(3);
	list.Next();
	list.Next();

	list.InsertAfter(10);
	TNode<int>* tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
	EXPECT_EQ(10, tmp->pNext->pNext->pNext->data);
}

TEST(TRingList, RingTest) {
	TRingList<int> list;
	TNode<int>* tmp;

	list.InsertLast(1);
	list.InsertLast(2);

	tmp = list.Search(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(1, tmp->pNext->pNext->pNext->data);
}