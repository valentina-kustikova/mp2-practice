#include <gtest.h>

#include "scantable.h"
#include <iostream>

using namespace std;

/*
TEST(ScanTable, TEST_NAME) {

}
*/

// ParameterizedConstructorTest
//TEST(ScanTable, ParameterizedConstructorTest) {
//	int size = 3;
//	ASSERT_NO_THROW(ScanTable<int, string> st(3)); // œŒ◊≈Ã” –”√¿≈“—ﬂ Õ¿ <,> ???
//}

TEST(ScanTable, ParameterizedConstructorTest_IsFull) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(false, st.IsFull());
}

TEST(ScanTable, ParameterizedConstructorTest_IsEmpty) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(ScanTable, ParameterizedConstructorTest_IsTabEnded) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(false, st.IsTabEnded());
}

TEST(ScanTable, ParameterizedConstructorTest_Reset) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(false, st.Reset());
}

TEST(ScanTable, ParameterizedConstructorTest_Next) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(false, st.Next());
}

TEST(ScanTable, ParameterizedConstructorTest_GetDataCount) {
	int size = 3;
	ScanTable<int, string> st(3);


	EXPECT_EQ(0, st.GetDataCount());
}

TEST(ScanTable, ParameterizedConstructorTest_GetMaxSize) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(size, st.GetMaxSize());
}

TEST(ScanTable, ParameterizedConstructorTest_GetKey_throw) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_ANY_THROW(st.GetKey());
	//EXPECT_EQ(NULL, st.GetKey());
}

TEST(ScanTable, ParameterizedConstructorTest_GetData_throw) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_ANY_THROW(st.GetData());
	//EXPECT_EQ(nullptr, st.GetData());
}

// InsertTest
TEST(ScanTable, InsertTest_Empty) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";

	EXPECT_NO_THROW(st.Insert(key, &data));
}

TEST(ScanTable, InsertTest_NotEmpty) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	string data2 = "b";
	st.Insert(key1, &data1);

	EXPECT_NO_THROW(st.Insert(key2, &data2));
}

TEST(ScanTable, InsertTest_Full) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key1 = 1;
	int key2 = 2;
	int key3 = 3;
	int key4 = 4;
	string data1 = "a";
	string data2 = "b";
	string data3 = "c";
	string data4 = "d";
	st.Insert(key1, &data1);
	st.Insert(key2, &data2);
	st.Insert(key3, &data3);

	EXPECT_ANY_THROW(st.Insert(key4, &data4));
}

// FindTest
TEST(ScanTable, FindTest) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	string data2 = "b";
	st.Insert(key1, &data1);
	st.Insert(key2, &data2);

	EXPECT_NO_THROW(st.Find(1));
}

TEST(ScanTable, FindTest_Key) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	TabRecord<int, string>* find = st.Find(1);

	EXPECT_EQ(key, find->GetKey());
}

TEST(ScanTable, FindTest_Data) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	TabRecord<int, string>* find = st.Find(1);

	EXPECT_EQ(data, *find->GetData());
}

TEST(ScanTable, FindTest_DataPointer) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	TabRecord<int, string>* find = st.Find(1);

	EXPECT_NE(&data, find->GetData());
}

TEST(ScanTable, FindTest_NotFound) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	EXPECT_NO_THROW(st.Find(2));
}

TEST(ScanTable, FindTest_NotFound_Pointer) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.Insert(key, &data);

	TabRecord<int, string>* find = st.Find(3);

	EXPECT_EQ(nullptr, find);
}

// IndexingOperatorTest
TEST(ScanTable, IndexingOperatorTest) {

}

// RemoveTest
TEST(ScanTable, RemoveTest) {

}

// CopyConstructorTest
TEST(ScanTable, CopyConstructorTest) {

}

// TypeCastCOnstructorTest
TEST(ScanTable, TypeCastCOnstructorTest) {

}

// GetKeyTest
TEST(ScanTable, GetKeyTest) {

}

// GetDataTest
TEST(ScanTable, GetDataTest) {

}