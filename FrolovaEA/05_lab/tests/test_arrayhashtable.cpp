#include <gtest.h>
#include "Arrayhashtable.h"

TEST(TArrayHashTable, constructor_auto_params) {
	TArrayHashTable<int, std::string> table;
	EXPECT_EQ(table.GetMaxSize(), 100);
	EXPECT_EQ(table.GetCount(), 0);
	EXPECT_TRUE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(TArrayHashTable, constructor_get_params) {
	TArrayHashTable<int, std::string> table(50,19);
	EXPECT_EQ(table.GetMaxSize(), 50);
	EXPECT_EQ(table.GetCount(), 0);
	EXPECT_TRUE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(TArrayHashTable, test_getCount_constructor) {
	TArrayHashTable<int, std::string> table(10,3);
	std::string data1 = "data1";
	std::string data2 = "data2";
	table.Insert(1, &data1);
	table.Insert(2, &data2);
	EXPECT_EQ(table.GetMaxSize(), 10);
	EXPECT_EQ(table.GetCount(), 2);
	EXPECT_FALSE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(TArrayHashTable, CopyConstructor) {
	TArrayHashTable<int, std::string> table(10,3);
	std::string data1 = "data1";
	std::string data2 = "data2";
	table.Insert(1, &data1);
	table.Insert(2, &data2);

	TArrayHashTable<int, std::string> copy(table);
	EXPECT_EQ(copy.GetCount(), 2);
	EXPECT_EQ(*copy.Find(1)->data, "data1");
	EXPECT_EQ(*copy.Find(2)->data, "data2");
}

TEST(TArrayHashTable, test_insert) {
	TArrayHashTable<int, std::string> table;
	std::string data1 = "data1";
	std::string data2 = "data2";
	table.Insert(1, &data1);
	table.Insert(2, &data2);
	EXPECT_EQ(table.GetCount(), 2);
	EXPECT_FALSE(table.IsEmpty());
	EXPECT_EQ(*table.Find(1)->data, "data1");
	EXPECT_EQ(*table.Find(2)->data, "data2");
}

TEST(TArrayHashTable, test_Remove_1) {
	TArrayHashTable<int, std::string> table;
	std::string data1 = "data1";
	table.Insert(1, &data1);
	ASSERT_NO_THROW(table.Remove(1));
}

TEST(TArrayHashTable, test_Remove_2) {
	TArrayHashTable<int, std::string> table;
	std::string data1 = "data1";
	table.Insert(1, &data1);
	table.Remove(1);
	EXPECT_EQ(table.GetMaxSize(), 100);
	EXPECT_EQ(table.GetCount(), 0);
	EXPECT_TRUE(table.IsEmpty());
	EXPECT_EQ(0, table.IsFull());
}

TEST(TArrayHashTable, test_find) {
	TArrayHashTable<int, std::string> table;
	std::string data1 = "data1";

	table.Insert(1, &data1);
	auto record = table.Find(1);
	ASSERT_NE(record, nullptr);
	EXPECT_EQ(record->key, 1);
	EXPECT_EQ(*record->data, "data1");

	EXPECT_EQ(table.Find(2), nullptr);
}


