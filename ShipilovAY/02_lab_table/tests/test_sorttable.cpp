#include <gtest.h>
#include "SortTable.h"

TEST(SortTable, SortTable_can_be_with_size)
{
	using SortTable = SortTable<char, int>;
	ASSERT_NO_THROW(SortTable S(5));
}

TEST(SortTable, SortTable_cannot_be_isempty)
{
	using SortTable = SortTable<char, int>;
	ASSERT_ANY_THROW(SortTable S(-5));
}

TEST(SortTable, copy_isEmpty)
{
	using SortTable = SortTable<char, int>;
	SortTable S1;
	ASSERT_NO_THROW(SortTable S(S1));
}

TEST(SortTable, cannot_SetNext_isEmpty)
{
	SortTable<char, int> S;
	ASSERT_NO_THROW(S.SetNext());
}

TEST(SortTable, correct_isEmpty_isEnd)
{
	SortTable<char, int> S;
	EXPECT_EQ(true, S.IsEnd());
}

TEST(SortTable, correct_getKey)
{
	SortTable<char, int> S;
	S.Insert('x', 1);
	S.Reset();
	EXPECT_EQ(1, S.GetKey());
}

TEST(SortTable, correct_getData)
{
	SortTable<char, int> S;
	S.Insert('x', 1);
	S.Reset();
	EXPECT_EQ('x', *S.GetData());
}

TEST(SortTable, after_Delete_isEmpty)
{
	SortTable<char, int> S;
	S.Insert('x', 1);
	S.Delete(1);
	EXPECT_TRUE(S.IsEmpty());
}

TEST(SortTable, correct_Insert_after_Delete)
{
	SortTable<char, int> S;
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Delete(2);
	S.Insert('y', 5);
	S.Reset(); S.SetNext(); S.SetNext();
	EXPECT_EQ('y', *S.GetData());
}

TEST(SortTable, correct_seasrch)
{
	SortTable<char, int> S(6);
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Insert('x^2', 4);
	S.Insert('y^2', 5);
	char* tmp = S.Search(2);
	EXPECT_EQ('y', *tmp);
}

TEST(SortTable, not_search_nullptr)
{
	SortTable<char, int> S(5);
	S.Insert('x', 1);
	S.Insert('y', 3);
	S.Insert('z', 2);
	S.Insert('x^2', 4);
	ASSERT_ANY_THROW(S.Search(5));
}

TEST(SortTable, correct_insert)
{
	SortTable<char, int> S(5);
	S.Insert('x', 1);
	S.Insert('z', 3);
	S.Insert('y', 2);
	S.Insert('x^2', 4);
	S.Insert('x', 5);
	EXPECT_NE(nullptr, S.Search(5));
}

TEST(SortTable, correct_delete)
{
	SortTable<char, int> S(4);
	S.Insert('x', 1);
	S.Insert('z', 3);
	S.Insert('y', 2);
	S.Delete(3);
	ASSERT_ANY_THROW(S.Search(3));
}

TEST(SortTable, correct_Clear)
{
	SortTable<char, int> S(4);
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Clear();
	EXPECT_EQ(true, S.IsEmpty());
}

TEST(SortTable, no_insert_with_not_key)
{
	SortTable<char, int> S;
	S.Insert('a', 1);
	S.Insert('b', 2);
	S.Insert('b', 3);
	EXPECT_NE(3, *(S.GetData()));
}

TEST(SortTable, throw_delete_no_key)
{
	SortTable<char, int> S(5);
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Insert('x^2', 4);
	ASSERT_NO_THROW(S.Delete(5));
}

TEST(SortTable, correct_clear)
{
	SortTable<char, int> S(4);
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Clear();
	EXPECT_EQ(true, S.IsEmpty());
}