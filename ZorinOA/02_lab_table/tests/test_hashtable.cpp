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
