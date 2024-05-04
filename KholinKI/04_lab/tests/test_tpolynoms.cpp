#include "TPolynom.h"

#include <gtest.h>

TEST(polynom, operator_plus_with_simple_polynoms) {
	TPolynom P("1+x");
	TPolynom Q("1-y");

	TPolynom R = P + Q;

	TPolynom test("2+x-y");
	ASSERT_TRUE(R == test);
}


TEST(polynom, polynom_string_contain_0_and_1_degrees) {
	TPolynom P("2*x^2*y^0-89*y^4*x^1");

	TPolynom test("2*x^2-89*y^4*x");
	ASSERT_TRUE(P == test);
}

TEST(polynoms, diffirintiate_y_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_y();

	TPolynom test("60*y+2*x*y*z^3+4*x^2*z^4");
	ASSERT_TRUE(test == R);
	//мономы-константы уничтожаются, а мономы с ненулевой степенью
	//y правильно дифференцируются
}

TEST(polynoms, multiple_differentiation_by_z) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R1,R2;
	R1 = P.differentiate_by_z();
	R2 = R1.differentiate_by_z();

	TPolynom test("6*x*y^2*z-24*x^2*z^2+48*x^2*y*z^2");

	ASSERT_TRUE(test == R2);
}

TEST(polynoms, diffirintiate_z_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_z();
	
	TPolynom test("3*x*y^2*z^2-8*x^2*z^3+16*x^2*y*z^3");
	//мономы-константы уничтожаются, а мономы с ненулевой степенью
	//z правильно дифференцируются
}



TEST(polynoms, similar_monoms_on_stage_creating) {
	TPolynom P("6*z^3-9*x^2*y^5+z^3+4*x^2*y^5-7*x*y*z^6");

	TPolynom test("7*z^3-5*x^2*y^5-7*x*y*z^6");
	ASSERT_TRUE(test == P);
}

TEST(polynom, operator_plus_for_polynom_with_zero_coefficient) {
	TPolynom P("2*x^2*y+3*z^3*x^3+4*z^3*y^2");
	TPolynom Q("2*x*y+3*z^3*x^2-4*z^3*y^2");
	TPolynom R = P + Q;

	TPolynom test("2*x^2*y+3*z^3*x^3+2*x*y+3*z^3*x^2");
	ASSERT_TRUE(test == R);
}


TEST(polynoms, polynom_no_contain_zero_coefficients) {
	TPolynom P("0*x^6*y^2*z-8*z^4+0-0*z^6*y^3");

	TPolynom test("-8*z^4");
	ASSERT_TRUE(P == test);
}



TEST(polynoms, operator_multiplication_work) {
	TPolynom P("3*x^3-5*x^3-y^4*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z+7*x^3*y^4*z");
	ASSERT_NO_THROW(TPolynom R = P * Q);
}



TEST(polynom, operator_minus_for_polynom_with_zero_coefficient) {
	TPolynom P("2*x^2*y+3*z^3*x^3+4*z^3*y^2");
	TPolynom Q("2*x*y+3*z^3*x^2+4*z^3*y^2");
	TPolynom R = P + (-Q);

	TPolynom test("2*x^2*y+3*z^3*x^3-2*x*y-3*z^3*x^2");
	ASSERT_TRUE(test == R);
}

TEST(polynom, operator_minus_with_polynoms_zero_degree_orderly_1_сheck_equality) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P + (-Q);

	TPolynom test("-43");
	ASSERT_TRUE(test == R);
}

TEST(polynom, operator_minus_with_polynoms_not_equal_degree_check_equality) {
	TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^7*y^5*z");
	TPolynom Q("4*x^6*y^2*z^6-6*x^2*y*z^8");
	TPolynom R = Q + (-P);

	TPolynom test("4*x^6*y^2*z^6-6*x^2*y*z^8-3*x^5*y^2*z^5+5*x^4*y^3*z^3-7*x^7*y^5*z");
	ASSERT_TRUE(test == R);
}



