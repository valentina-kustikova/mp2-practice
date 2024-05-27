#include "tmonom.h"

#include <gtest.h>

TEST(TMonom, constructor_test) {
	EXPECT_NO_THROW(TMonom m);
}

TEST(TMonom, constructor_test_Coeff) {
	TMonom m;
	EXPECT_EQ(0, m.GetCoef());
}

TEST(TMonom, constructor_test_degree) {
	TMonom m;
	EXPECT_EQ(0, m.GetDegree());
}

TEST(TMonom, constructor_test_with_params) {
	EXPECT_NO_THROW(TMonom m(2,123));
}

TEST(TMonom, constructor_test_with_params_degree_more_then_normal) {
	EXPECT_ANY_THROW(TMonom m(2, 1111));
}

TEST(TMonom, constructor_test_with_params_degree_less_then_normal) {
	EXPECT_ANY_THROW(TMonom m(2, -1));
}

TEST(TMonom, test_with_params_return_coef) {
	TMonom m(2, 123);
	EXPECT_EQ(2, m.GetCoef());
}

TEST(TMonom, test_with_params_return_degree) {
	TMonom m(2, 123);
	EXPECT_EQ(123, m.GetDegree());
}

TEST(TMonom, test_with_params_return_degreeFourParams) {
	TMonom m(2,1,2,3);
	EXPECT_EQ(123, m.GetDegree());
}

TEST(TMonom, test_with_params_return_coefeFourParams) {
	TMonom m(2, 1, 2, 3);
	EXPECT_EQ(2, m.GetCoef());
}

TEST(TMonom, test_with_params_return_coefeFourParams_check_intervalsX) {
	EXPECT_ANY_THROW(TMonom m(2, 11, 2, 3));
}

TEST(TMonom, test_with_params_return_coefeFourParams_check_intervalsY) {
	EXPECT_ANY_THROW(TMonom m(2, 1, 21, 3));
}

TEST(TMonom, test_with_params_return_coefeFourParams_check_intervalsZ) {
	EXPECT_ANY_THROW(TMonom m(2, 1, 1, 13));
}

TEST(TMonom, test_with_params_return_coefeFourParams_check_intervalsXmin) {
	EXPECT_ANY_THROW(TMonom m(2, -1, 2, 3));
}

TEST(TMonom, test_with_params_return_coefeFourParams_check_intervalsYmin) {
	EXPECT_ANY_THROW(TMonom m(2, 1, -1, 3));
}

TEST(TMonom, test_with_params_return_coefeFourParams_check_intervalsZmin) {
	EXPECT_ANY_THROW(TMonom m(2, 1, 1, -1));
}

TEST(TMonom, test_operator_equally_the_same_parameters) {
	TMonom m1(2, 123);
	TMonom m2(2, 123);
	EXPECT_EQ(true, m1==m2);
}

TEST(TMonom, test_operator_equally_different_coef) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	EXPECT_EQ(true, m1 == m2);
}

TEST(TMonom, test_operator_equally_different_degree) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	EXPECT_EQ(false, m1 == m2);
}

TEST(TMonom, test_operator_more_different_degree) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	EXPECT_EQ(true, m2 > m1);
}

TEST(TMonom, test_operator_more_equal_degree) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	EXPECT_EQ(false, m2 > m1);
}

TEST(TMonom, test_operator_more_the_opposite_condition) {
	TMonom m1(20, 123);
	TMonom m2(2, 23);
	EXPECT_EQ(false, m2 > m1);
}

TEST(TMonom, test_operator_less_the_true_condition) {
	TMonom m1(20, 123);
	TMonom m2(2, 23);
	EXPECT_EQ(true, m2 < m1);
}

TEST(TMonom, test_operator_less_the_equal_degree) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	EXPECT_EQ(false, m2 < m1);
}

TEST(TMonom, test_operator_less_the_opposite_condition) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	EXPECT_EQ(false, m2 < m1);
}

