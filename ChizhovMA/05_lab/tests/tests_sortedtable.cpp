#include "SortTable.h"

#include <gtest.h>


TEST(TSortTable, constructor_with_parametr)
{
    TScanTable<int, string> scanTable(5);
    string data1 = "Data1";
    string data2 = "Data2";
    scanTable.Insert(2, &data1);
    scanTable.Insert(1, &data2);
    TSortTable<int, string> sortTableFromScan(&scanTable);
    sortTableFromScan.Reset();
    EXPECT_EQ(1, sortTableFromScan.GetKey());
}
// Copy constructor
TEST(TSortTable, copy_constructor_test)
{
    // Создаем и заполняем исходную таблицу
    TSortTable<int, string> originalTable(5);
    string data1 = "Data1";
    string data2 = "Data2";
    originalTable.Insert(5, &data1);
    originalTable.Insert(10, &data2);
    TSortTable<int, string> copiedTable = originalTable;

    EXPECT_EQ(originalTable.GetCount(), copiedTable.GetCount());
}
TEST(TSortTable, copy_constructor_data) 
{
    // Создаем и заполняем исходную таблицу
    TSortTable<int, string> originalTable(10);
    string data1 = "Data1";
    string data2 = "Data2";
    originalTable.Insert(5, &data1);
    originalTable.Insert(10, &data2);
    TSortTable<int, string> copiedTable = originalTable;
    originalTable.Reset();
    copiedTable.Reset();

    EXPECT_EQ(originalTable.GetKey(), copiedTable.GetKey());
}
//Find
TEST(TSortTable, find_test) 
{
    TSortTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.Insert(5, &data1);
    table.Insert(10, &data2);

    TabRecord<int, string>* record = table.Find(5);
    EXPECT_EQ(record->GetKey(), 5);
}
TEST(TSortTable, find_non_existent_test)
{
    TSortTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.Insert(5, &data1);
    table.Insert(10, &data2);

    EXPECT_EQ(table.Find(7), nullptr);
}
//Insert
TEST(TSortTable, insert_test)
{
    TSortTable<int, string> table(5);
    string data1 = "Data1";
    table.Insert(5, &data1);
    EXPECT_EQ(table.GetCount(), 1);
}
TEST(TSortTable, insert_to_full_table_test)
{
    TSortTable<int, string> table(2);
    string data1 = "Data1";
    string data2 = "Data2";
    string data3 = "Data3";
    table.Insert(5, &data1);
    table.Insert(10, &data2);
    ASSERT_ANY_THROW(table.Insert(7, &data3));
}
TEST(TSortTable, insert_sorted_test)
{
    TSortTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    string data3 = "Data3";
    table.Insert(5, &data1);
    table.Insert(10, &data2);
    table.Insert(7, &data3);
    table.Reset();
    table.Next();
    EXPECT_EQ(table.GetKey(), 7);
}
// Remove
TEST(TSortTable, remove_test)
{
    TSortTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.Insert(5, &data1);
    table.Insert(10, &data2);

    table.Remove(5);
    EXPECT_EQ(table.GetCount(), 1);

}
TEST(TSortTable, remove_non_existent_test) 
{
    TSortTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.Insert(5, &data1);
    table.Insert(10, &data2);
    ASSERT_ANY_THROW(table.Remove(3));
}
TEST(TSortTable, remove_from_empty_table_test) 
{
    TSortTable<int, string> table(5);
    ASSERT_ANY_THROW(table.Remove(3));
}
