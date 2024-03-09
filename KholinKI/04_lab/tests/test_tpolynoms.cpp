#include "TPolynom.h"

#include <gtest.h>



//в самом начале учесть ограничение степеней
//подобные могут быть в самом начале
//сложить/вычесть два противоложных монома
//на пустой полином бросать исключение(пустая строка)

//TEST(polynoms, operator_multiplication_work) {
//	TPolynom P("3*x^3-5*x^3-y^4*z");
//	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z+7*x^3*y^4*z");
//	ASSERT_NO_THROW(TPolynom R = P * Q);
//}



TEST(polynoms, calculate_value_polynom_in_point_check_value_three_var_version1) {//у нас полином от трёх переменных
	TPolynom P("3*x^3-5*x^4-y^2+z^2");


	double res = P(2, 4, 6);
	ASSERT_TRUE(res == -36);
}
TEST(polynoms, calculate_value_polynom_in_point_check_value_no_var) {
	TPolynom P("2");

	double res = P(1, 1, 1);;
	ASSERT_TRUE(res == 2);
}

TEST(polynoms, diffirintiate_y_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_y();

	Node<TMonom>* m1 = new Node<TMonom>(*new TMonom(0, 0));
	Node<TMonom>* m2 = new Node<TMonom>(*new TMonom(60, 10));

	Node<TMonom>* found1 = R.GetMonoms()->search(m1->data);
	Node<TMonom>* found2 = R.GetMonoms()->search(m2->data);
	ASSERT_TRUE(found1->data.GetCoeff() == 1 && found2 != nullptr && found2->data.GetCoeff() == 60);
	//мономы-константы уничтожаются, а мономы с ненулевой степенью
	//y правильно дифференцируются
}

TEST(polynoms, diffirintiate_x_work) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	ASSERT_NO_THROW(TPolynom R = P.differentiate_by_x(););
}

TEST(polynoms, diffirintiate_x_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_x();

	Node<TMonom>* m1 = new Node<TMonom>(*new TMonom(0, 0));
	Node<TMonom>* m2 = new Node<TMonom>(*new TMonom(8, 114));

	Node<TMonom>* found1 = R.GetMonoms()->search(m1->data);
	Node<TMonom>* found2 = R.GetMonoms()->search(m2->data);
	ASSERT_TRUE(found1->data.GetCoeff() == 1 && found2 != nullptr && found2->data.GetCoeff() == 8);
	//мономы-константы уничтожаются, а мономы с ненулевой степенью
	//x правильно дифференцируются
}



TEST(polynoms, diffirintiate_z_check_values) {
	TPolynom P("4*x^2*y*z^4+x*y^2*z^3-780+30*y^2-2*x^2*z^4");
	TPolynom R = P.differentiate_by_z();

	Node<TMonom>* m1 = new Node<TMonom>(*new TMonom(0, 0));
	Node<TMonom>* m2 = new Node<TMonom>(*new TMonom(3, 122));

	Node<TMonom>* found1 = R.GetMonoms()->search(m1->data);
	Node<TMonom>* found2 = R.GetMonoms()->search(m2->data);
	ASSERT_TRUE(found1->data.GetCoeff() == 1 && found2 != nullptr && found2->data.GetCoeff() == 3);
	//мономы-константы уничтожаются, а мономы с ненулевой степенью
	//z правильно дифференцируются
}



//а если полином пустой?


TEST(polynoms, calculate_value_polynom_in_point_check_value_one_var) {
	TPolynom P("-y^2");


	double res = P(1,2);//перегрузка оператора
	ASSERT_TRUE(res == -4);
}

TEST(polynoms, calculate_value_polynom_in_point_check_value_two_var) {
	TPolynom P("3*x^3-5*x^4-y^2");


	double res = P(2, 4);
	ASSERT_TRUE(res == -72);
}




TEST(polynoms, calculate_value_polynom_in_point_check_value_three_var_version2) {
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z^2+7*x^3*y^1*z");


	double res = Q(2, 4, 2);
	ASSERT_TRUE(res == 48064);
}

TEST(polynoms, operator_multiplication_work) {
	TPolynom P("3*x^3-5*x^4-y^2*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z^2+7*x^3*y^1*z");
	ASSERT_NO_THROW(TPolynom R = P * Q);
}

