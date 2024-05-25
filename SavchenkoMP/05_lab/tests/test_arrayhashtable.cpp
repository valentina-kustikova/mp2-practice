#include <gtest.h>

#include "arrayhashtable.h"

/*
TEST(ArrayHashTable, TEST_NAME) {

}
*/

// Тест конструктора по умолчанию
TEST(ArrayHashTable, DefaultConstructor) {
    ArrayHashTable<int, std::string> table;
    EXPECT_EQ(table.get_size(), 0);
    EXPECT_EQ(table.get_max_size(), DEFAULT_SIZE);
    EXPECT_TRUE(table.empty());
    EXPECT_FALSE(table.full());
}

// Тест конструктора с параметрами
TEST(ArrayHashTable, ParameterizedConstructor) {
    int max_size = 20;
    size_t hash_step = 7;
    ArrayHashTable<int, std::string> table(max_size, hash_step);
    EXPECT_EQ(table.get_size(), 0);
    EXPECT_EQ(table.get_max_size(), max_size);
    EXPECT_TRUE(table.empty());
    EXPECT_FALSE(table.full());
}

// Тест конструктора копирования
TEST(ArrayHashTable, CopyConstructor) {
    ArrayHashTable<int, std::string> original(10, 3);
    std::string data1 = "data1";
    std::string data2 = "data2";
    original.insert(1, &data1);
    original.insert(2, &data2);

    ArrayHashTable<int, std::string> copy(original);
    EXPECT_EQ(copy.get_size(), 2);
    EXPECT_EQ(*copy.find(1)->data, "data1");
    EXPECT_EQ(*copy.find(2)->data, "data2");
}

// Тест метода insert
TEST(ArrayHashTable, Insert) {
    ArrayHashTable<int, std::string> table;
    std::string data1 = "data1";
    std::string data2 = "data2";

    table.insert(1, &data1);
    EXPECT_EQ(table.get_size(), 1);
    EXPECT_FALSE(table.empty());
    EXPECT_EQ(*table.find(1)->data, "data1");

    table.insert(2, &data2);
    EXPECT_EQ(table.get_size(), 2);
    EXPECT_EQ(*table.find(2)->data, "data2");
}

// Тест метода remove
TEST(ArrayHashTable, Remove) {
    ArrayHashTable<int, std::string> table;
    std::string data1 = "data1";
    std::string data2 = "data2";

    table.insert(1, &data1);
    table.insert(2, &data2);

    table.remove(1);
    EXPECT_EQ(table.get_size(), 1);
    EXPECT_EQ(table.find(1), nullptr);
    EXPECT_EQ(*table.find(2)->data, "data2");

    table.remove(2);
    EXPECT_EQ(table.get_size(), 0);
    EXPECT_TRUE(table.empty());
    EXPECT_EQ(table.find(2), nullptr);
}

// Тест метода find
TEST(ArrayHashTable, Find) {
    ArrayHashTable<int, std::string> table;
    std::string data = "test_data";

    table.insert(1, &data);
    auto record = table.find(1);
    ASSERT_NE(record, nullptr);
    EXPECT_EQ(record->key, 1);
    EXPECT_EQ(*record->data, "test_data");

    EXPECT_EQ(table.find(2), nullptr);
}

// Тест перегрузки оператора []
TEST(ArrayHashTable, BracketOperator) {
    ArrayHashTable<int, std::string> table;
    std::string data = "test_data";

    table.insert(1, &data);
    auto record = table[1];
    ASSERT_NE(record, nullptr);
    EXPECT_EQ(record->key, 1);
    EXPECT_EQ(*record->data, "test_data");

    EXPECT_EQ(table[2], nullptr);
}

// Тест методов reset и next
TEST(ArrayHashTable, ResetAndNext) {
    ArrayHashTable<int, std::string> table;
    std::string data1 = "data1";
    std::string data2 = "data2";

    table.insert(1, &data1);
    table.insert(2, &data2);

    EXPECT_FALSE(table.reset());
    EXPECT_EQ(*table.find(1)->data, "data1");
    EXPECT_FALSE(table.next());
    EXPECT_EQ(*table.find(2)->data, "data2");
    EXPECT_FALSE(table.next());
}