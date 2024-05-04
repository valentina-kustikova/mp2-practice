#include "tnode.h"
#include "tlist.h"
#include <gtest.h>

//TNode
TEST(TNode, can_create_Node) {
	ASSERT_NO_THROW(TNode<int>());
}

TEST(TNode, can_create_node_w_param) {
	ASSERT_NO_THROW(TNode<int> tmp(0,0));
}

TEST(TNode, can_create_copy_node) {
	TNode<int> Node(0, 0);
	ASSERT_NO_THROW(TNode<int> tmp(Node));
}


//LIST
//construct
TEST(TList, can_create_list) {
	ASSERT_NO_THROW(TList<int>());
}

TEST(TList, can_create_list_w_param) {
	TNode<int>* tmp = new TNode<int>(1, 0);
	ASSERT_NO_THROW(TList<int>* list = new TList<int>(tmp));
}

TEST(TList, can_create_copy_list) {
	TList<int> list;
	ASSERT_NO_THROW(TList<int> list_copy(list));
}

//functions Search, ~Tlist, Clear, Next, Sort, Is_Full, Is_Empty

TEST(TList, can_Search_data) {
	TList<int> list;
	TNode<int>* firstData = new TNode<int>(888);
	list.InsertFirst(firstData->data);
	ASSERT_NO_THROW(list.Search(888));
}

TEST(TList, can_delete_list) {
	TList<int> list;
	list.InsertFirst(2);
	list.~TList();
	EXPECT_EQ(true, list.is_Empty());
}
TEST(TList, can_Clear_list) {
	TList<int> list;
	list.InsertFirst(2);
	list.Clear();
	EXPECT_EQ(true, list.is_Empty());
}
TEST(TList, can_GetCurrData) {
	TList<int> list;
	list.InsertFirst(2);
	EXPECT_EQ(2, list.getCurrData());
}
TEST(TList, can_use_Next) { 
	TList<int> list;
	list.InsertFirst(2);
	list.InsertFirst(6);
	list.Next();
	EXPECT_EQ(2, list.getCurrData());
}
TEST(TList, can_use_Sort) { //descending sort 2,6 -> 6,2 
	TList<int> list;
	list.InsertFirst(2);
	list.InsertFirst(6);
	list.Sort();
	EXPECT_EQ(6, list.getCurrData());
}
TEST(TList, can_check_empty_true)
{
	TList<int> list;
	ASSERT_TRUE(list.is_Empty());
}
TEST(TList, can_check_empty_false)
{
	TList<int> list;
	list.InsertFirst(1);
	ASSERT_FALSE(list.is_Empty());
}
TEST(TList, can_check_full_false)
{
	TList<int> list;
	ASSERT_FALSE(list.is_Full());
}

//Insert
//first
TEST(TList, can_insert_first_true) {
	TList<int> list;
	list.InsertFirst(1);
	EXPECT_EQ(1, list.getCurrData());
}
TEST(TList, can_insert_first_false) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertFirst(2);
	EXPECT_NE(1, list.getCurrData());
}
//last
TEST(TList, can_insert_last_true) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(7);
	EXPECT_EQ(7, list.getCurrData());
}
TEST(TList, can_insert_last_false) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	list.Next();
	EXPECT_NE(1, list.getCurrData());
}
TEST(TList, can_insert_last_list_is_empty) {
	TList<int> list;
	list.InsertLast(1);
	EXPECT_EQ(1, list.getCurrData());
}
//before //InsertBefore(const TData& data_, const TData& NextData)
TEST(TList, can_insert_before_NextData_true) { 
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	list.InsertFirst(3);
	list.InsertBefore(7, 1);  //3712
	list.Reset();
	list.Next();
	EXPECT_EQ(7,list.getCurrData());
}
TEST(TList, can_insert_before_NextData_false) { 
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	list.InsertFirst(3);
	list.InsertBefore(7, 1);  //3712
	list.Reset();
	list.Next();
	EXPECT_NE(1, list.getCurrData());
}

