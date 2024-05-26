#include "sortedTable.h"
#include <gtest.h>

//-----------------------------------------------------------------------------------
//SortedTable
TEST(SortedTable, can_create_sortedTable_w_scanTable)
{

	TScanTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	SortedTable<int, std::string> srt(st);
	EXPECT_EQ(st.GetKey(), srt.GetKey());
}

TEST(SortedTable, can_copy_sortedTable_right)
{
	SortedTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	st.Insert(3, std::string("abcd"));
	st.Insert(7, std::string("abd"));
	st.Reset();
	SortedTable<int, std::string> copy(st);
	EXPECT_EQ(st.Find(1)->GetKey(), copy.Find(1)->GetKey());
	EXPECT_EQ(st.Find(3)->GetKey(), copy.Find(3)->GetKey());
	EXPECT_EQ(st.Find(7)->GetKey(), copy.Find(7)->GetKey());
}

//------------------------------------------------INSERT
TEST(SortedTable, can_insert)
{
	SortedTable<int, std::string> st(3);
	ASSERT_NO_THROW(st.Insert(1, std::string("abc")));
}
TEST(SortedTable, can_insert_right)
{
	SortedTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	EXPECT_EQ(1, st.Find(1)->GetKey());
}

//------------------------------------------------REMOVE
TEST(SortedTable, can_remove)
{
	SortedTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	ASSERT_NO_THROW(st.Remove(1));
}

TEST(SortedTable, cant_remove_key_not_found)
{
	SortedTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	st.Insert(3, std::string("abcd"));
	ASSERT_ANY_THROW(st.Remove(7));
}
TEST(SortedTable, cant_remove_table_is_empty)
{
	SortedTable<int, std::string> st(3);
	ASSERT_ANY_THROW(st.Remove(7));
}

//------------------------------------------------FIND
TEST(SortedTable, can_find)
{
	SortedTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	ASSERT_NO_THROW(st.Find(1));
}
TEST(SortedTable, cant_find)
{
	SortedTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	st.Insert(3, std::string("abcd"));
	EXPECT_EQ(nullptr, st.Find(7));
}
TEST(SortedTable, can_find_right)
{
	SortedTable<int, std::string> st(3);
	st.Insert(1, std::string("abc"));
	st.Insert(3, std::string("abcd"));
	st.Insert(7, std::string("abd"));
	EXPECT_EQ(3, st.Find(3)->GetKey());
}

//------------------------------------------------GetData
TEST(SortedTable, can_getData)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.GetData());
}

TEST(SortedTable, can_getData_right)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3,73);
	st.Insert(7, 89);
	EXPECT_EQ(73, *st.Find(3)->GetData());
}

//------------------------------------------------GetKey
TEST(SortedTable, can_getKey)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.GetKey());
}

TEST(SortedTable, can_getKey_right)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	EXPECT_EQ(3, st.Find(3)->GetKey());
}
//------------------------------------------------GetSize
TEST(SortedTable, can_getSize)
{
	SortedTable<int, int> st(3);
	ASSERT_NO_THROW(st.GetSize());
}
TEST(SortedTable, can_getSize_right)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	EXPECT_EQ(3, st.GetSize());
}

//------------------------------------------------IsFull
TEST(SortedTable, can_is_full)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	ASSERT_NO_THROW(st.IsFull());
}
TEST(SortedTable, check_is_not_full)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	EXPECT_EQ(false, st.IsFull());
}
TEST(SortedTable, check_is_full)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Insert(7, 89);
	EXPECT_EQ(true, st.IsFull());
}

//------------------------------------------------IsEmpty
TEST(SortedTable, can_is_empty)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.IsEmpty());
}
TEST(SortedTable, check_is_not_empty)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	EXPECT_EQ(false, st.IsEmpty());
}
TEST(SortedTable, check_is_empty)
{
	SortedTable<int, int> st(3);
	EXPECT_EQ(true, st.IsEmpty());
}

//------------------------------------------------IsTabEnded
TEST(SortedTable, can_IsTabEnded)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.IsTabEnded());
}
TEST(SortedTable, check_Is_not_TabEnded)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	EXPECT_EQ(false, st.IsTabEnded());
}
TEST(SortedTable, check_IsTabEnded)
{
	SortedTable<int, int> st(1);
	st.Insert(1, 52);
	st.Next();
	EXPECT_EQ(true, st.IsTabEnded());
}

//------------------------------------------------Next
TEST(SortedTable, can_Next)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.Next());
}
TEST(SortedTable, can_Next_right)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Reset();
	st.Next();
	EXPECT_EQ(3, st.GetKey());
}
//------------------------------------------------Reset
TEST(SortedTable, can_Reset)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	ASSERT_NO_THROW(st.Reset());
}
TEST(SortedTable, can_Reset_right)
{
	SortedTable<int, int> st(3);
	st.Insert(1, 52);
	st.Insert(3, 73);
	st.Reset();
	EXPECT_EQ(1, st.GetKey());
}
