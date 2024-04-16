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
TEST(ScanTable, InsertTest) {

}

// FindTest
TEST(ScanTable, FindTest) {

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