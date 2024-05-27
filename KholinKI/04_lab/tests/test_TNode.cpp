#include <gtest.h>

#include <TNode.h>

TEST(TNode, constructor_default_work) {
	ASSERT_NO_THROW(TNode<double> test());
}

TEST(TNode, constructor_parametr_work) {
	ASSERT_NO_THROW(TNode<double> test(5));
}

TEST(TNode, constructor_copy_work) {
	TNode<double> test1(5);
	ASSERT_NO_THROW(TNode<double> test2(test1));
}

TEST(TNode, different_memory) {
	TNode<double> test1(5);
	test1.data = 3;
	TNode<double> test2(test1);
	test2.data = 7;
	ASSERT_TRUE(&test1 != &test2);
}

TEST(TNode, destructor_work) {
	TNode<double>* test1= new TNode<double>(5);
	test1->data = 3;
	test1->pNext = new TNode<double>(8);
	ASSERT_NO_THROW(delete test1);
}