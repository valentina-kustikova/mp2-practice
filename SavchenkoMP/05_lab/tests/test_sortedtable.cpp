#include <gtest.h>

#include "sortedtable.h"

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