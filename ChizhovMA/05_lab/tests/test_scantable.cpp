#include "ScanTable.h"
#include "Tables.h"

#include <gtest.h>


//TEST(ScanTable, default_constructor_test)
//{
//	int size = 5;
//	ASSERT_NO_THROW(TScanTable<string, int> table(size));
//}
TEST(ScanTable, constructor_with_parametr_test_isfull) {
	int size = 3;
	TScanTable<int, string> st(3);

	EXPECT_EQ(false, st.IsFull());
}

TEST(ScanTable, constructor_with_parametr_test_isempty) {
	int size = 3;
	TScanTable<int, string> st(3);

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(ScanTable, constructor_with_parametr_test_istabended) {
	int size = 3;
	TScanTable<int, string> st(3);

	EXPECT_EQ(false, st.IsTabEnded());
}

TEST(ScanTable, constructor_with_parametr_test_reset) {
	int size = 3;
	TScanTable<int, string> st(3);

	EXPECT_EQ(false, st.Reset());
}

TEST(ScanTable, constructor_with_parametr_test_next) {
	int size = 3;
	TScanTable<int, string> st(3);

	EXPECT_EQ(false, st.Next());
}
// Copy Constructor Test
TEST(ScanTable, CopyConstructorTest) {
	int size = 3;
	TScanTable<int, string> st(3);
	st.Insert(1, &string("abc"));

	TScanTable<int, string> copiedSt(st);

	EXPECT_EQ(st.Find(1)->GetKey(), copiedSt.Find(1)->GetKey());
}
// Insert Test
TEST(ScanTable, insert_test_empty) {
	int size = 3;
	TScanTable<int, string> st(3);

	int key = 1;
	string data = "a";

	EXPECT_NO_THROW(st.Insert(key, &data));
}

TEST(ScanTable, insert_test_not_empty) {
	int size = 3;
	TScanTable<int, string> st(3);

	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	string data2 = "b";
	st.Insert(key1, &data1);

	EXPECT_NO_THROW(st.Insert(key2, &data2));
}

TEST(ScanTable, insert_test_full) {
	int size = 3;
	TScanTable<int, string> st(3);

	int key1 = 1;
	int key2 = 2;
	int key3 = 3;
	int key4 = 4;
	string data1 = "a";
	string data2 = "b";
	string data3 = "c";
	string data4 = "d";
	st.Insert(key1, &data1);
	st.Insert(key2, &data2);
	st.Insert(key3, &data3);

	EXPECT_ANY_THROW(st.Insert(key4, &data4));
}
// Remove Test
TEST(ScanTable, remove_test) {
	int size = 3;
	TScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	EXPECT_NO_THROW(st.Remove(1));
}
TEST(ScanTable, remove_test_empty) {
	int size = 5;
	TScanTable<int, string> st(5);

	ASSERT_ANY_THROW(st.Remove(1));
}
// Find Test
TEST(ScanTable, find_test) {
	int size = 5;
	TScanTable<int, string> st(size);

	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	string data2 = "b";
	st.Insert(key1, &data1);
	st.Insert(key2, &data2);

	EXPECT_NO_THROW(st.Find(1));
}

TEST(ScanTable, find_test_key) {
	int size = 5;
	TScanTable<int, string> st(size);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	TabRecord<int, string>* find = st.Find(1);

	EXPECT_EQ(key, find->GetKey());
}

TEST(ScanTable, find_test_data) {
	int size = 5;
	TScanTable<int, string> st(size);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	TabRecord<int, string>* find = st.Find(1);

	EXPECT_EQ(data, *find->GetData());
}

TEST(ScanTable, FindTest_NotFound) {
	int size = 3;
	TScanTable<int, string> st(size);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	EXPECT_EQ(nullptr, st.Find(2));
}
// GetKey Test
TEST(ScanTable, get_key_test) {
	int size = 3;
	TScanTable<int, string> st(size);

	int key = 1;
	string data = "abc";
	st.Insert(key, &data);
	st.Reset();
	int gk = st.GetKey();

	EXPECT_EQ(key, gk);
}
// GetData Test
TEST(ScanTable, get_data_test) {
	int size = 3;
	TScanTable<int, string> st(3);

	int key = 1;
	string data = "abc";
	st.Insert(key, &data);
	st.Reset();
	string gd = *st.GetData();

	EXPECT_EQ(data, gd);
}
