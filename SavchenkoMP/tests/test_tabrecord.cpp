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
//	ASSERT_NO_THROW(TabRecord<int, string> tr(key, data)); //  ¿  «¿œ»’Õ”“‹ ¬ ASSERT_NO_THROW  À¿—— — ƒ¬”Ãﬂ “»œ¿Ã»?
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
	
	EXPECT_EQ(tr1.GetKey(), tr2.GetKey());
}

TEST(TabRecord, CopyConstructorTest_DataPointer) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr1(key, data);
	TabRecord<int, string> tr2(tr1);

	EXPECT_EQ(tr1.GetData(), tr2.GetData());
}

TEST(TabRecord, CopyConstructorTest_Data) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr1(key, data);
	TabRecord<int, string> tr2(tr1);

	EXPECT_EQ(*tr1.GetData(), *tr2.GetData());
}

// GetKeyTest
TEST(TabRecord, GetKeyTest) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ(key, tr.GetKey());
}

// GetDataTest_Pointer
TEST(TabRecord, GetDataTest_Pointer) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ(data, tr.GetData());
}

TEST(TabRecord, GetDataTest_Data) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ("a", *tr.GetData());
}
