#include <gtest.h>
#include "TNode.h"
#include "TList.h"
#include "TRingList.h"

TEST (TNode, can_create_node_without_parametrs) {
	ASSERT_NO_THROW(TNode<int>());
}

TEST(TNode, can_create_node_with_key) {
	ASSERT_NO_THROW(TNode<int>(1));
}

TEST(TNode, can_create_node_with_key_and_pointer) {
	TNode<int>* p = new TNode<int>(1);
	ASSERT_NO_THROW(TNode<int>(2, p));
}

TEST(TNode, can_create_node_with_pointer) {
	TNode<int>* p = new TNode<int>(1);
	ASSERT_NO_THROW(TNode<int>(p));
}

//-------------------------------------------------------------------------

TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int>());
}

TEST(TList, can_create_list_with_pointer_to_first_element) {
	TNode<int>* p = new TNode<int>(1);
	ASSERT_NO_THROW(TList<int>(p));
}

TEST(TList, can_create_list_with_copy_constructor) {
	TList<int> lst;
	for (int i = 0; i < 5; i++) lst.insertLast(i);
	TList<int> lst1(lst);
	bool flag = true;
	lst.Reset();
	lst1.Reset();
	for (int i = 0; i < 5 && flag != false; i++) {
		flag = lst.getCurrent()->key == lst1.getCurrent()->key;
		lst.Next();
		lst1.Next();
	}
	ASSERT_TRUE(flag);
}

TEST(TList, can_destroy_list) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TList<int> lst(p);
	ASSERT_NO_THROW(lst.~TList());
}

TEST(TList, can_find_element) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TList<int> lst(p);
	EXPECT_EQ(2, lst.Search(2)->key);
}

TEST(TList, return_nullptr_when_cant_find_element) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TList<int> lst(p);
	EXPECT_EQ(nullptr, lst.Search(4));
}

TEST(TList, return_nullptr_when_try_to_find_element_in_empty_list) {
	TList<int> lst;
	EXPECT_EQ(nullptr, lst.Search(1));
}

TEST(TList, can_insert_element_in_first_position_in_empty_list) {
	TList<int> lst;
	lst.insertFirst(1);
	EXPECT_EQ(1, lst.getCurrent()->key);
}

TEST(TList, can_insert_element_in_last_position_in_emty_list) {
	TList<int> lst;
	lst.insertLast(1);
	EXPECT_EQ(1, lst.getCurrent()->key);
}

TEST(TList, can_insert_element_in_last_position_in_not_empty_list) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TList<int> lst(p);
	lst.insertLast(4);
	TNode<int>* tmp = lst.Search(4);
	EXPECT_EQ(4, tmp->key);
	EXPECT_EQ(nullptr, tmp->pNext);
}

TEST(TList, can_insert_element_in_first_position_in_not_empty_list) {
	TNode<int>* p = new TNode<int>(1);
	TList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(3);
	lst.insertFirst(0);
	EXPECT_EQ(0, lst.getCurrent()->key);
	EXPECT_EQ(lst.getCurrent()->pNext->key, lst.Search(1)->key);
}

TEST(TList, can_insert_element_before_curent_position) {
	TNode<int>* p = new TNode<int>(1);
	TList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(4);
	lst.insertBefore(3);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
	EXPECT_EQ(4, lst.Search(3)->pNext->key);
}

TEST(TList, can_insert_element_after_curent_position) {
	TNode<int>* p = new TNode<int>(1);
	TList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(4);
	lst.Reset();
	lst.Next();
	lst.insertAfter(3);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
	EXPECT_EQ(4, lst.Search(3)->pNext->key);
}

TEST(TList, can_instert_elemnt_before_old_key){
	TNode<int>* p = new TNode<int>(1);
	TList<int> lst(p);
	lst.insertLast(3);
	lst.insertLast(4);
	lst.insertBefore(3, 2);
	EXPECT_EQ(2, lst.Search(1)->pNext->key);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
}

