#include<gtest.h>

#include"ScanTable.h"


TEST(ScanTable, can_crate_scantable) {
	ScanTable<int, double> st;
	EXPECT_EQ(st.get_max_size(), 100);
}


TEST(ScanTable, can_insert_scantable) {
	ScanTable<int, string> st;
	string* str = new string("alblack");
	ASSERT_NO_THROW(st.insert(52, str));
}

TEST(ScanTable, can_insert_rec_with_repeat_key_scantable) {
	ScanTable<int, string> st;
	string* str = new string("alblack");
	st.insert(52, str);
	ASSERT_NO_THROW(st.insert(52, str));
}

TEST(ScanTable, can_find_scantable) {
	ScanTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);

	EXPECT_EQ(*st.find(52)->data, "alblack1");
}

TEST(ScanTable, can_crate_scantable_with_param) {
	ScanTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);
	
	ScanTable<int, string> st1(st);
	EXPECT_EQ(*st.find(52)->data, *st1.find(52)->data);
}



TEST(ScanTable, can_remove_rec) {
	ScanTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);

	ASSERT_NO_THROW(st.remove(52));
}




TEST(ScanTable, copied_table_has_its_own_memory) {
	ScanTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);

	ScanTable<int, string> st1(st);
	
	st.remove(52);

	string* str1_tmp = new string("tmp_alblack");
	st.insert(52, str1_tmp);

	EXPECT_NE(*st.find(52)->data, *st1.find(52)->data);
}



TEST(ScanTable, operator_inex_is_correct) {
	ScanTable<int, string> st;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	st.insert(52, str1);
	st.insert(53, str2);
	st.insert(54, str3);
	EXPECT_EQ(*st[52]->data, "alblack1");
}
