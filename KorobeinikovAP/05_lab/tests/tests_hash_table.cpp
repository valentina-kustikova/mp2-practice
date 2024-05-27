#include<gtest.h>

#include"HashTable.h"


TEST(HashTable, can_crate_HashTable) {
	HashTable<int, double> h_t;
	EXPECT_EQ(h_t.get_max_size(), 100);
}

TEST(HashTable, can_insert_Sortedtable) {
	HashTable<int, string> h_t;
	string* str = new string("alblack");
	ASSERT_NO_THROW(h_t.insert(52, str));
}

TEST(HashTable, can_insert_rec_with_repeat_key_Sortedtable) {
	//std::this_thread::sleep_for(std::chrono::milliseconds(200));
	HashTable<int, string> h_t;
	string* str = new string("alblack");
	h_t.insert(52, str);
	ASSERT_NO_THROW(h_t.insert(52, str));
}

TEST(HashTable, can_find_Sortedtable) {
	HashTable<int, string> h_t;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	h_t.insert(52, str1);
	h_t.insert(53, str2);
	h_t.insert(54, str3);

	EXPECT_EQ(*h_t.find(52)->data, "alblack1");
}

TEST(HashTable, can_crate_copi_Hashtable) {
	HashTable<int, string> h_t;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	h_t.insert(52, str1);
	h_t.insert(53, str2);
	h_t.insert(54, str3);

	HashTable<int, string> h_t1(h_t);

	EXPECT_EQ(*h_t.find(52)->data, *h_t1.find(52)->data);
}




TEST(HashTable, can_remove_rec) {
	HashTable<int, string> h_t;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	h_t.insert(52, str1);
	h_t.insert(53, str2);
	h_t.insert(54, str3);

	ASSERT_NO_THROW(h_t.remove(52));
	EXPECT_EQ(h_t.find(52), nullptr);
}




TEST(HashTable, copied_table_has_its_own_memory) {
	HashTable<int, string> h_t;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	h_t.insert(52, str1);
	h_t.insert(53, str2);
	h_t.insert(54, str3);

	HashTable<int, string> h_t1(h_t);

	h_t.remove(52);

	string* str1_tmp = new string("tmp_alblack");
	h_t.insert(52, str1_tmp);

	EXPECT_NE(*h_t.find(52)->data, *h_t1.find(52)->data);
}



TEST(HashTable, operator_inex_is_correct) {
	HashTable<int, string> h_t;
	string* str1 = new string("alblack1");
	string* str2 = new string("alblack2");
	string* str3 = new string("alblack3");

	h_t.insert(52, str1);
	h_t.insert(53, str2);
	h_t.insert(54, str3);
	EXPECT_EQ(*h_t[52]->data, "alblack1");
}
