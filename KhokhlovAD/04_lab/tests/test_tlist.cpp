#include "tlist.h"
#include <gtest.h>

//constructors/destructor
/////////////////////////////////////////////////
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

TEST(TList, destructor)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	ASSERT_NO_THROW(b.clear());
}
/////////////////////////////////////////////////


//empty
/////////////////////////////////////////////////
TEST(TList, empty_list_is_empty)
{
	TList<int> b;
	ASSERT_TRUE(b.isEmpty());
}

TEST(TList, not_empty_list_isnt_empty)
{
	TNode<int>* a = new TNode<int>(2);
	TList<int> b(a);
	ASSERT_FALSE(b.isEmpty());
}
/////////////////////////////////////////////////

//end
/////////////////////////////////////////////////

/////////////////////////////////////////////////