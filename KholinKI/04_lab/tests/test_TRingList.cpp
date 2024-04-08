#include "TRingList.h"
#include <gtest.h>

#define count_links 4

TEST(TRingList, constructor_default_work) {
	ASSERT_NO_THROW(TRingList<int>*rList = new TRingList<int>());
}

TEST(TRingList, constructor_with_parameter_work) {
	Node<int>* pFirst = new Node<int>(10);

	ASSERT_NO_THROW(TRingList<int>* rList = new TRingList<int>(pFirst));
}


TEST(TRingList, constructor_copy_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);


	ASSERT_NO_THROW(TRingList<int> rList_copy(rList));
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

TEST(TRingList, search_when_node_found_last) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(5);
	rList->insert_last(7);
	rList->insert_last(3);

	Node<int>* test = rList->search(3);

	ASSERT_TRUE(test != nullptr);
}

TEST(TRingList, search_when_node_found_first) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(5);
	rList->insert_last(7);
	rList->insert_last(3);

	Node<int>* test = rList->search(10);

	ASSERT_TRUE(test != nullptr);
}

TEST(TRingList, search_when_node_found_middle) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(5);
	rList->insert_last(7);
	rList->insert_last(3);

	Node<int>* test = rList->search(5);

	ASSERT_TRUE(test != nullptr);
}

TEST(TRingList, search_when_node_not_found) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(5);
	rList->insert_last(7);
	rList->insert_last(3);

	Node<int>* test = rList->search(12);

	ASSERT_TRUE(test == nullptr);
}


TEST(TRingList, search_inserted_data) {
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

TEST(TRingList, insert_before_work){
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	ASSERT_NO_THROW(rList.insert_before(6, 2));
}

TEST(TRingList, insert_before_check_values) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_first(1);
	rList.insert_first(12);
	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(7, 2);

	Node<int>* test = rList.search(7);

	ASSERT_TRUE(test->data == 7);
}

TEST(TRingList, insert_before_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_before(6, 2);
	rList.insert_before(4, 2);
	rList.insert_before(20, 10);
	rList.insert_before(30, 10);

	Node<int>* t1 = rList.search(6);
	Node<int>* t2 = rList.search(30);

	ASSERT_TRUE(t1->data == 6 && t2->data == 30);
}

TEST(TRingList, insert_after_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_after(4, 5);

	ASSERT_NO_THROW(rList.insert_after(4, 5));
}


TEST(TRingList, insert_after_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_after(4, 5);
	rList.insert_after(6, 5);
	rList.insert_after(7, 5);
	rList.insert_after(8, 5);

	Node<int>* t1 = rList.search(6);
	Node<int>* t2 = rList.search(8);

	ASSERT_TRUE(t1->data == 6 && t2->data == 8);
	
}

TEST(TRingList, remove_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_after(4, 5);

	ASSERT_NO_THROW(rList.remove(5));
}


TEST(TRingList, count_nodes) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(6, 10);
	rList.insert_after(4, 5);

	rList.remove(4);
	rList.remove(2);//6 5 
	rList.remove(10);

	int count = rList.GetSize();
	EXPECT_EQ(2, count);
}

TEST(TRingList, count_nodes_when_all_deleted) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(6, 10);
	rList.insert_after(4, 5);

	rList.remove(4);
	rList.remove(2);
	rList.remove(10);
	rList.remove(5);
	rList.remove(6);

	int count = rList.GetSize();
	EXPECT_EQ(0, count);
}

TEST(TRingList, different_memory) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_first(3);

	TRingList<int> rList_copy(rList);
	rList_copy.insert_first(7);

	ASSERT_TRUE(&rList != &rList_copy);
}

TEST(TRingList, destructor_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	rList->remove(5);

	ASSERT_NO_THROW(delete rList);
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
	rList->insert_first(3);
	rList->insert_first(12);
	rList->insert_first(80);
	rList->insert_first(33);
	rList->insert_after(4, 5);

	ASSERT_TRUE(rList->getCurrent()->data == 33);
}

TEST(TRingList, navigation_part_2_next_data) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);
	rList->insert_first(3);
	rList->insert_first(12);
	rList->insert_first(80);
	rList->insert_first(33);
	rList->insert_after(4, 5);

	rList->next();


	ASSERT_TRUE(rList->getCurrent()->data == 80);
}

TEST(TRingList, navigation_part_3_use_next_method_while_not_reached_end) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);
	rList->insert_first(3);
	rList->insert_first(12);
	rList->insert_first(80);
	rList->insert_first(33);
	rList->insert_after(4, 5);


	Node<int>* tmp_pStop = rList->pStop;
	while (!rList->Is_Ended()) {
		rList->next();
	}

	
	ASSERT_TRUE(rList->Is_Ended());
}


TEST(TRingList, navigation_part_4_reset_current_pointer) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(2);
	rList->insert_last(5);

	rList->insert_after(4, 5);

	while (!rList->Is_Ended()) {
		rList->next();
	}

	if (rList->Is_Ended()) {
		rList->reset();
	}

	ASSERT_TRUE(rList->getCurrent() == rList->pFirst);
}








