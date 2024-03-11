#include "tlist.h"
#include <gtest.h>

TEST(TList, can_create_emrty_list)
{
	ASSERT_NO_THROW(TList<int> a);
}

TEST(TList, can_copy_node)
{
	TNode<int>* a = new TNode<int>(2);
	ASSERT_NO_THROW(TList<int> b(a));
}

TEST(TList, can_copy_list)
{
	TList<int> a;
	ASSERT_NO_THROW(TList<int> b(a));
}