TEST(TList, cant_insert_before_list_empty) {
	TList<int> list;
	ASSERT_ANY_THROW(list.InsertBefore(1,1));
}
//After  InsertAfter(const TData& data_, const TData& PrevData) 
TEST(TList, can_insert_after_NextData_true) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	list.InsertFirst(3);	//312
	list.InsertAfter(7, 1); //3172  
	list.Reset();
	list.Next();
	list.Next();
	EXPECT_EQ(7, list.getCurrData());
}
TEST(TList, can_insert_after_NextData_false) {
	TList<int> list;
	list.InsertFirst(1);
	list.InsertLast(2);
	list.InsertFirst(3);
	list.InsertAfter(7, 1);  //3712
	list.Reset();
	list.Next();
	list.Next();
	EXPECT_NE(1, list.getCurrData());
}
TEST(TList, cant_insert_after_list_empty) {
	TList<int> list;
	ASSERT_ANY_THROW(list.InsertAfter(1, 1));
}

//functions Reset, GetCur, getCurrData

TEST(TList, can_Reset_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(1);
	list.Next();
	list.Reset();
	EXPECT_EQ(1, list.getCurrData());
}
TEST(TList, can_Reset) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(1);
	list.Next();
	list.Reset();
	ASSERT_NO_THROW(list.Reset());
}
TEST(TList, can_getCurrent_wd) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(1); 
	list.InsertLast(7);//137
	TNode<int>* tmp = list.GetCurrent();
	EXPECT_EQ(7, tmp->data);

}
TEST(TList, can_getCurrent) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(1);
	list.InsertLast(7);//137
	TNode<int>* tmp = list.GetCurrent();
	ASSERT_NO_THROW(list.GetCurrent());

}
TEST(TList, can_get_cur_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	list.Next();
	EXPECT_EQ(3, list.getCurrData());
}

TEST(TList, can_set_cur_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	list.Next();
	list.setCurrData(8);
	EXPECT_EQ(8, list.getCurrData());
}



//Remove, isEnd
TEST(TList, can_Remove_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	list.Remove(7);
	list.Reset();
	EXPECT_EQ(3, list.getCurrData());
}
TEST(TList, can_Remove) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	ASSERT_NO_THROW(list.Remove(7));
}
TEST(TList, cant_Remove) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	ASSERT_ANY_THROW(list.Remove(8));
}

TEST(TList, can_Remove_First_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	list.RemoveFirst();
	EXPECT_EQ(3, list.getCurrData());
}
TEST(TList, can_Remove_First) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	ASSERT_NO_THROW(list.RemoveFirst());
}
TEST(TList, can_Remove_Current_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	list.InsertFirst(8);
	list.Next();
	list.RemoveCurrent();
	EXPECT_EQ(3, list.getCurrData());
}
TEST(TList, can_Remove_Current) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	list.InsertFirst(8);
	list.Next();
	ASSERT_NO_THROW(list.RemoveCurrent());
}
TEST(TList, check_is_end_true) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	list.Next();
	list.Next();
	EXPECT_EQ(true, list.is_End());
}
TEST(TList, check_is_end_false) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7);
	EXPECT_NE(true, list.is_End());
}
//insert
//InsertBeforeCurrent(const TData& data_) //вставить перед текущим
TEST(TList, can_Insert_Before_Cur_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7); //73
	list.Next();
	list.InsertBeforeCurrent(9); //793
	EXPECT_EQ(9, list.getCurrData());
}
TEST(TList, can_Insert_Before_Cur) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7); //73
	list.Next();
	list.InsertBeforeCurrent(9); //793
	ASSERT_NO_THROW(list.InsertBeforeCurrent(9));
}
//InsertAfterCurrent(const TData& data_) //вставить после текущего
TEST(TList, can_Insert_After_Cur_data) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7); //73
	list.Next();
	list.InsertAfterCurrent(9); //739
	EXPECT_EQ(9, list.getCurrData());
}
TEST(TList, can_Insert_After_Cur) {
	TList<int> list;
	list.InsertFirst(3);
	list.InsertFirst(7); //73
	list.Next();
	list.InsertAfterCurrent(9); //739
	ASSERT_NO_THROW(list.InsertAfterCurrent(9));
}