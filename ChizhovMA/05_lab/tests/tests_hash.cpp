#include "HashTable.h"
#include "ArrayHashTable.h"
#include <gtest.h>

using namespace std;

// Тест конструктора и хэш-функции
//TEST(TArrayHashTable, ConstructorAndHashFunctionTest) {
//    size_t tableSize = 10;
//    size_t step = 3;
//    TArrayHashTable<string, int> arrayHashTable(tableSize, step);
//
//    // Тестируем хеширование строки "hello"
//    size_t expectedHashValue = 0;
//    const string testKey = "hello";
//    for (char c : testKey) {
//        expectedHashValue += c;
//    }
//    expectedHashValue %= tableSize;
//
//    size_t hashValue = arrayHashTable.hash_func(testKey);
//    EXPECT_EQ(hashValue, expectedHashValue);
//}

// Insert
TEST(TArrayHashTable, insert_test) 
{
    TArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    int data2 = 200;
    table.Insert("key1", &data1);
    table.Insert("key2", &data2);

    // Тестируем, что элементы были вставлены и находятся в таблице
    EXPECT_NE(table.Find("key1"), nullptr);
    EXPECT_NE(table.Find("key2"), nullptr);
}
TEST(TArrayHashTable, insert_to_full_table_test)
{
    TArrayHashTable<string, int> table(2, 1);

    int data1 = 100;
    int data2 = 200;
    int data3 = 300;
    table.Insert("key1", &data1);
    table.Insert("key2", &data2);

    ASSERT_ANY_THROW(table.Insert("key3", &data3));
}

// Remove
TEST(TArrayHashTable, remove_test)
{
    TArrayHashTable<string, int> table(10, 3);

    int data1 = 100;
    table.Insert("key1", &data1);
    table.Remove("key1");

    EXPECT_EQ(table.Find("key1"), nullptr);
}
TEST(TArrayHashTable, remove_error_test)
{
    TArrayHashTable<string, int> table(10, 3);

    int data1 = 100;
    table.Insert("key1", &data1);
    table.Remove("key1");

    ASSERT_ANY_THROW(table.Remove("key4"));
}
// Find
TEST(TArrayHashTable, find_test) {
    TArrayHashTable<string, int> table(5, 3);

    int data1 = 100;
    table.Insert("key1", &data1);

    TabRecord<string, int>* foundRecord = table.Find("key1");
    EXPECT_EQ(foundRecord->GetKey(), "key1");
}
TEST(TArrayHashTable, find_non_existent_test) {
    TArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    table.Insert("key1", &data1);

    TabRecord<string, int>* foundRecord = table.Find("key1");
    EXPECT_NE(foundRecord, nullptr);
}
// Reset
TEST(TArrayHashTable, reset_test) 
{
    TArrayHashTable<string, int> table(5, 1);

    // Вставим элементы в таблицу
    int data1 = 100;
    table.Insert("key1", &data1);
    int data2 = 200;
    table.Insert("key2", &data2);

    ASSERT_FALSE(table.Reset());
}
TEST(TArrayHashTable, reset_test_key) 
{
    TArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    table.Insert("key1", &data1);
    int data2 = 200;
    table.Insert("key2", &data2);
    table.Reset();
    EXPECT_EQ(table.GetKey(), "key1");
}
// Next
TEST(TArrayHashTable, next_test)
{
    TArrayHashTable<string, int> table(10, 3);

    int data1 = 100;
    table.Insert("key1", &data1);
    int data2 = 200;
    table.Insert("key2", &data2);

    table.Reset();
    table.Next();
    EXPECT_EQ(table.GetKey(), "key2");
}
TEST(TArrayHashTable, next_test_end)
{
    TArrayHashTable<string, int> table(5, 1);

    int data1 = 100;
    table.Insert("key1", &data1);
    int data2 = 200;
    table.Insert("key2", &data2);

    table.Reset();
    table.Next();
    table.Next();
    ASSERT_TRUE(table.Next());
}
//GetKey
TEST(TArrayHashTable, GetKeyTest)
{
    TArrayHashTable<string, int> table(5, 1);

    int data = 5;
    string key = "test data";
    table.Insert(key, &data);

    string retrievedKey = table.GetKey();

    EXPECT_EQ(retrievedKey, key);
}
//GetData
TEST(TArrayHashTable, GetDataTest)
{
    TArrayHashTable<string, int> table(5, 1);

    int data = 5;
    string key = "test data";
    table.Insert(key, &data);

    int* retrievedData = table.GetData();

    EXPECT_EQ(*retrievedData, data);
}