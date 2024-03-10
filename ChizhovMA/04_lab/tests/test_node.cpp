#include "ListHeader.h"

#include <gtest.h>

TEST(TNode, create_node)
{
    ASSERT_NO_THROW(TNode<int> n());
}

TEST(TNode, create_node_with_data)
{
    ASSERT_NO_THROW(TNode<int> n(5));
}

TEST(TNode, copy_constructor_node)
{
    TNode<int> n(5);
    ASSERT_NO_THROW(TNode<int> n2(n));
}