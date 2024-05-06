#include "ListHeader.h"

#include <gtest.h>


// Default
TEST(TNode, default_constructor_test)
{
	ASSERT_NO_THROW(TNode<int>* pNode = new TNode<int>);
}

TEST(TNode, default_constructor_test_data)
{
	TNode<int>* pNode = new TNode<int>;
	EXPECT_EQ(0, pNode->data);
}

TEST(TNode, default_constructor_test_pnext) {
	TNode<int>* node = new TNode<int>;
	EXPECT_EQ(nullptr, node->pNext);
}

// Parametr
// Data parametr
TEST(TNode, constructor_test_with_parametr)
{
	ASSERT_NO_THROW(TNode<int>*node = new TNode<int>(3));
}

TEST(TNode, constructor_test_with_parametr_data_test) {
	TNode<int>* node = new TNode<int>(3);
	EXPECT_EQ(3, node->data);
}

TEST(TNode, constructor_test_with_parametr_data_pnext_test) {
	TNode<int>* node = new TNode<int>(3);
	EXPECT_EQ(nullptr, node->pNext);
}

// pNext parametr
TEST(TNode, constructor_test_with_parametr_pnext) {
	TNode<int>* tmp = new TNode<int>(3);
	ASSERT_NO_THROW(TNode<int>*node = new TNode<int>(tmp));
}

TEST(TNode, constructor_test_with_parametr_pnext_data_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* pNode = new TNode<int>(tmp);

	EXPECT_EQ(0, pNode->data);
}

TEST(TNode, constructor_test_with_parametr_pnext_pnext_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* pNode = new TNode<int>(tmp);

	EXPECT_EQ(tmp, pNode->pNext);
}

TEST(TNode, constructor_test_with_parametr_pnext_pnext_data_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* pNode = new TNode<int>(tmp);

	EXPECT_EQ(3, pNode->pNext->data);
}

TEST(TNode, constructor_test_with_parametr_pnext_pnext_pnext_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(tmp);

	EXPECT_EQ(nullptr, node->pNext->pNext);
}


// Data and pnext
TEST(TNode, constructor_test_with_parametr_pnext_and_data) {
	TNode<int>* tmp = new TNode<int>(3);
	ASSERT_NO_THROW(TNode<int>* pNode = new TNode<int>(1, tmp));
}

TEST(TNode, constructor_test_with_parametr_pnext_and_data_data_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* pNode = new TNode<int>(1, tmp);

	EXPECT_EQ(1, pNode->data);
}

TEST(TNode, constructor_test_with_parametr_pnext_and_data_pnext_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* pNode = new TNode<int>(1, tmp);

	EXPECT_EQ(tmp, pNode->pNext);
}

TEST(TNode, constructor_test_with_parametr_pnext_and_data_pnext_data_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* pNode = new TNode<int>(1, tmp);

	EXPECT_EQ(3, pNode->pNext->data);
}

TEST(TNode, constructor_test_with_parametr_pnext_and_data_pnext_pnext_test) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* pNode = new TNode<int>(1, tmp);

	EXPECT_EQ(nullptr, pNode->pNext->pNext);
}