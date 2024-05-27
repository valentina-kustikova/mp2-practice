#include<gtest.h>

#include <string>
#include "TabRecord.h"

using namespace std;

//
//TEST(TabRecord, can_create_TabRecord)
//{
//	string* str = new string("alblack");
//	double* db = new double(51);
//	int a = 52;
//	TabRecord<int, double> rec(a, db);
//	ASSERT_NO_THROW(TabRecord<int, double> rec(a, db));
//}
//
//TEST(TabRecord, can_create_copied_TabRecord)
//{
//	string* str = new string("alblack");
//	TabRecord<int, string> rec(52, str);
//
//	ASSERT_NO_THROW(TabRecord<int, string> rec1(rec));
//}
TEST(TabRecord, correct_constructor_with_param) {
	int key = 1;
	string* data = new string("a");
	TabRecord<int, string> tr(key, data);

	EXPECT_EQ(key, tr.key);
	EXPECT_NE(data, tr.data);
}


TEST(TabRecord, check_correct_copied_TabRecord)
{
	string* str = new string("alblack");
	TabRecord<int, string> rec(52, str);
	TabRecord<int, string> rec1(rec);
	
	EXPECT_EQ(rec.key, rec1.key);
	EXPECT_EQ(*rec.data, *rec1.data);
}

TEST(TabRecord, check_correct_operator)
{
	string* str = new string("alblack");
	TabRecord<int, string> rec(52, str);
	TabRecord<int, string> rec1 = rec;

	EXPECT_EQ(rec.key, rec1.key);
	EXPECT_EQ(*rec.data, *rec1.data);
}