TEST(TList, can_instert_elemnt_after_old_key){
	TNode<int>* p = new TNode<int>(1);
	TList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(4);
	lst.insertAfter(2, 3);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
	EXPECT_EQ(4, lst.Search(3)->pNext->key);
}

TEST(TList, throw_when_try_to_insert_element_before_not_empty_key){
	TList<int> lst;
	ASSERT_ANY_THROW(lst.insertBefore(1, 1));
}

TEST(TList, throw_when_try_to_insert_element_after_not_empty_key){
	TList<int> lst;
	ASSERT_ANY_THROW(lst.insertAfter(1, 1));
}

TEST(TList, can_remove_existing_element) {
	TNode<int>* p = new TNode<int>(1);
	TList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(3);
	lst.Remove(2);
	EXPECT_EQ(3, lst.Search(1)->pNext->key);
}

TEST(TList, throw_when_try_to_remove_not_existing_element) {
	TList<int> lst;
	ASSERT_ANY_THROW(lst.Remove(5));
}

TEST(TList, can_clear_list) {
	TNode<int>* p = new TNode<int>(1);
	TList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(3);
	lst.Clear();
	EXPECT_EQ(0, lst.getSize());
}

TEST(TList, throw_when_try_to_clear_empty_list) {
	TList<int> lst;
	ASSERT_ANY_THROW(lst.Clear());
}

TEST(TList, can_get_size) {
	TList<int> lst;
	for (int i = 0; i < 5; i++) lst.insertLast(i);
	EXPECT_EQ(5, lst.getSize());
}

//-------------------------------------------------------------------------

TEST(TRingList, can_create_ringlist) {
	ASSERT_NO_THROW(TRingList<int> lst());
}

TEST(TRingList, can_create_ringlist_with_pointer_to_first_node) {
	TNode<int>* f = new TNode<int>(1);
	f->pNext = new TNode<int>(2);
	f->pNext->pNext = new TNode<int>(3);
	ASSERT_NO_THROW(TRingList<int> lst(f));
}

TEST(TRingList, can_create_ringlist_with_copy_conctructor_list_version) {
	TList<int> lst;
	for (int i = 0; i < 5; i++) lst.insertLast(i);
	bool flag = true;
	TRingList<int> rlst(lst);
	lst.Reset();
	rlst.Reset();
	for (int i = 0; i < 5 && flag != false; i++) {
		flag = lst.getCurrent()->key == rlst.getCurrent()->key;
		lst.Next();
		rlst.Next();
	}
	ASSERT_TRUE(flag);
}

TEST(TRingList, can_crete_list_with_copy_constructor_ringlist_version) {
	TRingList<int> lst;
	for (int i = 0; i < 5; i++) lst.insertLast(i);
	bool flag = true;
	TRingList<int> rlst(lst);
	lst.Reset();
	rlst.Reset();
	for (int i = 0; i < 5 && flag != false; i++) {
		flag = lst.getCurrent()->key == rlst.getCurrent()->key;
		lst.Next();
		rlst.Next();
	}
	ASSERT_TRUE(flag);
}

TEST(TRingList, can_destroy_list) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TRingList<int> lst(p);
	ASSERT_NO_THROW(lst.~TRingList());
}

TEST(TRingList, can_find_element) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TRingList<int> lst(p);
	EXPECT_EQ(2, lst.Search(2)->key);
}

TEST(TRingList, return_nullptr_when_cant_find_element) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TRingList<int> lst(p);
	EXPECT_EQ(nullptr, lst.Search(4));
}

TEST(TRingList, return_nullptr_when_try_to_find_element_in_empty_list) {
	TRingList<int> lst;
	EXPECT_EQ(nullptr, lst.Search(1));
}

TEST(TRingList, can_insert_element_in_first_position_in_empty_list) {
	TRingList<int> lst;
	lst.insertFirst(1);
	EXPECT_EQ(1, lst.getCurrent()->key);
}

