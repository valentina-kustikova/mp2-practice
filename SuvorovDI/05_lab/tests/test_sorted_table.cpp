#include <iostream>
#include <gtest.h>
#include "sorted_table.h"

/*  --- CREATING ---  */
TEST(SortedTable, can_create_empty_sortedtable) {
	//ASSERT_ANY_THROW(ScanTable<std::string, int> s_table(10));
	SortedTable<std::string, int> s_table(10);
	EXPECT_TRUE(s_table.IsEmpty());
}

TEST(SortedTable, can_create_sortedtable_by_enother_sortedtable) {
	//ASSERT_NO_THROW(ScanTable<std::string, int> s_table = ScanTable<std::string, int>(10));
	SortedTable<std::string, int> s_table(10);
	//ASSERT_NO_THROW(ScanTable<std::string, int> copy_s_table(s_table));
}

/*  --- INSERT ---  */
TEST(SortedTable, can_insert_into_sortedtable) {
	SortedTable<std::string, int> s_table(10);
	ASSERT_NO_THROW(s_table.Insert("first", new int(43)));
}

TEST(SortedTable, check_insert_into_sortedtable) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	TabRecord<std::string, int> res("first", new int(43));
	EXPECT_EQ(*s_table.GetCurrent(), res);
}

TEST(SortedTable, cannot_insert_if_such_key_is_already_existed) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	ASSERT_ANY_THROW(s_table.Insert("first", new int(10)));
}

TEST(SortedTable, check_that_table_is_full) {
	SortedTable<std::string, int> s_table(2);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(124));
	EXPECT_TRUE(s_table.IsFull());
}

TEST(SortedTable, cannot_insert_into_full_table) {
	SortedTable<std::string, int> s_table(2);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(124));
	ASSERT_ANY_THROW(s_table.Insert("third", new int(10)));
}

TEST(SortedTable, check_correction_of_the_insert_place) {
  SortedTable<std::string, int> s_table(10);
	s_table.Insert("c", new int(43));
	s_table.Insert("a", new int(124));
  s_table.Insert("t", new int(53));
  s_table.Insert("e", new int(62));
  s_table.Insert("o", new int(39));
  s_table.Insert("g", new int(11));
  std::string order = "acegot";
  s_table.Reset();
  int i = 0;
  while (!s_table.IsEnded()) {
    EXPECT_EQ(s_table.GetCurrent()->key, std::string(1, order[i++]));
    s_table.Next();
  }
}

/*  --- NAVIGATION ---  */
TEST(SortedTable, check_reset_operation) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("a", new int(43));
	s_table.Insert("b", new int(84));
	EXPECT_EQ(s_table.GetCurrent()->key, "b");
	s_table.Reset();
	EXPECT_EQ(s_table.GetCurrent()->key, "a");
}

TEST(SortedTable, check_getting_next_record) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("a", new int(43));
	s_table.Insert("c", new int(84));
	s_table.Insert("b", new int(9));
  s_table.Reset();
  EXPECT_EQ(s_table.GetCurrent()->key, "a");
  s_table.Next();
  EXPECT_EQ(s_table.GetCurrent()->key, "b");
  s_table.Next();
  EXPECT_EQ(s_table.GetCurrent()->key, "c");
}

TEST(SortedTable, check_getting_next_when_the_table_is_ended) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("a", new int(43));
	s_table.Insert("b", new int(84));
	s_table.Next();
	ASSERT_ANY_THROW(s_table.Next());
}

TEST(SortedTable, check_table_is_ended) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Reset();
	s_table.Next();
	s_table.Next();
	EXPECT_TRUE(s_table.IsEnded());
}

/*  --- COPY CONSTRUCTOR ---  */
TEST(SortedTable, check_equivalence_between_copy_and_origin_sortedtable) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("c", new int(43));
	s_table.Insert("a", new int(84));
	s_table.Insert("b", new int(-9));
	SortedTable<std::string, int> copy_s_table(s_table);

	s_table.Reset();
	while (!s_table.IsEnded()) {
		ASSERT_TRUE(*s_table.GetCurrent() == *copy_s_table.GetCurrent());
		s_table.Next();
		copy_s_table.Next();
	}
}

TEST(SortedTable, check_the_correct_order_in_sort_copy_of_scantable) {
	ScanTable<std::string, int> s_table(10);
	s_table.Insert("c", new int(43));
	s_table.Insert("a", new int(84));
	s_table.Insert("b", new int(-9));
	SortedTable<std::string, int> copy_s_table(&s_table);

  std::string order = "acb";
	copy_s_table.Reset();
  int i = 0;
  while (!copy_s_table.IsEnded()) {
    EXPECT_EQ(copy_s_table.GetCurrent()->key, std::string(1, order[i++]));
		copy_s_table.Next();
  }
	//!!!std::cout << ("C" > "B");!!!
}

/*  --- SEARCH ---  */
TEST(SortedTable, check_search_in_empty_table) {
	SortedTable<std::string, int> s_table(10);

	EXPECT_TRUE(s_table.Find("some") == nullptr);
}

TEST(SortedTable, check_search_an_existing_element) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("c", new int(43));
	s_table.Insert("a", new int(84));
	s_table.Insert("b", new int(9));

	TabRecord<std::string, int> res("b", new int(9));

	EXPECT_EQ(*s_table.Find("b"), res);
}

TEST(SortedTable, check_search_a_not_existing_element) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("c", new int(43));
	s_table.Insert("b", new int(84));
	s_table.Insert("a", new int(9));

	EXPECT_TRUE(s_table.Find("some") == nullptr);
}

/*  --- REMOVAL ---  */
TEST(SortedTable, try_to_remove_an_existing_element) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));
	s_table.Remove("second");

	EXPECT_TRUE(s_table.Find("second") == nullptr);
}

TEST(SortedTable, try_to_remove_a_not_existing_element) {
	SortedTable<std::string, int> s_table(10);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));
	ASSERT_ANY_THROW(s_table.Remove("some"));
}

TEST(SortedTable, try_to_remove_some_element_from_an_empty_table) {
	SortedTable<std::string, int> s_table(10);
	ASSERT_ANY_THROW(s_table.Remove("some"));
}