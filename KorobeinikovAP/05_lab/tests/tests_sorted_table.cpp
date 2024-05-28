#include<gtest.h>

#include"SortedTable.h"


TEST(SortedTable, can_crate_Sortedtable) {
	SortedTable<int, double> st;
	EXPECT_EQ(st.get_max_size(), 100);
}


TEST(SortedTable, can_insert_Sortedtable) {
	SortedTable<int, string> st;
	string* str = new string("alblack");
	ASSERT_NO_THROW(st.insert(52, str));
}

TEST(SortedTable, can_find_Sortedtable) {
	SortedTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);

	EXPECT_EQ(*st.find(52)->data, "alblack1");
}

TEST(SortedTable, can_crate_copi_Sortedtable_from_sorttable) {
	SortedTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);

	SortedTable<int, string> st1(st);
	EXPECT_EQ(*st.find(52)->data, *st1.find(52)->data);
}



TEST(SortedTable, can_crate_copi_Sortedtable_from_scantable_is_sort) {
	ScanTable<int, string>* st = new ScanTable<int, string>;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st->insert(52, str1);
	st->insert(53, str2);
	st->insert(54, str3);

	SortedTable<int, string> st1(st);
	EXPECT_EQ(*st->find(52)->data, *st1.find(52)->data);
}

TEST(SortedTable, can_crate_copi_Sortedtable_from_scantable_is_not_sort) {
	ScanTable<int, string>* st = new ScanTable<int, string>;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st->insert(52, str1);
	st->insert(55, str2);
	st->insert(51, str3);

	SortedTable<int, string> st1(st);
	EXPECT_EQ(*st->find(52)->data, *st1.find(52)->data);
}


TEST(SortedTable, can_remove_rec) {
	SortedTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);

	ASSERT_NO_THROW(st.remove(52));
	EXPECT_EQ(st.find(52), nullptr);
}




TEST(SortedTable, copied_table_has_its_own_memory) {
	SortedTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);

	SortedTable<int, string> st1(st);

	st.remove(52);

	string* str1_tmp = new string("tmp_alblack");
	st.insert(52, str1_tmp);

	EXPECT_NE(*st.find(52)->data, *st1.find(52)->data);
}



TEST(SortedTable, operator_inex_is_correct) {
	SortedTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);
	EXPECT_EQ(*st[52]->data, "alblack1");
}
