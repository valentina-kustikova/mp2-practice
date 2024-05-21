#include "gtest.h"
#include "hash_table.h"
#include "scan_table.h"
#include "sorted_table.h"
#include "table.h"
#include "record.h"
// ------- table -------
TEST (table, empty_)
{
    ScanTable<int, int> tabl;
    ASSERT_EQ(tabl.empty(), true);
    tabl.insert(1, 1);
    ASSERT_EQ(tabl.empty(), false);
} 

TEST (table, full)
{
    ScanTable<int, int> table(1);
    ASSERT_EQ(table.full(), false);
    table.insert(1, 1);
    ASSERT_EQ(table.full(), true);
}

TEST (table, get_size)
{
    ScanTable<int, int> table(1);
    ASSERT_EQ(table.get_size(), 0);
    table.insert(1, 1);
    ASSERT_EQ(table.get_size(), 1);
}

TEST (table, next_)
{
    ScanTable<int, int> table(1); table.insert(1, 0);
    ASSERT_EQ(table.next(), true);
    ASSERT_EQ(table.next(), false);
}
// ------- scan table ------- 
TEST(scan_table, create_scan_table)
{
    ScanTable<int, int> t1, t2(-5), t3(0);
    ASSERT_EQ(t1.get_max_size(), 101);
    ASSERT_EQ(t2.get_max_size(), -1);
    ASSERT_EQ(t3.get_max_size(), -1);  
}

TEST(scan_table, find_)
{
    ScanTable<int, int> table(10);
    table.insert(1, 1); table.insert(2, 2); table.insert(3, 3);
    ASSERT_NO_THROW(table.find(1));
    ASSERT_EQ(table.find(2)->data, 2);
    ASSERT_EQ(table.find(4), nullptr);
}

TEST(scan_table, insert)
{
    ScanTable<int, int> table(10);
    for (int i = 0; i < 5; ++i)
        ASSERT_NO_THROW(table.insert(i, i));
    for(int i = 0; i < 5; ++i)
    {
        ASSERT_NE(table.find(i), nullptr);
        ASSERT_EQ(table.find(i)->data, i);
    } 
}

TEST(scan_table, remove)
{
    ScanTable<int, int> table(10);
    for (int i = 0; i < 5; ++i)
        ASSERT_NO_THROW(table.insert(i, i));
        
    for(int i = 0; i < 5; ++i)
    {
        ASSERT_NO_THROW(table.remove(i));
        ASSERT_EQ(table.find(i), nullptr);
    }    
}

// ------- sorted table ------- 
TEST(sorted_table, create_scan_table)
{
    SortedTable<int, int> t1, t2(-5), t3(0);
    ASSERT_EQ(t1.get_max_size(), 101);
    ASSERT_EQ(t2.get_max_size(), -1);
    ASSERT_EQ(t3.get_max_size(), -1);
}

TEST(sorted_table, find_)
{
    SortedTable<int, int> table(10);
    table.insert(1, 1); table.insert(2, 2); table.insert(3, 3);
    ASSERT_NO_THROW(table.find(1));
    ASSERT_EQ(table.find(2)->data, 2);
    ASSERT_EQ(table.find(4), nullptr);
}

TEST(sorted_table, insert)
{
    SortedTable<int, int> table(10);
    for (int i = 0; i < 5; ++i)
        ASSERT_NO_THROW(table.insert(i, i));
    for(int i = 0; i < 5; ++i)
    {
        ASSERT_NE(table.find(i), nullptr);
        ASSERT_EQ(table.find(i)->data, i);
    } 
}

TEST(sorted_table, remove)
{
    SortedTable<int, int> table(10);
    for (int i = 0; i < 5; ++i)
        ASSERT_NO_THROW(table.insert(i, i));
        
    for(int i = 0; i < 5; ++i)
    {
        ASSERT_NO_THROW(table.remove(i));
        ASSERT_EQ(table.find(i), nullptr);
    }    

}

// hash table

TEST(hash_table, create_hash_table)
{
    HashTable<int, int> t1, t2(-5), t3(0);
    ASSERT_EQ(t1.get_max_size(), 101);
    ASSERT_EQ(t2.get_max_size(), -1);
    ASSERT_EQ(t3.get_max_size(), -1);
}

TEST(hash_table, find_)
{
    HashTable<int, int> table(10);
    table.insert(1, 1); table.insert(2, 2); table.insert(3, 3);
    ASSERT_NO_THROW(table.find(1));
    ASSERT_EQ(table.find(2)->data, 2);
    ASSERT_EQ(table.find(4), nullptr);
}

TEST(hash_table, insert)
{
    HashTable<int, int> table(10);
    for (int i = 0; i < 5; ++i)
        ASSERT_NO_THROW(table.insert(i, i));
    for (int i = 0; i < 5; ++i)
    {
        ASSERT_NE(table.find(i), nullptr);
        ASSERT_EQ(table.find(i)->data, i);
    }
}

TEST(hash_table, remove)
{
    HashTable<int, int> table(10);
    for (int i = 0; i < 5; ++i)
        ASSERT_NO_THROW(table.insert(i, i));

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_NO_THROW(table.remove(i));
        ASSERT_EQ(table.find(i), nullptr);
    }
}
