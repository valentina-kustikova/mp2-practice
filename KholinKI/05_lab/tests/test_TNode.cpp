#include <gtest.h>

#include <Node.h>

TEST(node, constructor_default_work) {
	ASSERT_NO_THROW(Node<double> test());
}

TEST(node, constructor_parametr_work) {
	ASSERT_NO_THROW(Node<double> test(5));
}

TEST(node, constructor_copy_work) {
	Node<double> tesTKey(5);
	ASSERT_NO_THROW(Node<double> tesTData(tesTKey));
}

TEST(node, different_memory) {
	Node<double> tesTKey(5);
	tesTKey.data = 3;
	Node<double> tesTData(tesTKey);
	tesTData.data = 7;
	ASSERT_TRUE(&tesTKey != &tesTData);
}

TEST(node, destructor_work) {
	Node<double>* tesTKey= new Node<double>(5);
	tesTKey->data = 3;
	tesTKey->pNext = new Node<double>(8);
	ASSERT_NO_THROW(delete tesTKey);
}