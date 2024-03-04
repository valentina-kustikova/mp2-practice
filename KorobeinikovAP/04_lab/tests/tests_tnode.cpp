#include<gtest.h>

#include "tnode.h"

TEST(TNode, can_create_node_with_data)
{
	ASSERT_NO_THROW(TNode<int> node(52));
}

TEST(TNode, can_create_node_with_data_and_pointer)
{
	TNode<int> next_node(53);

	ASSERT_NO_THROW(TNode<int> node(52, &next_node));
}


TEST(TNode, can_create_copy_of_the_node)
{
	TNode<int> original_node(100);

	ASSERT_NO_THROW(TNode<int> node(original_node));
}


TEST(TNode, copied_node_has_its_own_memory)
{
	TNode<int> a(3);

	TNode<int> b(a);
	b.data = 4;

	ASSERT_NE(b.data, a.data);
}