TEST(polynoms, calculate_value_polynom_in_point_check_value_three_var_version1) {
	TPolynom P("3*x^3-5*x^4-y^2+z^2");


	double res = P(2, 4, 6);
	ASSERT_TRUE(res == -36);
}


TEST(polynoms, diffirintiate_x_work) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	ASSERT_NO_THROW(TPolynom R = P.differentiate_by_x(););
}

TEST(polynoms, diffirintiate_x_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_x();

	TPolynom test("y^2*z^3-4*x*z^4+8*x*y*z^4");
	ASSERT_TRUE(test == R);
	//мономы-константы уничтожаются, а мономы с ненулевой степенью
	//x правильно дифференцируются
}


TEST(polynoms, calculate_value_polynom_in_point_check_value_three_var) {
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z^2+7*x^3*y^1*z");


	double res = Q(2, 4, 2);
	ASSERT_TRUE(res == 48064);
}


TEST(polynoms, operator_multiplication_with_similar_monoms) {
	TPolynom P("3*x^3-5*x^4-y^2*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z^2+7*x^3*y^1*z");
	TPolynom R = P * Q;

	TPolynom test
	("6*y^5*z^3-25*x^3*y^3*z^2+30*x^4*y^3*z^2-3*x^5*y^4*z^6+21*x^6*y*z-35*x^7*y*z+9*x^8*y^2*z^5-15*x^9*y^2*z^5");
	ASSERT_TRUE(test == R);
	//Мономы со степенями 332 и коэффициентами -7 и -18 существуют, и они приводятся к подобным.
}

TEST(polynom, operator_plus_with_polynoms_zero_degree) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P + Q;

	TPolynom test("49");
	ASSERT_TRUE(test == R);
}

TEST(polynom, operator_plus_with_polynoms_zero_degree_check_equality) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P + Q;

	TPolynom test("49");
	ASSERT_TRUE(test == R);
}

TEST(polynom, operator_minus_with_polynoms_not_equal_degree_check_sign) {
	TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^7*y^5*z");
	TPolynom Q("4*x^6*y^2*z^6-6*x^2*y*z^8");
	TPolynom R = Q + (-P);

	TPolynom test("-6*x^2*y*z^8+5*x^4*y^3*z^3-3*x^5*y^2*z^5+4*x^6*y^2*z^6-7*x^7*y^5*z");
	ASSERT_TRUE(test == R);
}

TEST(polynoms, operator_multiplication_with_exceeded_degree) {
	TPolynom P("3*x^7-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^4*z+7*x^3*y^4*z");
	ASSERT_ANY_THROW(TPolynom R = P * Q);
}




TEST(polynoms, operator_plus_with_monoms_equal_degree_work) {

	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^5*z+7*x^3*y^5*z");
	TPolynom R = P + Q;

	TPolynom test("-7*y^5*z+7*x^3*y^5*z-5*x^4+3*x^5+3*x^5*y^2*z^5");
	ASSERT_TRUE(test == R);
}

TEST(polynoms, operator_plus_with_monoms_not_equal_degree_work) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^6*z+7*x^3*y^5*z");
	TPolynom R = P + Q;

	TPolynom test("-y^5*z-6*y^6*z+7*x^3*y^5*z-5*x^4+3*x^5+3*x^5*y^2*z^5");
	ASSERT_TRUE(test == R);
}

TEST(polynoms, operator_plus_work) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^3*y^5*z");
	ASSERT_NO_THROW(TPolynom R = P + Q);
}

TEST(polynom, operator_minus_with_polynoms_zero_degree_orderly_1) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P + (-Q);

	TPolynom test("-43");
	ASSERT_TRUE(test == R);
}


TEST(polynoms, constructor_parameter_with_list_work_2) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	ASSERT_NO_THROW(TPolynom Q = P.GetMonoms());
}


