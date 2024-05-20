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


