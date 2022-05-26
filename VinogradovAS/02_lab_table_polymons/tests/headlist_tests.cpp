//#include <gtest.h>
//#include "scanTable.h"
//#include <polinom.h>
//
//#define SS <int,string>
//
//TEST(ScanTable, can_create_table)
//{
//    ASSERT_NO_THROW(ScanTable SS T2);
//}
//
//TEST(ScanTable, can_copy_empty_table)
//{
//    ScanTable SS  T1;
//    ASSERT_NO_THROW(ScanTable SS T2(T1));
//}
//
//TEST(ScanTable, can_not_GetKey_empty_table)
//{
//    ScanTable SS  T1;
//    ASSERT_ANY_THROW(T1.GetKey());
//}
//TEST(ScanTable, can_not_GetData_empty_table)
//{
//    ScanTable SS  T1;
//    ASSERT_ANY_THROW(T1.GetData());
//}
//TEST(ScanTable, can_not_SetNext_empty_table)
//{
//    ScanTable SS  T1;
//    ASSERT_ANY_THROW(T1.Next());
//}
//TEST(ScanTable, can_not_Delete_empty_table)
//{
//    ScanTable SS  T1;
//    ASSERT_ANY_THROW(T1.Delete("one"));
//}
//TEST(ScanTable, can_not_Search_empty_table)
//{
//    ScanTable SS  T1;
//    EXPECT_EQ(nullptr, T1.Search("one"));
//}
//TEST(ScanTable, can_Reset_empty_table)
//{
//    ScanTable SS  T1;
//    ASSERT_NO_THROW(T1.Reset());
//}
//TEST(ScanTable, IsEnd_correct_empty_table)
//{
//    ScanTable SS  T1;
//    EXPECT_EQ(true, T1.IsTabEnded());
//}
//TEST(ScanTable, can_Insert_empty_table)
//{
//    ScanTable SS  T1;
//    ASSERT_NO_THROW(T1.Insert(1, "one"));
//}
//TEST(ScanTable, Insert_correct_empty_table1)
//{
//    ScanTable SS  T1;
//    T1.Insert(1, "one");
//    EXPECT_EQ(1, T1.GetCount());
//  EXPECT_EQ(1, *(T1.Search("one")));
//}
//
//TEST(ScanTable, comparison_maxSize)
//{
//    ScanTable SS  T1;
//    EXPECT_EQ(10, T1.GetMaxSize());
//}
//
//TEST(ScanTable, comparison_maxSize1)
//{
//    ScanTable SS  T1(5);
//    EXPECT_EQ(5, T1.GetMaxSize());
//}
//
//TEST(ScanTable, comparison_count_after_delete)
//{
//    ScanTable SS  T1(5);
//    T1.Insert(1, "1");
//    T1.Delete("1");
//    EXPECT_EQ(0, T1.GetCount());
//}
//
//TEST(ScanTable, comparison_count_after_delete1)
//{
//    ScanTable SS  T1(5);
//    T1.Insert(1, "1");
//    T1.Delete("1");
//    T1.Insert(1, "1");
//    EXPECT_EQ(1, T1.GetCount());
//}