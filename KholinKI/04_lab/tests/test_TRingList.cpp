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

TEST(TRingList, insert_last_control_pLast_and_pStop) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(5);
	rList->insert_last(2);
	rList->insert_last(7);
	
	Node<int>* test = rList->search(7);
	Node<int>* tmp_last = rList->GetPLast();
	Node<int>* tmp_pStop = rList->GetPStop();
	Node<int>* tmp_pFirst = rList->GetPFirst();

	ASSERT_TRUE(test->data == 7 && test == tmp_last
				&& test->pNext == tmp_pStop && tmp_pStop->pNext == tmp_pFirst);
}

TEST(TRingList, insert_last_control_pLast_and_pStop_when_list_empty) {
	Node<int>* pFirst = new Node<int>();
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_last(7);

	Node<int>* test = rList->search(7);
	Node<int>* tmp_last = rList->GetPLast();
	Node<int>* tmp_pStop = rList->GetPStop();
	Node<int>* tmp_pFirst = rList->GetPFirst();

	ASSERT_TRUE(test->data == 7 && test == tmp_last
		&& test->pNext == tmp_pStop && tmp_pStop->pNext == tmp_pFirst);
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

TEST(TRingList, insert_first_control_pFirst_and_pStop_and_pCurr) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_first(5);
	rList->insert_first(6);
	rList->insert_first(8);

	Node<int>* test = rList->search(8);
	Node<int>* tmp_pFirst = rList->GetPFirst();
	Node<int>* tmp_pStop = rList->GetPStop();
	Node<int>* tmp_pCurr = rList->GetCurrent();
	ASSERT_TRUE(test->data == 8 && test == tmp_pFirst
				&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst);
}

TEST(TRingList, insert_first_control_pFirst_and_pStop_and_pCurr_when_list_empty) {
	Node<int>* pFirst = new Node<int>();
	TRingList<int>* rList = new TRingList<int>(pFirst);

	rList->insert_first(5);

	Node<int>* test = rList->search(5);
	Node<int>* tmp_pFirst = rList->GetPFirst();
	Node<int>* tmp_pStop = rList->GetPStop();
	Node<int>* tmp_pCurr = rList->GetCurrent();
	ASSERT_TRUE(test->data == 5 && test == tmp_pFirst
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst);
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

TEST(TRingList, insert_before_first_node_and_control_pFirst_and_pStop_and_pCurr) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_first(1);
	rList.insert_first(12);
	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(7, 12);

	Node<int>* test = rList.search(7);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();

	ASSERT_TRUE(test->data == 7 && test == tmp_pFirst
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst);
}

TEST(TRingList, a_lot_inserts_before_control_pFirst_and_pStop_and_pCurr) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_first(1);
	rList.insert_first(12);
	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(7, 12);
	rList.insert_before(9, 2);
	rList.insert_before(80, 1);
	rList.insert_before(54, 9);
	rList.insert_before(15, 7);


	Node<int>* test = rList.search(15);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();

	ASSERT_TRUE(test->data == 15 && test == tmp_pFirst
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst);
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

TEST(TRingList, insert_after_last_node_and_control_pLast_and_pStop_and_pFirst) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_first(1);
	rList.insert_first(12);
	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(7, 12);
	rList.insert_after(20, 5);

	Node<int>* test = rList.search(20);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();

	ASSERT_TRUE(test->data == 20 && test == tmp_pLast
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst);
}

TEST(TRingList, a_lot_inserts_after_control_pLast_and_pStop_and_pFirst) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_first(1);
	rList.insert_first(12);
	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(7, 12);
	rList.insert_after(20, 5);
	rList.insert_after(21, 12);
	rList.insert_after(22, 7);
	rList.insert_after(23, 20);

	Node<int>* test = rList.search(23);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();

	ASSERT_TRUE(test->data == 23 && test == tmp_pLast
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst);
}

TEST(TRingList, remove_work) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);

	rList.insert_after(4, 5);

	ASSERT_NO_THROW(rList.remove(5));
}

TEST(TRingList, remove_first_node_and_control_all_pointers) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(6, 10);
	rList.insert_after(4, 5);
	
	rList.remove(6);

	Node<int>* test = rList.search(10);
	Node<int>* deleted_node = rList.search(6);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();

	ASSERT_TRUE(test->data == 10 && test == tmp_pFirst
				&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst
				&& tmp_pLast->pNext == tmp_pStop);
	EXPECT_EQ(nullptr, deleted_node);
}


TEST(TRingList, remove_last_node_and_control_all_pointers) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(6, 10);
	rList.insert_after(4, 5);

	rList.remove(4);

	Node<int>* test = rList.search(5);
	Node<int>* deleted_node = rList.search(4);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();

	ASSERT_TRUE(test->data == 5 && test == tmp_pLast
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst
		&& tmp_pLast->pNext == tmp_pStop);
	EXPECT_EQ(nullptr, deleted_node);
}

TEST(TRingList, a_lot_remove_last_node_and_control_all_pointers) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(6, 10);
	rList.insert_after(4, 5);

	rList.remove(4);
	rList.remove(2);//6 5 
	rList.remove(10);

	Node<int>* test = rList.search(5);
	Node<int>* test2 = rList.search(6);
	Node<int>* deleted_node1 = rList.search(4);
	Node<int>* deleted_node2 = rList.search(10);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();

	ASSERT_TRUE(test->data == 5 && test == tmp_pLast
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst
		&& tmp_pLast->pNext == tmp_pStop);
	ASSERT_TRUE(test2->data == 6 && test2 == tmp_pFirst
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst
		&& tmp_pLast->pNext == tmp_pStop);
	ASSERT_TRUE(deleted_node1 == nullptr && deleted_node2 == nullptr);
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

	ASSERT_NO_THROW(delete rList;);
}

TEST(TRingList, inserts_and_search_after_clear) {
	Node<int>* pFirst = new Node<int>(10);
	TRingList<int> rList(pFirst);

	rList.insert_last(2);
	rList.insert_last(5);
	rList.insert_before(6, 10);
	rList.insert_after(4, 5);

	rList.clear();


	rList.insert_first(4);
	rList.insert_last(7);
	rList.insert_first(9);
	rList.insert_first(12);
	rList.insert_last(90);
	rList.insert_before(40,90);
	rList.insert_after(99,9);

	Node<int>* test = rList.search(12);
	Node<int>* test2 = rList.search(90);

	Node<int>* tmp_pFirst = rList.GetPFirst();
	Node<int>* tmp_pStop = rList.GetPStop();
	Node<int>* tmp_pCurr = rList.GetCurrent();
	Node<int>* tmp_pLast = rList.GetPLast();
	
	ASSERT_TRUE(test->data == 12 && test == tmp_pFirst
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst
		&& tmp_pLast->pNext == tmp_pStop);
	ASSERT_TRUE(test2->data == 90 && test2 == tmp_pLast
		&& tmp_pStop->pNext == tmp_pFirst && tmp_pCurr == tmp_pFirst
		&& tmp_pLast->pNext == tmp_pStop);
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

	Node<int>* tmp = rList->GetCurrent();

	ASSERT_TRUE(tmp->data == 33);
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

	Node<int>* tmp = rList->GetCurrent();

	ASSERT_TRUE(tmp->data == 80);
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

	Node<int>* tmp = rList->GetCurrent();
	Node<int>* tmp_pStop = rList->GetPStop();
	while (tmp != tmp_pStop) {
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

	ASSERT_TRUE(rList->Is_Begin());
}








