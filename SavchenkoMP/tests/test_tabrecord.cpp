#include <gtest.h>

#include <iostream>
#include "tabrecord.h"

using namespace std;

/*
TEST(TabRecord, TEST_NAME) {

}
*/

// DefaultConstructorTest
//TEST(TabRecord, DefaultConstructorTest) {
//	int key = 1;
//	string* data = new string("a");
//	
//	ASSERT_NO_THROW(TabRecord<int, string> tr(key, data));
//}

// CopyConstructorTest
//TEST(TabRecord, CopyConstructorTest) {
//	int key = 1;
//	string* data = new string("a");
//	TabRecord<int, string> tr1(key, data);
//	
//	ASSERT_NO_THROW(TabRecord<int, string> tr2(tr1));
//}

TEST(TabRecord, CopyConstructorTest_Key) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr1(key, data);
	TabRecord<int, string> tr2(tr1);
	
	EXPECT_EQ(tr1.get_key(), tr2.get_key());
}

TEST(TabRecord, CopyConstructorTest_DataPointer) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr1(key, data);
	TabRecord<int, string> tr2(tr1);

	EXPECT_EQ(tr1.get_data(), tr2.get_data());
}

TEST(TabRecord, CopyConstructorTest_Data) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr1(key, data);
	TabRecord<int, string> tr2(tr1);

	EXPECT_EQ(*tr1.get_data(), *tr2.get_data());
}

// GetKeyTest
TEST(TabRecord, GetKeyTest) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ(key, tr.get_key());
}

// GetDataTest_Pointer
TEST(TabRecord, GetDataTest_Pointer) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ(data, tr.get_data());
}

TEST(TabRecord, GetDataTest_Data) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ("a", *tr.get_data());
}
