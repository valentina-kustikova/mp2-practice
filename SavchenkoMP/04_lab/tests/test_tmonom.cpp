#include <gtest.h>

#include "tmonom.h"

/*
1. DefaultConstructorTest - проверка конструктора по умолчанию.
2. CopyConstructorTest - проверка конструктора копирования.
3. ParameterizedConstructorTest - проверка параметризированного конструктора.
4. DegreeConstructorTest - проверка конструктора с заданием степени.
5. GetCoeffTest - проверка метода получения коэффициента.
6. GetDegreeTest - проверка метода получения степени.
7. SetCoeffTest - проверка метода установки коэффициента.
8. SetDegreeTest - проверка метода установки степени.
9. ValueCalculationTest - проверка метода вычисления значения монома.
10. LessThanOperatorTest - проверка оператора "<".
11. GreaterThanOperatorTest - проверка оператора ">".
12. LessThanOrEqualOperatorTest - проверка оператора "<=".
13. GreaterThanOrEqualOperatorTest - проверка оператора ">=".
14. EqualityOperatorTest - проверка оператора "==".
15. InequalityOperatorTest - проверка оператора "!=".
16. AssignmentOperatorTest - проверка оператора присваивания.
17. MultiplicationOperatorTest - проверка оператора умножения.
18. DifferentiationXTest - проверка метода дифференциации по X.
19. DifferentiationYTest - проверка метода дифференциации по Y.
20. DifferentiationZTest - проверка метода дифференциации по Z.
21. GetStringTest - проверка метода получения строкового представления.
22. OutputStreamOperatorTest - проверка оператора вывода в поток.
*/

/*
TEST(TMonom, TEST_NAME) {

}
*/

// DefaultConstructorTest
TEST(TMonom, DefaultConstructorTest) {
	EXPECT_NO_THROW(TMonom m);
}

TEST(TMonom, DefaultConstructorTest_Coeff) {
	TMonom m;

	EXPECT_EQ(0, m.get_coeff());
}

TEST(TMonom, DefaultConstructorTest_Degree) {
	TMonom m;

	EXPECT_EQ(0, m.get_degree());
}


// ParameterizedConstructorTest
TEST(TMonom, ParameterizedConstructorTest) {
	EXPECT_NO_THROW(TMonom m(2, 123));
}

TEST(TMonom, ParameterizedConstructorTest_Coeff) {
	TMonom m(2, 123);

	EXPECT_EQ(2, m.get_coeff());
}

TEST(TMonom, ParameterizedConstructorTest_Degree) {
	TMonom m(2, 123);

	EXPECT_EQ(123, m.get_degree());
}

TEST(TMonom, ParameterizedConstructorTest_NotValidDegree_Less0) {
	EXPECT_ANY_THROW(TMonom m(2, -3));
}

TEST(TMonom, ParameterizedConstructorTest_NotValidDegree_More999) {
	EXPECT_ANY_THROW(TMonom m(2, 1000));
}


// DegreeConstructorTest
TEST(TMonom, DegreeConstructorTest) {
	EXPECT_NO_THROW(TMonom m(2, 1, 2, 3));
}

TEST(TMonom, DegreeConstructorTest_Coeff) {
	TMonom m(2, 1, 2, 3);

	EXPECT_EQ(2, m.get_coeff());
}

TEST(TMonom, DegreeConstructorTest_Degree) {
	TMonom m(2, 1, 2, 3);

	EXPECT_EQ(123, m.get_degree());
}

TEST(TMonom, DegreeConstructorTest_NotValidDegree_Less0) {
	EXPECT_ANY_THROW(TMonom m1(2, -3, 1, 1));
	EXPECT_ANY_THROW(TMonom m2(2, 1, -3, 1));
	EXPECT_ANY_THROW(TMonom m3(2, 1, 1, -3));
}

TEST(TMonom, DegreeConstructorTest_NotValidDegree_More9) {
	EXPECT_ANY_THROW(TMonom m1(2, 10, 1, 1));
	EXPECT_ANY_THROW(TMonom m2(2, 1, 10, 1));
	EXPECT_ANY_THROW(TMonom m3(2, 1, 1, 10));
}


// EqualityOperatorTest
TEST(TMonom, EqualityOperatorTest_Smaller) {
	TMonom m1(2, 123);
	TMonom m2(4, 333);

	EXPECT_EQ(false, m1 == m2);
}

