#include <gtest.h>
#include <string>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "AVLTable.h"
using namespace std;
#define SS <int,int>
#define FF <int,string>


//Тесты для класса бинарное поисковое дерево
TEST(BinaryTree, can_create_tree1)
{
ASSERT_NO_THROW(BinaryTree SS T2);
}
TEST(BinaryTree, can_Insert_empty_tree1)
{
BinaryTree SS  T1;
ASSERT_NO_THROW(T1.Insert(1, 1));
}
TEST(BinaryTree, Insert_correct_empty_tree1)
{
BinaryTree SS  T1;
T1.Insert(1, 1);
EXPECT_EQ(1, (*T1.Find(1)).GetKey());
}
TEST(BinaryTree, corect_Delete1)
{
BinaryTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
T1.printTree((BalanceNode SS*)(T1.Find(8)), nullptr, 1);
T1.Delete(17);
T1.printTree((BalanceNode SS*)(T1.Find(8)), nullptr, 1);
EXPECT_EQ(8, (*T1.Find(8)).GetKey());
EXPECT_EQ(28, (*T1.Find(28)).GetKey());
EXPECT_EQ(41, (*T1.Find(41)).GetKey());
//EXPECT_EQ(nullptr, T1.Find(17));
}
TEST(BinaryTree, corect_Insert1)
{
BinaryTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
T1.Insert(3, 1);
EXPECT_EQ(3, (*T1.Find(3)).GetKey());
}
TEST(BinaryTree, corect_Insert_after_Delete1)
{
BinaryTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
T1.printTree((BalanceNode SS*)(T1.Find(8)), nullptr, 1);
T1.Delete(8);
T1.printTree((BalanceNode SS*)(T1.Find(17)), nullptr, 1);
T1.Delete(17);
T1.printTree((BalanceNode SS*)(T1.Find(28)), nullptr, 1);
T1.Delete(28);
T1.printTree((BalanceNode SS*)(T1.Find(41)), nullptr, 1);
T1.Delete(41);
T1.printTree((BalanceNode SS*)(T1.Find(0)), nullptr, 1);
T1.Insert(1, 1);
T1.printTree((BalanceNode SS*)(T1.Find(1)), nullptr, 1);

EXPECT_EQ(1, (*T1.Find(1)).GetKey());
}
TEST(BinaryTree, can_not_Insert_record_wich_key_isnt_unique1)
{
BinaryTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
EXPECT_NO_THROW(T1.Insert(17, 2));
}
TEST(BinaryTree, can_not_Delete_record_wich_key_unique1)
{
BinaryTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
EXPECT_NO_THROW(T1.Delete(88));
}
TEST(BinaryTree, corect_FindRecord1)
{
BinaryTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
EXPECT_EQ(17, (*T1.Find(17)).GetKey());
}
TEST(BinaryTree, corect_FindRecordMax1)
{
BinaryTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(18, (*T1.FindMax(T1.Find(18))).GetKey());
}
TEST(BinaryTree, corect_FindRecordMin1)
{
BinaryTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(1, (*T1.FindMin(T1.Find(1))).GetKey());
}
TEST(BinaryTree, corect_FindRecordNext1)
{
BinaryTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(12, (*T1.FindNext(T1.Find(8))).GetKey());
}
TEST(BinaryTree, corect_FindRecordPrev1)
{
BinaryTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(7, (*T1.FindPrev(T1.Find(8))).GetKey());
}

//Тесты для класса сбалансированные АВЛ дерево
TEST(AVLTree, can_create_tree2)
{
ASSERT_NO_THROW(AVLTree SS T2);
}
TEST(AVLTree, can_Insert_empty_tree2)
{
AVLTree SS  T1;
ASSERT_NO_THROW(T1.Insert(1, 1));
}
TEST(AVLTree, Insert_correct_empty_tree2)
{
AVLTree SS  T1;
T1.Insert(1, 1);
EXPECT_EQ(1, (*T1.Find(1)).GetKey());
}
TEST(AVLTree, corect_Delete2)
{
AVLTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
T1.printTree((BalanceNode SS*)(T1.Find(17)), nullptr, 1);
T1.Delete(17);
//T1.printTree((BalanceNode SS*)(T1.Find(28)), nullptr, 1);
T1.printTree((BalanceNode SS*)(T1.Find(28)), nullptr, 1);

EXPECT_EQ(8, (*T1.Find(8)).GetKey());
EXPECT_EQ(28, (*T1.Find(28)).GetKey());
EXPECT_EQ(41, (*T1.Find(41)).GetKey());
EXPECT_EQ(nullptr, T1.Find(17));
}
TEST(AVLTree, corect_Insert2)
{
AVLTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
T1.Insert(3, 1);
EXPECT_EQ(3, (*T1.Find(3)).GetKey());
 }
