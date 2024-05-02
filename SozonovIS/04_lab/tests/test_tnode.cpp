#include "tnode.h"
#include <gtest.h>

TEST(TNode, can_create_node) {
	ASSERT_NO_THROW(TNode<int> node);
}

TEST(TNode, can_create_node_with_data) {
	ASSERT_NO_THROW(TNode<int>* node = new TNode<int>(5));
}

TEST(TNode, next_node_is_null) {
	TNode<int>* node = new TNode<int>(5);
	EXPECT_EQ(nullptr, node->pNext);
}

TEST(TNode, data_is_correct) {
	TNode<int>* node = new TNode<int>(5);
	EXPECT_EQ(5, node->data);
}

TEST(TNode, next_node_is_correct) {
	TNode<int>* node = new TNode<int>(5);
    node->pNext = new TNode<int>(6);
	EXPECT_EQ(6, node->pNext->data);
}

TEST(TNode, can_copy_node) {
	TNode<int>* node1 = new TNode<int>(5);
	ASSERT_NO_THROW(TNode<int>* node2 = new TNode<int>(node1->data, node1->pNext));
}

TEST(TNode, copied_node_has_same_data) {
	TNode<int>* node1 = new TNode<int>(5);
	TNode<int>* node2 = new TNode<int>(node1->data, node1->pNext);
	EXPECT_EQ(node1->data, node2->data);
	EXPECT_EQ(node1->pNext, node2->pNext);
}

TEST(TNode, next_node_has_correct_data) {
	TNode<int>* node2 = new TNode<int>(5);
	TNode<int>* node1 = new TNode<int>(4, node2);
	EXPECT_EQ(5, node1->pNext->data);
}