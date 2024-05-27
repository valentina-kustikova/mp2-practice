#include <gtest.h>

#include "TList.h"

TEST(List, constructor_default_work) {
	ASSERT_NO_THROW(TList<int>*List = new TList<int>());
}

TEST(List, constructor_with_parameter_work) {
	TNode<int>* pFirst = new TNode<int>(10);

	ASSERT_NO_THROW(TList<int>*List = new TList<int>(pFirst));
}

TEST(List, constructor_copy_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);


	TList<int> List_copy(List);
}

TEST(List, insert_last_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_NO_THROW(List->insert_last(5));
}

TEST(List, search_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);
	ASSERT_NO_THROW(List->search(10));
}

TEST(List, search_when_TNode_found_last) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	TNode<int>* test = List->search(3);

	ASSERT_TRUE(test != nullptr);
}

TEST(List, search_when_TNode_found_first) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	TNode<int>* test = List->search(10);

	ASSERT_TRUE(test != nullptr);
}

TEST(List, search_when_TNode_found_middle) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	TNode<int>* test = List->search(5);

	ASSERT_TRUE(test != nullptr);
}

TEST(List, search_when_TNode_not_found) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(5);
	List->insert_last(7);
	List->insert_last(3);

	TNode<int>* test = List->search(12);

	ASSERT_TRUE(test == nullptr);
}


TEST(List, search_inserted_data) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);
	List->insert_last(3);

	EXPECT_TRUE(List->search(3)->data, 3);
}

TEST(TList, insert_first_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_NO_THROW(List->insert_first(5));
}



TEST(List, insert_before_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	ASSERT_NO_THROW(List.insert_before(6, 2));
}

TEST(List, insert_before_check_values) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_first(1);
	List.insert_first(12);
	List.insert_last(2);
	List.insert_last(5);
	List.insert_before(7, 2);

	TNode<int>* test = List.search(7);

	ASSERT_TRUE(test->data == 7);
}


TEST(List, insert_before_check_data) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_before(6, 2);
	List.insert_before(4, 2);
	List.insert_before(20, 10);
	List.insert_before(30, 10);

	TNode<int>* t1 = List.search(6);
	TNode<int>* t2 = List.search(30);

	ASSERT_TRUE(t1->data == 6 && t2->data == 30);
}

TEST(List, insert_after_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_after(4, 5);

	ASSERT_NO_THROW(List.insert_after(4, 5));
}


TEST(List, insert_after_check_data) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_after(4, 5);
	List.insert_after(6, 5);
	List.insert_after(7, 5);
	List.insert_after(8, 5);

	TNode<int>* t1 = List.search(6);
	TNode<int>* t2 = List.search(8);

	ASSERT_TRUE(t1->data == 6 && t2->data == 8);

}

TEST(List, remove_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_after(4, 5);

	ASSERT_NO_THROW(List.remove(5));
}

TEST(TList, different_memory) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_first(3);

	TList<int> List_copy(List);
	List_copy.insert_first(7);

	ASSERT_TRUE(&List != &List_copy);
}


TEST(TList, clear_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_before(6, 2);
	List.insert_before(4, 2);
	List.insert_before(20, 10);
	List.insert_before(30, 10);

	ASSERT_NO_THROW(List.clear());
}

TEST(TList, work_after_clear) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_before(6, 2);
	List.insert_before(4, 2);
	List.insert_before(20, 10);
	List.insert_before(30, 10);

	List.clear();

	ASSERT_NO_THROW(List.insert_last(5));
}

TEST(TList, count_TNodes_after_clear) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int> List(pFirst);

	List.insert_last(2);
	List.insert_last(5);

	List.insert_before(6, 2);
	List.insert_before(4, 2);
	List.insert_before(20, 10);
	List.insert_before(30, 10);

	List.clear();

	int test_size = List.GetSize();

	EXPECT_EQ(0,test_size);
}



TEST(TList, count_TNodes) {
	TNode<int>* pFirst = new TNode<int>(10);
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

TEST(TList, count_TNodes_when_all_deleted) {
	TNode<int>* pFirst = new TNode<int>(10);
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
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	List->remove(5);

	ASSERT_NO_THROW(delete List;);
}

TEST(TList, Is_Full_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	ASSERT_NO_THROW(List->IsFull());
}

TEST(TList, Is_Full_false) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	ASSERT_FALSE(List->IsFull());
}

TEST(TList, Is_Empty_work) {
	TNode<int>* pFirst = new TNode<int>(10);
	TList<int>* List = new TList<int>(pFirst);

	List->insert_last(2);
	List->insert_last(5);

	List->insert_after(4, 5);

	ASSERT_NO_THROW(List->IsEmpty());
}

TEST(TList, Is_Empty_true) {
	TNode<int>* pFirst = nullptr;
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_TRUE(List->IsEmpty());
}

TEST(TList, Is_Empty_false) {
	TNode<int>* pFirst = new TNode<int>(5);
	TList<int>* List = new TList<int>(pFirst);

	ASSERT_FALSE(List->IsEmpty());
}

TEST(TList, navigation_part_1_current_data) {
	TNode<int>* pFirst = new TNode<int>(10);
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
	TNode<int>* pFirst = new TNode<int>(10);
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
	TNode<int>* pFirst = new TNode<int>(10);
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
	TNode<int>* pFirst = new TNode<int>(10);
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