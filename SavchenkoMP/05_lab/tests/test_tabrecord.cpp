#include <gtest.h>

#include <iostream>
#include "tabrecord.h"

using namespace std;

/*
TEST(TabRecord, TEST_NAME) {

}
*/

//// DefaultConstructorTest
//TEST(TabRecord, DefaultConstructorTest) {
//	int key = 1;
//	string* data = new string("a");
//	
//	ASSERT_NO_THROW(TabRecord<int,string> tr(key, data)); //  ¿  «¿œ»’Õ”“‹ ¬ ASSERT_NO_THROW  À¿—— — ƒ¬”Ãﬂ “»œ¿Ã»?
//}

//// CopyConstructorTest
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

	EXPECT_EQ(tr1.key, tr2.key);
}

TEST(TabRecord, CopyConstructorTest_DataPointer) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr1(key, data);
	TabRecord<int, string> tr2(tr1);

	EXPECT_NE(tr1.data, tr2.data);
}

TEST(TabRecord, CopyConstructorTest_Data) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr1(key, data);
	TabRecord<int, string> tr2(tr1);

	EXPECT_EQ(*tr1.data, *tr2.data);
}

// GetKeyTest
TEST(TabRecord, GetKeyTest) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ(key, tr.key);
}

// GetDataTest_Pointer
TEST(TabRecord, GetDataTest_Pointer) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_NE(data, tr.data);
}

TEST(TabRecord, GetDataTest_Data) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ(*data, *tr.data);
}
