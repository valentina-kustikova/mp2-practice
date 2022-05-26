#include <gtest.h>
#include "hashTable.h"
#include <polinom.h>

#define SS <int,string>

TEST(HashTable, comparison_count_after_delete)
{
    HashTable SS  T1(5);
    T1.Insert(1, "1");
    T1.Delete("1");
    EXPECT_EQ(0, T1.GetCount());
}

TEST(HashTable, comparison_count_after_delete1)
{
    HashTable SS  T1(5);
    T1.Insert(1, "1");
    T1.Delete("1");
    T1.Insert(1, "1");
    EXPECT_EQ(1, T1.GetCount());
}

TEST(HashTable, can_create_table1)
{
    ASSERT_NO_THROW(HashTable SS T2);
}


TEST(HashTable, can_not_GetKey_empty_table)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.GetKey());
}
TEST(HashTable, can_not_GetData_empty_table)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.GetData());
}

TEST(HashTable, can_not_Delete_empty_table)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.Delete("xyz"));
}
TEST(HashTable, can_not_Search_empty_table1)
{
    HashTable SS  T1;
    EXPECT_EQ(nullptr, T1.Search("xyz"));
}
TEST(HashTable, can_Reset_empty_table1)
{
    HashTable SS  T1;
    ASSERT_NO_THROW(T1.Reset());
}
TEST(HashTable, IsEnd_correct_empty_table1)
{
    HashTable SS  T1;
    EXPECT_EQ(true, T1.IsTabEnded());
}
TEST(HashTable, can_Insert_empty_table1)
{
    HashTable SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, "xyz"));
}
TEST(HashTable, Insert_correct_empty_table1)
{
    HashTable SS  T1;
    T1.Insert(1, "xyz");
    EXPECT_EQ(1, T1.GetCount());
    EXPECT_EQ(1, *(T1.Search("xyz")));
}

TEST(HashTable, comparison_maxSize)
{
    HashTable SS  T1;
    EXPECT_EQ(10, T1.GetMaxSize());
}

TEST(HashTable, comparison_maxSize1)
{
    HashTable SS  T1(5);
    EXPECT_EQ(5, T1.GetMaxSize());
}

