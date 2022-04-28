#include <gtest.h>
#include <string>
#include "HashTable.h"

TEST(HashTable, can_create_HashTable_with_positive_size)
{
	using HashTable = HashTable<std::string, int>;
	ASSERT_NO_THROW(HashTable(5));
}

TEST(HashTable, cant_create_HashTable_with_size_less_zero)
{
	using HashTable = HashTable<std::string, int>;
	ASSERT_ANY_THROW(HashTable S(-5));
}

TEST(HashTable, can_copy_empty_table)
{
	using HashTable = HashTable<char, int>;
	HashTable A;
	ASSERT_NO_THROW(HashTable B(A));
}

TEST(HashTable, cant_goNext_empty_table)
{
	HashTable<char, int> A;
	A.Reset();
	ASSERT_NO_THROW(A.goNext());
}

TEST(HashTable, empty_table_getKey_is_default_value)
{
	HashTable<char, int> A;
	A.Reset();
	EXPECT_EQ(char(), A.getKey());
}

TEST(HashTable, empty_table_getData_is_nullptr)
{
	HashTable<char, int> A;
	A.Reset();
	EXPECT_EQ(nullptr, A.getData());
}

TEST(HashTable, empty_table_isEnd_correct)
{
	HashTable<char, int> A;
	A.Reset();
	EXPECT_EQ(true, A.isEnd());
}

TEST(HashTable, getKey_correct)
{
	HashTable<char, int> A;
	A.Insert('a', 1);
	A.Reset();
	EXPECT_EQ('a', A.getKey());
}

TEST(HashTable, getData_correct)
{
	HashTable<char, int> A;
	A.Insert('a', 1);
	A.Reset();
	EXPECT_EQ(1, *A.getData());
}

TEST(HashTable, empty_after_delete)
{
	HashTable<char, int> A;
	A.Insert('a', 1);
	A.Delete('a');
	EXPECT_TRUE(A.isEmpty());
}

TEST(HashTable, correct_insert_after_delete)
{
	HashTable<char, int> A;
	A.Insert('a', 1);
	A.Insert('b', 2);
	A.Insert('c', 3);
	A.Delete('b');
	A.Insert('b', 100);
	A.Reset(); A.goNext(); A.goNext();
	EXPECT_EQ(100, *A.getData());
}

TEST(HashTable, insert_correct)
{
	HashTable<std::string, int> H;
	H.Insert("first", 1);
	EXPECT_NE(nullptr, H.Find("first"));
}

TEST(HashTable, delete_correct)
{
	HashTable<std::string, int> H(5);
	H.Insert("first", 1);
	H.Insert("second", 2);
	H.Insert("third", 3);
	H.Insert("fourth", 4);
	H.Insert("fifth", 5);
	H.Delete("third");
	EXPECT_EQ(nullptr, H.Find("third"));
}

TEST(HashTable, no_throw_delete_when_no_key)
{
	HashTable<std::string, int> S(8);
	S.Insert("a", 1);
	S.Insert("b", 3);
	S.Insert("c", 2);
	S.Insert("d", 4);
	S.Insert("f", 6);
	S.Insert("e", 5);
	S.Insert("g", 7);
	ASSERT_NO_THROW(S.Delete("z"));
}

TEST(HashTable, clear_correct)
{
	HashTable<char, int> S(8);
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