TEST(polynoms, operator_multiplication_with_similar_monoms) {
	TPolynom P("3*x^3-5*x^4-y^2*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z^2+7*x^3*y^1*z");
	TPolynom R = P * Q;

	Node<TMonom>* sim_m = new Node<TMonom>(*new TMonom(-7+(-18), 332));
	Node<TMonom>* found = R.GetMonoms()->search(sim_m->data);
	ASSERT_TRUE(found != nullptr && found->data.GetCoeff() == -25);
	//Мономы со степенями 332 и коэффициентами -7 и -18 существуют, и они приводятся к подобным.
}

TEST(polynoms, operator_multiplication_with_unsimilar_monoms) {
	TPolynom P("3*x^3-5*x^4-y^3*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^3*z^2+7*x^3*y^1*z");
	TPolynom R = P * Q;

	Node<TMonom>* sim_m1 = new Node<TMonom>(*new TMonom(-7, 342));
	Node<TMonom>* sim_m2 = new Node<TMonom>(*new TMonom(-18, 332));

	Node<TMonom>* found1 = R.GetMonoms()->search(sim_m1->data);
	Node<TMonom>* found2 = R.GetMonoms()->search(sim_m2->data);
	ASSERT_TRUE(found1 != nullptr && found2 != nullptr);
	//Мономы m1 и m2 существуют в R, и они неподобны.
}

TEST(polynom, operator_plus_with_polynoms_zero_degree) {
	TPolynom P("3");
	TPolynom Q("46");
	TPolynom R = P + Q;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(49, 0));
	Node<TMonom>* found = R.GetMonoms()->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.GetCoeff() == test->data.GetCoeff());//мономы равные?
	//существует моном из R, равный test.
}

TEST(polynom, operator_minus_with_polynoms_not_equal_degree_check_sign) {//учесть, когда получатся нулевые мономы
	TPolynom P("3*x^5*y^2*z^5-5*x^4*y^3*z^3+7*x^7*y^5*z");
	TPolynom Q("4*x^6*y^2*z^6-6*x^2*y*z^8");
	TPolynom R = Q - P;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(5, 433));
	Node<TMonom>* found = R.GetMonoms()->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.GetCoeff() == test->data.GetCoeff());//мономы равные?
	//существует моном из R, равный test.
}




//3:при умножении мономов получился моном с нулевым коэффициентом.

TEST(polynoms, operator_multiplication_with_exceeded_degree) {
	TPolynom P("3*x^7-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^4*z+7*x^3*y^4*z");
	ASSERT_ANY_THROW(TPolynom R = P * Q);
}





TEST(polynoms, operator_plus_with_monoms_equal_degree_work) {//учесть, когда получатся нулевые мономы

	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^5*z+7*x^3*y^5*z");
	TPolynom R = P + Q;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(-7, 51));
	Node<TMonom>* found = R.GetMonoms()->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.GetCoeff() == test->data.GetCoeff());
	//существует моном из R, равный test.

}

TEST(polynoms, operator_plus_with_monoms_not_equal_degree_work) {
	TPolynom P("3*x^5-5*x^4-y^5*z");
	TPolynom Q("3*x^5*y^2*z^5-6*y^6*z+7*x^3*y^5*z");
	TPolynom R = P + Q;

	Node<TMonom>* test = new Node<TMonom>(*new TMonom(-6, 61));
	Node<TMonom>* found = R.GetMonoms()->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.GetCoeff() == -6);
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
	Node<TMonom>* found = R.GetMonoms()->search(test->data);
	ASSERT_TRUE(found != nullptr && found->data.GetCoeff() == test->data.GetCoeff());//мономы равные?
	//существует моном из R, равный test.
}


//учесть .когда получаются нулевые мономы


//4: полиномы одинакового размера(можно в samples опробовать



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

TEST(polynoms, constructor_copy_work) {//не проверен через debug конструктор копирования списков
	TPolynom P("3*x^5-5*x^4-y^5*z");
	ASSERT_NO_THROW(TPolynom Q(P));
}




//TEST(polynoms, different_memory) {
//	TPolynom P("3*x^5-5*x^4-y^5*z");
//	TPolynom Q(P);
//
//	//операции?
//}




