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