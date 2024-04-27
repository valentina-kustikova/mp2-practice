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


TEST(List, insert_before_check_data) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_before(6, 2);
	List.insert_before(4, 2);
	List.insert_before(20, 10);
	List.insert_before(30, 10);

	Node<int>* TKey = List.search(6);
	Node<int>* TData = List.search(30);

	ASSERT_TRUE(TKey->data == 6 && TData->data == 30);
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

	Node<int>* TKey = List.search(6);
	Node<int>* TData = List.search(8);

	ASSERT_TRUE(TKey->data == 6 && TData->data == 8);

}

TEST(List, remove_work) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_after(4, 5);

	ASSERT_NO_THROW(List.remove(5));
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

	ASSERT_TRUE(List->getCurrent()->data == 33);
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


	ASSERT_TRUE(List->getCurrent()->data == 80);
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

	while (!List->Is_Ended()) {
		List->next();
	}


	ASSERT_TRUE(List->Is_Ended());
}


TEST(TList, navigation_part_4_reset_current_pointer) {
	Node<int>* pFirst = new Node<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	while (!List->Is_Ended()) {
		List->next();
	}

	if (List->Is_Ended()) {
		List->reset();
	}

	ASSERT_TRUE(List->getCurrent() == List->pFirst);
}