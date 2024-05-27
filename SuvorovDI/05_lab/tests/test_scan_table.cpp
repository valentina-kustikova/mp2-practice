#include <iostream>
#include <gtest.h>
#include "table.h"
#include "scan_table.h"

/*  --- CREATING ---  */
TEST(ScanTable, can_create_empty_scantable) {
	//ASSERT_ANY_THROW(ScanTable<std::string, int> s_table(10));
	ScanTable<std::string, int> s_table(10);
	EXPECT_TRUE(s_table.IsEmpty());
}

TEST(ScanTable, can_create_scantable_by_enother_scantable) {
	//ASSERT_NO_THROW(ScanTable<std::string, int> s_table = ScanTable<std::string, int>(10));
	ScanTable<std::string, int> s_table(10);
	//ASSERT_NO_THROW(ScanTable<std::string, int> copy_s_table(s_table));
}

/*  --- INSERT ---  */
TEST(ScanTable, can_insert_into_scantable) {
	ScanTable<std::string, int> s_table(10);
	ASSERT_NO_THROW(s_table.Insert("first", new int(43)));
}

TEST(ScanTable, check_insert_into_scantable) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	TabRecord<std::string, int> res("first", new int(43));
	EXPECT_EQ(*s_table.GetCurrent(), res);
}

TEST(ScanTable, cannot_insert_if_such_key_is_already_existed) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	ASSERT_ANY_THROW(s_table.Insert("first", new int(10)));
}

TEST(ScanTable, check_that_table_is_full) {
	ScanTable<std::string, int> s_table(2);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(124));
	EXPECT_TRUE(s_table.IsFull());
}

TEST(ScanTable, cannot_insert_into_full_table) {
	ScanTable<std::string, int> s_table(2);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(124));
	ASSERT_ANY_THROW(s_table.Insert("third", new int(10)));
}

/*  --- NAVIGATION ---  */
TEST(ScanTable, check_reset_operation) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	TabRecord<std::string, int> res1("first", new int(43));
	TabRecord<std::string, int> res2("second", new int(84));
	EXPECT_EQ(*s_table.GetCurrent(), res2);
	s_table.Reset();
	EXPECT_EQ(*s_table.GetCurrent(), res1);
}

TEST(ScanTable, check_getting_next_record) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));
	TabRecord<std::string, int> res1("first", new int(43));
	TabRecord<std::string, int> res2("second", new int(84));
	TabRecord<std::string, int> res3("third", new int(9));
	s_table.Reset();
	EXPECT_EQ(*s_table.GetCurrent(), res1);
	s_table.Next();
	EXPECT_EQ(*s_table.GetCurrent(), res2);
	s_table.Next();
	EXPECT_EQ(*s_table.GetCurrent(), res3);
}

TEST(ScanTable, check_getting_next_when_the_table_is_ended) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));

	s_table.Reset();
	s_table.Next();
	ASSERT_ANY_THROW(s_table.Next());
}

TEST(ScanTable, check_table_is_ended) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Reset();
	s_table.Next();
	EXPECT_TRUE(s_table.IsEnded());
}

/*  --- COPY CONSTRUCTOR ---  */
TEST(ScanTable, check_equivalence_between_copy_and_origin_scantable) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(-9));
	ScanTable<std::string, int> copy_s_table(s_table);

	s_table.Reset();
	while (!s_table.IsEnded()) {
		ASSERT_TRUE(*s_table.GetCurrent() == *copy_s_table.GetCurrent());
		s_table.Next();
		copy_s_table.Next();
	}
}

/*  --- SEARCH ---  */
TEST(ScanTable, check_search_in_empty_table) {
	ScanTable<std::string, int> s_table(10);

	EXPECT_TRUE(s_table.Find("some") == nullptr);
}

TEST(ScanTable, check_search_an_existing_element) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));

	TabRecord<std::string, int> res("second", new int(84));

	EXPECT_EQ(*s_table.Find("second"), res);
}

TEST(ScanTable, check_search_a_not_existing_element) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));

	EXPECT_TRUE(s_table.Find("some") == nullptr);
}

/*  --- REMOVAL ---  */
TEST(ScanTable, try_to_remove_an_existing_element) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));
	s_table.Remove("second");

	EXPECT_TRUE(s_table.Find("second") == nullptr);
}

TEST(ScanTable, try_to_remove_a_not_existing_element) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));
	ASSERT_ANY_THROW(s_table.Remove("some"));
}

TEST(ScanTable, try_to_remove_some_element_from_an_empty_table) {
	ScanTable<std::string, int> s_table(10);
	ASSERT_ANY_THROW(s_table.Remove("some"));
}