#include "TPolynom.h"

#include <gtest.h>

TEST(polynoms, diffirintiate_y_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_y();

	Node<TMonom>* m1 = new Node<TMonom>(*new TMonom(4, 204));
	Node<TMonom>* m2 = new Node<TMonom>(*new TMonom(60, 10));

	Node<TMonom>* found1 = R.monoms->search(m1->data);
	Node<TMonom>* found2 = R.monoms->search(m2->data);
	ASSERT_TRUE(found1->data.coeff == 4 && found1 != nullptr && found2 != nullptr && found2->data.coeff == 60);
	//мономы-константы уничтожаютс€, а мономы с ненулевой степенью
	//y правильно дифференцируютс€
}

TEST(polynoms, multiple_differentiation_by_z) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R;
	R = P.differentiate_by_z();
	R = R.differentiate_by_z();

	Node<TMonom>* m1 = new Node<TMonom>(*new TMonom(48, 212));
	Node<TMonom>* m2 = new Node<TMonom>(*new TMonom(6, 121));

	Node<TMonom>* found1 = R.monoms->search(m1->data);
	Node<TMonom>* found2 = R.monoms->search(m2->data);
	ASSERT_TRUE(found1->data.coeff == 48 && found2 != nullptr && found2->data.coeff == 6);
}

TEST(polynoms, diffirintiate_z_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_z();

	Node<TMonom>* m1 = new Node<TMonom>(*new TMonom(16, 213));
	Node<TMonom>* m2 = new Node<TMonom>(*new TMonom(3, 122));

	Node<TMonom>* found1 = R.monoms->search(m1->data);
	Node<TMonom>* found2 = R.monoms->search(m2->data);
	ASSERT_TRUE(found1->data.coeff == 16 && found2 != nullptr && found2->data.coeff == 3);
	//мономы-константы уничтожаютс€, а мономы с ненулевой степенью
	//z правильно дифференцируютс€
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

TEST(polynom, operator_minus_for_opposite_polynoms) {
	TPolynom P("6*x^4*y^2+z^5");
	TPolynom Q("6*x^4*y^2+z^5");
	TPolynom R = P - Q;

	TPolynom test("");
	int size_R = R.monoms->GetSize();
	int size_test = test.monoms->GetSize();
	EXPECT_EQ(size_test,size_R);
}

TEST(polynoms, operator_multiplication_work) {
	TPolynom P("3*x^3-5*x^3-y^4*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z+7*x^3*y^4*z");
	ASSERT_NO_THROW(TPolynom R = P * Q);
}



TEST(polynom, operator_minus_for_polynom_with_zero_coefficient) {
	TPolynom P("2*x^2*y+3*z^3*x^3+4*z^3*y^2");
	TPolynom Q("2*x*y+3*z^3*x^2+4*z^3*y^2");
	TPolynom R = P - Q;

	TPolynom test("2*x^2*y+3*z^3*x^3-2*x*y-3*z^3*x^2");
	ASSERT_TRUE(test == R);
}



TEST(polynoms, operator_multiplication_with_unsimilar_monoms_check_equality) {
	TPolynom P("2*x^2*y+3*z^3*x^3");
	TPolynom Q("2*x*y+3*z^3*x^2");
	TPolynom R;

	R = P * Q;

	TPolynom test("4*x^3*y^2+12*x^4*y*z^3+9*x^5*z^6");
	ASSERT_TRUE(test == R);
}

TEST(polynom, operator_minus_with_polynoms_zero_degree_orderly_1_сheck_equality) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P - Q;

	TPolynom test("-43");
	ASSERT_TRUE(test == R);
}

TEST(polynom, operator_minus_with_polynoms_not_equal_degree_check_equality) {//учесть, когда получатс€ нулевые мономы
	TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^7*y^5*z");
	TPolynom Q("4*x^6*y^2*z^6-6*x^2*y*z^8");
	TPolynom R = Q - P;

	TPolynom test("4*x^6*y^2*z^6-6*x^2*y*z^8-3*x^5*y^2*z^5+5*x^4*y^3*z^3-7*x^7*y^5*z");
	ASSERT_TRUE(test == R);
}

TEST(polynoms, calculate_value_polynom_in_point_check_value_three_var_version1) {//у нас полином от трЄх переменных
	TPolynom P("3*x^3-5*x^4-y^2+z^2");


	double res = P(2, 4, 6);
	ASSERT_TRUE(res == -36);
}

TEST(polynoms, calculate_value_polynom_in_point_check_value_no_var) {
	TPolynom P("2");

	double res = P(1, 1, 1);;
	ASSERT_TRUE(res == 2);
}



