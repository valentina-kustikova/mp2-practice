#include <gtest.h>

#include "TMonom.h"

TEST(monom, default_parameter_constructor_work) {
	ASSERT_NO_THROW(TMonom m(2.92, 4));
}



TEST(monom, constructor_copy_work) {
	TMonom m1(2.92, 4);
	ASSERT_NO_THROW(TMonom m2(m1));
}

TEST(monom, different_memory) {
	TMonom m1(2.92, 4);
	m1.SetCoeff(6);
	m1.SetWP(9);

	TMonom m2(m1);
	m2.SetCoeff(6);
	m2.SetWP(9);

	ASSERT_TRUE(&m1 != &m2);
}

TEST(monom, operation_less) {
	TMonom m1(6.95, 114);
	TMonom m2(6.95, 104);

	ASSERT_TRUE(m2 < m1);
}


TEST(monom, operation_not_equal) {
	TMonom m1(8.95, 114);
	TMonom m2(7.95, 104);

	bool res1 = m1 != m2;
	bool res2 = 114 != 104;

	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_more) {
	TMonom m1(12.95, 94);
	TMonom m2(7.95, 104);

	bool res1 = 94 <= 104;
	bool res2 = m1 <= m2;


	ASSERT_TRUE(res1 == res2);
}

TEST(monom, assign_check_values) {
	TMonom m1(7.95, 124);
	TMonom m2(12.95, 104);
	TMonom m3 = m1;
	ASSERT_NO_THROW(m3.GetCoeff() == 7.95 && m3.GetWP() == 124 || m3 == m1);
}

TEST(monom, triple_assign) {
	TMonom m1(7.95, 124);
	TMonom m2(12.95, 104);
	TMonom m3(5.24, 92);
	m1 = m2 = m3;
	ASSERT_NO_THROW(m2 == m3 && m1 == m2 && m1 == m3);
}

TEST(monom, multiplication_work) {
	TMonom m1(7.95, 124);
	TMonom m2(12.95, 104);
	ASSERT_NO_THROW(m1 * m2);
}

TEST(monom, multiplication_check_values) {
	TMonom m1(5, 124);
	TMonom m2(4, 104);
	TMonom m3 = m1 * m2;
	ASSERT_TRUE(m3.GetCoeff() == 20 && m3.GetWP() == 228);
}

TEST(monom, multiplication_degree_limit_is_OK) {
	TMonom m1(5, 124);
	TMonom m2(4, 104);
	ASSERT_NO_THROW(m1 * m2);
}

TEST(monom, multiplication_degree_limit_exceeded) {
	TMonom m1(5, 126);
	TMonom m2(4, 104);
	ASSERT_ANY_THROW(m1 * m2);
}

TEST(monom, operator_plus_work) {
	TMonom m1(1, 100);
	TMonom m2(14, 100);

	ASSERT_NO_THROW(m1 + m2);
}

TEST(monom, operator_plus_no_work) {
	TMonom m1(1, 100);
	TMonom m2(14, 124);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(monom, operator_plus_check_values) {
	TMonom m1(1, 100);
	TMonom m2(14, 100);

	TMonom res = m1 + m2;

	EXPECT_EQ(15, res.GetCoeff());
}

TEST(monom, operator_unary_minus_work) {
	TMonom m1(-8, 190);
	ASSERT_NO_THROW(m1 = -m1);
}

TEST(monom, monom_subtraction) {
	TMonom m1(-9, 189);
	TMonom m2(12, 189);

	TMonom res = m1 + (-m2);

	EXPECT_EQ(-21, res.GetCoeff());
}