TEST(TMonom, EqualityOperatorTest_Equal) {
	TMonom m1(2, 123);
	TMonom m2(4, 123);

	EXPECT_EQ(true, m1 == m2);
}

TEST(TMonom, EqualityOperatorTest_Bigger) {
	TMonom m1(2, 123);
	TMonom m2(4, 100);

	EXPECT_EQ(false, m1 == m2);
}


// CopyConstructorTest
TEST(TMonom, CopyConstructorTest) {
	TMonom m1(2, 123);
	TMonom m2(m1);

	EXPECT_EQ(true, m1 == m2);
}


// SetCoeffTest
TEST(TMonom, SetCoeffTest) {
	TMonom m(2, 123);
	m.set_coeff(10);

	EXPECT_EQ(10, m.get_coeff());
}


// SetDegreeTest
TEST(TMonom, SetDegreeTest) {
	TMonom m(2, 123);
	m.set_degree(1,0,1);

	EXPECT_EQ(101, m.get_degree());
}

TEST(TMonom, SetDegreeTest_NotValidDegree_Less0_DegX) {
	TMonom m(2, 123);
	
	EXPECT_ANY_THROW(m.set_degree(-1, 0, 1));
}
TEST(TMonom, SetDegreeTest_NotValidDegree_Less0_DegY) {
	TMonom m(2, 123);

	EXPECT_ANY_THROW(m.set_degree(1, -1, 1));
}
TEST(TMonom, SetDegreeTest_NotValidDegree_Less0_DegZ) {
	TMonom m(2, 123);

	EXPECT_ANY_THROW(m.set_degree(1, 0, -1));
}

TEST(TMonom, SetDegreeTest_NotValidDegree_More9_DegX) {
	TMonom m(2, 123);
	
	EXPECT_ANY_THROW(m.set_degree(10, 0, 1));
}

TEST(TMonom, SetDegreeTest_NotValidDegree_More9_DegY) {
	TMonom m(2, 123);

	EXPECT_ANY_THROW(m.set_degree(1, 10, 1));
}

TEST(TMonom, SetDegreeTest_NotValidDegree_More9_DegZ) {
	TMonom m(2, 123);

	EXPECT_ANY_THROW(m.set_degree(1, 0, 10));
}

TEST(TMonom, SetDegreeTest_Convolution) {
	TMonom m(2, 123);
	m.set_degree(10);

	EXPECT_EQ(10, m.get_degree());
}

TEST(TMonom, SetDegreeTest_Convolution_NotValidDegree_Less0) {
	TMonom m(2, 123);
	
	EXPECT_ANY_THROW(m.set_degree(-1));
}

TEST(TMonom, SetDegreeTest_Convolution_NotValidDegree_More999) {
	TMonom m(2, 123);

	EXPECT_ANY_THROW(m.set_degree(1000));
}


// ValueCalculationTest
TEST(TMonom, ValueCalculationTest) {
	TMonom m(2, 234);

	EXPECT_EQ(720000, m.value(3, 4, 5));
}


// LessThanOperatorTest // Less Equal Bigger
TEST(TMonom, LessThanOperatorTest_Smaller) {
	TMonom m1(2, 123);
	TMonom m2(4, 333);

	EXPECT_EQ(true, m1 < m2);
}

TEST(TMonom, LessThanOperatorTest_Equal) {
	TMonom m1(2, 123);
	TMonom m2(4, 123);

	EXPECT_EQ(false, m1 < m2);
}

TEST(TMonom, LessThanOperatorTest_Bigger) {
	TMonom m1(2, 123);
	TMonom m2(4, 100);

	EXPECT_EQ(false, m1 < m2);
}


// GreaterThanOperatorTest
TEST(TMonom, GreaterThanOperatorTest_Smaller) {
	TMonom m1(2, 123);
	TMonom m2(4, 333);

	EXPECT_EQ(false, m1 > m2);
}

TEST(TMonom, GreaterThanOperatorTest_Equal) {
	TMonom m1(2, 123);
	TMonom m2(4, 123);

	EXPECT_EQ(false, m1 > m2);
}

TEST(TMonom, GreaterThanOperatorTest_Bigger) {
	TMonom m1(2, 123);
	TMonom m2(4, 100);

	EXPECT_EQ(true, m1 > m2);
}


// LessThanOrEqualOperatorTest
TEST(TMonom, LessThanOrEqualOperatorTest_Smaller) {
	TMonom m1(2, 123);
	TMonom m2(4, 333);

	EXPECT_EQ(true, m1 <= m2);
}

