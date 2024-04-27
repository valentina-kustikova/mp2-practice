#include "gtest.h"

#include "ArrayScanTable.h"

#define MAX_SIZE 25

TEST(ArrayScanTable, insert_work) {
	TArrayScanTable<int, string> table(MAX_SIZE);
	Data<string>* d = new Data<string>("Ivan");
	ASSERT_NO_THROW(table.Insert(1, d));
}

TEST(ArrayScanTable, find_work) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	ASSERT_NO_THROW(table.Find(2));
}

TEST(ArrayScanTable, remove_work) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	ASSERT_NO_THROW(table.Remove(2));
}

TEST(ArrayScanTable, IsEmpty_work) {
	TArrayScanTable<int, string> table(MAX_SIZE);
	ASSERT_NO_THROW(table.IsEmpty());
}

TEST(ArrayScanTable, IsEmpty_true) {
	TArrayScanTable<int, string> table(MAX_SIZE);
	ASSERT_TRUE(table.IsEmpty());
}

TEST(ArrayScanTable, IsEmpty_false) {
	TArrayScanTable<int, string> table(MAX_SIZE);
	Data<string>* d = new Data<string>("Ivan");
	table.Insert(1, d);
	ASSERT_FALSE(table.IsEmpty());
}

TEST(ArrayScanTable, IsFull_work) {
	TArrayScanTable<int, string> table(MAX_SIZE);
	ASSERT_NO_THROW(table.IsFull());
}

TEST(ArrayScanTable, IsFull_true) {
	TArrayScanTable<int, string> table(1);
	Data<string>* d = new Data<string>("Ivan");
	table.Insert(1, d);
	ASSERT_TRUE(table.IsFull()); 
}

TEST(ArrayScanTable, IsFull_false) {
	TArrayScanTable<int, string> table(MAX_SIZE);
	Data<string>* d = new Data<string>("Ivan");
	table.Insert(1, d);
	ASSERT_FALSE(table.IsFull());
}

TEST(ArrayScanTable, getters) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	int count = table.GetCount();
	int key = table.GetKey();
	Data<string>* data = table.GetData();
	ASSERT_TRUE(count == 3 && key == 1 && data->value == "Ivan");
}

