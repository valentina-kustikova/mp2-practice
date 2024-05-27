#include "ScanTable.h"
#include "Tables.h"

#include <gtest.h>


//TEST(ScanTable, default_constructor_test)
//{
//	int size = 5;
//	ASSERT_NO_THROW(TScanTable<string, int> table(size));
//}

// Copy Constructor Test
TEST(ScanTable, copy_constructor_test)
{
	TScanTable<int, string> st(3);
	st.Insert(1, &string("abc"));

	TScanTable<int, string> copiedSt(st);

	EXPECT_EQ(st.Find(1)->GetKey(), copiedSt.Find(1)->GetKey());
}
// Insert Test
TEST(ScanTable, insert_test_empty) 
{
	TScanTable<int, string> st(3);

	string data = "Data1";

	EXPECT_NO_THROW(st.Insert(5, &data));
}

TEST(ScanTable, insert_test_not_empty) 
{
	TScanTable<int, string> st(3);

	string data1 = "Data1";
	string data2 = "Data2";
	st.Insert(5, &data1);

	EXPECT_NO_THROW(st.Insert(10, &data2));
}

TEST(ScanTable, insert_test_full) 
{
	TScanTable<int, string> st(3);

	string data1 = "Data1";
	string data2 = "Data2";
	string data3 = "Data3";
	string data4 = "Data4";
	st.Insert(2, &data1);
	st.Insert(3, &data2);
	st.Insert(5, &data3);

	EXPECT_ANY_THROW(st.Insert(10, &data4));
}
// Remove Test
TEST(ScanTable, remove_test)
{
	TScanTable<int, string> st(3);

	string data1 = "Data1";
	string  data2 = "Data2";
	st.Insert(5, &data1);
	st.Insert(10, &data2);

	st.Remove(5);

	EXPECT_EQ(st.GetCount(), 1);
}
TEST(ScanTable, remove_test_empty) 
{
	TScanTable<int, string> st(5);

	ASSERT_ANY_THROW(st.Remove(1));
}
TEST(ScanTable, remove_non_existent_test)
{
	TScanTable<int, string> table(5);
	string data1 = "Data1";
	string data2 = "Data2";
	table.Insert(5, &data1);
	table.Insert(10, &data2);
	ASSERT_ANY_THROW(table.Remove(3));
}
// Find Test
TEST(ScanTable, find_test)
{

	TScanTable<int, string> st(5);

	string data1 = "Data1";
	string data2 = "Data2";
	st.Insert(5, &data1);
	st.Insert(10, &data2);

	EXPECT_NO_THROW(st.Find(1));
}

TEST(ScanTable, find_test_key) 
{
	TScanTable<int, string> st(5);

	string data = "Data1";
	st.Insert(5, &data);

	TabRecord<int, string>* find = st.Find(5);

	EXPECT_EQ(find->GetKey(), 5);
}

TEST(ScanTable, find_test_data)
{
	TScanTable<int, string> st(5);

	string data = "Data1";
	st.Insert(5, &data);

	TabRecord<int, string>* find = st.Find(5);

	EXPECT_EQ(data, *find->GetData());
}

TEST(ScanTable, test_not_find)
{
	TScanTable<int, string> st(3);

	string data = "Data1";
	st.Insert(5, &data);

	EXPECT_EQ(st.Find(2), nullptr);
}
// GetKey Test
TEST(ScanTable, get_key_test) 
{
	TScanTable<int, string> st(3);

	string data = "Data1";
	st.Insert(5, &data);
	st.Reset();
	int gk = st.GetKey();

	EXPECT_EQ(gk, 5);
}
// GetData Test
TEST(ScanTable, get_data_test) 
{
	TScanTable<int, string> st(3);

	string data = "Data1";
	st.Insert(5, &data);
	st.Reset();
	string gd = *st.GetData();

	EXPECT_EQ(data, gd);
}
//Is Full
TEST(ScanTable, is_full_test_false)
{
	TScanTable<int, string> st(3);

	ASSERT_FALSE(st.IsFull());
}

TEST(ScanTable, is_full_test_false_with_elements)
{
	TScanTable<int, string> st(3);
	string data1 = "Data1";
	st.Insert(5, &data1);
	ASSERT_FALSE(st.IsFull());
}

TEST(ScanTable, is_full_test_true)
{
	TScanTable<int, string> st(1);
	
	string data = "Data1";
	st.Insert(5, &data);
	ASSERT_TRUE(st.IsFull());
}
//Is Empty
TEST(ScanTable, is_empty_test_false) 
{
	TScanTable<int, string> st(3);
	
	string data = "Data1";
	st.Insert(5, &data);
	ASSERT_FALSE(st.IsEmpty());
}

TEST(ScanTable, is_empty_test_true)
{
	TScanTable<int, string> st(3);

	ASSERT_TRUE(st.IsEmpty());
}
//Count
TEST(ScanTable, get_count_test)
{
	TScanTable<int, string> st(3);
	
	string data = "Data1";
	st.Insert(5, &data);
	EXPECT_EQ(st.GetCount(), 1);
}
//Is tab Ended
TEST(ScanTable, is_tab_ended_test) 
{
	TScanTable<int, string> st(3);

	ASSERT_FALSE(st.IsTabEnded());
}
TEST(ScanTable, is_tab_ended_true_test)
{
	TScanTable<int, string> st(1);	
	string data = "Data1";
	st.Insert(5, &data);
	st.Reset();
	st.Next();

	ASSERT_TRUE(st.IsTabEnded());
}
// Reset
TEST(ScanTable, reset_test)
{
	TScanTable<int, string> st(3);

	ASSERT_FALSE(st.Reset());
}
//Next
TEST(ScanTable, next_test)
{
	TScanTable<int, string> st(3);

	ASSERT_FALSE(st.Next());
}
TEST(ScanTable, next_test_true)
{
	TScanTable<int, string> st(1);
	string data = "Data1";
	st.Insert(5, &data);
	st.Reset();
	st.Next();
	ASSERT_TRUE(st.Next());
}