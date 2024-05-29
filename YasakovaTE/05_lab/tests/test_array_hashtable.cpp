#include "ArrayHashTable.h"
#include "HashTable.h"
#include <gtest.h>
using namespace std;

TEST(ArrayHashTable, can_create_table) {
    ArrayHashTable<int, string> hashTable(10, 1);
    EXPECT_TRUE(hashTable.IsEmpty());
}

TEST(ArrayHashTableTest, InsertTest) {
    ArrayHashTable<int, string> hashTable(10, 1);
    hashTable.Insert(1, new std::string("data1"));
    ASSERT_NE(hashTable.Find(1), nullptr);
}

TEST(ArrayHashTable, CollisionTest) {
    ArrayHashTable<int, string> hashTable(3, 1);
    hashTable.Insert(1, new std::string("data1"));
    hashTable.Insert(4, new std::string("data2")); // 4 % 3 = 1, коллизия
    ASSERT_NE(hashTable.Find(1), nullptr);
    ASSERT_NE(hashTable.Find(4), nullptr);
}

TEST(ArrayHashTable, ReinsertionTest) {
    ArrayHashTable<int, string> hashTable(10, 1);
    hashTable.Insert(1, new std::string("data1"));
    hashTable.Remove(1);
    hashTable.Insert(1, new std::string("newData")); // Повторная вставка
    ASSERT_NE(hashTable.Find(1), nullptr);
}

TEST(ArrayHashTable, CopyConstructorTest) {
    ArrayHashTable<int, string> hashTable(5, 2);
    hashTable.Insert(1, new std::string("data1"));
    ArrayHashTable<int, string> copiedTable(hashTable);

    ASSERT_NE(hashTable.Find(1), nullptr);
    ASSERT_NE(copiedTable.Find(1), nullptr);
}

TEST(ArrayHashTable, FindNotExistingElementTest) {
    ArrayHashTable<int, string> hashTable(5, 2);
    hashTable.Insert(1, new std::string("data1"));
    ASSERT_EQ(hashTable.Find(2), nullptr);
}