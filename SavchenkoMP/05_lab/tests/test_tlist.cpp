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

	ASSERT_NO_THROW(list.insert_first(1));
}

TEST(TList, InsertionFirstTest_EmptyList) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_first(1);
	tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(nullptr, tmp->pNext);
}

TEST(TList, InsertionFirstTest_NotEmptyList) {
	TList<int> list;
	TNode<int>* tmp;
	list.insert_first(2);
	list.insert_first(1);

	tmp = list.find(1);
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

// SearchTest
TEST(TList, SearchTest_EmptyList) {
	TList<int> list;

	EXPECT_EQ(nullptr, list.find(1));
}

TEST(TList, SearchTest_NotFound) {
	TList<int> list;
	list.insert_first(3);
	list.insert_first(2);
	list.insert_first(1);

	EXPECT_EQ(nullptr, list.find(4));
}

TEST(TList, SearchTest_FirstInList) {
	TList<int> list;
	TNode<int>* tmp;
	list.insert_first(3);
	list.insert_first(2);
	list.insert_first(1);

	tmp = list.find(1);
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

TEST(TList, SearchTest_SecondInList) {
	TList<int> list;
	TNode<int>* tmp;
	list.insert_first(3);
	list.insert_first(2);
	list.insert_first(1);

	tmp = list.find(2);
	EXPECT_EQ(2, tmp->data);
	EXPECT_EQ(3, tmp->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

TEST(TList, SearchTest_ThirdInList) {
	TList<int> list;
	TNode<int>* tmp;
	list.insert_first(3);
	list.insert_first(2);
	list.insert_first(1);

	tmp = list.find(3);
	EXPECT_EQ(3, tmp->data);
	EXPECT_EQ(nullptr, tmp->pNext);
}

// InsertionLastTest
TEST(TList, InsertionLastTest) {
	TList<int> list;

	ASSERT_NO_THROW(list.insert_first(1));
}

TEST(TList, InsertionLastTest_EmptyList) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(nullptr, tmp->pNext);
}

TEST(TList, InsertionLastTest_NotEmptyList) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

// IsEmptyTest
TEST(TList, IsEmptyTest_Empty) {
	TList<int> list;

	EXPECT_EQ(true, list.empty());

}

TEST(TList, IsEmptyTest_NotEmpty) {
	TList<int> list;
	list.insert_first(1);

	EXPECT_EQ(false, list.empty());

}

// GetSizeTest
TEST(TList, GetSizeTest_Empty) {
	TList<int> list;

	EXPECT_EQ(0, list.size());
}

TEST(TList, GetSizeTest_NotEmpty) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	EXPECT_EQ(3, list.size());
}

// ClearTest
TEST(TList, ClearTest) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	EXPECT_NO_THROW(list.clear());
}

TEST(TList, ClearTest_SizeCheck) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.clear();

	EXPECT_EQ(0, list.size());
}

TEST(TList, ClearTest_InsertAfterClear) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.clear();

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	TNode<int>* tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}


// InsertionBeforeTest
TEST(TList, InsertionBeforeTest_NotFound) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	EXPECT_ANY_THROW(list.insert_before(10, 4));
}

TEST(TList, InsertionBeforeTest_Found) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.insert_before(10, 2);
	tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
}

TEST(TList, InsertionBeforeTest_FoundFirst) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.insert_before(10, 1);
	tmp = list.find(10);

	EXPECT_EQ(10, tmp->data);
	EXPECT_EQ(1, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
}

// InsertionAfterTest
TEST(TList, InsertionAfterTest_NotFound) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	EXPECT_ANY_THROW(list.insert_after(10, 4));
}

TEST(TList, InsertionAfterTest_Found) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.insert_after(10, 2);
	tmp = list.find(2);

	EXPECT_EQ(2, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
}

