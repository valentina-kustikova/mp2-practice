#include <gtest.h>
#include "ScanTable.h"

TEST(ScanTable, can_create_ScanTable_with_positive_length)
{
	using ScanTable = ScanTable<char, int>;
	ASSERT_NO_THROW(ScanTable T(5));
}

TEST(ScanTable, cant_create_ScanTable_with_size_gr_than_MAX)
{
	using ScanTable = ScanTable<char, int>;
	ASSERT_ANY_THROW(ScanTable T(MAX_SIZE + 1));
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

TEST(ScanTable, cant_insert_when_mem_full)
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
	EXPECT_NO_THROW('z', 0);
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



