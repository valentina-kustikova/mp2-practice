#include "array_hash_table.h"
#include <string>
#include <gtest.h>

TEST(ArrayHashTable, can_insert_record_into_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	ASSERT_NO_THROW(hash_table.Insert("1", new int(1)));
}

TEST(ArrayHashTable, throws_when_insert_into_full_hash_table) {
	ArrayHashTable<string, int> hash_table(3, 1);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	ASSERT_ANY_THROW(hash_table.Insert("4", new int(4)));
}

TEST(ArrayHashTable, can_search_record_in_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	EXPECT_EQ(*hash_table.Search("2")->data, 2);
}

TEST(ArrayHashTable, return_nullptr_when_there_is_no_searching_record_in_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	EXPECT_EQ(hash_table.Search("4"), nullptr);
}

TEST(ArrayHashTable, can_get_current_record_in_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	hash_table.Reset();
	hash_table.Next();
	EXPECT_EQ(*hash_table.GetCurrent()->data, 1);
}

TEST(ArrayHashTable, can_remove_record_from_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	ASSERT_NO_THROW(hash_table.Remove("2"));
}

TEST(ArrayHashTable, throws_when_remove_from_empty_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	ASSERT_ANY_THROW(hash_table.Remove("1"));
}

TEST(ArrayHashTable, throws_when_there_is_no_removing_record_in_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	ASSERT_ANY_THROW(hash_table.Remove("4"));
}

TEST(ArrayHashTable, can_reset_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	ASSERT_NO_THROW(hash_table.Reset());;
}

TEST(ArrayHashTable, can_move_to_the_next_record_in_hash_table) {
	ArrayHashTable<string, int> hash_table(10, 2);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	hash_table.Reset();
	hash_table.Next();
	EXPECT_EQ(*hash_table.GetCurrent()->data, 1);
}

TEST(ArrayHashTable, throws_when_end_of_the_hash_table) {
	ArrayHashTable<string, int> hash_table(3, 1);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	hash_table.Reset();
	for (int i = 0; i < 3; i++)
		hash_table.Next();
	ASSERT_ANY_THROW(hash_table.Next());;
}

TEST(ArrayHashTable, can_determine_if_hash_table_is_empty) {
	ArrayHashTable<string, int> hash_table(10, 2);
	EXPECT_TRUE(hash_table.IsEmpty());;
}

TEST(ArrayHashTable, can_determine_if_hash_table_is_full) {
	ArrayHashTable<string, int> hash_table(3, 1);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	EXPECT_TRUE(hash_table.IsFull());;
}

TEST(ArrayHashTable, can_determine_if_hash_table_is_ended) {
	ArrayHashTable<string, int> hash_table(3, 1);
	for (int i = 0; i < 3; i++)
		hash_table.Insert(to_string(i), new int(i));
	hash_table.Reset();
	for (int i = 0; i < 3; i++)
		hash_table.Next();
	EXPECT_TRUE(hash_table.IsEnded());;
}