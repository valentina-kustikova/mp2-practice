#include <gtest.h>
#include "ScanTable.h"

using namespace std;

TEST(TScanTable, constructor_auto_params) {
	TScanTable<int, std::string> table;
	EXPECT_EQ(table.GetMaxSize(), 100);
	EXPECT_EQ(table.GetCount(), 0);
	EXPECT_TRUE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(TScanTable, constructor_get_params) {
	TScanTable<int, std::string> table(50);
	EXPECT_EQ(table.GetMaxSize(), 50);
	EXPECT_EQ(table.GetCount(), 0);
	EXPECT_TRUE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(TScanTable, test_getCount_constructor) {
	TScanTable<int, std::string> table(10);
	std::string data1 = "data1";
	std::string data2 = "data2";
	table.Insert(1, &data1);
	table.Insert(2, &data2);
	EXPECT_EQ(table.GetMaxSize(), 10);
	EXPECT_EQ(table.GetCount(), 2);
	EXPECT_FALSE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(TScanTable, CopyConstructor) {
	TScanTable<int, std::string> table(10);
	std::string data1 = "data1";
	std::string data2 = "data2";
	table.Insert(1, &data1);
	table.Insert(2, &data2);

	TScanTable<int, std::string> copy(table);
	EXPECT_EQ(copy.GetCount(), 2);
	EXPECT_EQ(*copy.Find(1)->data, "data1");
	EXPECT_EQ(*copy.Find(2)->data, "data2");
}

TEST(TScanTable, test_insert) {
	TScanTable<int, std::string> table;
	std::string data1 = "data1";
	std::string data2 = "data2";
	table.Insert(1, &data1);
	table.Insert(2, &data2);
	EXPECT_EQ(table.GetCount(), 2);
	EXPECT_FALSE(table.IsEmpty());
	EXPECT_EQ(*table.Find(1)->data, "data1");
	EXPECT_EQ(*table.Find(2)->data, "data2");
}

TEST(TScanTable, test_Remove_1) {
	TScanTable<int, std::string> table;
	std::string data1 = "data1";
	table.Insert(1, &data1);
	ASSERT_NO_THROW(table.Remove(1));
}

TEST(TScanTable, test_Remove_2) {
	TScanTable<int, std::string> table;
	std::string data1 = "data1";
	table.Insert(1, &data1);
	table.Remove(1);
	EXPECT_EQ(table.GetMaxSize(), 100);
	EXPECT_EQ(table.GetCount(), 0);
	EXPECT_TRUE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(ScanTable, test_find) {
	TScanTable<int, std::string> table;
	std::string data1 = "data1";

	table.Insert(1, &data1);
	auto record = table.Find(1);
	ASSERT_NE(record, nullptr);
	EXPECT_EQ(record->key, 1);
	EXPECT_EQ(*record->data, "data1");

	EXPECT_EQ(table.Find(2), nullptr);
}

TEST(TScanTable, test_IsEmpty) {
	int size = 5;
	TScanTable<int, string> st(5);

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(ScanTable, test_IsTabEnded) {
	int size = 5;
	TScanTable<int, string> st(5);

	EXPECT_EQ(false, st.IsTabEnded());
}

TEST(TScanTable, test_Reset) {
	int size = 5;
	TScanTable<int, string> st(5);

	EXPECT_EQ(false, st.Reset());
}

TEST(TScanTable, test_Next) {
	int size = 5;
	TScanTable<int, string> st(5);

	EXPECT_EQ(false, st.Next());
}

TEST(ScanTable, test_GetCount) {
	int size = 5;
	TScanTable<int, string> st(5);


	EXPECT_EQ(0, st.GetCount());
}

TEST(ScanTable, test_GetMaxSize) {
	int size = 5;
	TScanTable<int, string> st(5);


	EXPECT_EQ(5, st.GetMaxSize());
}

TEST(TScanTable, test_Insert_Full) {
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

TEST(TScanTable, test_find_1) {
	int size = 5;
	TScanTable<int, string> st(5);
	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	st.Insert(key1, &data1);
	st.Insert(key2, &data1);

	EXPECT_NO_THROW(st.Find(1));
}

TEST(TScanTable, test_find_2) {
	int size = 5;
	TScanTable<int, string> st(5);
	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	st.Insert(key1, &data1);
	st.Insert(key2, &data1);

	TTabRecord<int, string>* find = st.Find(1);

	EXPECT_EQ(key1, find->key);
}

TEST(TScanTable, test_find_3) {
	int size = 5;
	TScanTable<int, string> st(5);
	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	st.Insert(key1, &data1);
	st.Insert(key2, &data1);

	TTabRecord<int, string>* find = st.Find(1);

	EXPECT_EQ(data1, *find->GetData());
}

TEST(TScanTable, test_find_4) {
	int size = 5;
	TScanTable<int, string> st(5);
	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	st.Insert(key1, &data1);
	st.Insert(key2, &data1);

	TTabRecord<int, string>* find = st.Find(1);

	EXPECT_NE(&data1, find->GetData());
}

TEST(TScanTable, test_find_5) {
	int size = 5;
	TScanTable<int, string> st(5);
	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	st.Insert(key1, &data1);
	st.Insert(key2, &data1);

	EXPECT_NO_THROW(st.Find(3));
	
}