TEST(polynoms, diffirintiate_x_work) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	ASSERT_NO_THROW(TPolynom R = P.differentiate_by_x(););
}

TEST(polynoms, diffirintiate_x_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_x();

	Node<TMonom>* m1 = new Node<TMonom>(*new TMonom(-4, 104));
	Node<TMonom>* m2 = new Node<TMonom>(*new TMonom(8, 114));

	Node<TMonom>* found1 = R.monoms->search(m1->data);
	Node<TMonom>* found2 = R.monoms->search(m2->data);
	ASSERT_TRUE(found1->data.coeff == -4 && found2 != nullptr && found2->data.coeff == 8);
	//мономы-константы уничтожаютс€, а мономы с ненулевой степенью
	//x правильно дифференцируютс€
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

	Node<TMonom>* sim_m = new Node<TMonom>(*new TMonom(-7+(-18), 332));
	Node<TMonom>* found = R.monoms->search(sim_m->data);
	ASSERT_TRUE(found != nullptr && found->data.coeff == -25);
	//ћономы со степен€ми 332 и коэффициентами -7 и -18 существуют, и они привод€тс€ к подобным.
}

TEST(polynoms, operator_multiplication_with_unsimilar_monoms) {
	TPolynom P("3*x^3-5*x^4-y^3*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z^2+7*x^3*y^1*z");
	TPolynom R = P * Q;

	Node<TMonom>* sim_m1 = new Node<TMonom>(*new TMonom(-7, 342));
	Node<TMonom>* sim_m2 = new Node<TMonom>(*new TMonom(-18, 332));

	Node<TMonom>* found1 = R.monoms->search(sim_m1->data);
	Node<TMonom>* found2 = R.monoms->search(sim_m2->data);
	ASSERT_TRUE(found1 != nullptr && found2 != nullptr);
	//ћономы m1 и m2 существуют в R, и они неподобны.
}



TEST(polynom, operator_plus_with_polynoms_zero_degree) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P + Q;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(49, 0));
	Node<TMonom>* found = R.monoms->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.coeff == test->data.coeff);//мономы равные?
	//существует моном из R, равный test.
}

TEST(polynom, operator_plus_with_polynoms_zero_degree_check_equality) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P + Q;

	TPolynom test("49");
	ASSERT_TRUE(test == R);
}

TEST(polynom, operator_minus_with_polynoms_not_equal_degree_check_sign) {//учесть, когда получатс€ нулевые мономы
	TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^7*y^5*z");
	TPolynom Q("4*x^6*y^2*z^6-6*x^2*y*z^8");
	TPolynom R = Q - P;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(5, 433));
	Node<TMonom>* found = R.monoms->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.coeff == test->data.coeff);//мономы равные?
	//существует моном из R, равный test.
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

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(-7, 51));
	Node<TMonom>* found = R.monoms->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.coeff == test->data.coeff);
	//существует моном из R, равный test.

}

TEST(polynoms, operator_plus_with_monoms_not_equal_degree_work) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^6*z+7*x^3*y^5*z");
	TPolynom R = P + Q;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(-6, 61));
	Node<TMonom>* found = R.monoms->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.coeff == -6);
	//существует моном из R, равный test.
	
}

TEST(polynoms, operator_plus_work) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^3*y^5*z");
	ASSERT_NO_THROW(TPolynom R = P + Q);
}

TEST(polynom, operator_minus_with_polynoms_zero_degree_orderly_1) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P - Q;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(-43, 0));
	Node<TMonom>* found = R.monoms->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.coeff == test->data.coeff);//мономы равные?
	//существует моном из R, равный test.
}


TEST(polynoms, constructor_parameter_with_list_work_2) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	ASSERT_NO_THROW(TPolynom Q = P.monoms);
}


TEST(polynoms, constructor_parameter_with_list_work_1) {
	TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^3*y^5*z");
	ASSERT_NO_THROW(TPolynom Q = P.monoms);
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

TEST(polynoms, polynom_with_only_zero) {
	TPolynom P("0");

	TPolynom test("");

	int size_P = P.monoms->GetSize();
	int size_test = test.monoms->GetSize();
	EXPECT_EQ(size_test, size_P);
}

TEST(polynoms, polynom_with_only_series_zeros) {
	TPolynom P("-0-0+0-0");

	TPolynom test("");

	int size_P = P.monoms->GetSize();
	int size_test = test.monoms->GetSize();
	EXPECT_EQ(size_test, size_P);
}