TEST(TRingList, can_insert_element_in_last_position_in_emty_list) {
	TRingList<int> lst;
	lst.insertLast(1);
	EXPECT_EQ(1, lst.getCurrent()->key);
}

TEST(TRingList, can_insert_element_in_last_position_in_not_empty_list) {
	TNode<int>* p = new TNode<int>(1);
	p->pNext = new TNode<int>(2);
	p->pNext->pNext = new TNode<int>(3);
	TRingList<int> lst(p);
	lst.insertLast(4);
	TNode<int>* tmp = lst.Search(4);
	EXPECT_EQ(4, tmp->key);
	EXPECT_EQ(lst.getFirst(), tmp->pNext->pNext);
}

TEST(TRingList, can_insert_element_in_first_position_in_not_empty_list) {
	TNode<int>* p = new TNode<int>(1);
	TRingList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(3);
	lst.insertFirst(0);
	EXPECT_EQ(0, lst.getCurrent()->key);
	EXPECT_EQ(lst.getCurrent()->pNext->key, lst.Search(1)->key);
	EXPECT_EQ(lst.getCurrent(), lst.getLast()->pNext->pNext);
}

TEST(TRingList, can_insert_element_before_curent_position) {
	TNode<int>* p = new TNode<int>(1);
	TRingList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(4);
	lst.insertBefore(3);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
	EXPECT_EQ(4, lst.Search(3)->pNext->key);
}

TEST(TRingList, can_insert_element_after_curent_position) {
	TNode<int>* p = new TNode<int>(1);
	TRingList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(4);
	lst.Reset();
	lst.Next();
	lst.insertAfter(3);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
	EXPECT_EQ(4, lst.Search(3)->pNext->key);
}

TEST(TRingList, can_instert_elemnt_before_old_key) {
	TNode<int>* p = new TNode<int>(1);
	TRingList<int> lst(p);
	lst.insertLast(3);
	lst.insertLast(4);
	lst.insertBefore(3, 2);
	EXPECT_EQ(2, lst.Search(1)->pNext->key);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
}

TEST(TRingList, can_instert_elemnt_after_old_key) {
	TNode<int>* p = new TNode<int>(1);
	TRingList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(4);
	lst.insertAfter(2, 3);
	EXPECT_EQ(3, lst.Search(2)->pNext->key);
	EXPECT_EQ(4, lst.Search(3)->pNext->key);
}

TEST(TRingList, throw_when_try_to_insert_element_before_not_empty_key) {
	TRingList<int> lst;
	ASSERT_ANY_THROW(lst.insertBefore(1, 1));
}

TEST(TRingList, throw_when_try_to_insert_element_after_not_empty_key) {
	TRingList<int> lst;
	ASSERT_ANY_THROW(lst.insertAfter(1, 1));
}

TEST(TRingList, can_remove_existing_element) {
	TNode<int>* p = new TNode<int>(1);
	TRingList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(3);
	lst.Remove(2);
	EXPECT_EQ(3, lst.Search(1)->pNext->key);
}

TEST(TRingList, throw_when_try_to_remove_not_existing_element) {
	TRingList<int> lst;
	ASSERT_ANY_THROW(lst.Remove(5));
}

TEST(TRingList, can_clear_list) {
	TNode<int>* p = new TNode<int>(1);
	TRingList<int> lst(p);
	lst.insertLast(2);
	lst.insertLast(3);
	lst.Clear();
	EXPECT_EQ(0, lst.getSize());
}

TEST(TRingList, throw_when_try_to_clear_empty_list) {
	TRingList<int> lst;
	ASSERT_ANY_THROW(lst.Clear());
}

TEST(TRingList, can_get_size) {
	TRingList<int> lst;
	for (int i = 0; i < 5; i++) lst.insertLast(i);
	EXPECT_EQ(5, lst.getSize());
}
