#include "tnode.h"

#include <gtest.h>


TEST(TNode, test_constructor) {
	ASSERT_NO_THROW(TNode<int>*node = new TNode<int>);
}

TEST(TNode, test_Constructor_key) {
	TNode<int>* node = new TNode<int>;
	EXPECT_EQ(0, node->key);
}

TEST(TNode, test_constructor_pointer) {
	TNode<int>* node = new TNode<int>;
	EXPECT_EQ(nullptr, node->pNext);
}

TEST(TNode, test_constructor_with_param) {
	ASSERT_NO_THROW(TNode<int>*node = new TNode<int>(5));
}

TEST(TNode, test_constructor_with_param_checkPointer) {
	TNode<int>*node = new TNode<int>(5);
	EXPECT_EQ(nullptr, node->pNext);
}

TEST(TNode, test_constructor_with_param_checkKey) {
	TNode<int>* node = new TNode<int>(5);
	EXPECT_EQ(5, node->key);
}

TEST(TNode, test_constructor_with_param_checkdata) {
	TNode<int>* node1 = new TNode<int>(5);
	TNode<int>* node2 = new TNode<int>(node1);
	EXPECT_EQ(5, node2->pNext->key);
}

TEST(TNode, test_constructor_with_param_checkpointer) {
	TNode<int>* node1 = new TNode<int>(5);
	TNode<int>* node2 = new TNode<int>(node1);
	EXPECT_EQ(nullptr, node2->pNext->pNext);
}

TEST(TNode, test_constructor_with_param_assertnothrow) {
	TNode<int>* node1 = new TNode<int>(5);
	ASSERT_NO_THROW(TNode<int>*node2 = new TNode<int>(1,node1););
}

TEST(TNode, test_constructor_with_param_checkkeysecond) {
	TNode<int>* node1 = new TNode<int>(5);
	TNode<int>* node2 = new TNode<int>(1,node1);
	EXPECT_EQ(5, node2->pNext->key);
}