TEST(AVLTree, corect_Insert_after_Delete2)
{  
AVLTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
T1.Delete(8);
T1.Delete(17);
T1.Delete(28);
T1.Delete(41);
T1.Insert(1, 1);
EXPECT_EQ(1, (*T1.Find(1)).GetKey());
}
TEST(AVLTree, can_not_Insert_record_wich_key_isnt_unique2)
{
AVLTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
EXPECT_NO_THROW(T1.Insert(17, 2));//ТАК И ЗАДУМАНО
}
TEST(AVLTree, can_not_Delete_record_wich_key_unique2)
{
AVLTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
EXPECT_NO_THROW(T1.Delete(88));
}
TEST(AVLTree, corect_FindRecord2)
{
AVLTree SS  T1;
for (int i = 0; i < 4; i++)
{
T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
}
EXPECT_EQ(17, (*T1.Find(17)).GetKey());
}
TEST(AVLTree, corect_FindRecordMax2)
{
AVLTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(18, (*T1.FindMax(T1.Find(18))).GetKey());
}
TEST(AVLTree, corect_FindRecordMin2)
{
AVLTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(1, (*T1.FindMin(T1.Find(1))).GetKey());
}
TEST(AVLTree, corect_FindRecordNext2)
{
AVLTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(12, (*T1.FindNext(T1.Find(8))).GetKey());
}
TEST(AVLTree, corect_FindRecordPrev2)
{
AVLTree SS  T1;
T1.Insert(8, 1);
T1.Insert(2, 12);
T1.Insert(4, 1);
T1.Insert(3, 1);
T1.Insert(1, 1);
T1.Insert(12, 1);
T1.Insert(18, 1);
T1.Insert(7, 1);
EXPECT_EQ(7, (*T1.FindPrev(T1.Find(8))).GetKey());
}

