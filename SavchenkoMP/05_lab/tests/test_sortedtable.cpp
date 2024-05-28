#include <gtest.h>

#include "sortedtable.h"

using namespace std;

/*
TEST(SortedTable, TEST_NAME) {

}
*/

/// Тест конструктора по умолчанию
TEST(SortedTable, DefaultConstructor) {
    SortedTable<int, std::string> table;
    EXPECT_EQ(table.get_size(), 0);
    EXPECT_EQ(table.get_max_size(), DEFAULT_SIZE);
    EXPECT_TRUE(table.empty());
    EXPECT_FALSE(table.full());
}

// Тест конструктора с параметром
TEST(SortedTable, ParameterizedConstructor) {
    int max_size = 20;
    SortedTable<int, std::string> table(max_size);
    EXPECT_EQ(table.get_size(), 0);
    EXPECT_EQ(table.get_max_size(), max_size);
    EXPECT_TRUE(table.empty());
    EXPECT_FALSE(table.full());
}

// Тест конструктора копирования из ScanTable
TEST(SortedTable, CopyConstructorFromScanTable) {
    ScanTable<int, std::string> scanTable(10);
    std::string data1 = "data1";
    std::string data2 = "data2";
    scanTable.insert(2, &data1);
    scanTable.insert(1, &data2);

    SortedTable<int, std::string> sortedTable(scanTable);
    EXPECT_EQ(sortedTable.get_size(), 2);
    EXPECT_EQ(*sortedTable.find(1)->data, "data2");
    EXPECT_EQ(*sortedTable.find(2)->data, "data1");
}

// Тест конструктора копирования
TEST(SortedTable, CopyConstructor) {
    SortedTable<int, std::string> original(10);
    std::string data1 = "data1";
    std::string data2 = "data2";
    original.insert(2, &data1);
    original.insert(1, &data2);

    SortedTable<int, std::string> copy(original);
    EXPECT_EQ(copy.get_size(), 2);
    EXPECT_EQ(*copy.find(1)->data, "data2");
    EXPECT_EQ(*copy.find(2)->data, "data1");
}

// Тест метода insert
TEST(SortedTable, Insert) {
    SortedTable<int, std::string> table;
    std::string data1 = "data1";
    std::string data2 = "data2";

    table.insert(2, &data1);
    table.insert(1, &data2);

    EXPECT_EQ(table.get_size(), 2);
    EXPECT_FALSE(table.empty());
    EXPECT_EQ(*table.find(1)->data, "data2");
    EXPECT_EQ(*table.find(2)->data, "data1");
}

// Тест метода remove
TEST(SortedTable, Remove) {
    SortedTable<int, std::string> table;
    std::string data1 = "data1";
    std::string data2 = "data2";

    table.insert(2, &data1);
    table.insert(1, &data2);

    table.remove(1);
    EXPECT_EQ(table.get_size(), 1);
    EXPECT_EQ(table.find(1), nullptr);
    EXPECT_EQ(*table.find(2)->data, "data1");

    table.remove(2);
    EXPECT_EQ(table.get_size(), 0);
    EXPECT_TRUE(table.empty());
    EXPECT_EQ(table.find(2), nullptr);
}

// Тест метода find
TEST(SortedTable, Find) {
    SortedTable<int, std::string> table;
    std::string data = "test_data";

    table.insert(1, &data);
    auto record = table.find(1);
    ASSERT_NE(record, nullptr);
    EXPECT_EQ(record->key, 1);
    EXPECT_EQ(*record->data, "test_data");

    EXPECT_EQ(table.find(2), nullptr);
}

// Тест перегрузки оператора []
TEST(SortedTable, BracketOperator) {
    SortedTable<int, std::string> table;
    std::string data = "test_data";

    table.insert(1, &data);
    auto record = table[1];
    ASSERT_NE(record, nullptr);
    EXPECT_EQ(record->key, 1);
    EXPECT_EQ(*record->data, "test_data");

    EXPECT_EQ(table[2], nullptr);
}


//////////////////////////////////////////////////////////


// create sort table from scan
TEST(SortedTable, constructor_with_parametr_key)
{
    ScanTable<int, string> scanTable(5);
    string data1 = "Data1";
    string data2 = "Data2";
    scanTable.insert(2, &data1);
    scanTable.insert(1, &data2);
    SortedTable<int, string> SortedTableFromScan(scanTable);
    SortedTableFromScan.reset();
    EXPECT_EQ(1, SortedTableFromScan.get_curr()->key);
}

// Copy constructor
TEST(SortedTable, copy_constructor_test)
{
    // Ñîçäàåì è çàïîëíÿåì èñõîäíóþ òàáëèöó
    SortedTable<int, string> originalTable(5);
    string data1 = "Data1";
    string data2 = "Data2";
    originalTable.insert(5, &data1);
    originalTable.insert(10, &data2);
    SortedTable<int, string> copiedTable = originalTable;

    EXPECT_EQ(originalTable.get_size(), copiedTable.get_size());
}

