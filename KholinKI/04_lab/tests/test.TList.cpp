#include <gtest.h>

#include "TList.h"

TEST(List, constructor_default_work) {
	ASSERT_NO_THROW(TList<int>*List = new TList<int>());
}

TEST(List, constructor_with_parameter_work) {
	Node<int>* pFirst = new Node<int>(10);

	ASSERT_NO_THROW(TList<int>*List = new TList<int>(pFirst));
}

TEST(List, constructor_copy_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);


	TList<int> List_copy(List);
}

TEST(List, insert_last_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_NO_THROW(List->insert_last(5));
}

TEST(List, insert_last_control_pLast_and_pStop) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(2);
	List->insert_last(7);

	Node<int>* test = List->search(7);
	List->reset();

	ASSERT_TRUE(test->data == 7 && test == List->pLast
		&& test->pNext == List->pStop);
}

TEST(List, insert_last_control_pLast_and_pStop_when_list_empty) {
	Node<int>* pFirst = new Node<int>();
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(7);

	Node<int>* test = List->search(7);


	ASSERT_TRUE(test->data == 7 && test == List->pLast
		&& test->pNext == List->pStop);
}


TEST(List, search_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);
	ASSERT_NO_THROW(List->search(10));
}

TEST(List, search_when_node_found_last) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	Node<int>* test = List->search(3);

	ASSERT_TRUE(test != nullptr);
}

TEST(List, search_when_node_found_first) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	Node<int>* test = List->search(10);

	ASSERT_TRUE(test != nullptr);
}

TEST(List, search_when_node_found_middle) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	Node<int>* test = List->search(5);

	ASSERT_TRUE(test != nullptr);
}

TEST(List, search_when_node_not_found) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	Node<int>* test = List->search(12);

	ASSERT_TRUE(test == nullptr);
}


TEST(List, search_inserted_data) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);
	List->insert_last(3);

	EXPECT_TRUE(List->search(3)->data, 3);
}

TEST(TList, insert_first_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_NO_THROW(List->insert_first(5));
}

TEST(List, insert_first_control_pFirst_and_pStop_and_pCurr) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_first(5);
	List->insert_first(6);
	List->insert_first(8);

	Node<int>* test = List->search(8);

	ASSERT_TRUE(test->data == 8 && test == List->pFirst && List->pCurr == List->pFirst);
}

TEST(List, insert_first_control_pFirst_and_pStop_and_pCurr_when_list_empty) {
	Node<int>* pFirst = new Node<int>();
	TList<int>* List = new TList<int>(pFirst);

	List->insert_first(5);

	Node<int>* test = List->search(5);

	ASSERT_TRUE(test->data == 5 && test == List->pFirst && List->pCurr == List->pFirst);
}

TEST(List, insert_before_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	ASSERT_NO_THROW(List.insert_before(6, 2));
}

TEST(List, insert_before_check_values) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_first(1);
	List.insert_first(12);
	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(7, 2);

	Node<int>* test = List.search(7);

	ASSERT_TRUE(test->data == 7);
}

TEST(List, insert_before_first_node_and_control_pFirst_and_pStop_and_pCurr) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_first(1);
	List.insert_first(12);
	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(7, 12);

	Node<int>* test = List.search(7);

	ASSERT_TRUE(test->data == 7 && test == List.pFirst && List.pCurr == List.pFirst);
}

TEST(List, a_lot_inserts_before_control_pFirst_and_pStop_and_pCurr) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_first(1);
	List.insert_first(12);
	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(7, 12);
	List.insert_before(9, 2);
	List.insert_before(80, 1);
	List.insert_before(54, 9);
	List.insert_before(15, 7);


	Node<int>* test = List.search(15);


	ASSERT_TRUE(test->data == 15 && test == List.pFirst && List.pCurr == List.pFirst);
}


TEST(List, insert_before_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_before(6, 2);
	List.insert_before(4, 2);
	List.insert_before(20, 10);
	List.insert_before(30, 10);

	Node<int>* t1 = List.search(6);
	Node<int>* t2 = List.search(30);

	ASSERT_TRUE(t1->data == 6 && t2->data == 30);
}

TEST(List, insert_after_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_after(4, 5);

	ASSERT_NO_THROW(List.insert_after(4, 5));
}


TEST(List, insert_after_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_after(4, 5);
	List.insert_after(6, 5);
	List.insert_after(7, 5);
	List.insert_after(8, 5);

	Node<int>* t1 = List.search(6);
	Node<int>* t2 = List.search(8);

	ASSERT_TRUE(t1->data == 6 && t2->data == 8);

}

TEST(List, insert_after_last_node_and_control_pLast_and_pStop_and_pFirst) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_first(1);
	List.insert_first(12);
	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(7, 12);
	List.insert_after(20, 5);

	Node<int>* test = List.search(20);
	List.reset();


	ASSERT_TRUE(test->data == 20 && test == List.pLast && List.pCurr == List.pFirst);
}

TEST(List, a_lot_inserts_after_control_pLast_and_pStop_and_pFirst) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_first(1);
	List.insert_first(12);
	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(7, 12);
	List.insert_after(20, 5);
	List.insert_after(21, 12);
	List.insert_after(22, 7);
	List.insert_after(23, 20);

	Node<int>* test = List.search(23);


	(test->data == 7 && test == List.pLast && List.pCurr == List.pFirst);
}

TEST(List, remove_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_after(4, 5);

	ASSERT_NO_THROW(List.remove(5));
}

