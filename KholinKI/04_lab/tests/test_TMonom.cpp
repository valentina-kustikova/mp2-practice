#include <gtest.h>

#include "TMonom.h"

TEST(monom, default_parameter_constructor_work) {
	ASSERT_NO_THROW(TMonom m(2.92, 4));
}



TEST(monom, constructor_copy_work) {
	TMonom m1(2.92, 4);
	ASSERT_NO_THROW(TMonom m2(m1));
}

TEST(monom, check_set_and_get_coeff_methods) {
	TMonom m1(2.92, 4);
	m1.coeff=6;
	EXPECT_EQ(6, m1.coeff);
}

TEST(monom, check_set_and_get_wd_methods) {
	TMonom m1(2.92, 4);
	m1.wrap_degree=62;
	EXPECT_EQ(62, m1.wrap_degree);
}

TEST(monom, different_memory) {
	TMonom m1(2.92, 4);
	m1.coeff = 6;
	m1.wrap_degree = 9;

	TMonom m2(m1);
	m2.coeff = 6;
	m2.wrap_degree = 9;

	ASSERT_TRUE(&m1 != &m2);
}

TEST(monom, operation_more_when_different_degrees) {
	TMonom m1(2.92, 62);
	TMonom m2(6.95, 104);

	bool res1 = 104 > 62 && 6.95 > 2.92;

	ASSERT_TRUE(m2 > m1 && res1 == true);
}

TEST(monom, operation_more_when_equal_degrees_1) {
	TMonom m1(2.92, 104);
	TMonom m2(6.95, 104);

	bool res1 = m2 > m1;
	if (m2.coeff > m1.coeff && m1.wrap_degree == m2.wrap_degree){
		res1 = true;//доп.условие
	}
	else {
		res1 = false;
	}

	bool res2 = 104 == 104 && 6.95 > 2.92;

	ASSERT_TRUE(res1 == res2);
}

TEST(monom, operation_more_when_equal_degrees_2) {
	TMonom m1(9.92, 104);
	TMonom m2(6.95, 104);

	bool res1 = m2 > m1;
	if (m2.coeff > m1.coeff && m1.wrap_degree == m2.wrap_degree) {
		res1 = true;//доп.условие
	}
	else {
		res1 = false;
	}

	bool res2 = 104 == 104 && 6.95 > 9.92;

	ASSERT_TRUE(res1 == res2);
}

TEST(monom, operation_more_when_equal_monoms) {
	TMonom m1(6.95, 104);
	TMonom m2(6.95, 104);

	bool res2 = 104 == 104 && 6.95 > 6.95;
	bool res1 = m2 > m1;
	if (m1.coeff == m2.coeff && m1.wrap_degree == m2.wrap_degree) {
		res1 = false;
	}
	else {
		res1 = true;
	}

	ASSERT_TRUE(res1 == res2);
}

TEST(monom, operation_less_with_different_degrees) {
	TMonom m1(6.95, 114);
	TMonom m2(6.95, 104);

	ASSERT_TRUE(m2 < m1);
}

TEST(monom, operation_less_with_equal_degrees_1) {
	TMonom m1(6.95, 104);
	TMonom m2(7.95, 104);

	bool res1 = m2 < m1;
	if (m2.coeff < m1.coeff && m1.wrap_degree == m2.wrap_degree) {
		res1 = false;//доп.условие
	}
	else {
		res1 = true;
	}

	bool res2 = 104 == 104 && 7.95 < 6.95;

	ASSERT_FALSE(res1 == res2);
}

TEST(monom, operation_less_with_equal_degrees_2) {
	TMonom m1(8.95, 104);
	TMonom m2(7.95, 104);

	bool res1 = m2 < m1;
	if (m2.coeff < m1.coeff && m1.wrap_degree == m2.wrap_degree) {
		res1 = true;//доп.условие
	}
	else {
		res1 = false;
	}

	bool res2 = 104 == 104 && 7.95 < 8.95;

	ASSERT_TRUE(res1 == res2);
}

TEST(monom, operation_not_equal_with_different_degrees){
	TMonom m1(8.95, 114);
	TMonom m2(7.95, 104);

	bool res1 = m1 != m2;
	bool res2 = 114 != 104 && 8.95 != 7.95;

	ASSERT_TRUE(res1 == res2);
}

