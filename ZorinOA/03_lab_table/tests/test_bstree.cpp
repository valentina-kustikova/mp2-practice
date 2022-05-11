#include <gtest.h>
#include "BinarySearchTree.h"

TEST(BinarySearchTree, can_delete_right_child_with_only_left_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');

	ASSERT_NO_THROW(T.Delete(10));
}

TEST(BinarySearchTree, can_delete_right_child_with_only_right_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(11, ' ');

	ASSERT_NO_THROW(T.Delete(10));
}

TEST(BinarySearchTree, can_delete_left_child_with_only_right_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(4, ' ');

	ASSERT_NO_THROW(T.Delete(3));
}

TEST(BinarySearchTree, can_delete_left_child_with_only_left_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(2, ' ');

	ASSERT_NO_THROW(T.Delete(3));
}

TEST(BinarySearchTree, can_delete_root_with_two_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');
	
	ASSERT_NO_THROW(T.Delete(5));
}

TEST(BinarySearchTree, can_delete_root_with_one_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(2, ' ');
	T.Insert(1, ' ');

	ASSERT_NO_THROW(T.Delete(5));
}

TEST(BinarySearchTree, can_delete_root_with_zero_child)
{
	BSTree<int, char> T;
	T.Insert(5, ' ');

	ASSERT_NO_THROW(T.Delete(5));
}

TEST(BinarySearchTree, cant_delete_at_empty_tree)
{
	BSTree<int, char> T;

	ASSERT_NO_THROW(T.Delete(5));
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