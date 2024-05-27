#include <iostream>
#include <gtest.h>
#include "array_hash_table.h"

/*  --- CREATING ---  */
TEST(ArrayHashTable, can_create_empty_arrhashtable) {
	//ASSERT_ANY_THROW(ScanTable<std::string, int> s_table(10));
	ArrayHashTable<std::string, int> s_table(10, 3);
	EXPECT_TRUE(s_table.IsEmpty());
}

TEST(ArrayHashTable, can_create_arrhashtable_by_enother_arrhashtable) {
	//ASSERT_NO_THROW(ScanTable<std::string, int> s_table = ScanTable<std::string, int>(10));
	ArrayHashTable<std::string, int> s_table(10, 3);
	//ASSERT_NO_THROW(ScanTable<std::string, int> copy_s_table(s_table));
}

/*  --- INSERT ---  */
TEST(ArrayHashTable, can_insert_into_arrhashtable) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	ASSERT_NO_THROW(s_table.Insert("first", new int(43)));
}

TEST(ArrayHashTable, check_insert_into_arrhashtable) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("first", new int(43));
	TabRecord<std::string, int> res("first", new int(43));
	EXPECT_EQ(*s_table.GetCurrent(), res);
}

TEST(ArrayHashTable, cannot_insert_if_such_key_is_already_existed) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("first", new int(43));
	ASSERT_ANY_THROW(s_table.Insert("first", new int(10)));
}

TEST(ArrayHashTable, check_that_table_is_full) {
	ArrayHashTable<std::string, int> s_table(5, 2);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(124));
  s_table.Insert("third", new int(43));
	s_table.Insert("fourth", new int(124));
  s_table.Insert("fifth", new int(43));
	EXPECT_TRUE(s_table.IsFull());
}

TEST(ArrayHashTable, cannot_insert_into_full_table) {
	ArrayHashTable<std::string, int> s_table(5, 2);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(124));
  s_table.Insert("third", new int(43));
	s_table.Insert("fourth", new int(124));
  s_table.Insert("fifth", new int(43));
	ASSERT_ANY_THROW(s_table.Insert("sixth", new int(10)));
}

/*  --- NAVIGATION ---  */
TEST(ArrayHashTable, check_getting_current) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("a", new int(43));
	s_table.Insert("ab", new int(84));
	EXPECT_EQ(s_table.GetCurrent()->key, "ab");
}

TEST(ArrayHashTable, check_getting_next_when_the_table_is_ended) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("a", new int(43));
	s_table.Insert("b", new int(84));
	ASSERT_ANY_THROW(s_table.Next());
}

TEST(ArrayHashTable, check_table_is_ended) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Reset();
	s_table.Next();
	EXPECT_TRUE(s_table.IsEnded());
}

/*  --- COPY CONSTRUCTOR ---  */
TEST(ArrayHashTable, check_equivalence_between_copy_and_origin_arrhashtable) {
	ArrayHashTable<std::string, int> s_table(10, 4);
	s_table.Insert("c", new int(43));
	s_table.Insert("a", new int(84));
	s_table.Insert("b", new int(-9));
	ArrayHashTable<std::string, int> copy_s_table(s_table);

	s_table.Reset();
  copy_s_table.Reset();
	while (!s_table.IsEnded()) {
		ASSERT_TRUE(*s_table.GetCurrent() == *copy_s_table.GetCurrent());
		s_table.Next();
		copy_s_table.Next();
	}
}

/*  --- SEARCH ---  */
TEST(ArrayHashTable, check_search_in_empty_table) {
	ArrayHashTable<std::string, int> s_table(10, 3);

	EXPECT_TRUE(s_table.Find("some") == nullptr);
}

TEST(ArrayHashTable, check_search_an_existing_element) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("c", new int(43));
	s_table.Insert("a", new int(84));
	s_table.Insert("b", new int(9));

	TabRecord<std::string, int> res("b", new int(9));

	EXPECT_EQ(*s_table.Find("b"), res);
}

TEST(ArrayHashTable, check_search_a_not_existing_element) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("c", new int(43));
	s_table.Insert("b", new int(84));
	s_table.Insert("a", new int(9));

	EXPECT_TRUE(s_table.Find("some") == nullptr);
}

/*  --- REMOVAL ---  */
TEST(ArrayHashTable, try_to_remove_an_existing_element) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));
	s_table.Remove("second");

	EXPECT_TRUE(s_table.Find("second") == nullptr);
}

TEST(ArrayHashTable, try_to_remove_a_not_existing_element) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	s_table.Insert("first", new int(43));
	s_table.Insert("second", new int(84));
	s_table.Insert("third", new int(9));
	ASSERT_ANY_THROW(s_table.Remove("some"));
}

TEST(ArrayHashTable, try_to_remove_some_element_from_an_empty_table) {
	ArrayHashTable<std::string, int> s_table(10, 3);
	ASSERT_ANY_THROW(s_table.Remove("some"));
}