//Тесты на балансировку Деревьев AVL
TEST(AVLTree, correct_balanced_tree_Insert_1_One_L_rotate)
{
BinaryTree SS TEST;
TEST.Insert(4, 1);
TEST.Insert(1, 12);
TEST.Insert(8, 12);
TEST.Insert(6, 1);
TEST.Insert(10, 1);
TEST.Insert(12, 1);

cout << "\nBINARY_START_TREE__________________________________\n";
TEST.printTree((BalanceNode SS*)(TEST.Find(4)), nullptr, 1);

AVLTree SS  T1;
//случай 1 - однократный RR поворот
T1.Insert(4, 1);
T1.Insert(1, 12);
T1.Insert(8, 12);
T1.Insert(6, 1);
T1.Insert(10, 1);
T1.Insert(12, 1);

BinaryTree SS  TT1;
TT1.Insert(8, 1);
TT1.Insert(4, 12);
TT1.Insert(10, 12);
TT1.Insert(1, 1);
TT1.Insert(6, 1);
TT1.Insert(12, 1);

cout << "\nAVL_TREE__________________________________\n";
T1.printTree((BalanceNode SS*)(T1.Find(8)), nullptr, 1);
cout << "\nBINARY_TREE_________________________________\n";
TT1.printTree((TT1.Find(8)), nullptr, 1);
EXPECT_EQ(T1, TT1);
}
TEST(AVLTree, correct_balanced_treet_Insert_2_One_R_rotate)
{
	BinaryTree SS TEST;
	TEST.Insert(20, 1);
	TEST.Insert(17, 12);
	TEST.Insert(22, 12);
	TEST.Insert(11, 1);
	TEST.Insert(18, 1);
	TEST.Insert(7, 1);

	cout << "\nBINARY_START_TREE__________________________________\n";
	TEST.printTree((BalanceNode SS*)(TEST.Find(20)), nullptr, 1);



AVLTree SS  T1;
// случай 1 - однократный LL поворот
   T1.Insert(20, 1);
   T1.Insert(17, 12);
   T1.Insert(22, 12);
   T1.Insert(11, 1);
   T1.Insert(18, 1);
   T1.Insert(7, 1);

   BinaryTree SS  TT1;
   TT1.Insert(17, 1);
   TT1.Insert(11, 1);
   TT1.Insert(20, 1);
   TT1.Insert(7, 1);
   TT1.Insert(18, 1);
   TT1.Insert(22, 1);

   cout << "\nAVL_TREE__________________________________\n";
   T1.printTree((BalanceNode SS*)(T1.Find(17)), nullptr, 1);
   cout << "\nBINARY_TREE_________________________________\n";
   TT1.printTree((TT1.Find(17)), nullptr, 1);

   EXPECT_EQ(T1, TT1);
}
TEST(AVLTree, correct_balanced_tree_Insert_3_Two_LL_rotate)
{
AVLTree SS  T1;
T1.Insert(11, 1);
T1.Insert(7, 12);
T1.Insert(20, 12);
T1.Insert(5, 1);
T1.Insert(9, 1);
T1.Insert(15, 1);
T1.Insert(25, 1);
T1.Insert(3, 1);
T1.Insert(6, 1);
T1.Insert(8, 1);
T1.Insert(10, 1);
T1.Insert(12, 1);
T1.Insert(17, 1);
T1.Insert(19, 1);

BinaryTree SS  TT1;

TT1.Insert(11, 1);
TT1.Insert(7, 1);
TT1.Insert(17, 1);
TT1.Insert(5, 1);
TT1.Insert(9, 1);
TT1.Insert(15, 1);
TT1.Insert(20, 1);
TT1.Insert(3, 1);
TT1.Insert(6, 1);
TT1.Insert(8, 1);
TT1.Insert(10, 1);
TT1.Insert(12, 1);
TT1.Insert(19, 1);
TT1.Insert(25, 1);

cout << "\nAVL_TREE__________________________________\n";
T1.printTree((BalanceNode SS*)(T1.Find(11)), nullptr, 1);
cout << "\nBINARY_TREE_________________________________\n";
TT1.printTree((TT1.Find(11)), nullptr, 1);

EXPECT_EQ(T1, TT1);
}
TEST(AVLTree, correct_balanced_tree_Insert_4_Two_RR_rotate)
{
AVLTree SS  T1;
T1.Insert(15, 1);
T1.Insert(5, 1);
T1.Insert(29, 1);
T1.Insert(4, 1);
T1.Insert(7, 1);
//T1.Insert(4, 1);
T1.Insert(25, 1);
T1.Insert(30, 1);
T1.Insert(1, 1);
T1.Insert(6, 1);
T1.Insert(8, 1);
T1.Insert(9, 1);

BinaryTree SS  TT1;

TT1.Insert(7, 1);
TT1.Insert(5, 1);
TT1.Insert(15, 1);
TT1.Insert(4, 1);
TT1.Insert(1, 1);
TT1.Insert(6, 1);
TT1.Insert(8, 1);
TT1.Insert(9, 1);
TT1.Insert(29, 1);
TT1.Insert(25, 1);
TT1.Insert(30, 1);
//T1.Insert(9, 1);

cout << "\nAVL_TREE__________________________________\n";
T1.printTree((BalanceNode SS*)(T1.Find(7)), nullptr, 1);
cout << "\nBINARY_TREE_________________________________\n";
TT1.printTree((TT1.Find(7)), nullptr, 1);
EXPECT_EQ(T1, TT1);
}

