#include <gtest.h>
#include "list.h"

TEST(List, can_create_empty_list)
{
	ASSERT_NO_THROW(List<char> L);
}

TEST(List, can_copy_list)
{
	List<char> L;
	ASSERT_NO_THROW(List<char> T(L));
}

TEST(List, can_copy_list_by_operator)
{
	List<char> L;
	ASSERT_NO_THROW(List<char> T = L);
}

TEST(List, insert_to_head_correct)
{
	List<char> L;
	L.InsertToHead('a');
	L.InsertToHead('b');
	L.InsertToHead('c');
	EXPECT_NE(nullptr, L.Search('c'));
}

TEST(List, delete_head_correct)
{
	List<char> L;
	L.InsertToHead('a');
	L.InsertToHead('b');
	L.InsertToHead('c');
	L.DeleteHead();
	EXPECT_EQ(nullptr, L.Search('c'));
}

TEST(List, delete_correct)
{
	List<char> L;
	L.InsertToHead('a');
	L.InsertToHead('b');
	L.InsertToHead('c');
	L.Delete('b');
	EXPECT_EQ(nullptr, L.Search('b'));
}