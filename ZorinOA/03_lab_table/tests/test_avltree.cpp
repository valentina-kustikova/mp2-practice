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

TEST(AVLTree, correct_balancing_small_left_rotate_with_root)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(30, ' ');
	T.Insert(70, ' ');
	//T.Insert(10, ' ');
	//T.Insert(40, ' ');
	T.Insert(60, ' ');
	T.Insert(80, ' ');

	//T.Print();
	T.Insert(75, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(50, node->key);
	EXPECT_EQ(60, node->right->key);
	EXPECT_EQ(30, node->left->key);
	node = node->parent;
	EXPECT_EQ(70, node->key);
	EXPECT_EQ(80, node->right->key);
	EXPECT_EQ(50, node->left->key);
	node = node->right;
	EXPECT_EQ(75, node->left->key);
}

TEST(AVLTree, correct_balancing_small_right_rotate_with_root)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(30, ' ');
	T.Insert(70, ' ');
	T.Insert(10, ' ');
	T.Insert(40, ' ');
	//T.Insert(60, ' ');
	//T.Insert(80, ' ');

	//T.Print();
	T.Insert(5, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(10, node->key);
	EXPECT_EQ(5, node->left->key);
	node = node->parent;
	EXPECT_EQ(30, node->key);
	EXPECT_EQ(10, node->left->key);
	EXPECT_EQ(50, node->right->key);
	node = node->right;
	EXPECT_EQ(40, node->left->key);
	EXPECT_EQ(70, node->right->key);
}

TEST(AVLTree, correct_balancing_big_left_rotate_with_root)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(30, ' ');
	T.Insert(70, ' ');
	//T.Insert(10, ' ');
	//T.Insert(40, ' ');
	T.Insert(60, ' ');
	T.Insert(80, ' ');

	//T.Print();
	T.Insert(55, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(50, node->key);
	EXPECT_EQ(55, node->right->key);
	EXPECT_EQ(30, node->left->key);
	node = node->parent;
	EXPECT_EQ(60, node->key);
	EXPECT_EQ(70, node->right->key);
	EXPECT_EQ(50, node->left->key);
	node = node->right;
	EXPECT_EQ(80, node->right->key);
}

TEST(AVLTree, correct_balancing_big_right_rotate_with_root)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(30, ' ');
	T.Insert(70, ' ');
	T.Insert(10, ' ');
	T.Insert(40, ' ');
	//T.Insert(60, ' ');
	//T.Insert(80, ' ');

	//T.Print();
	T.Insert(45, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(30, node->key);
	EXPECT_EQ(10, node->left->key);
	node = node->parent;
	EXPECT_EQ(40, node->key);
	EXPECT_EQ(30, node->left->key);
	EXPECT_EQ(50, node->right->key);
	node = node->right;
	EXPECT_EQ(45, node->left->key);
	EXPECT_EQ(70, node->right->key);
}

TEST(AVLTree, correct_balancing_small_right_rotate)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(30, ' ');
	T.Insert(500, ' ');
	T.Insert(10, ' ');
	T.Insert(40, ' ');
	T.Insert(300, ' ');
	T.Insert(700, ' ');
	T.Insert(100, ' ');
	T.Insert(400, ' ');

	//T.Print();
	T.Insert(99, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(30, node->key);
	EXPECT_EQ(10, node->left->key);
	EXPECT_EQ(40, node->right->key);
	node = node->parent;
	EXPECT_EQ(50, node->key);
	EXPECT_EQ(30, node->left->key);
	EXPECT_EQ(300, node->right->key);
	node = node->right;
	EXPECT_EQ(100, node->left->key);
	EXPECT_EQ(99, node->left->left->key);
	EXPECT_EQ(500, node->right->key);
	node = node->right;
	EXPECT_EQ(400, node->left->key);
	EXPECT_EQ(700, node->right->key);
}

TEST(AVLTree, correct_balancing_small_left_rotate)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(80, ' ');
	T.Insert(5, ' ');
	T.Insert(70, ' ');
	T.Insert(90, ' ');
	T.Insert(3, ' ');
	T.Insert(7, ' ');
	T.Insert(6, ' ');
	T.Insert(9, ' ');

	//T.Print();
	T.Insert(8, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(5, node->key);
	EXPECT_EQ(6, node->right->key);
	EXPECT_EQ(3, node->left->key);
	node = node->parent;
	EXPECT_EQ(7, node->key);
	EXPECT_EQ(9, node->right->key);
	EXPECT_EQ(5, node->left->key);
	node = node->right;
	EXPECT_EQ(8, node->left->key);
	node = node->parent->parent;
	EXPECT_EQ(50, node->key);
	EXPECT_EQ(80, node->right->key);
	EXPECT_EQ(7, node->left->key);
	node = node->right;
	EXPECT_EQ(90, node->right->key);
	EXPECT_EQ(70, node->left->key);
}

