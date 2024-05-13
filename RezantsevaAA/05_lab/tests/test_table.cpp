#include "tabRecord.h"
#include "table.h"
#include <gtest.h>

//TabRecord не можжем тестить из-за двух параметров в <>
TEST(TTabRecord, can_get_key)
{
	TTabRecord<int, int> rec(3,5);
	ASSERT_NO_THROW(rec.GetKey());
}

TEST(TTabRecord, can_right_get_key)
{
	TTabRecord<int, int> rec(3, 5);
	EXPECT_EQ(3, rec.GetKey());
}

TEST(TTabRecord, can_get_data)
{
	TTabRecord<int, int> rec(3, 5);
	ASSERT_NO_THROW(rec.GetData());
}

//TEST(TTabRecord, can_right_get_data)
//{
//	TTabRecord<int, int> rec(3, 5);
//	EXPECT_EQ(5, rec.GetData());
//}
//TScanTable