TEST(AVLTree, correct_balanced_tree_Delete_1_One_L_rotate)
{
AVLTree SS  T1;
//удаление 1
T1.Insert(10, 1);
T1.Insert(3, 12);
T1.Insert(25, 12);
T1.Insert(1, 1);
T1.Insert(15, 1);
T1.Insert(30, 1);
T1.Insert(12, 1);
T1.Insert(20, 1);
T1.Insert(35, 1);
T1.Delete(1);

BinaryTree SS  TT1;
TT1.Insert(15, 1);
TT1.Insert(10, 1);
TT1.Insert(25, 1);
TT1.Insert(3, 1);
TT1.Insert(12, 1);
TT1.Insert(20, 1);
TT1.Insert(30, 1);
TT1.Insert(35, 1);


cout << "\nAVL_TREE__________________________________\n";
T1.printTree((BalanceNode SS*)(T1.Find(15)), nullptr, 1);
cout << "\nBINARY_TREE_________________________________\n";
TT1.printTree((TT1.Find(15)), nullptr, 1);
EXPECT_EQ(T1, TT1);
}
TEST(AVLTree, correct_balanced_tree_Delete_2_One_R_rotate)
{
   AVLTree SS  T1;
   //удаление 2
   T1.Insert(10, 1);
   T1.Insert(3, 12);
   T1.Insert(25, 12);
   T1.Insert(1, 1);
   T1.Insert(4, 1);
   T1.Delete(25);

   BinaryTree SS  TT1;
   TT1.Insert(4, 1);
   TT1.Insert(3, 1);
   TT1.Insert(10, 1);
   TT1.Insert(1, 1);

   cout << "\nAVL_TREE__________________________________\n";
   T1.printTree((BalanceNode SS*)(T1.Find(4)), nullptr, 1);
   cout << "\nBINARY_TREE_________________________________\n";
   TT1.printTree((TT1.Find(4)), nullptr, 1);

   EXPECT_EQ(T1, TT1);
}
TEST(AVLTree, correct_balanced_tree_Delete_3_Two_LL_rotate)
{
AVLTree SS  T1;
   //удаление 3
   T1.Insert(11, 1);
   T1.Insert(7, 12);
   T1.Insert(20, 12);
   T1.Insert(5, 1);
   T1.Insert(9, 1);
   T1.Insert(15, 1);
   T1.Insert(25, 1);
   T1.Insert(3, 1);
   T1.Insert(6, 1);
   T1.Insert(8, 1);
   T1.Insert(10, 1);
   T1.Insert(12, 1);
   T1.Insert(17, 1);
   T1.Insert(23, 1);
   T1.Insert(27, 1);
   T1.Insert(26, 1);
   T1.Insert(30, 1);

   //T1.printTree((BalanceNode SS*)(T1.Find(11)),nullptr,1);
   //std::cout << T1;
   T1.Delete(9);

   BinaryTree SS  TT1;
   TT1.Insert(11, 1);
   TT1.Insert(7, 1);
   TT1.Insert(20, 1);
   TT1.Insert(5, 1);
   TT1.Insert(10, 1);
   TT1.Insert(15, 1);
   TT1.Insert(25, 1);
   TT1.Insert(3, 1);
   TT1.Insert(6, 1);
   TT1.Insert(8, 1);
   TT1.Insert(12, 1);
   TT1.Insert(17, 1);
   TT1.Insert(23, 1);
   TT1.Insert(27, 1);
   TT1.Insert(26, 1);
   TT1.Insert(30, 1);

   cout << "\nAVL_TREE__________________________________\n";
   T1.printTree((BalanceNode SS*)(T1.Find(11)), nullptr, 1);
   cout << "\nBINARY_TREE_________________________________\n";
   TT1.printTree((TT1.Find(11)), nullptr, 1);

   EXPECT_EQ(T1, TT1);
}
TEST(AVLTree, correct_balanced_tree_Delete_4_Two_RR_rotate)
{
	AVLTree SS  T1;
	T1.Insert(20, 1);
	T1.Insert(15, 1);
	T1.Insert(40, 1);
	T1.Insert(12, 1);
	T1.Insert(18, 1);
	T1.Insert(30, 1);
	T1.Insert(50, 1);
	T1.Insert(10, 1);
	T1.Insert(13, 1);
	T1.Insert(17, 1);
	T1.Insert(19, 1);
	T1.Insert(25, 1);
	T1.Insert(2, 1);
	T1.Insert(11, 1);
	//T1.Insert(12, 1);
	T1.Insert(14, 1);

	T1.Delete(25);
	BinaryTree SS  TT1;
	TT1.Insert(15, 1);
	TT1.Insert(12, 1);
	TT1.Insert(20, 1);
	TT1.Insert(10, 1);
	TT1.Insert(13, 1);
	TT1.Insert(18, 1);
	TT1.Insert(40, 1);
	TT1.Insert(2, 1);
	TT1.Insert(11, 1);
	//TT1.Insert(12, 1);
	TT1.Insert(14, 1);
	TT1.Insert(17, 1);
	TT1.Insert(19, 1);
	TT1.Insert(30, 1);
	TT1.Insert(50, 1);
	//T1.Insert(13, 1);

	cout << "\nAVL_TREE__________________________________\n";
	T1.printTree((BalanceNode SS*)(T1.Find(15)), nullptr, 1);
	cout << "\nBINARY_TREE_________________________________\n";
	TT1.printTree((TT1.Find(15)), nullptr, 1);
	EXPECT_EQ(T1, TT1);

}

 //Тесты для класса таблиц на АВЛ деревьях
