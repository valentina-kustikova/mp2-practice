#include <gtest.h>
#include "SortTable.h"

TEST(SortTable, can_create_SortTable_with_positive_size)
{
	using SortTable = SortTable<char, int>;
	ASSERT_NO_THROW(SortTable S(5));
}

TEST(SortTable, cant_create_SortTable_with_size_gr_than_MAX)
{
	using SortTable = SortTable<char, int>;
	ASSERT_ANY_THROW(SortTable S(MAX_SIZE + 1));
}

TEST(SortTable, cant_create_ScanTable_with_size_gr_than_MAX)
{
	using SortTable = SortTable<char, int>;
	ASSERT_ANY_THROW(SortTable T(MAX_SIZE + 1));
}

TEST(SortTable, find_is_correct)
{
	SortTable<char, int> S(8);
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

TEST(SortTable, not_find_is_nullptr)
{
	SortTable<char, int> S(8);
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

TEST(SortTable, insert_correct)
{
	SortTable<char, int> S(8);
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

TEST(SortTable, cant_insert_when_mem_full)
{
	SortTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	S.Insert('x', 100);
	EXPECT_NO_THROW('z', 0);
}

TEST(SortTable, delete_correct)
{
	SortTable<char, int> S(8);
	S.Insert('a', 1);
	S.Insert('c', 3);
	S.Insert('b', 2);
	S.Insert('d', 4);
	S.Insert('f', 6);
	S.Insert('e', 5);
	S.Insert('g', 7);
	S.Delete('c');
	EXPECT_EQ(nullptr, S.Find('c'));
}
