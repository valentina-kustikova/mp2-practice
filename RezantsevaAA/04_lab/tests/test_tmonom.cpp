#include "tmonom.h"
#include <gtest.h>

TEST(TMonom, can_create_monom) {
	ASSERT_NO_THROW(TMonom monom());
}
TEST(TMonom, cant_create_monom_w_big_degree) {
	ASSERT_ANY_THROW(TMonom(1, 1000));
}
TEST(TMonom, cant_create_monom_w_less_degree) {
	ASSERT_ANY_THROW(TMonom(1, -1));
}
TEST(TMonom, can_create_monom_w_param) {
	double c = 2;
	double d = 3;
	ASSERT_NO_THROW(TMonom monom(c,d));
}
TEST(TMonom, can_copy_monom) {
	double c = 2;
	double d = 3;
	TMonom monom(c, d);
	ASSERT_NO_THROW(TMonom copy_monom(monom));
}
TEST(TMonom, check_operotor_m1_m2_) {
	double c = 2;
	double d = 3;
	TMonom monom1(c, d);
	c = 7; d = 8;
	TMonom monom2(c, d);
	ASSERT_NO_THROW(monom1 = monom2);
}
//SET&GET
//Coeff
TEST(TMonom, can_setCoeff) {
	TMonom m;
	ASSERT_NO_THROW(m.SetCoeff(2));
}
TEST(TMonom, can_setCoeff_data) {
	TMonom m;
	m.SetCoeff(2);
	EXPECT_EQ(2, m.GetCoeff());
}
TEST(TMonom, can_getCoeff) {
	TMonom m(2,2);
	ASSERT_NO_THROW(m.GetCoeff());
}
TEST(TMonom, can_getCoeff_data) {
	TMonom m(2, 2);
	EXPECT_EQ(2,m.GetCoeff());
}
//Degree
TEST(TMonom, can_setDegree) {
	TMonom m;
	ASSERT_NO_THROW(m.SetDegree(4));
}
TEST(TMonom, cant_setDegree_d_less_0) {
	TMonom m;
	ASSERT_ANY_THROW(m.SetDegree(-3));
}
TEST(TMonom, cant_setDegree_d_too_big) {
	TMonom m;
	ASSERT_ANY_THROW(m.SetDegree(1000));
}
TEST(TMonom, can_setDegree_data) {
	TMonom m;
	m.SetDegree(4);
	EXPECT_EQ(4, m.GetDegree());
}
TEST(TMonom, can_get_degree) {
	TMonom m(2, 2);
	ASSERT_NO_THROW(m.GetDegree());
}
TEST(TMonom, can_get_degree_data) {
	TMonom m(2, 2);
	EXPECT_EQ(2,m.GetDegree());
}
//oprators
//operator<
TEST(TMonom, check_comparison1) {
	TMonom m1(2, 2);
	TMonom m2(2, 4);
	ASSERT_NO_THROW(m1 < m2);
}
TEST(TMonom, check_comparison1_true) {
	TMonom m1(2, 2);
	TMonom m2(2, 4);
	EXPECT_EQ(true, m1 < m2);
}
TEST(TMonom, check_comparison1_false) {
	TMonom m1(2, 6);
	TMonom m2(2, 4);
	EXPECT_NE(true, m1 < m2);
}
//operator>
TEST(TMonom, check_comparison2) {
	TMonom m1(2, 2);
	TMonom m2(2, 4);
	ASSERT_NO_THROW(m2 > m1);
}
TEST(TMonom, check_comparison2_true) {
	TMonom m1(2, 2);
	TMonom m2(2, 4);
	EXPECT_EQ(true, m2 > m1);
}
TEST(TMonom, check_comparison2_false) {
	TMonom m1(2, 2);
	TMonom m2(2, 1);
	EXPECT_NE(true, m2 > m1);
}
//operator==
TEST(TMonom, check_comparison3) {
	TMonom m1(2, 2);
	TMonom m2(2, 2);
	ASSERT_NO_THROW(m2 == m1);
}
TEST(TMonom, check_comparison3_true) {
	TMonom m1(2, 2);
	TMonom m2(2, 2);
	EXPECT_EQ(true,m2 == m1);
}
TEST(TMonom, check_comparison3_false) {
	TMonom m1(2, 2);
	TMonom m2(3, 2);
	EXPECT_NE(true, m2 == m1);
}
//operator!=
TEST(TMonom, check_comparison4) {
	TMonom m1(2, 2);
	TMonom m2(2, 3);
	ASSERT_NO_THROW(m2 != m1);
}
TEST(TMonom, check_comparison4_true) {
	TMonom m1(2, 2);
	TMonom m2(2, 3);
	EXPECT_EQ(true, m2 != m1);
}
TEST(TMonom, check_comparison4_false) {
	TMonom m1(2, 2);
	TMonom m2(2, 2);
	EXPECT_NE(true, m2 != m1);
}
//operator*
TEST(TMonom, can_duplicate) {
	TMonom m1(3, 2);
	TMonom m2(2, 2);
	ASSERT_NO_THROW(m1 * m2);
}
TEST(TMonom, cant_duplicate) {
	TMonom m1(3, 2);
	TMonom m2(2, 999);
	ASSERT_ANY_THROW(m1 * m2);
}
TEST(TMonom, can_duplicate_data) {
	TMonom m1(3, 2);
	TMonom m2(2, 2);
	TMonom result = m1 * m2;
	EXPECT_EQ(6, result.GetCoeff());
	EXPECT_EQ(4, result.GetDegree());
}