TEST(List, remove_first_node_and_control_all_pointers) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(6, 10);
	List.insert_after(4, 5);

	List.remove(6);

	Node<int>* test = List.search(10);
	Node<int>* deleted_node = List.search(6);
	List.reset();

	ASSERT_TRUE(test->data == 10 && test == List.pFirst
				&& List.pCurr == List.pFirst && List.pLast->pNext == List.pStop);
	EXPECT_EQ(nullptr, deleted_node);
}


TEST(List, remove_last_node_and_control_all_pointers) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(6, 10);
	List.insert_after(4, 5);

	List.remove(4);

	Node<int>* test = List.search(5);
	Node<int>* deleted_node = List.search(4);
	List.reset();

	ASSERT_TRUE(test->data == 5 && test == List.pLast
		&& List.pCurr == List.pFirst && List.pLast->pNext == List.pStop);
	EXPECT_EQ(nullptr, deleted_node);
}

TEST(List, a_lot_remove_last_node_and_control_all_pointers) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(6, 10);
	List.insert_after(4, 5);

	List.remove(4);
	List.remove(2);//6 5 
	List.remove(10);

	Node<int>* test = List.search(5);
	Node<int>* deleted_node = List.search(4);
	List.reset();

	ASSERT_TRUE(test->data == 5 && test == List.pLast
		&& List.pCurr == List.pFirst && List.pLast->pNext == List.pStop);
	EXPECT_EQ(deleted_node,nullptr);
}

TEST(TList, inserts_and_search_after_clear_variant_1) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(6, 10);
	List.insert_after(4, 5);

	List.clear();

	List.insert_first(4);
	List.insert_last(7);
	List.insert_first(9);
	List.insert_first(12);
	List.insert_last(90);
	List.insert_before(40, 90);
	List.insert_after(99, 9);

	Node<int>* test = List.search(12);
	List.reset();

	ASSERT_TRUE(test->data == 12 && test == List.pFirst
		&& List.pCurr == List.pFirst && List.pLast->pNext == List.pStop);
}

TEST(TList, inserts_and_search_after_clear_variant_2) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(6, 10);
	List.insert_after(4, 5);

	List.clear();

	List.insert_first(4);
	List.insert_last(7);
	List.insert_first(9);
	List.insert_first(12);
	List.insert_last(90);
	List.insert_before(40, 90);
	List.insert_after(99, 9);

	Node<int>* test2 = List.search(90);
	List.reset();

	ASSERT_TRUE(test2->data == 90 && test2 == List.pLast
		&& List.pCurr == List.pFirst && List.pLast->pNext == List.pStop);
}

TEST(TList, different_memory) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_first(3);

	TList<int> List_copy(List);
	List_copy.insert_first(7);

	ASSERT_TRUE(&List != &List_copy);
}

TEST(TList, count_nodes) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(6, 10);
	List.insert_after(4, 5);

	List.remove(4);
	List.remove(2);//6 5 
	List.remove(10);

	int count = List.GetSize();
	EXPECT_EQ(2, count);
}

TEST(TList, count_nodes_when_all_deleted) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(6, 10);
	List.insert_after(4, 5);

	List.remove(4);
	List.remove(2);
	List.remove(10);
	List.remove(5);
	List.remove(6);

	int count = List.GetSize();
	EXPECT_EQ(0, count);
}

TEST(TList, destructor_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	List->remove(5);

	ASSERT_NO_THROW(delete List;);
}

TEST(TList, Is_Full_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	ASSERT_NO_THROW(List->IsFull());
}

TEST(TList, Is_Full_false) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	ASSERT_FALSE(List->IsFull());
}

TEST(TList, Is_Empty_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	ASSERT_NO_THROW(List->IsEmpty());
}

TEST(TList, Is_Empty_true) {
	Node<int>* pFirst = nullptr;
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_TRUE(List->IsEmpty());
}

TEST(TList, Is_Empty_false) {
	Node<int>* pFirst = new Node<int>(5);
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_FALSE(List->IsEmpty());
}

TEST(TList, navigation_part_1_current_data) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);
	List->insert_first(3);
	List->insert_first(12);
	List->insert_first(80);
	List->insert_first(33);
	List->insert_after(4, 5);

	Node<int>* tmp = List->pCurr;

	ASSERT_TRUE(tmp->data == 33);
}

TEST(TList, navigation_part_2_next_data) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);
	List->insert_first(3);
	List->insert_first(12);
	List->insert_first(80);
	List->insert_first(33);
	List->insert_after(4, 5);

	List->next();

	Node<int>* tmp = List->pCurr;

	ASSERT_TRUE(tmp->data == 80);
}

TEST(TList, navigation_part_3_use_next_method_while_not_reached_end) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);
	List->insert_first(3);
	List->insert_first(12);
	List->insert_first(80);
	List->insert_first(33);
	List->insert_after(4, 5);

	Node<int>* tmp = List->pCurr;
	Node<int>* tmp_pStop = List->pStop;
	while (tmp != tmp_pStop) {
		List->next();
		tmp = List->pCurr;
	}


	ASSERT_TRUE(List->Is_Ended());
}


TEST(TList, navigation_part_4_reset_current_pointer) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	Node<int>* tmp = List->pCurr;

	while (tmp != List->pStop) {
		List->next();
		tmp = List->pCurr;
	}

	if (List->Is_Ended()) {
		List->reset();
		tmp = List->pCurr;
	}

	ASSERT_TRUE(List->pCurr == List->pFirst);
}