TEST(TMonom, LessThanOrEqualOperatorTest_Equal) {
	TMonom m1(2, 123);
	TMonom m2(4, 123);

	EXPECT_EQ(true, m1 <= m2);
}

TEST(TMonom, LessThanOrEqualOperatorTest_Bigger) {
	TMonom m1(2, 123);
	TMonom m2(4, 100);

	EXPECT_EQ(false, m1 <= m2);
}


// GreaterThanOrEqualOperatorTest
TEST(TMonom, GreaterThanOrEqualOperatorTest_Smaller) {
	TMonom m1(2, 123);
	TMonom m2(4, 333);

	EXPECT_EQ(false, m1 >= m2);
}

TEST(TMonom, GreaterThanOrEqualOperatorTest_Equal) {
	TMonom m1(2, 123);
	TMonom m2(4, 123);

	EXPECT_EQ(true, m1 >= m2);
}

TEST(TMonom, GreaterThanOrEqualOperatorTest_Bigger) {
	TMonom m1(2, 123);
	TMonom m2(4, 100);

	EXPECT_EQ(true, m1 >= m2);
}


// InequalityOperatorTest
TEST(TMonom, InequalityOperatorTest_Smaller) {
	TMonom m1(2, 123);
	TMonom m2(4, 333);

	EXPECT_EQ(true, m1 != m2);
}

TEST(TMonom, InequalityOperatorTest_Equal) {
	TMonom m1(2, 123);
	TMonom m2(4, 123);

	EXPECT_EQ(false, m1 != m2);
}

TEST(TMonom, InequalityOperatorTest_Bigger) {
	TMonom m1(2, 123);
	TMonom m2(4, 100);

	EXPECT_EQ(true, m1 != m2);
}


// AssignmentOperatorTest
TEST(TMonom, AssignmentOperatorTest) {
	TMonom m1(2, 123);
	TMonom m2(4, 100);

	m2 = m1;
	EXPECT_EQ(true, m1 == m2);
}


// MultiplicationOperatorTest
TEST(TMonom, MultiplicationOperatorTest) {
	TMonom m1(2, 123);
	TMonom m2(4, 345);

	TMonom exp(8, 468);
  EXPECT_EQ(true, exp == m1 * m2);
}

TEST(TMonom, MultiplicationOperatorTest_BigDegree) {
	TMonom m1(2, 163);
	TMonom m2(4, 345);
	
	EXPECT_ANY_THROW(m1 * m2);
}


// DifferentiationXTest
TEST(TMonom, DifferentiationXTest) {
	TMonom m(2, 234);

	TMonom exp(4, 134);
	EXPECT_EQ(true, exp == m.dif_x());
}

TEST(TMonom, DifferentiationXTest_ZeroDegX) {
	TMonom m(2, 34);

	TMonom exp(0, 0);
	EXPECT_EQ(true, exp == m.dif_x());
}


// DifferentiationYTest
TEST(TMonom, DifferentiationYTest) {
	TMonom m(2, 244);

	TMonom exp(8, 234);
	EXPECT_EQ(true, exp == m.dif_y());
}

TEST(TMonom, DifferentiationYTest_ZeroDegY) {
	TMonom m(2, 204);

	TMonom exp(0, 0);
	EXPECT_EQ(true, exp == m.dif_y());
}


// DifferentiationZTest
TEST(TMonom, DifferentiationZTest) {
	TMonom m(2, 234);

	TMonom exp(8, 233);
	EXPECT_EQ(true, exp == m.dif_z());
}

TEST(TMonom, DifferentiationZTest_ZeroDegZ) {
	TMonom m(2, 230);

	TMonom exp(0, 0);
	EXPECT_EQ(true, exp == m.dif_z());
}


// GetStringTest
TEST(TMonom, GetStringTest) {
	TMonom m(10, 234);

	string exp = "10.000000*x^2*y^3*z^4";
	EXPECT_EQ(exp, m.get_string());
}

TEST(TMonom, GetStringTest_DegreeZero) {
	TMonom m(10, 0);

	string exp = "10.000000";
	EXPECT_EQ(exp, m.get_string());
}

TEST(TMonom, GetStringTest_DegreeOne) {
	TMonom m(10, 121);

	string exp = "10.000000*x*y^2*z";
	EXPECT_EQ(exp, m.get_string());
}