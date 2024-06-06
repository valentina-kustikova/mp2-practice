#include <gtest.h>
#include "TabRecord.h"

#include <iostream>


using namespace std;

TEST(TTabRecord, constructor_without_parameters) {
	TTabRecord<int, string> record;
	EXPECT_EQ(record.key, int());
	EXPECT_EQ(record.data, nullptr);
}

TEST(TTabRecord, constructor_with_parameters) {
	std::string data = "data1";
	TTabRecord<int, std::string> record(1, &data);
	EXPECT_EQ(record.key, 1);
	EXPECT_EQ(*record.data, "data1");
}

TEST(TTabRecord, Copy_Constructor) {
	std::string data = "data1";
	TTabRecord<int, std::string> original(1, &data);
	TTabRecord<int, std::string> copy(original);
	EXPECT_EQ(copy.key, 1);
	EXPECT_EQ(*copy.data, "data1");
}

TEST(TTabRecord, the_operator_is_equal_to) {
	std::string data1 = "data1";
	std::string data2 = "data2";
	TTabRecord<int, std::string> record1(1, &data1);
	TTabRecord<int, std::string> record2(2, &data2);

	record2 = record1;
	EXPECT_EQ(record2.key, 1);
	EXPECT_EQ(*record2.data, "data1");
}

