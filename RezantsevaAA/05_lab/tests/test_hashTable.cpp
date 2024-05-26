#include <gtest.h>
#include "arrayHashTable.h"
#include <gtest.h>

//-----------------------------------------------------------------------------------
//TArrayHashTable
TEST(TArrayHashTable, can_copy_hashTable)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ht.Insert(1, std::string("abc"));
	ht.Insert(3, std::string("abcd"));
	ht.Insert(7, std::string("abd"));
	TArrayHashTable<int, std::string> copy(ht);
	EXPECT_EQ(ht.Find(1)->GetKey(), copy.Find(1)->GetKey());
	EXPECT_EQ(ht.Find(3)->GetKey(), copy.Find(3)->GetKey());
	EXPECT_EQ(ht.Find(7)->GetKey(), copy.Find(7)->GetKey());
}

//------------------------------------------------INSERT
TEST(TArrayHashTable, can_insert)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ASSERT_NO_THROW(ht.Insert(1, std::string("abc")));
}
TEST(TArrayHashTable, can_insert_right)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ht.Insert(1, std::string("abc"));
	EXPECT_EQ(1, ht.Find(1)->GetKey());
}

//------------------------------------------------REMOVE
TEST(TArrayHashTable, can_remove)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ht.Insert(1, std::string("abc"));
	ASSERT_NO_THROW(ht.Remove(1));
}

TEST(TArrayHashTable, cant_remove_key_not_found)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ht.Insert(1, std::string("abc"));
	ht.Insert(3, std::string("abcd"));
	ASSERT_ANY_THROW(ht.Remove(7));
}
TEST(TArrayHashTable, cant_remove_table_is_empty)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ASSERT_ANY_THROW(ht.Remove(7));
}

//------------------------------------------------FIND
TEST(TArrayHashTable, can_find)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ht.Insert(1, std::string("abc"));
	ASSERT_NO_THROW(ht.Find(1));
}
TEST(TArrayHashTable, cant_find)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ht.Insert(1, std::string("abc"));
	ht.Insert(3, std::string("abcd"));
	EXPECT_EQ(nullptr, ht.Find(7));
}
TEST(TArrayHashTable, can_find_right)
{
	TArrayHashTable<int, std::string> ht(5, 1);
	ht.Insert(1, std::string("abc"));
	ht.Insert(3, std::string("abcd"));
	ht.Insert(7, std::string("abd"));
	EXPECT_EQ(3, ht.Find(3)->GetKey());
}

//------------------------------------------------GetData
TEST(TArrayHashTable, can_getData)
{
	TArrayHashTable<int, int> ht(5, 1);
	ht.Insert(1, 52);
	ASSERT_NO_THROW(ht.GetData());
}

TEST(TArrayHashTable, can_getData_right)
{
	TArrayHashTable<int, int> ht(5, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	ht.Insert(7, 89);
	EXPECT_EQ(73, *ht.Find(3)->GetData());
}

//------------------------------------------------GetKey
TEST(TArrayHashTable, can_getKey)
{
	TArrayHashTable<int, int> ht(5, 1);
	ht.Insert(1, 52);
	ASSERT_NO_THROW(ht.GetKey());
}

TEST(TArrayHashTable, can_getKey_right)
{
	TArrayHashTable<int, int> ht(5, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	ht.Insert(7, 89);
	EXPECT_EQ(3, ht.Find(3)->GetKey());
}

//------------------------------------------------GetSize
TEST(TArrayHashTable, can_getSize)
{
	TArrayHashTable<int, int> ht(5, 1);
	ASSERT_NO_THROW(ht.GetSize());
}
TEST(TArrayHashTable, can_getSize_right)
{
	TArrayHashTable<int, int> ht(5, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	ht.Insert(7, 89);
	EXPECT_EQ(3, ht.GetSize());
}

//------------------------------------------------IsFull
TEST(TArrayHashTable, can_is_full)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	ht.Insert(7, 89);
	ASSERT_NO_THROW(ht.IsFull());
}
TEST(TArrayHashTable, check_is_not_full)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	EXPECT_EQ(false, ht.IsFull());
}
TEST(TArrayHashTable, check_is_full)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	ht.Insert(7, 89);
	EXPECT_EQ(true, ht.IsFull());
}

//------------------------------------------------IsEmpty
TEST(TArrayHashTable, can_is_empty)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ASSERT_NO_THROW(ht.IsEmpty());
}
TEST(TArrayHashTable, check_is_not_empty)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	EXPECT_EQ(false, ht.IsEmpty());
}
TEST(TArrayHashTable, check_is_empty)
{
	TArrayHashTable<int, int> ht(3, 1);
	EXPECT_EQ(true, ht.IsEmpty());
}

//------------------------------------------------IsTabEnded
TEST(TArrayHashTable, can_IsTabEnded)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ASSERT_NO_THROW(ht.IsTabEnded());
}
TEST(TArrayHashTable, check_Is_not_TabEnded)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	EXPECT_EQ(false, ht.IsTabEnded());
}
TEST(TArrayHashTable, check_IsTabEnded)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Next();
	EXPECT_EQ(true, ht.IsTabEnded());
}

//------------------------------------------------Next
TEST(TArrayHashTable, can_Next)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ASSERT_NO_THROW(ht.Next());
}
TEST(TArrayHashTable, can_Next_right)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	ht.Reset();
	ht.Next();
	EXPECT_EQ(3, ht.GetKey());
}

//------------------------------------------------Reset
TEST(TArrayHashTable, can_Reset)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ASSERT_NO_THROW(ht.Reset());
}
TEST(TArrayHashTable, can_Reset_right)
{
	TArrayHashTable<int, int> ht(3, 1);
	ht.Insert(1, 52);
	ht.Insert(3, 73);
	ht.Reset();
	EXPECT_EQ(1, ht.GetKey());
}