#include "scan_table.h"
#include <string>
#include <gtest.h>

TEST(ScanTable, can_insert_record_into_scan_table) {
	ScanTable<string, int> scan_table(10);
	ASSERT_NO_THROW(scan_table.Insert("1", new int(1)));
}

TEST(ScanTable, throws_when_insert_into_full_scan_table) {
	ScanTable<string, int> scan_table(3);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	ASSERT_ANY_THROW(scan_table.Insert("4", new int(4)));
}

TEST(ScanTable, can_search_record_in_scan_table) {
	ScanTable<string, int> scan_table(10);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	EXPECT_EQ(*scan_table.Search("2")->data, 2);
}

TEST(ScanTable, return_nullptr_when_there_is_no_searching_record_in_scan_table) {
	ScanTable<string, int> scan_table(10);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	EXPECT_EQ(scan_table.Search("4"), nullptr);
}

TEST(ScanTable, can_get_current_record_in_scan_table) {
	ScanTable<string, int> scan_table(10);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	scan_table.Reset();
	scan_table.Next();
	EXPECT_EQ(*scan_table.GetCurrent()->data, 1);
}

TEST(ScanTable, can_remove_record_from_scan_table) {
	ScanTable<string, int> scan_table(10);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	ASSERT_NO_THROW(scan_table.Remove("2"));
}

TEST(ScanTable, throws_when_remove_from_empty_scan_table) {
	ScanTable<string, int> scan_table(10);
	ASSERT_ANY_THROW(scan_table.Remove("1"));
}

TEST(ScanTable, throws_when_there_is_no_removing_record_in_scan_table) {
	ScanTable<string, int> scan_table(10);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	ASSERT_ANY_THROW(scan_table.Remove("4"));
}

TEST(ScanTable, can_reset_scan_table) {
	ScanTable<string, int> scan_table(10);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	ASSERT_NO_THROW(scan_table.Reset());;
}

TEST(ScanTable, can_move_to_the_next_record_in_scan_table) {
	ScanTable<string, int> scan_table(10);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	scan_table.Reset();
	scan_table.Next();
	EXPECT_EQ(*scan_table.GetCurrent()->data, 1);
}

TEST(ScanTable, throws_when_end_of_the_scan_table) {
	ScanTable<string, int> scan_table(3);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	scan_table.Reset();
	for (int i = 0; i < 3; i++)
		scan_table.Next();
	ASSERT_ANY_THROW(scan_table.Next());;
}

TEST(ScanTable, can_determine_if_scan_table_is_empty) {
	ScanTable<string, int> scan_table(10);
	EXPECT_TRUE(scan_table.IsEmpty());;
}

TEST(ScanTable, can_determine_if_scan_table_is_full) {
	ScanTable<string, int> scan_table(3);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	EXPECT_TRUE(scan_table.IsFull());;
}

TEST(ScanTable, can_determine_if_scan_table_is_ended) {
	ScanTable<string, int> scan_table(3);
	for (int i = 0; i < 3; i++)
		scan_table.Insert(to_string(i), new int(i));
	scan_table.Reset();
	for (int i = 0; i < 3; i++)
		scan_table.Next();
	EXPECT_TRUE(scan_table.IsEnded());;
}