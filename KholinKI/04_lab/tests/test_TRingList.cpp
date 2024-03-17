#include "TRingList.h"
#include <gtest.h>

#define count_links 4

TEST(TRingList, constructor_with_parameter_work) {
	Node<int>* pFirst = new Node<int>(10);

	ASSERT_NO_THROW(TRingList<int>* rList = new TRingList<int>(pFirst));
}

TEST(TRingList, insert_last_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	ASSERT_NO_THROW(rList->insert_last(5));
}


TEST(TRingList, search_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);
	ASSERT_NO_THROW(rList->search(10));
}

TEST(TRingList, insert_search_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);
	rList->insert_last(3);

	EXPECT_TRUE(rList->search(3)->data, 3);
}

TEST(TRingList, insert_first_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	ASSERT_NO_THROW(rList->insert_first(5));
}

TEST(TRingList, constructor_copy_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);


	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_last(3);

	ASSERT_NO_THROW(TRingList<int> rList_copy(rList));
}

TEST(TRingList, insert_before_work){
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	ASSERT_NO_THROW(rList.insert_before(6, 2));
}


TEST(TRingList, insert_before_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_before(6, 2);

	EXPECT_TRUE(rList.search(6)->data, 6);
	ASSERT_TRUE(rList.search(6)->pNext->data, 2);
}

TEST(TRingList, insert_after_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_after(4, 5);

	EXPECT_TRUE(rList.search(4)->data, 4);
	ASSERT_TRUE(rList.search(5)->pNext->data, 4);
	
}

TEST(TRingList, remove_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_after(4, 5);

	ASSERT_NO_THROW(rList.remove(5));
}

TEST(TRingList, check_deleted_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_after(4, 5);

	rList.remove(5);

	EXPECT_EQ(nullptr,rList.search(5));
}

TEST(TRingList, destructor_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	rList->remove(5);

	ASSERT_NO_THROW(delete rList;);
}

TEST(TRingList, Is_Full_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	ASSERT_NO_THROW(rList->IsFull());
}

TEST(TRingList, Is_Full_false) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	ASSERT_FALSE(rList->IsFull());
}
//
//TEST(TRingList, Is_Full_true) {
//	Node<int>* pFirst = new Node<int>(10);
//	TRingList<int>* rList = new TRingList<int>(pFirst);
//
//	rList->insert_last(2);
//	rList->insert_last(5);
//
//	rList->insert_after(4, 5);
//
//	ASSERT_FALSE(rList->IsFull());
//}

TEST(TRingList, Is_Empty_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	ASSERT_NO_THROW(rList->IsEmpty());
}

TEST(TRingList, Is_Empty_true) {
	Node<int>* pFirst = nullptr;
	TRingList<int>* rList = new TRingList<int>(pFirst);

	ASSERT_TRUE(rList->IsEmpty());
}

TEST(TRingList, Is_Empty_false) {
	Node<int>* pFirst = new Node<int>(5);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	ASSERT_FALSE(rList->IsEmpty());
}

TEST(TRingList, navigation_part_1_current_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	ASSERT_TRUE(rList->GetCurrent()->data == 10, 10);
}

TEST(TRingList, navigation_part_2_next_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	rList->next();

	Node<int>* tmp = rList->GetCurrent();

	ASSERT_FALSE(rList->GetCurrent()->data == 10);
}

TEST(TRingList, navigation_part_3_check_end) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	Node<int>* tmp = rList->GetCurrent();

	while (tmp != rList->GetPStop()) {
		rList->next();
		tmp = rList->GetCurrent();
	}

	

	ASSERT_TRUE(rList->Is_End());
}

TEST(TRingList, navigation_part_4_reset_current_pointer) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	Node<int>* tmp = rList->GetCurrent();

	while (tmp != rList->GetPStop()) {
		rList->next();
		tmp = rList->GetCurrent();
	}

	if (rList->Is_End()) {
		rList->reset();
		tmp = rList->GetCurrent();
	}

	ASSERT_TRUE(tmp == rList->GetPFirst());
}