TEST(TMonom, test_operator_not_equally_the_same_parameters) {
	TMonom m1(2, 123);
	TMonom m2(2, 123);
	EXPECT_EQ(false, m1 != m2);
}

TEST(TMonom, test_operator_not_equally_different_coef) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	EXPECT_EQ(false, m1 != m2);
}

TEST(TMonom, test_operator_not_equally_different_degree_true) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	EXPECT_EQ(true, m1 != m2);
}

TEST(TMonom, test_operator_assignment_different_degree_and_coeff) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	EXPECT_NO_THROW(m1=m2);
}

TEST(TMonom, test_operator_assignment_different_degree_and_coeff_check_value) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	m1 = m2;
	EXPECT_EQ(m2, m1);
}

TEST(TMonom, test_operator_addition_different_degree_and_coeff) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	EXPECT_ANY_THROW(m1+m2);
}

TEST(TMonom, test_operator_addition_equal_degree_) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	EXPECT_NO_THROW(m1+m2);
}

TEST(TMonom, test_operator_addition_equal_degree_checking_the_value) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	TMonom m3(22, 123);
	EXPECT_EQ(m3, m1 + m2);
}

TEST(TMonom, test_operator_subtraction_different_degree_and_coeff) {
	TMonom m1(20, 123);
	TMonom m2(2, 223);
	EXPECT_ANY_THROW(m1 - m2);
}

TEST(TMonom, test_operator_subtraction_equal_degree_) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	EXPECT_NO_THROW(m1 - m2);
}

TEST(TMonom, test_operator_subtraction_equal_degree_checking_the_value) {
	TMonom m1(20, 123);
	TMonom m2(2, 123);
	TMonom m3(-18, 123);
	EXPECT_EQ(m3, m2 + m1);
}

TEST(TMonom, test_operator_multiplication_different_degree_and_coeff) {
	TMonom m1(20, 10);
	TMonom m2(2, 100);
	EXPECT_NO_THROW(m1 * m2);
}

TEST(TMonom, test_operator_multiplication_the_degree_overcomes_the_allowed_interval) {
	TMonom m1(20, 999);
	TMonom m2(2, 123);
	EXPECT_ANY_THROW(m1 * m2);
}

TEST(TMonom, test_operator_multiplication__checking_the_value) {
	TMonom m1(20, 111);
	TMonom m2(2, 123);
	TMonom m3(40, 234);
	EXPECT_EQ(m3, m2 * m1);
}

TEST(TMonom, test_checking_the_method_get_value1) {
	TMonom m1(20, 111);
	double a = 20;
	EXPECT_EQ(a, m1.GetValue(1,1,1));
}

TEST(TMonom, test_checking_the_method_get_value2) {
	TMonom m1(20, 222);
	double a = 1280;
	EXPECT_EQ(a, m1.GetValue(2, 2, 2));
}

TEST(TMonom, test_checking_the_method_get_degree_x) {
	TMonom m1(20, 222);
	EXPECT_EQ(2, m1.GetDegreeX());
}

TEST(TMonom, test_checking_the_method_get_degree_y) {
	TMonom m1(20, 222);
	EXPECT_EQ(2, m1.GetDegreeY());
}

TEST(TMonom, test_checking_the_method_get_degree_z) {
	TMonom m1(20, 222);
	EXPECT_EQ(2, m1.GetDegreeZ());
}

TEST(TMonom, test_checking_the_method_dif_x_Xdegree_is_zero) {
	TMonom m1(20, 22);
	TMonom m2(0, 0);
	EXPECT_EQ(m2, m1.dif_x());
}

TEST(TMonom, test_checking_the_method_dif_x_Xdegree_more_then_zero1) {
	TMonom m1(20, 122);
	TMonom m2(20, 22);
	EXPECT_EQ(m2, m1.dif_x());
}

