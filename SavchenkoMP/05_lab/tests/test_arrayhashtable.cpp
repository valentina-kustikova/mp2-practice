#include <gtest.h>

#include "arrayhashtable.h"

using namespace std;

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

    EXPECT_TRUE(table.reset());
    EXPECT_EQ(*table.find(1)->data, "data1");
    EXPECT_TRUE(table.next());
    EXPECT_EQ(*table.find(2)->data, "data2");
    EXPECT_FALSE(table.next());
}


/////////////////////////////////////////////////////


TEST(ArrayHashTable, copy_constructor_test)
{
    ArrayHashTable<string, int> table(5, 1);
    int data1 = 100;
    int data2 = 200;
    table.insert("key1", &data1);
    table.insert("key2", &data2);

    ArrayHashTable<string, int> copy_table(table);
    EXPECT_NE(copy_table.find("key1"), nullptr);
}
// insert
TEST(ArrayHashTable, insert_test)
{
    ArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    int data2 = 200;
    table.insert("key1", &data1);
    table.insert("key2", &data2);


    EXPECT_NE(table.find("key1"), nullptr);
}
TEST(ArrayHashTable, insert_to_full_table_test)
{
    ArrayHashTable<string, int> table(2, 1);

    int data1 = 100;
    int data2 = 200;
    int data3 = 300;
    table.insert("key1", &data1);
    table.insert("key2", &data2);

    ASSERT_ANY_THROW(table.insert("key3", &data3));
}
// remove
TEST(ArrayHashTable, remove_test)
{
    ArrayHashTable<string, int> table(10, 3);

    int data1 = 100;
    table.insert("key1", &data1);
    table.remove("key1");

    EXPECT_EQ(table.find("key1"), nullptr);
}
TEST(ArrayHashTable, remove_error_test)
{
    ArrayHashTable<string, int> table(10, 3);

    ASSERT_ANY_THROW(table.remove("key4"));
}
// find
TEST(ArrayHashTable, find_test)
{
    ArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    table.insert("key1", &data1);

    TabRecord<string, int>* foundRecord = table.find("key1");
    EXPECT_EQ(foundRecord->key, "key1");
}
TEST(ArrayHashTable, find_non_existent_test) {
    ArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    table.insert("key1", &data1);

    TabRecord<string, int>* foundRecord = table.find("key3");
    EXPECT_EQ(foundRecord, nullptr);
}
// reset
TEST(ArrayHashTable, reset_test)
{
    ArrayHashTable<string, int> table(5, 1);

    // Âñòàâèì ýëåìåíòû â òàáëèöó
    int data1 = 100;
    table.insert("key1", &data1);
    int data2 = 200;
    table.insert("key2", &data2);

    ASSERT_TRUE(table.reset());
}
TEST(ArrayHashTable, reset_test_key)
{
    ArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    table.insert("key1", &data1);
    int data2 = 200;
    table.insert("key2", &data2);
    table.reset();
    EXPECT_EQ(table.get_curr()->key, "key1");
}
// next
TEST(ArrayHashTable, next_test)
{
    ArrayHashTable<string, int> table(10, 3);

    int data1 = 100;
    table.insert("key1", &data1);
    int data2 = 200;
    table.insert("key2", &data2);

    table.reset();
    table.next();
    EXPECT_EQ(table.get_curr()->key, "key2");
}
TEST(ArrayHashTable, next_test_end)
{
    ArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    table.insert("key1", &data1);
    int data2 = 200;
    table.insert("key2", &data2);

    table.reset();
    table.next();
    table.next();
    ASSERT_FALSE(table.next());
}
//GetKey
TEST(ArrayHashTable, GetKeyTest)
{
    ArrayHashTable<string, int> table(5, 1);

    int data = 5;
    string key = "test data";
    table.insert(key, &data);

    string retrievedKey = table.get_curr()->key;

    EXPECT_EQ(retrievedKey, key);
}
//GetData
TEST(ArrayHashTable, GetDataTest)
{
    ArrayHashTable<string, int> table(5, 1);

    int data = 5;
    string key = "test data";
    table.insert(key, &data);

    int* retrievedData = table.get_curr()->data;

    EXPECT_EQ(*retrievedData, data);
}
//Is full
TEST(ArrayHashTable, is_full_test_false)
{
    ArrayHashTable<string, string> ht(3, 1);

    ASSERT_FALSE(ht.full());
}

TEST(ArrayHashTable, is_full_test_false_with_elements)
{
    ArrayHashTable<string, string> ht(3, 1);
    string data = "abc";
    string key = "one";
    ht.insert(key, &data);
    ASSERT_FALSE(ht.full());
}

TEST(ArrayHashTable, is_full_test_true)
{
    ArrayHashTable<string, string> ht(2, 1);
    string key = "one";
    string data = "abc";
    ht.insert(key, &data);
    string key2 = "two";
    string data2 = "cbc";
    ht.insert(key2, &data2);
    ASSERT_TRUE(ht.full());
}
//Is Empty
TEST(ArrayHashTable, is_empty_test_false)
{
    ArrayHashTable<string, string> ht(3, 1);
    string key = "one";
    string data = "abc";
    ht.insert(key, &data);
    ASSERT_FALSE(ht.empty());
}

TEST(ArrayHashTable, is_empty_test_true)
{
    ArrayHashTable<string, string> ht(3, 1);

    ASSERT_TRUE(ht.empty());
}
//Count
TEST(ArrayHashTable, get_count_test)
{
    ArrayHashTable<string, string> ht(3, 1);
    string key = "one";
    string data = "abc";
    ht.insert(key, &data);
    string key2 = "two";
    string data2 = "cbc";
    ht.insert(key2, &data2);
    EXPECT_EQ(ht.get_size(), 2);
}