#include "tmonom.h"
#include <gtest.h>

TEST(TMonom, can_create_empty_monom) {
	ASSERT_NO_THROW(TMonom monom);
}

TEST(TMonom, check_is_empty_monom_data_correct) {
	TMonom monom;
	EXPECT_EQ(monom.coeff, 0);
	EXPECT_EQ(monom.degree, -1);
}

TEST(TMonom, can_create_monom) {
	ASSERT_NO_THROW(TMonom monom(1, 111));
}

TEST(TMonom, check_is_monom_data_correct) {
	TMonom monom(1, 111);
	EXPECT_EQ(monom.coeff, 1);
	EXPECT_EQ(monom.degree, 111);
}

TEST(TMonom, throws_whem_create_monom_with_wrong_degree) {
	ASSERT_ANY_THROW(TMonom new_monom(1, 1111));
}

TEST(TMonom, check_less_than_operation) {
	TMonom mon1(1, 111);
	TMonom mon2(1, 112);
	EXPECT_TRUE(mon1 < mon2);
}

TEST(TMonom, check_less_than_or_equal_to_operation) {
	TMonom mon1(1, 111);
	TMonom mon2(2, 111);
	EXPECT_TRUE(mon1 <= mon2);
}

TEST(TMonom, check_greater_than_operation) {
	TMonom mon1(1, 111);
	TMonom mon2(1, 112);
	EXPECT_TRUE(mon2 > mon1);
}

TEST(TMonom, check_greater_than_or_equal_to_operation) {
	TMonom mon1(1, 111);
	TMonom mon2(2, 111);
	EXPECT_TRUE(mon2 >= mon1);
}

TEST(TMonom, check_equal_to_operation) {
	TMonom mon1(1, 111);
	TMonom mon2(1, 111);
	EXPECT_TRUE(mon1 == mon2);
}

TEST(TMonom, check_not_equal_to_operation) {
	TMonom mon1(1, 111);
	TMonom mon2(1, 112);
	EXPECT_TRUE(mon1 != mon2);
}