TEST(AVLTree, correct_balancing_big_left_rotate)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(80, ' ');
	T.Insert(5, ' ');
	T.Insert(70, ' ');
	T.Insert(90, ' ');
	T.Insert(3, ' ');
	T.Insert(10, ' ');
	T.Insert(9, ' ');
	T.Insert(11, ' ');

	//T.Print();
	T.Insert(8, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(5, node->key);
	EXPECT_EQ(8, node->right->key);
	EXPECT_EQ(3, node->left->key);
	node = node->parent;
	EXPECT_EQ(9, node->key);
	EXPECT_EQ(10, node->right->key);
	EXPECT_EQ(5, node->left->key);
	node = node->right;
	EXPECT_EQ(11, node->right->key);
	node = node->parent->parent;
	EXPECT_EQ(50, node->key);
	EXPECT_EQ(80, node->right->key);
	EXPECT_EQ(9, node->left->key);
	node = node->right;
	EXPECT_EQ(90, node->right->key);
	EXPECT_EQ(70, node->left->key);
}

TEST(AVLTree, correct_balancing_big_right_rotate)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(30, ' ');
	T.Insert(500, ' ');
	T.Insert(10, ' ');
	T.Insert(40, ' ');
	T.Insert(300, ' ');
	T.Insert(700, ' ');
	T.Insert(100, ' ');
	T.Insert(400, ' ');

	//T.Print();
	T.Insert(450, ' ');
	//T.Print();

	TreeNode<int, char>* node = T.FindMin()->parent;
	EXPECT_EQ(30, node->key);
	EXPECT_EQ(10, node->left->key);
	EXPECT_EQ(40, node->right->key);
	node = node->parent;
	EXPECT_EQ(50, node->key);
	EXPECT_EQ(30, node->left->key);
	EXPECT_EQ(400, node->right->key);
	node = node->right;
	EXPECT_EQ(300, node->left->key);
	EXPECT_EQ(100, node->left->left->key);
	EXPECT_EQ(500, node->right->key);
	node = node->right;
	EXPECT_EQ(450, node->left->key);
	EXPECT_EQ(700, node->right->key);
}

TEST(AVLTree, correct_tree_big_size)
{
	AVLTree<int, char> T;
	T.Insert(50, ' ');
	T.Insert(70, ' ');
	T.Insert(30, ' ');
	T.Insert(20, ' ');
	T.Insert(35, ' ');
	T.Insert(60, ' ');
	T.Insert(80, ' ');
	T.Delete(35);
	T.Insert(75, ' ');
	T.Insert(65, ' ');
	T.Insert(55, ' ');
	T.Insert(85, ' ');
	T.Insert(31, ' ');
	T.Insert(36, ' ');
	T.Insert(22, ' ');
	T.Delete(31);
	T.Delete(50);
	T.Insert(52, ' ');
	T.Insert(56, ' ');
	T.Insert(90, ' ');
	T.Insert(66, ' ');
	T.Insert(51, ' ');
	T.Insert(37, ' ');
	T.Insert(10, ' ');
	T.Insert(5, ' ');
	T.Delete(90);
	T.Delete(22);
	//T.Print();
	T.Insert(38, ' ');
	T.Insert(53, ' ');
	T.Insert(32, ' ');
	T.Insert(54, ' ');
	T.Delete(60);
	T.Delete(50);
	T.Delete(56);
	T.Insert(100, ' ');
	T.Insert(1, ' ');
	T.Insert(90, ' ');
	T.Insert(16, ' ');
	T.Insert(56, ' ');
	T.Delete(100);
	T.Delete(52);
	T.Delete(55);
	T.Delete(70);
	T.Insert(52, ' ');
	//T.Print();
	
	TreeNode<int, char>* node = T.FindMin()->parent->parent;
	EXPECT_EQ(10, node->key);
	EXPECT_EQ(5, node->left->key);
	EXPECT_EQ(20, node->right->key);
	EXPECT_EQ(1, node->left->left->key);
	EXPECT_EQ(16, node->right->left->key);
	node = node->parent;
	EXPECT_EQ(30, node->key);
	EXPECT_EQ(10, node->left->key);
	EXPECT_EQ(36, node->right->key);
	EXPECT_EQ(32, node->right->left->key);
	node = node->parent;
	EXPECT_EQ(37, node->key);
	EXPECT_EQ(30, node->left->key);
	EXPECT_EQ(56, node->right->key);
	node = node->right;
	EXPECT_EQ(56, node->key);
	EXPECT_EQ(51, node->left->key);
	EXPECT_EQ(75, node->right->key);
	node = node->right;
	EXPECT_EQ(75, node->key);
	EXPECT_EQ(65, node->left->key);
	EXPECT_EQ(85, node->right->key);
	EXPECT_EQ(80, node->right->left->key);
	EXPECT_EQ(90, node->right->right->key);
	EXPECT_EQ(66, node->left->right->key);
	node = node->parent->left;
	EXPECT_EQ(51, node->key);
	EXPECT_EQ(38, node->left->key);
	EXPECT_EQ(53, node->right->key);
	EXPECT_EQ(52, node->right->left->key);
	EXPECT_EQ(54, node->right->right->key);

}