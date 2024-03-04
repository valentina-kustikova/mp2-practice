#include "tlist.h"

#include <gtest.h>

TEST(TList, can_create_empty_list)
{
	ASSERT_NO_THROW(TList<int> s() );
}
