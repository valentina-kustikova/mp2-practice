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

	EXPECT_EQ(false, st.full());
}

TEST(ScanTable, ParameterizedConstructorTest_IsEmpty) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(true, st.empty());
}

TEST(ScanTable, ParameterizedConstructorTest_IsTabEnded) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(false, st.ended());
}

TEST(ScanTable, ParameterizedConstructorTest_Reset) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(false, st.reset());
}

TEST(ScanTable, ParameterizedConstructorTest_Next) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(false, st.next());
}

TEST(ScanTable, ParameterizedConstructorTest_GetDataCount) {
	int size = 3;
	ScanTable<int, string> st(3);


	EXPECT_EQ(0, st.get_size());
}

TEST(ScanTable, ParameterizedConstructorTest_GetMaxSize) {
	int size = 3;
	ScanTable<int, string> st(3);

	EXPECT_EQ(size, st.get_max_size());
}

// InsertTest
TEST(ScanTable, InsertTest_Empty) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";

	EXPECT_NO_THROW(st.insert(key, &data));
}

TEST(ScanTable, InsertTest_NotEmpty) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	string data2 = "b";
	st.insert(key1, &data1);

	EXPECT_NO_THROW(st.insert(key2, &data2));
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
	st.insert(key1, &data1);
	st.insert(key2, &data2);
	st.insert(key3, &data3);

	EXPECT_ANY_THROW(st.insert(key4, &data4));
}

// FindTest
TEST(ScanTable, FindTest) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key1 = 1;
	int key2 = 2;
	string data1 = "a";
	string data2 = "b";
	st.insert(key1, &data1);
	st.insert(key2, &data2);

	EXPECT_NO_THROW(st.find(1));
}

TEST(ScanTable, FindTest_Key) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.insert(key, &data);

	TabRecord<int, string>* find = st.find(1);

	EXPECT_EQ(key, find->key);
}

TEST(ScanTable, FindTest_Data) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.insert(key, &data);

	TabRecord<int, string>* find = st.find(1);

	EXPECT_EQ(data, *find->data);
}

TEST(ScanTable, FindTest_DataPointer) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.insert(key, &data);

	TabRecord<int, string>* find = st.find(1);

	EXPECT_NE(&data, find->data);
}

TEST(ScanTable, FindTest_NotFound) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.insert(key, &data);

	EXPECT_NO_THROW(st.find(2));
}

TEST(ScanTable, FindTest_NotFound_Pointer) {
	int size = 3;
	ScanTable<int, string> st(3);

	int key = 1;
	string data = "a";
	st.insert(key, &data);

	TabRecord<int, string>* find = st.find(3);

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