TEST(monom, operation_not_equal_with_equal_degrees_and_different_coeffs) {
	TMonom m1(8.95, 104);
	TMonom m2(7.95, 104);

	bool res1 = m1 != m2;
	if (m1.coeff != m2.coeff && m1.wrap_degree == m2.wrap_degree) {
		res1 = true;
	}
	else {
		res1 = false;
	}
	bool res2 = 104 == 104 && 8.95 != 7.95;

	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_more_with_different_degrees) {
	TMonom m1(12.95, 94);
	TMonom m2(7.95, 104);

	bool res1 = 94 <= 104;
	bool res2 = m1 <= m2;


	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_more_with_equal_degrees_1) {
	TMonom m1(12.95, 104);
	TMonom m2(7.95, 104);
	
	//<=
	bool res1 = 104 == 104 && 12.95 <= 7.95;
	bool res2 = m1 <= m2;
	if (m1.coeff <= m2.coeff && m1.wrap_degree == m2.wrap_degree) {
		res2 = true;
	}
	else {
		res2 = false;
	}

	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_more_with_equal_degrees_2) {
	TMonom m1(12.95, 104);
	TMonom m2(12.95, 104);

	//<=
	bool res1 = 104 == 104 && 12.95 == 12.95;
	bool res2 = m1 <= m2;
	if (m1.coeff <= m2.coeff && m1.wrap_degree == m2.wrap_degree) {
		res2 = true;
	}
	else {
		res2 = false;
	}


	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_more_when_equal_degrees_3) {
	TMonom m1(12.95, 104);
	TMonom m2(7.95, 104);

	//<=
	bool res1 = 104 == 104 && 12.95 <= 7.95;
	bool res2 = m1 <= m2;
	if (m1.coeff <= m2.coeff && m1.wrap_degree == m2.wrap_degree) {
		res2 = true;
	}
	else{
		res2 = false;
	}

	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_less_with_different_degrees) {
	TMonom m1(2.95, 114);
	TMonom m2(12.95, 104);

	//>=
	bool res1 = 114 > 104 && 12.95 != 2.95;
	bool res2 = m1 >= m2;


	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_less_with_equal_degrees_1) {
	TMonom m1(12.95, 104);
	TMonom m2(7.95, 104);

	//>=
	bool res1 = 114 > 104 && 12.95 >= 7.95;
	bool res2 = m1 >= m2;
	if (m1.coeff >= m2.coeff && m1.wrap_degree == m2.wrap_degree) {
		res2 = true; 
	}
	else {
		res2 = false;
	}


	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_less_with_equal_degrees_2) {
	TMonom m1(12.95, 104);
	TMonom m2(12.95, 104);

	//>=
	bool res1 = 104 >= 104 && 12.95 >= 12.95;
	bool res2 = m1 >= m2;
	if (m1.coeff >= m2.coeff && m1.wrap_degree == m2.wrap_degree) {
		res2 = true;
	}
	else {
		res2 = false;
	}

	ASSERT_TRUE(res1 == res2);
}

TEST(Monom, operation_no_less_when_equal_degrees_3) {
	TMonom m1(7.95, 104);
	TMonom m2(12.95, 104);

	//>=
	bool res1 = 104 == 104 && 7.95 <= 12.95;
	bool res2 = m1 >= m2;
	if (m1.coeff <= m2.coeff && m1.wrap_degree == m2.wrap_degree)res2 = false;

	ASSERT_TRUE(res1 != res2);
}

TEST(monom, assign_work) {
	TMonom m1(7.95, 124);
	TMonom m2(12.95, 104);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(monom, assign_check_values) {
	TMonom m1(7.95, 124);
	TMonom m2(12.95, 104);
	TMonom m3 = m1;
	ASSERT_NO_THROW(m3.coeff == 7.95 && m3.wrap_degree == 124 || m3 == m1);
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
	ASSERT_TRUE(m3.coeff == 20 && m3.wrap_degree == 228);
}

TEST(monom, multiplication_degree_limit_is_OK) {
	TMonom m1(5, 124);
	TMonom m2(4, 104);
	ASSERT_NO_THROW(m1*m2);
}

TEST(monom, multiplication_degree_limit_exceeded) {
	TMonom m1(5, 126);
	TMonom m2(4, 104);
	ASSERT_ANY_THROW(m1 * m2);
}