#include <gtest.h>
#include "AVLTree.h"

TEST(AVLTree, delete_right_child_with_only_left_child)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');

	EXPECT_TRUE(T.Delete(10));
	EXPECT_EQ(nullptr, T.Find(10));
}

TEST(AVLTree, delete_right_child_with_only_right_child)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(11, ' ');

	EXPECT_TRUE(T.Delete(10));
	EXPECT_EQ(nullptr, T.Find(10));
}

TEST(AVLTree, delete_left_child_with_only_right_child)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(4, ' ');

	EXPECT_TRUE(T.Delete(3));
	EXPECT_EQ(nullptr, T.Find(3));
}

TEST(AVLTree, delete_left_child_with_only_left_child)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(2, ' ');

	EXPECT_TRUE(T.Delete(3));
	EXPECT_EQ(nullptr, T.Find(3));
}

TEST(AVLTree, delete_root_with_two_child)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');

	EXPECT_TRUE(T.Delete(5));
	EXPECT_EQ(nullptr, T.Find(5));
}

TEST(AVLTree, delete_root_with_one_child)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(2, ' ');
	T.Insert(1, ' ');

	EXPECT_TRUE(T.Delete(5));
	EXPECT_EQ(nullptr, T.Find(5));
}

TEST(AVLTree, delete_root_with_zero_child)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');

	EXPECT_TRUE(T.Delete(5));
	EXPECT_EQ(nullptr, T.Find(5));
}

TEST(AVLTree, cant_delete_at_empty_tree)
{
	AVLTree<int, char> T;

	EXPECT_FALSE(T.Delete(10));
}

TEST(AVLTree, find_correct)
{
	AVLTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');

	EXPECT_EQ('e', *(T.Find(9)));
}

TEST(AVLTree, can_clear)
{
	AVLTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');

	ASSERT_NO_THROW(T.Clear());
}

TEST(AVLTree, empty_after_clear)
{
	AVLTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');
	T.Clear();
	EXPECT_TRUE(T.isEmpty());
}

TEST(AVLTree, find_min_correct)
{
	AVLTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');
	EXPECT_EQ(3, T.FindMin()->key);
}

TEST(AVLTree, find_next_correct)
{
	AVLTree<int, char> T;
	T.Insert(5, 'a');
	T.Insert(3, 'b');
	T.Insert(10, 'c');
	T.Insert(6, 'd');
	T.Insert(9, 'e');
	TreeNode<int, char>* tmp = T.FindMin();
	EXPECT_EQ(5, T.FindNext(tmp)->key);
}

TEST(AVLTree, insert_correct)
{
	AVLTree<int, char> T;
	T.Insert(5, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(6, ' ');
	T.Insert(2, ' ');

	EXPECT_TRUE(T.Insert(100, 'a'));
	EXPECT_EQ('a', *T.Find(100));
}