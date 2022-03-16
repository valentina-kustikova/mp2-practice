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

TEST(HashTable, cant_create_HashTable_with_size_gr_than_MAX)
{
	using HashTable = HashTable<std::string, int>;
	ASSERT_ANY_THROW(HashTable S(MAX_SIZE + 1));
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