TEST(AVLTable, can_create_table1)
{
ASSERT_NO_THROW(AVLTable FF T2);
}
TEST(AVLTable, can_not_GetData_empty_table1)
{
AVLTable FF  T1;
ASSERT_NO_THROW(T1.GetData());
}
TEST(AVLTable, can_not_SetNext_empty_table1)
{
AVLTable FF  T1;
ASSERT_NO_THROW(T1.SetNext());
}
TEST(AVLTable, can_not_RemoveRecord_empty_table1)
{
AVLTable FF  T1;
ASSERT_NO_THROW(T1.RemoveRecord("one"));
}
TEST(AVLTable, can_not_FindRecord_empty_table1)
{
AVLTable FF  T1;
ASSERT_NO_THROW(T1.FindRecord("one"));
}
TEST(AVLTable, can_InsertRecord_empty_table1)
{
AVLTable FF  T1;
ASSERT_NO_THROW(T1.InsertRecord(1, "one"));
}
TEST(AVLTable, InsertRecord_correct_empty_table1)
{
AVLTable FF  T1;
T1.InsertRecord(1, "one");
EXPECT_EQ(1, T1.GetCount());
EXPECT_EQ(1, *(T1.FindRecord("one")));
}
TEST(AVLTable, can_GetData1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.Reset();
ASSERT_NO_THROW(*(T1.GetData()));
}
TEST(AVLTable, GetData_corect1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.Reset();
EXPECT_EQ(8, *(T1.GetData()));
}
TEST(AVLTable, can_GetKey1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.Reset();
ASSERT_NO_THROW(T1.GetKey());
}
TEST(AVLTable, GetKey_corect1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.Reset();
EXPECT_EQ("1 record", T1.GetKey());
}
TEST(AVLTable, can_SetNext1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.Reset();
ASSERT_NO_THROW(T1.SetNext());
}
TEST(AVLTable, SetNext_correct1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.Reset();
T1.SetNext();
cout << T1;
EXPECT_EQ(17, *(T1.GetData()));
}
TEST(AVLTable, corect_RemoveRecord1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.RemoveRecord("2 record");
T1.Reset();
EXPECT_EQ(8, *(T1.GetData()));
T1.SetNext();
EXPECT_EQ(28, *(T1.GetData()));
T1.SetNext();
EXPECT_EQ(41, *(T1.GetData()));
}
TEST(AVLTable, empty_after_RemoveRecord1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.RemoveRecord("1 record");
T1.RemoveRecord("2 record");
T1.RemoveRecord("3 record");
T1.RemoveRecord("4 record");
EXPECT_EQ(true, T1.IsEmpty());
}
TEST(AVLTable, corect_InsertRecord1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");

}
T1.InsertRecord(5, "5 record");
T1.Reset();
T1.SetNext();
T1.SetNext();
T1.SetNext();
T1.SetNext();
EXPECT_EQ(5, *(T1.GetData()));
}
TEST(AVLTable, corect_InsertRecord_after_RemoveRecord1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.RemoveRecord("1 record");
T1.RemoveRecord("2 record");
T1.RemoveRecord("3 record");
T1.RemoveRecord("4 record");
T1.InsertRecord(0, "0");
T1.Reset();
EXPECT_EQ(0, *(T1.GetData()));

}
TEST(AVLTable, corect_FindRecord1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
EXPECT_EQ(17, *(T1.FindRecord("2 record")));
}
TEST(AVLTable, can_not_InsertRecord_record_wich_key_isnt_unique1)
{
AVLTable FF  T1;
for (int i = 0; i < 4; i++)
{
T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
EXPECT_NO_THROW(T1.InsertRecord(2, "2 record"));
}
TEST(AVLTable, Delete_Bin_1)
{
	BinaryTree SS T1;
	for (int i = 0; i < 4; i++)
	{
		T1.Insert(i, 1);
	}
	//cout << T1;
	for (int i = 3; i >= 0; i--)
	{
		cout << "TEST______________\n";
		cout << T1;
		T1.Delete(i);
		cout << "__________________\n";

	}
	T1.Insert(200, 1);
	cout << T1;
}
TEST(AVLTable, Delete_Bin_2)
{
	BinaryTree SS T1;
	for (int i = 0; i < 4; i++)
	{
		T1.Insert(i, 1);
	}
	//cout << T1;
	cout << T1;
	T1.Clear();
	cout << T1;
	T1.Insert(200, 1);
	cout << T1;
}
TEST(AVLTable, Delete_Avl_1)
{
	AVLTree SS  T1;
	//BinaryTree SS T1;
	for (int i = 0; i < 4; i++)
	{
		T1.Insert(i, 1);
	}
	//cout << T1;
	for (int i = 3; i >= 0; i--)
	{
		cout << "TEST______________\n";
		cout << T1;
		T1.Delete(i);
		cout << "__________________\n";

	}
	T1.Insert(200, 1);
	cout << T1;
}
TEST(AVLTable, Delete_Avl_2)
{
	AVLTree SS  T1;
	//BinaryTree SS T1;
	for (int i = 0; i < 4; i++)
	{
		T1.Insert(i, 1);
	}
	cout << T1;
	T1.Clear();
	cout << T1;
	T1.Insert(200, 1);
	cout << T1;
}

