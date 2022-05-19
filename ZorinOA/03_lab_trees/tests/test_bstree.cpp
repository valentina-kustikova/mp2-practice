#include <gtest.h>
#include "BinarySearchTree.h"

TEST(BinarySearchTree, delete_right_child_with_only_left_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');

	EXPECT_TRUE(T.Delete(10));
	EXPECT_EQ(nullptr, T.Find(10));
}

TEST(BinarySearchTree, delete_right_child_with_only_right_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(11, ' ');

	EXPECT_TRUE(T.Delete(10));
	EXPECT_EQ(nullptr, T.Find(10));
}

TEST(BinarySearchTree, delete_left_child_with_only_right_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(4, ' ');

	EXPECT_TRUE(T.Delete(3));
	EXPECT_EQ(nullptr, T.Find(3));
}

TEST(BinarySearchTree, delete_left_child_with_only_left_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(2, ' ');

	EXPECT_TRUE(T.Delete(3));
	EXPECT_EQ(nullptr, T.Find(3));
}

TEST(BinarySearchTree, delete_root_with_two_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');

	EXPECT_TRUE(T.Delete(5));
	EXPECT_EQ(nullptr, T.Find(5));
}

TEST(BinarySearchTree, delete_root_with_one_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(2, ' ');
	T.Insert(1, ' ');

	EXPECT_TRUE(T.Delete(5));
	EXPECT_EQ(nullptr, T.Find(5));
}

TEST(BinarySearchTree, delete_root_with_zero_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');

	EXPECT_TRUE(T.Delete(5));
	EXPECT_EQ(nullptr, T.Find(5));
}

TEST(BinarySearchTree, cant_delete_at_empty_tree)
{
	BSTree<int, char> T;

	EXPECT_FALSE(T.Delete(10));
}

TEST(BinarySearchTree, find_correct)
{
	BSTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');

	EXPECT_EQ('e', *(T.Find(9)));
}

TEST(BinarySearchTree, can_clear)
{
	BSTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');

	ASSERT_NO_THROW(T.Clear());
}

TEST(BinarySearchTree, empty_after_clear)
{
	BSTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');
	T.Clear();
	EXPECT_TRUE(T.isEmpty());
}

TEST(BinarySearchTree, find_min_correct)
{
	BSTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');
	EXPECT_EQ(3, T.FindMin()->key);
}

TEST(BinarySearchTree, find_next_correct)
{
	BSTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');
	TreeNode<int, char>* tmp = T.FindMin();
	EXPECT_EQ(5, T.FindNext(tmp)->key);
}

TEST(BinarySearchTree, insert_correct)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(2, ' ');

	EXPECT_TRUE(T.Insert(100, 'a'));
	EXPECT_EQ('a', *T.Find(100));
}