TEST(polynoms, constructor_parameter_with_list_work_1) {
	TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^3*y^5*z");
	ASSERT_NO_THROW(TPolynom Q = P.GetMonoms());
}



TEST(polynoms, constructor_parameter_with_string_work_4) {
	ASSERT_NO_THROW(TPolynom P("4"));
}

TEST(polynoms, constructor_parameter_with_string_work_1) {
	ASSERT_NO_THROW(TPolynom P("4*x*y^2-2*z+45*y^5*x^3*z^9"));
}

TEST(polynoms, constructor_parameter_with_string_work_2) {
	ASSERT_NO_THROW(TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^3*y^5*z"));
}

TEST(polynoms, constructor_parameter_with_string_work_3) {
	ASSERT_NO_THROW(TPolynom P("3*x^5-5*x^4-y^5*z"));
}

TEST(polynoms, constructor_copy_work) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	ASSERT_NO_THROW(TPolynom Q(P));
}

TEST(polynoms, constructor_copy_copy_equal_original) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q(P);
	ASSERT_TRUE(P == Q);
}

TEST(polynoms, check_assign) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q = P;
	ASSERT_TRUE(P == Q);
}

TEST(polynoms, check_triple_assign) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom R("6*x^2*y^2");
	TPolynom Q = P = R;
	ASSERT_TRUE(P == R && Q == P  && Q == R);
}

TEST(polynoms, different_memory) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom T("3*x^4+5*y^3");
	TPolynom H("6*z+7*y^4");
	P = P + T;
	TPolynom Q(P);
	Q = Q + H;
	ASSERT_TRUE(!(P == Q));
}

TEST(polynom, corrector_work) {
	TRingList<TMonom>* new_monoms = new TRingList<TMonom>;

	TMonom m1(3, 120);	TMonom m4(50, 549);
	TMonom m2(6, 240);	TMonom m5(-6, 240);
	TMonom m3(-4, 120); TMonom m6(45, 365);

	new_monoms->insert_first(m1);
	new_monoms->insert_first(m2);
	new_monoms->insert_first(m3);

	new_monoms->insert_last(m4);
	new_monoms->insert_last(m5);
	new_monoms->insert_last(m6);

	ASSERT_NO_THROW(TPolynom P(new_monoms));
}


TEST(polynom, corrector_deleted_similars) {
	TRingList<TMonom>* new_monoms = new TRingList<TMonom>;

	TMonom m1(3, 120);	TMonom m4(50, 549);
	TMonom m2(6, 240);	TMonom m5(-6, 240);
	TMonom m3(-4, 120); TMonom m6(45, 365);

	new_monoms->insert_first(m1);
	new_monoms->insert_first(m2);
	new_monoms->insert_first(m3);

	new_monoms->insert_last(m4);
	new_monoms->insert_last(m5);
	new_monoms->insert_last(m6);

	TPolynom P(new_monoms);

	TPolynom test("-x*y^2+45*x^3*y^6*z^5+50*x^5*y^4*z^9");
	ASSERT_TRUE(test == P);
}

TEST(polynom, corrector_not_expected_similars) {
	TRingList<TMonom>* new_monoms = new TRingList<TMonom>;

	TMonom m1(3, 120);	TMonom m4(50, 549);
	TMonom m2(6, 242);	TMonom m5(-6, 240);
	TMonom m3(-4, 124); TMonom m6(45, 365);

	new_monoms->insert_first(m1);
	new_monoms->insert_first(m2);
	new_monoms->insert_first(m3);

	new_monoms->insert_last(m4);
	new_monoms->insert_last(m5);
	new_monoms->insert_last(m6);

	TPolynom P(new_monoms);

	TPolynom test("3*x*y^2-4*x*y^2*z^4-6*x^2*y^4+6*x^2*y^4*z^2+45*x^3*y^6*z^5+50*x^5*y^4*z^9");
	ASSERT_TRUE(test == P);
}
