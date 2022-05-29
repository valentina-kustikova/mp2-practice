#include <gtest.h>
#include "ScanTable.h"

TEST(ScanTable, ScanTable_can_be_with_size)
{
	using ScanTable = ScanTable<char, int>;
	ASSERT_NO_THROW(ScanTable S(5));
}

TEST(ScanTable, ScanTable_cannot_be_isempty)
{
	using ScanTable = ScanTable<char, int>;
	ASSERT_ANY_THROW(ScanTable S(-5));
}

TEST(ScanTable, ccopy_isempty)
{
	using ScanTable = ScanTable<char, int>;
	ScanTable A;
	ASSERT_NO_THROW(ScanTable S(A));
}

TEST(ScanTable, cannot_SetNext_isempty)
{
	ScanTable<char, int> S;
	ASSERT_NO_THROW(S.SetNext());
}

TEST(ScanTable, correct_isempty_isEnd)
{
	ScanTable<char, int> S;
	EXPECT_EQ(true, S.IsEnd());
}

TEST(ScanTable, correct_GetKey)
{
	ScanTable<char, int> S;
	S.Insert('x', 1);
	S.Reset();
	EXPECT_EQ(1, S.GetKey());
}

TEST(ScanTable, correct_GetData)
{
	ScanTable<char, int> S;
	S.Insert('x', 1);
	S.Reset();
	EXPECT_EQ('x', *S.GetData());
}

TEST(ScanTable, after_Delete_isempty)
{
	ScanTable<char, int> S;
	S.Insert('x', 1);
	S.Delete(1);
	EXPECT_TRUE(S.IsEmpty());
}

TEST(ScanTable, correct_Insert_after_delete)
{
	ScanTable<char, int> S;
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Delete(2);
	S.Insert('y', 5);
	S.Reset(); S.SetNext(); S.SetNext();
	EXPECT_EQ('y', *S.GetData());
}

TEST(ScanTable, correct_Seasrch)
{
	ScanTable<char, int> S(6);
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Insert('x^2', 4);
	S.Insert('y^2', 5);
	char* tmp = S.Search(2);
	EXPECT_EQ('y', *tmp);
}

TEST(ScanTable, not_Search_nullptr)
{
	ScanTable<char, int> S(5);
	S.Insert('x', 1);
	S.Insert('y', 3);
	S.Insert('z', 2);
	S.Insert('x^2', 4);
	ASSERT_ANY_THROW(S.Search(5));
}

TEST(ScanTable, correct_Delete)
{
	ScanTable<char, int> S(4);
	S.Insert('x', 1);
	S.Insert('z', 3);
	S.Insert('y', 2);
	S.Delete(3);
	ASSERT_ANY_THROW(S.Search(3));
}

TEST(ScanTable, correct_Insert)
{
	ScanTable<char, int> S(5);
	S.Insert('x', 1);
	S.Insert('z', 3);
	S.Insert('y', 2);
	S.Insert('x^2', 4);
	S.Insert('x', 5);
	EXPECT_NE(nullptr, S.Search(5));
}

TEST(ScanTable, no_Insert_with_not_key)
{
	ScanTable<char, int> S;
	S.Insert('a', 1);
	S.Insert('b', 2);
	S.Insert('b', 3);
	EXPECT_NE(3, *(S.GetData()));
}

TEST(ScanTable, throw_Delete_no_key)
{
	ScanTable<char, int> S(5);
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Insert('x^2', 4);
	ASSERT_NO_THROW(S.Delete(5));
}

TEST(ScanTable, correct_clear)
{
	ScanTable<char, int> S(4);
	S.Insert('x', 1);
	S.Insert('y', 2);
	S.Insert('z', 3);
	S.Clear();
	EXPECT_EQ(true, S.IsEmpty());
}