#include <gtest.h>
#include "BSTree.h"
#include "AVLTree.h"
#define SS <int,int>
using namespace std;


TEST(TBinaryTree, 121)
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
    cout << T1;
    T1.Delete(8);
    cout << endl << T1;
    //  cout<<endl<<(*T1.search("3")).GetKey();
    //  cout<<endl<<*((*T1.search("3")).GetData());
      //T1.PrintTreeInOrder();
     // ASSERT_NO_THROW(BSTree SS T2(T1));

}


//“есты дл€ класса бинарное поисковое дерево
TEST(TBinaryTree, can_create_tree1)
{
    ASSERT_NO_THROW(BSTree SS T2);
}
TEST(TBinaryTree, can_copy_empty_tree1)
{
    BSTree SS  T1;
    ASSERT_NO_THROW(BSTree SS T2(T1));
}
TEST(TBinaryTree, can_Insert_empty_tree1)
{
    BSTree SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, 1));
}
TEST(TBinaryTree, Insert_correct_empty_tree1)
{ BSTree SS  T1;
  T1.Insert(1, 1);
  EXPECT_EQ(1, (*T1.Find(1)).GetKey());
}
TEST(TBinaryTree, can_copy_tree1)
{
    BSTree SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    ASSERT_NO_THROW(BSTree SS  A(T1));
}
TEST(TBinaryTree, copied_tree_correct1)
{
    BSTree SS T1;
    for (int i = 0; i < 4; i++)
    {
        string s;
        T1.Insert((i + 1) * 8 + (i * i) % 13, 1);
    }
    BSTree SS  A(T1);
    EXPECT_EQ(8, (*A.Find(8)).GetKey());
    EXPECT_EQ(17, (*A.Find(17)).GetKey());
    EXPECT_EQ(28, (*A.Find(28)).GetKey());
    EXPECT_EQ(41, (*A.Find(41)).GetKey());
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
    EXPECT_EQ(18, (*T1.FindMax(T1.Find(8))).GetKey());
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
