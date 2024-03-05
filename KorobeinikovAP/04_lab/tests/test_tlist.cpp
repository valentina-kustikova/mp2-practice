#include "tlist.h"

#include <gtest.h>

TEST(TList, can_create_empty_list)
{
	ASSERT_NO_THROW(TList<int> s() );
}


TEST(TList, can_create_list_from_pfirst)
{
	TNode<int> c(54);
	TNode<int> b(53, &c);
	TNode<int> a(52, &b);

	ASSERT_NO_THROW(TList<int> l(&a));
}
