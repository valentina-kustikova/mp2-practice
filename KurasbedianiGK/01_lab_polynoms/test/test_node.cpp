#include "node.h"
#include "gtest.h"

TEST(Node, can_create_node) {
    ASSERT_NO_THROW(Node<int>(4, nullptr));
}

TEST(Node, can_create_node_via_copy_ctor) {
    Node<int> node(4, nullptr);

    ASSERT_NO_THROW(Node<int>{node});
}

TEST(Node, created_node_via_copy_ctor_is_correct) {
    Node<int> node(4, nullptr);

    EXPECT_EQ(node, Node<int>{node});
}

TEST(Node, operator_less) {
    Node<int> node(4, nullptr);
    Node<int> node1(5, nullptr);

    EXPECT_LT(node, node1);
}

TEST(Node, operator_less_false) {
    Node<int> node(4, nullptr);

    EXPECT_FALSE(node < node);
}

TEST(Node, operator_eq_eq_true) {
    EXPECT_TRUE(Node<int>(4, nullptr) == Node<int>(4, nullptr));
}

TEST(Node, operator_eq_eq_false) {
    EXPECT_FALSE(Node<int>(4, nullptr) == Node<int>(5, nullptr));
}