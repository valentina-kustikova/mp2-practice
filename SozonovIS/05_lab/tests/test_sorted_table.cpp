#include "sorted_table.h"
#include <string>
#include <gtest.h>

TEST(SortedTable, can_insert_record_into_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	ASSERT_NO_THROW(sorted_table.Insert("1", new int(1)));
}

TEST(SortedTable, throws_when_insert_into_full_sorted_table) {
	SortedTable<string, int> sorted_table(3);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	ASSERT_ANY_THROW(sorted_table.Insert("4", new int(4)));
}

TEST(SortedTable, can_search_record_in_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	EXPECT_EQ(*sorted_table.Search("2")->data, 2);
}

TEST(SortedTable, return_nullptr_when_there_is_no_searching_record_in_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	EXPECT_EQ(sorted_table.Search("4"), nullptr);
}

TEST(SortedTable, can_get_current_record_in_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	sorted_table.Reset();
	EXPECT_EQ(*sorted_table.GetCurrent()->data, 1);
}

TEST(SortedTable, can_remove_record_from_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	ASSERT_NO_THROW(sorted_table.Remove("2"));
}

TEST(SortedTable, throws_when_remove_from_empty_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	ASSERT_ANY_THROW(sorted_table.Remove("1"));
}

TEST(SortedTable, throws_when_there_is_no_removing_record_in_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	ASSERT_ANY_THROW(sorted_table.Remove("4"));
}

TEST(SortedTable, can_reset_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	ASSERT_NO_THROW(sorted_table.Reset());;
}

TEST(SortedTable, can_move_to_the_next_record_in_sorted_table) {
	SortedTable<string, int> sorted_table(10);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	sorted_table.Reset();
	sorted_table.Next();
	EXPECT_EQ(*sorted_table.GetCurrent()->data, 2);
}

TEST(SortedTable, throws_when_end_of_the_sorted_table) {
	SortedTable<string, int> sorted_table(3);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	sorted_table.Reset();
	for (int i = 0; i < 3; i++)
		sorted_table.Next();
	ASSERT_ANY_THROW(sorted_table.Next());;
}

TEST(SortedTable, can_determine_if_sorted_table_is_empty) {
	SortedTable<string, int> sorted_table(10);
	EXPECT_TRUE(sorted_table.IsEmpty());;
}

TEST(SortedTable, can_determine_if_sorted_table_is_full) {
	SortedTable<string, int> sorted_table(3);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	EXPECT_TRUE(sorted_table.IsFull());;
}

TEST(SortedTable, can_determine_if_sorted_table_is_ended) {
	SortedTable<string, int> sorted_table(3);
	sorted_table.Insert("2", new int(2));
	sorted_table.Insert("3", new int(3));
	sorted_table.Insert("1", new int(1));
	sorted_table.Reset();
	for (int i = 0; i < 3; i++)
		sorted_table.Next();
	EXPECT_TRUE(sorted_table.IsEnded());;
}