#include <gtest.h>

#include "tnode.h"

/*
TEST(TNode, TEST_NAME) {

}
*/

// DefaultConstructorTest
TEST(TNode, DefaultConstructorTest_Constructor) {
	ASSERT_NO_THROW(TNode<int>*node = new TNode<int>);
}

TEST(TNode, DefaultConstructorTest_key) {
	TNode<int>* node = new TNode<int>;
	EXPECT_EQ(0, node->key);
}

TEST(TNode, DefaultConstructorTest_pointer) {
	TNode<int>* node = new TNode<int>;
	EXPECT_EQ(nullptr, node->pNext);
}

// ParameterizedConstructorTests
// DataParameter
TEST(TNode, ParameterizedConstructorTest_DataParameter_Constructor) {
	ASSERT_NO_THROW(TNode<int>* node = new TNode<int>(3));
}

TEST(TNode, ParameterizedConstructorTest_DataOperand_data) {
	TNode<int>* node = new TNode<int>(3);
	EXPECT_EQ(3, node->key);
}

TEST(TNode, ParameterizedConstructorTest_DataOperand_pointer) {
	TNode<int>* node = new TNode<int>(3);
	EXPECT_EQ(nullptr, node->pNext);
}

// PointerParameter
TEST(TNode, ParameterizedConstructorTest_PointerParameter_Constructor) {
	TNode<int>* tmp = new TNode<int>(3);
	ASSERT_NO_THROW(TNode<int>* node = new TNode<int>(tmp));
}

TEST(TNode, ParameterizedConstructorTest_PointerParameter_data) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(tmp);

	EXPECT_EQ(0, node->key);
}

TEST(TNode, ParameterizedConstructorTest_PointerParameter_pointer) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(tmp);

	EXPECT_EQ(tmp, node->pNext);
}

TEST(TNode, ParameterizedConstructorTest_PointerParameter_pointer_data) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(tmp);

	EXPECT_EQ(3, node->pNext->key);
}

TEST(TNode, ParameterizedConstructorTest_PointerParameter_pointer_pointer) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(tmp);

	EXPECT_EQ(nullptr, node->pNext->pNext);
}


// DataAndPointerParameter
TEST(TNode, ParameterizedConstructorTest_DataAndPointerParameter_Constructor) {
	TNode<int>* tmp = new TNode<int>(3);
	ASSERT_NO_THROW(TNode<int>*node = new TNode<int>(1, tmp));
}

TEST(TNode, ParameterizedConstructorTest_DataAndPointerParameter_data) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(1, tmp);

	EXPECT_EQ(1, node->key);
}

TEST(TNode, ParameterizedConstructorTest_DataAndPointerParameter_pointer) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(1, tmp);

	EXPECT_EQ(tmp, node->pNext);
}

TEST(TNode, ParameterizedConstructorTest_DataAndPointerParameter_pointer_data) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(1, tmp);

	EXPECT_EQ(3, node->pNext->key);
}

TEST(TNode, ParameterizedConstructorTest_DataAndPointerParameter_pointer_pointer) {
	TNode<int>* tmp = new TNode<int>(3);
	TNode<int>* node = new TNode<int>(1, tmp);

	EXPECT_EQ(nullptr, node->pNext->pNext);
}