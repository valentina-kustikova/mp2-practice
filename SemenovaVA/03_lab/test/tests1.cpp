#include <gtest.h>
#include <string>
#include "BSTree.h"
#include "AVLTree.h"
#include "AVLTable.h"
#define SS <int,int>
#define FF <int,string>
using namespace std;

//Тесты для класса бинарное поисковое дерево
TEST(TBinaryTree, can_create_tree1)
{
    ASSERT_NO_THROW(BSTree SS T2);
}
TEST(TBinaryTree, can_Insert_empty_tree1)
{
    BSTree SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, 1));
}
TEST(TBinaryTree, Insert_correct_empty_tree1)
{
    BSTree SS  T1;
    T1.Insert(1, 1);
    EXPECT_EQ(1, (*T1.Find(1)).GetKey());
}
TEST(TBinaryTree, corect_Delete1)
{
    BSTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    T1.Delete(17);
    EXPECT_EQ(8, (*T1.Find(8)).GetKey());
    EXPECT_EQ(28, (*T1.Find(28)).GetKey());
    EXPECT_EQ(41, (*T1.Find(41)).GetKey());
    EXPECT_EQ(nullptr, T1.Find(17));
}
TEST(TBinaryTree, corect_Insert1)
{
    BSTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    T1.Insert(3, 1);
    EXPECT_EQ(3, (*T1.Find(3)).GetKey());
}
TEST(TBinaryTree, corect_Insert_after_Delete1)
{
    BSTree SS  T1;
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
TEST(TBinaryTree, can_not_Insert_record_wich_key_isnt_unique1)
{
    BSTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    ASSERT_ANY_THROW(T1.Insert(17, 2));
}
TEST(TBinaryTree, can_not_Delete_record_wich_key_unique1)
{
    BSTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    ASSERT_ANY_THROW(T1.Delete(88));
}
TEST(TBinaryTree, corect_Search1)
{
    BSTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    EXPECT_EQ(17, (*T1.Find(17)).GetKey());
}
TEST(TBinaryTree, corect_SearchMax1)
{
    BSTree SS  T1;
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
TEST(TBinaryTree, corect_SearchMin1)
{
    BSTree SS  T1;
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
TEST(TBinaryTree, corect_SearchNext1)
{
    BSTree SS  T1;
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
TEST(TBinaryTree, corect_SearchPrev1)
{
    BSTree SS  T1;
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
TEST(TBalanceTree, can_create_tree2)
{
    ASSERT_NO_THROW(AVLTree SS T2);
}
TEST(TBalanceTree, can_Insert_empty_tree2)
{
    AVLTree SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, 1));
}
TEST(TBalanceTree, Insert_correct_empty_tree2)
{
    AVLTree SS  T1;
    T1.Insert(1, 1);
    EXPECT_EQ(1, (*T1.Find(1)).GetKey());
}
TEST(TBalanceTree, corect_Delete2)
{
    AVLTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    T1.Delete(17);
    EXPECT_EQ(8, (*T1.Find(8)).GetKey());
    EXPECT_EQ(28, (*T1.Find(28)).GetKey());
    EXPECT_EQ(41, (*T1.Find(41)).GetKey());
    EXPECT_EQ(nullptr, T1.Find(17));
}
TEST(TBalanceTree, corect_Insert2)
{
    AVLTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    T1.Insert(3, 1);
    EXPECT_EQ(3, (*T1.Find(3)).GetKey());
 }
TEST(TBalanceTree, corect_Insert_after_Delete2)
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
TEST(TBalanceTree, can_not_Insert_record_wich_key_isnt_unique2)
{
    AVLTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    ASSERT_ANY_THROW(T1.Insert(17, 2));
}
TEST(TBalanceTree, can_not_Delete_record_wich_key_unique2)
{
    AVLTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    ASSERT_ANY_THROW(T1.Delete(88));
}
TEST(TBalanceTree, corect_Search2)
{
    AVLTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    EXPECT_EQ(17, (*T1.Find(17)).GetKey());
}
TEST(TBalanceTree, corect_SearchMax2)
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
TEST(TBalanceTree, corect_SearchMin2)
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
TEST(TBalanceTree, corect_SearchNext2)
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
TEST(TBalanceTree, corect_SearchPrev2)
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
TEST(TBalanceTree, corect_Insert2_1)
{
    AVLTree SS  T1;
    //случай 1 - однократный RR поворот
    T1.Insert(4, 1);
    T1.Insert(1, 12);
    T1.Insert(8, 12);
    T1.Insert(6, 1);
    T1.Insert(10, 1);
    T1.Insert(12, 1);
    EXPECT_EQ(12, (*T1.Find(12)).GetKey());
}
TEST(TBalanceTree, corect_Insert2_2)
{
    AVLTree SS  T1;
    // случай 1 - однократный LL поворот
   T1.Insert(20, 1);
   T1.Insert(17, 12);
   T1.Insert(22, 12);
   T1.Insert(11, 1);
   T1.Insert(18, 1);
   T1.Insert(7, 1);
   EXPECT_EQ(7, (*T1.Find(7)).GetKey());
}
TEST(TBalanceTree, corect_Insert2_3)
{
    AVLTree SS  T1;
    //случай 2 - двукратный LR поворот
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
    EXPECT_EQ(19, (*T1.Find(19)).GetKey());
}
TEST(TBalanceTree, corect_Insert2_4)
{
    AVLTree SS  T1;
    //случай 2 - двукратный RL поворот
    T1.Insert(15, 1);
    T1.Insert(5, 12);
    T1.Insert(25, 12);
    T1.Insert(4, 1);
    T1.Insert(7, 1);
    T1.Insert(1, 1);
    EXPECT_EQ(1,(*T1.Find(1)).GetKey());
}
TEST(TBalanceTree, corect_Delete2_1)
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
    EXPECT_EQ(nullptr, T1.Find(1));
}
TEST(TBalanceTree, corect_Delete2_2)
{
    AVLTree SS  T1;
    //удаление 2
   T1.Insert(10, 1);
   T1.Insert(3, 12);
   T1.Insert(25, 12);
   T1.Insert(1, 1);
   T1.Insert(4, 1);
   T1.Delete(25);
    EXPECT_EQ(nullptr, T1.Find(25));
}
TEST(TBalanceTree, corect_Delete2_3)
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
   T1.Delete(9);
    EXPECT_EQ(nullptr, T1.Find(9));
}

//Тесты для класса таблиц на АВЛ деревьях
TEST(AVLTable, can_create_table1)
{
    ASSERT_NO_THROW(AVLTable FF T2);
}
TEST(AVLTable, can_not_GetData_empty_table1)
{
    AVLTable FF  T1;
    ASSERT_ANY_THROW(T1.GetData());
}
TEST(AVLTable, can_not_GetKey_empty_table1)
{
    AVLTable FF  T1;
    ASSERT_ANY_THROW(T1.GetKey());
}
TEST(AVLTable, can_not_SetNext_empty_table1)
{
    AVLTable FF  T1;
    ASSERT_ANY_THROW(T1.SetNext());
}
TEST(AVLTable, can_not_Delete_empty_table1)
{
    AVLTable FF  T1;
    ASSERT_ANY_THROW(T1.Delete("one"));
}
TEST(AVLTable, can_not_Search_empty_table1)
{
    AVLTable FF  T1;
    ASSERT_ANY_THROW(T1.Search("one"));
}
TEST(AVLTable, can_Insert_empty_table1)
{
    AVLTable FF  T1;
    ASSERT_NO_THROW(T1.Insert(1, "one"));
}
TEST(AVLTable, Insert_correct_empty_table1)
{
    AVLTable FF  T1;
    T1.Insert(1, "one");
    EXPECT_EQ(1, T1.GetCount());
    EXPECT_EQ(1, *(T1.Search("one")));
}
TEST(AVLTable, can_GetData1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(*(T1.GetData()));
}
TEST(AVLTable, GetData_corect1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    EXPECT_EQ(8, *(T1.GetData()));
}
TEST(AVLTable, can_GetKey1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.GetKey());
}
TEST(AVLTable, GetKey_corect1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    EXPECT_EQ("1 record", T1.GetKey());
}
TEST(AVLTable, can_SetNext1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.SetNext());
}
TEST(AVLTable, SetNext_correct1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    T1.SetNext();
    EXPECT_EQ(17, *(T1.GetData()));
}
TEST(AVLTable, corect_Delete1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("2 record");
    T1.Reset();
    EXPECT_EQ(8, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(28, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(41, *(T1.GetData()));
}
TEST(AVLTable, empty_after_Delete1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("1 record");
    T1.Delete("2 record");
    T1.Delete("3 record");
    T1.Delete("4 record");
    EXPECT_EQ(true, T1.IsEmpty());
}
TEST(AVLTable, corect_Insert1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");    

    }
    T1.Insert(5, "5 record");
    T1.Reset();
    T1.SetNext();
    T1.SetNext();
    T1.SetNext();
    T1.SetNext();
    EXPECT_EQ(5, *(T1.GetData()));
}
TEST(AVLTable, corect_Insert_after_Delete1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("1 record");
    T1.Delete("2 record");
    T1.Delete("3 record");
    T1.Delete("4 record");
    T1.Insert(0, "0");
    T1.Reset();
    EXPECT_EQ(0, *(T1.GetData()));

   

}
TEST(AVLTable, corect_Search1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    EXPECT_EQ(17, *(T1.Search("2 record")));
}
TEST(AVLTable, can_not_Insert_record_wich_key_isnt_unique1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    ASSERT_ANY_THROW(T1.Insert(2, "2 record"));
}
TEST(AVLTable, can_copy_empty_table1)
{
    AVLTable FF  T1;
    ASSERT_NO_THROW(AVLTable FF T2(T1));
}
TEST(AVLTable, can_copy_table1)
{
    AVLTable FF  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    ASSERT_NO_THROW(AVLTable FF  A(T1));
}
TEST(AVLTable, copied_table_correct1)
{
    AVLTable FF T1;

    for (int i = 0; i < 4; i++)
    {
        string s;
        s = to_string(i + 1) + " record";
        T1.Insert((i + 1) * 8 + (i * i) % 13, s);
    }
    AVLTable FF  A(T1);
    A.Reset();
    EXPECT_EQ(8, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(17, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(28, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(41, *(A.GetData()));
}
