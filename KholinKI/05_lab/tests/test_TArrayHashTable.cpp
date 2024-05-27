#include "ArrayHashTable.h"

#include "gtest.h"

TEST(ArrayHashTable, insert_work) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	ASSERT_NO_THROW(table.Insert(1, names[0]));
}

TEST(ArrayHashTable, insert_exist_record) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	ASSERT_ANY_THROW(table.Insert(1, names[0]));
}

TEST(ArrayHashTable, insert_no_exist_record) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[0]);

	table.Insert(4, names[0]);
	table.Insert(7, names[0]);
	ASSERT_NO_THROW(table.Insert(2, names[1]));
}

TEST(ArrayHashTable, find_work) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[1]);

	table.Insert(4, names[0]);
	table.Insert(7, names[2]);

	ASSERT_NO_THROW(table.Find(4));
}

TEST(ArrayHashTable, find_when_table_empty) {
	TArrayHashTable<int, string> table;

	ASSERT_NO_THROW(table.Find(4));
}



TEST(ArrayHashTable, find_no_exist_record) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[1]);

	table.Insert(4, names[0]);
	table.Insert(7, names[2]);

	ASSERT_NO_THROW(table.Find(5));
}

TEST(ArrayHashTable, find_exist_record_with_check) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[1]);

	table.Insert(4, names[0]);
	table.Insert(7, names[2]);

	TTabRecord<int, string>* search = table.Find(4);

	ASSERT_TRUE(search->key == 4);
}

TEST(ArrayHashTable, find_no_exist_record_with_check) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[1]);

	table.Insert(4, names[0]);
	table.Insert(7, names[2]);

	TTabRecord<int, string>* search = table.Find(5);

	ASSERT_TRUE(search == nullptr);
}

TEST(ArrayHashTable, remove_work) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[1]);

	table.Insert(4, names[0]);
	table.Insert(7, names[2]);

	ASSERT_NO_THROW(table.Remove(10));
}

TEST(ArrayHashTable, remove_when_table_empty) {
	TArrayHashTable<int, string> table;

	ASSERT_NO_THROW(table.Remove(10));
}


TEST(ArrayHashTable, remove_no_exist_record) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[1]);

	table.Insert(4, names[0]);
	table.Insert(7, names[2]);

	ASSERT_ANY_THROW(table.Remove(9));
}

TEST(ArrayHashTable, remove_and_insert_again) {
	TArrayHashTable<int, string> table;

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table.Insert(1, names[0]);
	table.Insert(10, names[1]);

	table.Insert(4, names[0]);
	table.Insert(7, names[2]);

	table.Remove(4);
	
	ASSERT_NO_THROW(table.Insert(4, names[0]));
}

TEST(ArrayHashTable, destructor_work) {
	TArrayHashTable<int, string>* table = new TArrayHashTable<int,string>();

	Data<string>** names = new Data<string>*[3];
	names[0] = new Data<string>("Ivan");
	names[1] = new Data<string>("Nikolay");
	names[2] = new Data<string>("Aleksandr");

	table->Insert(1, names[0]);
	table->Insert(10, names[1]);

	table->Insert(4, names[0]);
	table->Insert(7, names[2]);

	ASSERT_NO_THROW(delete table);
}
