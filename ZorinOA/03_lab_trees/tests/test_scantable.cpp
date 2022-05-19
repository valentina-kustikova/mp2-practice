#include <gtest.h>
#include "ScanTable.h"

TEST(ScanTable, can_create_ScanTable_with_positive_length)
{
	using ScanTable = ScanTable<char, int>;
	ASSERT_NO_THROW(ScanTable T(5));
}

TEST(ScanTable, cant_create_ScanTable_with_size_less_zero)
{
	using ScanTable = ScanTable<char, int>;
	ASSERT_ANY_THROW(ScanTable S(-5));
}

TEST(ScanTable, can_copy_empty_table)
{
	using ScanTable = ScanTable<char, int>;
	ScanTable A;
	ASSERT_NO_THROW(ScanTable B(A));
}

TEST(ScanTable, cant_goNext_empty_table)
{
	ScanTable<char, int> A;
	ASSERT_NO_THROW(A.goNext());
}

TEST(ScanTable, empty_table_getKey_is_default_value)
{
	ScanTable<char, int> A;
	EXPECT_EQ(char(), A.getKey());
}

TEST(ScanTable, empty_table_getData_is_nullptr)
{
	ScanTable<char, int> A;
	EXPECT_EQ(nullptr, A.getData());
}

TEST(ScanTable, empty_table_isEnd_correct)
{
	ScanTable<char, int> A;
	EXPECT_EQ(true, A.isEnd());
}

TEST(ScanTable, getKey_correct)
{
	ScanTable<char, int> A;
	A.Insert('a', 1);
	A.Reset();
	EXPECT_EQ('a', A.getKey());
}

TEST(ScanTable, getData_correct)
{
	ScanTable<char, int> A;
	A.Insert('a', 1);
	A.Reset();
	EXPECT_EQ(1, *A.getData());
}

TEST(ScanTable, empty_after_delete)
{
	ScanTable<char, int> A;
	A.Insert('a', 1);
	A.Delete('a');
	EXPECT_TRUE(A.isEmpty());
}

TEST(ScanTable, correct_insert_after_delete)
{
	ScanTable<char, int> A;
	A.Insert('a', 1);
	A.Insert('b', 2);
	A.Insert('c', 3);
	A.Delete('b');
	A.Insert('b', 100);
	A.Reset(); A.goNext(); A.goNext();
	EXPECT_EQ(100, *A.getData());
}

TEST(ScanTable, find_is_correct)
{
	ScanTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	int* tmp = S.Find('b');
	EXPECT_EQ(2, *tmp);
}

TEST(ScanTable, not_find_is_nullptr)
{
	ScanTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	int* tmp = S.Find('z');
	EXPECT_EQ(nullptr, tmp);
}

TEST(ScanTable, insert_correct)
{
	ScanTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	S.Insert('x', 100);
	EXPECT_NE(nullptr, S.Find('x'));
}

TEST(ScanTable, no_throw_insert_when_tab_is_full)
{
	ScanTable<char, int> S(1);
	S.Insert('a', 1);
	ASSERT_NO_THROW(S.Insert('b', 2));
}

TEST(ScanTable, cant_insert_with_not_unique_key)
{
	ScanTable<char, int> S;
	S.Insert('a', 1);
	S.Insert('b', 2);
	S.Insert('b', 3);
	EXPECT_NE(3, *(S.getData()));
}

TEST(ScanTable, delete_correct)
{
	ScanTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	S.Delete('g');
	EXPECT_EQ(nullptr, S.Find('g'));
}

TEST(ScanTable, no_throw_delete_when_no_key)
{
	ScanTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	ASSERT_NO_THROW(S.Delete('z'));
}

TEST(ScanTable, clear_correct)
{
	ScanTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	S.Clear();
	EXPECT_EQ(true, S.isEmpty());
}