TEST(TMonom, test_checking_the_method_dif_x_Xdegree_more_then_zero2) {
	TMonom m1(20, 222);
	TMonom m2(40, 122);
	EXPECT_EQ(m2, m1.dif_x());
}

TEST(TMonom, test_checking_the_method_dif_y_Ydegree_is_zero) {
	TMonom m1(20, 102);
	TMonom m2(0, 0);
	EXPECT_EQ(m2, m1.dif_y());
}

TEST(TMonom, test_checking_the_method_dif_y_Ydegree_more_then_zero1) {
	TMonom m1(20, 122);
	TMonom m2(40, 112);
	EXPECT_EQ(m2, m1.dif_y());
}

TEST(TMonom, test_checking_the_method_dif_y_Ydegree_more_then_zero2) {
	TMonom m1(20, 112);
	TMonom m2(20, 102);
	EXPECT_EQ(m2, m1.dif_y());
}

TEST(TMonom, test_checking_the_method_dif_z_Zdegree_is_zero) {
	TMonom m1(20, 110);
	TMonom m2(0, 0);
	EXPECT_EQ(m2, m1.dif_z());
}

TEST(TMonom, test_checking_the_method_dif_z_Zdegree_more_then_zero1) {
	TMonom m1(20, 122);
	TMonom m2(40, 121);
	EXPECT_EQ(m2, m1.dif_z());
}

TEST(TMonom, test_checking_the_method_dif_z_Zdegree_more_then_zero2) {
	TMonom m1(20, 111);
	TMonom m2(20, 110);
	EXPECT_EQ(m2, m1.dif_z());
}

TEST(TMonom, test_checking_the_method_set_degree_zero) {
	TMonom m1(20, 111);
	m1.SetDegree(0);
	EXPECT_EQ(0, m1.GetDegree());
}

TEST(TMonom, test_checking_the_method_set_degree_more_then_zero) {
	TMonom m1(20, 111);
	m1.SetDegree(10);
	EXPECT_EQ(10, m1.GetDegree());
}

TEST(TMonom, test_checking_the_method_set_degree_less_then_zero) {
	TMonom m1(20, 111);
	EXPECT_ANY_THROW(m1.SetDegree(-1));
}

TEST(TMonom, test_checking_the_method_set_degree_more_then_max) {
	TMonom m1(20, 111);
	EXPECT_ANY_THROW(m1.SetDegree(1111));
}

TEST(TMonom, test_checking_the_method_set_degree_individually_error1) {
	TMonom m1(20, 111);
	EXPECT_ANY_THROW(m1.SetDegreeXYZ(-1, 1, 1));
}

TEST(TMonom, test_checking_the_method_set_degree_individually_error2) {
	TMonom m1(20, 111);
	EXPECT_ANY_THROW(m1.SetDegreeXYZ(1, -1, 1));
}

TEST(TMonom, test_checking_the_method_set_degree_individually_error3) {
	TMonom m1(20, 111);
	EXPECT_ANY_THROW(m1.SetDegreeXYZ(1, 1, -1));
}

TEST(TMonom, test_checking_the_method_set_degree_individually_no_error) {
	TMonom m1(20, 132);
	EXPECT_NO_THROW(m1.SetDegreeXYZ(1, 1, 1));
}

TEST(TMonom, test_checking_the_method_set_degree_individually_check_x) {
	TMonom m1(20, 132);
	m1.SetDegreeXYZ(1, 1, 1);
	EXPECT_EQ(1, m1.GetDegreeX());
}

TEST(TMonom, test_checking_the_method_set_degree_individually_check_y) {
	TMonom m1(20, 132);
	m1.SetDegreeXYZ(1, 1, 1);
	EXPECT_EQ(1, m1.GetDegreeY());
}

TEST(TMonom, test_checking_the_method_set_degree_individually_check_z) {
	TMonom m1(20, 132);
	m1.SetDegreeXYZ(1, 1, 1);
	EXPECT_EQ(1, m1.GetDegreeZ());
}