TEST(TList, InsertionAfterTest_FoundLast) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.insert_after(10, 3);
	tmp = list.find(3);

	EXPECT_EQ(3, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

// CopyConstructorTest
TEST(TList, CopyConstructorTest_List_Empty) {
	TList<int> expl;
	TNode<int>* exp;

	TList<int> list(expl);

	EXPECT_EQ(true, list.empty());
}

TEST(TList, CopyConstructorTest_List_NotEmpty) {
	TList<int> expl;

	expl.insert_last(1);
	expl.insert_last(2);
	expl.insert_last(3);

	TList<int> list(expl);
	TNode<int>* tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

TEST(TList, CopyConstructorTest_Node_Empty) {
	TNode<int>* pFirst = nullptr;

	TList<int> list(pFirst);

	EXPECT_EQ(true, list.empty());
}

TEST(TList, CopyConstructorTest_Node_NotEmpty) {
	TNode<int>* pFirst = new TNode<int>(1);
	pFirst->pNext = new TNode<int>(2);
	pFirst->pNext->pNext = new TNode<int>(3);

	TList<int> list(pFirst);
	TNode<int>* tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext);
}

// RemovalTest
TEST(TList, RemovalTest_First) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.remove(1);

	tmp = list.find(2);

	EXPECT_EQ(nullptr, list.find(1));
	EXPECT_EQ(2, tmp->data);
	EXPECT_EQ(3, tmp->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}

TEST(TList, RemovalTest_Middle) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.insert_last(4);
	list.remove(2);

	tmp = list.find(1);

	EXPECT_EQ(nullptr, list.find(2));
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(3, tmp->pNext->data);
	EXPECT_EQ(4, tmp->pNext->pNext->data);
}

TEST(TList, RemovalTest_Last) {
	TList<int> list;
	TNode<int>* tmp;

	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.remove(3);

	tmp = list.find(1);

	EXPECT_EQ(nullptr, list.find(3));
	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext);
}


// NAVIGATION
// GetCurrentTest
TEST(TList, GetCurrentTest) {
	TList<int> list;

	EXPECT_NO_THROW(list.get_curr());
}

TEST(TList, GetCurrentTest_NullptrIfEmpty) {
	TList<int> list;
	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(nullptr, tmp);
}

TEST(TList, GetCurrentTest_BeforeReset) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(1, tmp->data);
}

TEST(TList, GetCurrentTest_AfterReset) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.reset();
	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(1, tmp->data);
}

// ResetTest
TEST(TList, ResetTest) {
	TList<int> list;
	list.insert_last(1);

	EXPECT_NO_THROW(list.reset());
}

TEST(TList, ResetTest_Empty) {
	TList<int> list;

	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(nullptr, tmp);
}

TEST(TList, ResetTest_NotEmpty) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(1, tmp->data);
}

// NextTest
TEST(TList, NextTest_BeforeReset) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.next();
	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(2, tmp->data);
}

TEST(TList, NextTest_AfterReset) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.reset();
	list.next();
	list.next();
	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(3, tmp->data);
}

TEST(TList, NextTest_MultipleNext) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.insert_last(4);

	list.next(3);
	TNode<int>* tmp = list.get_curr();

	EXPECT_EQ(4, tmp->data);
}

// IsEndedTest
TEST(TList, IsEnded_NotEnded_BeforeReset) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);

	EXPECT_EQ(false, list.ended());
}

TEST(TList, IsEnded_NotEnded_AfterReset) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.reset();

	EXPECT_EQ(false, list.ended());
}

TEST(TList, IsEnded_LastNode) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.reset();
	list.next();

	EXPECT_EQ(false, list.ended());
}

TEST(TList, IsEnded_Ended) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.reset();
	list.next();
	list.next();

	EXPECT_EQ(true, list.ended());
}

// InsertBeforeTest
TEST(TList, InsertBeforeTest_BeforeNext) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.insert_before(10);
	TNode<int>* tmp = list.find(10);

	EXPECT_EQ(10, tmp->data);
	EXPECT_EQ(1, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext->pNext);
}

TEST(TList, InsertBeforeTest_AfterNext) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.next();

	list.insert_before(10);
	TNode<int>* tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext->pNext);
}

// InsertAfterTest
TEST(TList, InsertAfterTest_BeforeNext) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);

	list.insert_after(10);
	TNode<int>* tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(10, tmp->pNext->data);
	EXPECT_EQ(2, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext->pNext);
}

TEST(TList, InsertAfterTest_AfterNext_AtMiddle) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.next();

	list.insert_after(10);
	TNode<int>* tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(10, tmp->pNext->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext->pNext);
}

TEST(TList, InsertAfterTest_AfterNext_AtEnd) {
	TList<int> list;
	list.insert_last(1);
	list.insert_last(2);
	list.insert_last(3);
	list.next();
	list.next();

	list.insert_after(10);
	TNode<int>* tmp = list.find(1);

	EXPECT_EQ(1, tmp->data);
	EXPECT_EQ(2, tmp->pNext->data);
	EXPECT_EQ(3, tmp->pNext->pNext->data);
	EXPECT_EQ(10, tmp->pNext->pNext->pNext->data);
	EXPECT_EQ(nullptr, tmp->pNext->pNext->pNext->pNext);
}

