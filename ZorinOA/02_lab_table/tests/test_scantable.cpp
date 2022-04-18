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
    ScanTable<char,int> S(1);
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


