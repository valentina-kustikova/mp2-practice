#include <gtest.h>

#include "ArraySortTable.h"

#define MAX_SIZE 25

TEST(ArraySortTable, insert_work) {
	TArraySortTable<int, string> table(MAX_SIZE);
	Data<string>* d = new Data<string>("Ivan");
	ASSERT_NO_THROW(table.Insert(1, d));
}

TEST(ArraySortTable, find_work) {
	TArraySortTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	ASSERT_NO_THROW(table.Find(2));
}

//TEST(ArraySortTable, constructor_transformation_to_SortTable_work) {
//
//}

//TEST(ArraySortTable, SimpleSort_work) {
//	TArraySortTable<int, string> table(MAX_SIZE);
//
//	Data<string>** names = new Data<string>*[3];
//	names[0] = new Data<string>("Ivan");
//	names[1] = new Data<string>("Nikolay");
//	names[2] = new Data<string>("Aleksandr");
//
//	table.Insert(1, names[0]);
//	table.Insert(-4, names[1]);
//	table.Insert(3, names[2]);
//
//	ASSERT_NO_THROW(table.SimpleSort());
//}
//
//TEST(ArraySortTable, SelectSort_work) {
//	TArraySortTable<int, string> table(MAX_SIZE);
//
//	Data<string>** names = new Data<string>*[3];
//	names[0] = new Data<string>("Ivan");
//	names[1] = new Data<string>("Nikolay");
//	names[2] = new Data<string>("Aleksandr");
//
//	table.Insert(1, names[0]);
//	table.Insert(-4, names[1]);
//	table.Insert(3, names[2]);
//
//	ASSERT_NO_THROW(table.SelectSort());
//}
//
//TEST(ArraySortTable, InsertSort_work) {
//	TArraySortTable<int, string> table(MAX_SIZE);
//
//	Data<string>** names = new Data<string>*[3];
//	names[0] = new Data<string>("Ivan");
//	names[1] = new Data<string>("Nikolay");
//	names[2] = new Data<string>("Aleksandr");
//	names[3] = new Data<string>("Nikolay");
//	names[4] = new Data<string>("Kirill");
//
//	table.Insert(1, names[0]);
//	table.Insert(-4, names[1]);
//	table.Insert(-8, names[2]);
//	table.Insert(8, names[3]);
//	table.Insert(6, names[4]);
//
//	ASSERT_NO_THROW(table.InsertSort());
//}
//
//TEST(ArraySortTable, BubbleSort_work) {
//	TArraySortTable<int, string> table(MAX_SIZE);
//
//	Data<string>** names = new Data<string>*[3];
//	names[0] = new Data<string>("Ivan");
//	names[1] = new Data<string>("Nikolay");
//	names[2] = new Data<string>("Aleksandr");
//	names[3] = new Data<string>("Nikolay");
//	names[4] = new Data<string>("Kirill");
//
//	table.Insert(1, names[0]);
//	table.Insert(-4, names[1]);
//	table.Insert(-8, names[2]);
//	table.Insert(8, names[3]);
//	table.Insert(6, names[4]);
//
//	ASSERT_NO_THROW(table.BubbleSort());
//}


//TEST(ArraySortTable, remove_work) {
//	TArraySortTable<int, string> table(MAX_SIZE);
//
//	Data<string>** names = new Data<string>*[3];
//	names[0] = new Data<string>("Ivan");
//	names[1] = new Data<string>("Nikolay");
//	names[2] = new Data<string>("Aleksandr");
//
//	table.Insert(1, names[0]);
//	table.Insert(2, names[1]);
//	table.Insert(3, names[2]);
//
//	ASSERT_NO_THROW(table.Remove(1));
//}