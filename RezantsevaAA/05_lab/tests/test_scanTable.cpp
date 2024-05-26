#include "tabRecord.h"
#include "table.h"
#include "scanTable.h"
#include <gtest.h>

//TabRecord 
TEST(TTabRecord, can_get_key)
{
	TTabRecord<int, int> rec(3, 5);
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

TEST(TTabRecord, can_right_get_data)
{
	TTabRecord<int, int> rec(3, 5);
	EXPECT_EQ(5, *rec.GetData());
}

//-----------------------------------------------------------------------------------
//ScanTable
TEST(TScanTable, can_copy_scanTable_right)
{
	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));

	TScanTable<int, std::string> copy(st);
	EXPECT_EQ(st.Find(1)->GetKey(), copy.Find(1)->GetKey());
}
//------------------------------------------------INSERT
TEST(TScanTable, can_insert)
{
	TScanTable<int, std::string> st(3);
	ASSERT_NO_THROW(st.Insert(1, std::string("abc")));
}
TEST(TScanTable, can_insert_right)
{
	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	EXPECT_EQ(1, st.Find(1)->GetKey());
}
//------------------------------------------------REMOVE
TEST(TScanTable, can_remove)
{
	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	ASSERT_NO_THROW(st.Remove(1));
}
TEST(TScanTable, cant_remove)
{
	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	st.Insert(3, std::string("abcd"));
	ASSERT_ANY_THROW(st.Remove(7));
}
//------------------------------------------------FIND
TEST(TScanTable, can_find)
{
	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	ASSERT_NO_THROW(st.Find(1));
}
TEST(TScanTable, cant_find)
{
	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	st.Insert(3, std::string("abcd"));
	EXPECT_EQ(nullptr, st.Find(7));
}
TEST(TScanTable, can_find_right)
{
	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	st.Insert(3, std::string("abcd"));
	st.Insert(7, std::string("abd"));
	EXPECT_EQ(3, st.Find(3)->GetKey());
}
//------------------------------------------------GetData
TEST(TScanTable, can_getData)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.GetData());
}

TEST(TScanTable, can_getData_right)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	EXPECT_EQ(73, *st.Find(3)->GetData());
}
//------------------------------------------------GetKey
TEST(TScanTable, can_getKey)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.GetKey());
}

TEST(TScanTable, can_getKey_right)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	EXPECT_EQ(3, st.Find(3)->GetKey());
}
//------------------------------------------------GetSize
TEST(TScanTable, can_getSize)
{
	TScanTable<int, int> st(3);
	ASSERT_NO_THROW(st.GetSize());
}
TEST(TScanTable, can_getSize_right)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	EXPECT_EQ(3, st.GetSize());
}
//------------------------------------------------IsFull
TEST(TScanTable, can_is_full)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	ASSERT_NO_THROW(st.IsFull());
}
TEST(TScanTable, check_is_not_full)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	EXPECT_EQ(false, st.IsFull());
}
TEST(TScanTable, check_is_full)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	EXPECT_EQ(true, st.IsFull());
}
//------------------------------------------------IsEmpty
TEST(TScanTable, can_is_empty)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.IsEmpty());
}
TEST(TScanTable, check_is_not_empty)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	EXPECT_EQ(false, st.IsEmpty());
}
TEST(TScanTable, check_is_empty)
{
	TScanTable<int, int> st(3);
	EXPECT_EQ(true, st.IsEmpty());
}
//------------------------------------------------IsTabEnded
TEST(TScanTable, can_IsTabEnded)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.IsTabEnded());
}
TEST(TScanTable, check_Is_not_TabEnded)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	EXPECT_EQ(false, st.IsTabEnded());
}
TEST(TScanTable, check_IsTabEnded)
{
	TScanTable<int, int> st(1);
	st.Insert(1, 52);
	st.Next();
	EXPECT_EQ(true, st.IsTabEnded());
}
//------------------------------------------------Next
TEST(TScanTable, can_Next)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.Next());
}
TEST(TScanTable, can_Next_right)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Reset();
	st.Next();
	EXPECT_EQ(3, st.GetKey());
}
//------------------------------------------------Reset
TEST(TScanTable, can_Reset)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.Reset());
}
TEST(TScanTable, can_Reset_right)
{
	TScanTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Reset();
	EXPECT_EQ(1, st.GetKey());
}
