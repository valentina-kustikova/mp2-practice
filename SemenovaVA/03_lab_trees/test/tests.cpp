#include <gtest.h>
#include <string>
#include "ScanTable.h"
#include "SortTable.h"
#include "HashTable.h"
#define SS <int,string>

using namespace std;

//Тесты для класса просматриваемых таблиц
TEST(ScanTable, can_create_table1)
{
    ASSERT_NO_THROW(ScanTable SS T2);
}
TEST(ScanTable, can_copy_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_NO_THROW(ScanTable SS T2(T1));
}
TEST(ScanTable, can_not_GetData_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_ANY_THROW(T1.GetData());
}
TEST(ScanTable, can_not_GetKey_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_ANY_THROW(T1.GetKey());
}
TEST(ScanTable, can_not_SetNext_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_ANY_THROW(T1.SetNext());
}
TEST(ScanTable, can_not_Delete_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_ANY_THROW(T1.Delete("one"));
}
TEST(ScanTable, can_not_Search_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_ANY_THROW(T1.Search("one"));
}
TEST(ScanTable, can_Reset_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_NO_THROW(T1.Reset());
}
TEST(ScanTable, IsEnd_correct_empty_table1)
{
    ScanTable SS  T1;
    EXPECT_EQ(true, T1.IsEnd());
}
TEST(ScanTable, can_Insert_empty_table1)
{
    ScanTable SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, "one"));
}
TEST(ScanTable, Insert_correct_empty_table1)
{
    ScanTable SS  T1;
    T1.Insert(1, "one");
    EXPECT_EQ(1, T1.GetCount());
    EXPECT_EQ(1, *(T1.Search("one")));
}
TEST(ScanTable, can_GetData1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(*(T1.GetData()));
}
TEST(ScanTable, GetData_corect1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    EXPECT_EQ(8, *(T1.GetData()));
}
TEST(ScanTable, can_GetKey1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.GetKey());
}
TEST(ScanTable, GetKey_corect1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    EXPECT_EQ("1 record", T1.GetKey());
}
TEST(ScanTable, can_SetNext1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.SetNext());
}
TEST(ScanTable, SetNext_correct1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    T1.SetNext();
    EXPECT_EQ(17, *(T1.GetData()));
}
TEST(ScanTable, SetNext_the_end1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset(); //8
    T1.SetNext();//17
    T1.SetNext();//28
    T1.SetNext();//41
    T1.SetNext();//8
    EXPECT_EQ(8, *(T1.GetData()));
}
TEST(ScanTable, can_copy_table1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    ASSERT_NO_THROW(ScanTable SS  A(T1));
}
TEST(ScanTable, copied_table_correct1)
{
    ScanTable <int, string> T1;

    for (int i = 0; i < 4; i++)
    {
        string s;
        s = to_string(i + 1) + " record";
        T1.Insert((i + 1) * 8 + (i * i) % 13, s);
    }
    ScanTable SS  A(T1);
    A.Reset();
    EXPECT_EQ(8, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(17, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(28, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(41, *(A.GetData()));
}
TEST(ScanTable, corect_Delete1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("2 record");
    T1.Reset();
    EXPECT_EQ(8, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(41, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(28, *(T1.GetData()));
}
TEST(ScanTable, empty_after_Delete1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("1 record");
    T1.Delete("2 record");
    T1.Delete("3 record");
    T1.Delete("4 record");
    EXPECT_EQ(true, T1.IsEmpty());
}
TEST(ScanTable, corect_Insert1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Insert(3, "3");
    T1.Reset();
    T1.SetNext();
    T1.SetNext();
    T1.SetNext();
    T1.SetNext();
    EXPECT_EQ(3, *(T1.GetData()));
}
TEST(ScanTable, corect_Insert_after_Delete1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("1 record");
    T1.Delete("2 record");
    T1.Delete("3 record");
    T1.Delete("4 record");
    T1.Insert(0, "0");
    EXPECT_EQ(0, *(T1.GetData()));
}
TEST(ScanTable, corect_Search1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    EXPECT_EQ(17, *(T1.Search("2 record")));
}
TEST(ScanTable, can_not_Insert_record_wich_key_isnt_unique1)
{
    ScanTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    ASSERT_ANY_THROW(T1.Insert(2, "2 record"));
}

//Тесты для класса упорядоченных таблиц
TEST(SortTable, can_create_table2)
{
    ASSERT_NO_THROW(SortTable SS  T1);
}
TEST(SortTable, can_copy_empty_table2)
{
    SortTable SS  T1;
    ASSERT_NO_THROW(SortTable SS  T2(T1));
}
TEST(SortTable, can_not_GetData_empty_table2)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.GetData());
}
TEST(SortTable, can_not_GetKey_empty_table2)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.GetKey());
}
TEST(SortTable, can_not_SetNext_empty_table2)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.SetNext());
}
TEST(SortTable, can_not_Delete_empty_table2)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.Delete("one"));
}
TEST(SortTable, can_not_Search_empty_table2)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.Search("one"));
}
TEST(SortTable, can_Reset_empty_table2)
{
    SortTable SS  T1;
    ASSERT_NO_THROW(T1.Reset());
}
TEST(SortTable, IsEnd_correct_empty_table2)
{
    SortTable SS  T1;
    EXPECT_EQ(true, T1.IsEnd());
}
TEST(SortTable, can_Insert_empty_table2)
{
    SortTable SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, "one"));
}
TEST(SortTable, Insert_correct_empty_table2)
{
    SortTable SS  T1;
    T1.Insert(1, "one");
    EXPECT_EQ(1, T1.GetCount());
    EXPECT_EQ(1, *(T1.Search("one")));
}
TEST(SortTable, can_GetData2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(*(T1.GetData()));
}
TEST(SortTable, GetData_corect2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Reset();
    EXPECT_EQ(2, *(T1.GetData()));
}
TEST(SortTable, can_GetKey2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.GetKey());
}
TEST(SortTable, GetKey_corect2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Reset();
    EXPECT_EQ("17 record", T1.GetKey());
}
TEST(SortTable, can_SetNext2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.SetNext());
}
TEST(SortTable, SetNext_correct2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Reset();
    T1.SetNext();
    EXPECT_EQ(3, *(T1.GetData()));
}
TEST(SortTable, SetNext_the_end2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Reset(); //2
    T1.SetNext();//3
    T1.SetNext();//4
    T1.SetNext();//1
    T1.SetNext();//2
    EXPECT_EQ(2, *(T1.GetData()));
}
TEST(SortTable, can_copy_table2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    ASSERT_NO_THROW(SortTable SS  A(T1));
}
TEST(SortTable, copied_table_correct2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    SortTable SS  A(T1);
    A.Reset();
    EXPECT_EQ(2, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(3, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(4, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(1, *(A.GetData()));
}
TEST(SortTable, corect_Delete2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Delete("28 record");
    T1.Reset();
    EXPECT_EQ(2, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(4, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(1, *(T1.GetData()));
}
TEST(SortTable, empty_after_Delete2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Delete("8 record");
    T1.Delete("17 record");
    T1.Delete("28 record");
    T1.Delete("41 record");
    EXPECT_EQ(true, T1.IsEmpty());
}
TEST(SortTable, corect_Insert2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Insert(3, "3");
    T1.Reset();
    T1.SetNext();
    T1.SetNext();
    EXPECT_EQ(3, *(T1.GetData()));
}
TEST(SortTable, corect_Insert_after_Delete2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    T1.Delete("8 record");
    T1.Delete("17 record");
    T1.Delete("28 record");
    T1.Delete("41 record");
    T1.Insert(0, "0");
    EXPECT_EQ(0, *(T1.GetData()));
}
TEST(SortTable, corect_Search2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    EXPECT_EQ(3, *(T1.Search("28 record")));
}
TEST(SortTable, can_not_Insert_record_wich_key_isnt_unique2)
{
    SortTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1), to_string((i + 1) * 8 + (i * i) % 13) + " record");
    }
    ASSERT_ANY_THROW(T1.Insert(2, "28 record"));
}

//Тесты для класса Хеш-таблиц
TEST(HashTable, can_create_table3)
{
    ASSERT_NO_THROW(HashTable SS  T1);
}
TEST(HashTable, can_copy_empty_table3)
{
    HashTable SS  T1;
    ASSERT_NO_THROW(HashTable SS  T2(T1));
}
TEST(HashTable, can_not_GetData_empty_table3)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.GetData());
}
TEST(HashTable, can_not_GetKey_empty_table3)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.GetKey());
}
TEST(HashTable, can_not_SetNext_empty_table3)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.SetNext());
}
TEST(HashTable, can_not_Delete_empty_table3)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.Delete("one"));
}
TEST(HashTable, can_not_Search_empty_table3)
{
    HashTable SS  T1;
    ASSERT_ANY_THROW(T1.Search("one"));
}
TEST(HashTable, can_Reset_empty_table3)
{
    HashTable SS  T1;
    ASSERT_NO_THROW(T1.Reset());
}
TEST(HashTable, IsEnd_correct_empty_table3)
{
    HashTable SS  T1;
    EXPECT_EQ(true, T1.IsEnd());
}
TEST(HashTable, can_Insert_empty_table3)
{
    HashTable SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, "one"));
}
TEST(HashTable, Insert_correct_empty_table3)
{
    HashTable SS  T1;
    T1.Insert(1, "one");
    EXPECT_EQ(1, T1.GetCount());
    EXPECT_EQ(1, *(T1.Search("one")));
}
TEST(HashTable, can_GetData3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(*(T1.GetData()));
}
TEST(HashTable, GetData_corect3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    EXPECT_EQ(8, *(T1.GetData()));
}
TEST(HashTable, can_GetKey3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.GetKey());
}
TEST(HashTable, GetKey_corect3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    EXPECT_EQ("1 record", T1.GetKey());
}
TEST(HashTable, can_SetNext3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    ASSERT_NO_THROW(T1.SetNext());
}
TEST(HashTable, SetNext_correct3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset();
    T1.SetNext();
    EXPECT_EQ(17, *(T1.GetData()));
}
TEST(HashTable, SetNext_the_end3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Reset(); //8
    T1.SetNext();//17
    T1.SetNext();//28
    T1.SetNext();//41
    T1.SetNext();//8
    EXPECT_EQ(8, *(T1.GetData()));
}
TEST(HashTable, can_copy_table3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    ASSERT_NO_THROW(HashTable SS  A(T1));
}
TEST(HashTable, copied_table_correct3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    HashTable SS  A(T1);
    A.Reset();
    EXPECT_EQ(8, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(17, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(28, *(A.GetData()));
    A.SetNext();
    EXPECT_EQ(41, *(A.GetData()));
}
TEST(HashTable, corect_Delete3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("2 record");
    T1.Reset();
    EXPECT_EQ(8, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(28, *(T1.GetData()));
    T1.SetNext();
    EXPECT_EQ(41, *(T1.GetData()));
}
TEST(HashTable, empty_after_Delete3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("1 record");
    T1.Delete("2 record");
    T1.Delete("3 record");
    T1.Delete("4 record");
    EXPECT_EQ(true, T1.IsEmpty());
}
TEST(HashTable, corect_Insert3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Insert(3, "3");
    T1.Reset();
    T1.SetNext();
    T1.SetNext();
    T1.SetNext();
    T1.SetNext();
    EXPECT_EQ(3, *(T1.GetData()));
}
TEST(HashTable, corect_Insert_after_Delete3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    T1.Delete("1 record");
    T1.Delete("2 record");
    T1.Delete("3 record");
    T1.Delete("4 record");
    T1.Insert(0, "0");
    EXPECT_EQ(0, *(T1.GetData()));
}
TEST(HashTable, corect_Search3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    EXPECT_EQ(17, *(T1.Search("2 record")));
}
TEST(HashTable, can_not_Insert_record_wich_key_isnt_unique3)
{
    HashTable SS  T1;
    for (int i = 0; i < 4; i++)
    {
        T1.Insert((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
    }
    ASSERT_ANY_THROW(T1.Insert(2, "2 record"));
}
