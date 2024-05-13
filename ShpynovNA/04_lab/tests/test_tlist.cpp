#include "theadringlist.h"
#include <gtest.h>
#include <vector>
template<typename TData> class TestTList : public TList<TData> {
public:
	TestTList():TList() {}
	TestTList(const TestTList<TData>&l) :TList(l) {}
	TestTList(TNode<TData>*n):TList(*n) {}
	using TList<TData>::pFirst;
	using TList<TData>::pLast;
	using TList<TData>::pCurrent;
	using TList<TData>::pStop;
};

template<typename TData> class TestRingTList : public THeadRingList<TData> {
public:
	TestRingTList() :THeadRingList() {}
	TestRingTList(const THeadRingList<TData>& l) :THeadRingList(l) {}
	TestRingTList(TNode<TData>* n) :THeadRingList(*n) {}
	using THeadRingList<TData>::pFirst;
	using THeadRingList<TData>::pLast;
	using THeadRingList<TData>::pCurrent;
	using THeadRingList<TData>::pStop;
};



TEST(TNode, can_create_node) {
	ASSERT_NO_THROW(TNode<int>());
}
TEST(TNode, can_create_node1) {
	ASSERT_NO_THROW(TNode<int>(0));
}
TEST(TNode, can_create_node2) {
	ASSERT_NO_THROW(TNode<int>(0,0));
}



TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int>());
}
TEST(TList, can_create_list_from_node) {
	TNode<int> node(0);
	ASSERT_NO_THROW(TList<int>(*node));
}
TEST(TList, can_copy_list) {
	TList<int> list;
	ASSERT_NO_THROW(TList<int>(list));
}
TEST(TList, can_insert_into_list) {
	TestTList<int> list;
	list.InsertFirst(1);
	EXPECT_EQ(list.pFirst->data, 1);
}
TEST(TList, list_copy_correct) {
	TList<int> tmp;
	tmp.InsertLast(1);
	tmp.InsertLast(2);
	tmp.InsertLast(3);
	tmp.InsertLast(4);
	TList<int> tmp1 = tmp;
	EXPECT_EQ(tmp, tmp1);
}
TEST(TList, list_insert_first_correct) {
	TestTList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(3);
	EXPECT_EQ(list.pFirst->data, 3);
}
TEST(TList, list_insert_last_correct) {
	TestTList<int> list;
	list.InsertFirst(1);
	list.InsertLast(3);
	EXPECT_EQ(list.pLast->data, 3);
}
TEST(TList, list_insert_before_correct) {
	TestTList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(3);
	list.InsertFirst(5);
	list.InsertBefore(3, 4);
	EXPECT_EQ(list.pFirst->pNext->data, 4);
}
TEST(TList, list_insert_after_correct) {
	TestTList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(3);
	list.InsertFirst(5);
	list.InsertAfter(3, 4);
	EXPECT_EQ(list.pFirst->pNext->pNext->data, 4);
}
TEST(TList, list_clear_correct) {
	TestTList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(3);
	list.InsertFirst(5);
	list.clear();
	EXPECT_EQ(list.pFirst, nullptr);
}
TEST(TList, el_delete_correct) {
	TestTList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(3);
	list.InsertFirst(5);
	TNode<int>* tmp = list.pFirst->pNext;
	list.DeleteNode(tmp);
	EXPECT_EQ(list.pFirst->pNext->data, 1);
}
TEST(TList, list_compare_correct) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(3);
	list.InsertFirst(5);
	TList<int> list1 = list;
	ASSERT_TRUE(list == list1);
}



TEST(THeadRingList, can_create_ring_list) {
	ASSERT_NO_THROW(TestRingTList<int>());
}
TEST(THeadRingList, insert_first_correct) {
	TestRingTList<int> tmp;
	tmp.InsertFirst(3);
	tmp.InsertFirst(1);
	EXPECT_EQ(tmp.pFirst->data, 1);
}
TEST(THeadRingList, insert_last_correct) {
	TestRingTList<int> tmp;
	tmp.InsertFirst(3);
	tmp.InsertFirst(5);
	tmp.InsertLast(1);
	EXPECT_EQ(tmp.pLast->data, 1);
}
TEST(THeadRingList, can_assign_Ring_list) {
	TestRingTList<int> tmp;
	std::vector<int> A;
	std::vector<int> B;
	for (int i = 1; i < 8; i += 2) {
		tmp.InsertLast(i);
		A.push_back(i);
	}
	TestRingTList<int> tmp1;
	tmp1 = tmp;
	tmp1.reset();
	int i = 0;
	while (!tmp1.IsEnded()) {
		B.push_back(tmp1.pCurrent->data);
		i++;
		tmp1.next();
	}
	EXPECT_EQ(A, B);
}
TEST(THeadRingList, el_delete_correct) {
	TestRingTList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(3);
	list.InsertFirst(5);
	TNode<int>* tmp = list.pFirst->pNext;
	list.DeleteNode(tmp);
	EXPECT_EQ(list.pFirst->pNext->data, 1);
}