TEST(SortedTable, copy_constructor_test_data)
{
    SortedTable<int, string> originalTable(5);
    string data1 = "Data1";
    string data2 = "Data2";
    originalTable.insert(5, &data1);
    originalTable.insert(10, &data2);
    SortedTable<int, string> copiedTable(originalTable);

    EXPECT_EQ(*originalTable.get_curr()->data, *copiedTable.get_curr()->data);
}

TEST(SortedTable, copy_constructor_data) 
{
    SortedTable<int, string> originalTable(10);
    string data1 = "Data1";
    string data2 = "Data2";
    originalTable.insert(5, &data1);
    originalTable.insert(10, &data2);
    SortedTable<int, string> copiedTable = originalTable;
    originalTable.reset();
    copiedTable.reset();

    EXPECT_EQ(originalTable.get_curr()->key, copiedTable.get_curr()->key);
}
//Is_Empty
TEST(SortedTable, is_empty_test)
{
    SortedTable<int, string> table(5);
    ASSERT_TRUE(table.empty());
}

TEST(SortedTable, is_empty_test_false)
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    table.insert(5, &data1);
    ASSERT_FALSE(table.empty());
}

//Is_Full
TEST(SortedTable, is_full_test)
{
    SortedTable<int, string> table(5);
    ASSERT_FALSE(table.full());
}
TEST(SortedTable, is_full_test_false_with_elements)
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    table.insert(5, &data1);
    ASSERT_FALSE(table.full());
}

TEST(SortedTable, is_full_test_true)
{
    SortedTable<int, string> table(2);
    string data1 = "Data1";
    string data2 = "Data2";
    table.insert(5, &data1);
    table.insert(10, &data2);

    ASSERT_TRUE(table.full());
}
//Count
TEST(SortedTable, get_count_test)
{
    SortedTable<int, string> table(2);
    string data1 = "Data1";
    string data2 = "Data2";
    table.insert(5, &data1);
    table.insert(10, &data2);

    EXPECT_EQ(table.get_size(), 2);
}
//find
TEST(SortedTable, find_test) 
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.insert(5, &data1);
    table.insert(10, &data2);

    TabRecord<int, string>* record = table.find(5);
    EXPECT_EQ(record->key, 5);
}
TEST(SortedTable, find_non_existent_test)
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.insert(5, &data1);
    table.insert(10, &data2);

    EXPECT_EQ(table.find(7), nullptr);
}
//insert
TEST(SortedTable, insert_test)
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    table.insert(5, &data1);
    EXPECT_EQ(table.get_size(), 1);
}
TEST(SortedTable, insert_to_full_table_test)
{
    SortedTable<int, string> table(2);
    string data1 = "Data1";
    string data2 = "Data2";
    string data3 = "Data3";
    table.insert(5, &data1);
    table.insert(10, &data2);
    ASSERT_ANY_THROW(table.insert(7, &data3));
}/////
TEST(SortedTable, insert_sorted_test)
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    string data3 = "Data3";
    table.insert(5, &data1);
    table.insert(10, &data2);
    table.insert(7, &data3);
    table.reset();
    table.next();
    EXPECT_EQ(table.get_curr()->key, 7);
}
// remove
TEST(SortedTable, remove_test)
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.insert(5, &data1);
    table.insert(10, &data2);

    table.remove(5);
    EXPECT_EQ(table.get_size(), 1);

}
TEST(SortedTable, remove_non_existent_test) 
{
    SortedTable<int, string> table(5);
    string data1 = "Data1";
    string data2 = "Data2";
    table.insert(5, &data1);
    table.insert(10, &data2);
    ASSERT_ANY_THROW(table.remove(3));
}
TEST(SortedTable, remove_from_empty_table_test) 
{
    SortedTable<int, string> table(5);
    ASSERT_ANY_THROW(table.remove(3));
}
//Is tab Ended
TEST(SortedTable, is_tab_ended_test)
{
    SortedTable<int, string> table(3);

    ASSERT_FALSE(table.ended());
}
TEST(SortedTable, is_tab_ended_true_test)
{
    SortedTable<int, string> table(1);
    string data = "Data1";
    table.insert(5, &data);
    table.reset();
    table.next();

    ASSERT_TRUE(table.ended());
}
// reset
TEST(SortedTable, reset_test)
{
    SortedTable<int, string> table(3);

    ASSERT_FALSE(table.reset());
}
//next
TEST(SortedTable, next_test)
{
    SortedTable<int, string> table(3);

    ASSERT_FALSE(table.next());
}
TEST(SortedTable, next_test_true)
{
    SortedTable<int, string> table(1);
    string data = "Data1";
    table.insert(5, &data);
    table.reset();
    table.next();
    ASSERT_TRUE(table.next());
}