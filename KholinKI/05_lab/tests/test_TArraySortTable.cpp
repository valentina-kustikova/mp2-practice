#include <gtest.h>

#include "ArraySortTable.h"

#define MAX_SIZE 25


TEST(ArraySortTable, constructor_transformation_to_SortTable_work) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	TArraySortTable<int, string> sort_table(table);
}

TEST(ArraySortTable, find_work) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	TArraySortTable<int, string> sort_table(table);

	ASSERT_NO_THROW(sort_table.Find(2));
}

TEST(ArraySortTable, insert_with_exist_key_after_sort) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	TArraySortTable<int, string> sort_table(table);
	ASSERT_ANY_THROW(sort_table.Insert(3,names[0]));
}

TEST(ArraySortTable, insert_with_no_exist_key_after_sort) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[5];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");
	names[3] = new Data<string>("Vanya");
	names[4] = new Data<string>("Kirill");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);
	table.Insert(5, names[3]);
	table.Insert(7, names[4]);


	TArraySortTable<int, string> sort_table(table);
	sort_table.Insert(8, names[0]);

	TTabRecord<int, string>* test = sort_table.Find(8);
	EXPECT_EQ(8,test->key);
}

TEST(ArraySortTable, find_check_record) {
	TArrayScanTable<int, string> table(MAX_SIZE);

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(2, names[1]);
	table.Insert(3, names[2]);

	TArraySortTable<int, string> sort_table(table);

	TTabRecord<int, string>* test = table.Find(2);

	EXPECT_EQ(2, test->key);
}

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