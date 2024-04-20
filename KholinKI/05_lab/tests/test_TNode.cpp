#include <gtest.h>

#include <Node.h>

TEST(node, constructor_default_work) {
	ASSERT_NO_THROW(Node<double> test());
}

TEST(node, constructor_parametr_work) {
	ASSERT_NO_THROW(Node<double> test(5));
}

TEST(node, constructor_copy_work) {
	Node<double> test1(5);
	ASSERT_NO_THROW(Node<double> test2(test1));
}

TEST(node, different_memory) {
	Node<double> test1(5);
	test1.data = 3;
	Node<double> test2(test1);
	test2.data = 7;
	ASSERT_TRUE(&test1 != &test2);
}

TEST(node, destructor_work) {
	Node<double>* test1= new Node<double>(5);
	test1->data = 3;
	test1->pNext = new Node<double>(8);
	ASSERT_NO_THROW(delete test1);
}