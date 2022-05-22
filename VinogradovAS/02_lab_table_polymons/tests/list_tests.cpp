#include <gtest.h>

#include "sortTable.h"

#include <polinom.h>

#define SS <int,string>

TEST(SortTable, can_create_table1)
{
    ASSERT_NO_THROW(SortTable SS T2);
}

TEST(SortTable, can_copy_empty_table1)
{
    SortTable SS  T1;
    ASSERT_NO_THROW(SortTable SS T2(T1));
}

TEST(SortTable, can_not_GetKey_empty_table1)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.GetKey());
}
TEST(SortTable, can_not_GetData_empty_table1)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.GetData());
}
TEST(SortTable, can_not_SetNext_empty_table1)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.Next());
}
TEST(SortTable, can_not_Delete_empty_table1)
{
    SortTable SS  T1;
    ASSERT_ANY_THROW(T1.Delete("one"));
}
TEST(SortTable, can_not_Search_empty_table1)
{
    SortTable SS  T1;
    EXPECT_EQ(nullptr, T1.Search("one"));
}
TEST(SortTable, can_Reset_empty_table1)
{
    SortTable SS  T1;
    ASSERT_NO_THROW(T1.Reset());
}
TEST(SortTable, IsEnd_correct_empty_table1)
{
    SortTable SS  T1;
    EXPECT_EQ(true, T1.IsTabEnded());
}
TEST(SortTable, can_Insert_empty_table1)
{
    SortTable SS  T1;
    ASSERT_NO_THROW(T1.Insert(1, "one"));
}
TEST(SortTable, Insert_correct_empty_table1)
{
    SortTable SS  T1;
    T1.Insert(1, "one");
    EXPECT_EQ(1, T1.GetCount());
    EXPECT_EQ(1, *(T1.Search("one")));
}

TEST(SortTable, comparison_maxSize)
{
    SortTable SS  T1;
    EXPECT_EQ(10, T1.GetMaxSize());
}

TEST(SortTable, comparison_maxSize1)
{
    ScanTable SS  T1(5);
    EXPECT_EQ(5, T1.GetMaxSize());
}

TEST(SortTable, comparison_count_after_delete)
{
    SortTable SS  T1(5);
    T1.Insert(1, "1");
    T1.Delete("1");
    EXPECT_EQ(0, T1.GetCount());
}

TEST(SortTable, comparison_count_after_delete1)
{
    SortTable SS  T1(5);
    T1.Insert(1, "1");
    T1.Delete("1");
    T1.Insert(1, "1");
    EXPECT_EQ(1, T1.GetCount());
}