#include <gtest.h>

#include "tpolynom.h"

/*
TEST(TPolynom, TEST_NAME) {

}
*/

// DefaultConstructorTest
TEST(TPolynom, DefaultConstructorTest) {
	EXPECT_NO_THROW(TPolynom p);
}

// ParameterizedConstructorTest
TEST(TPolynom, ParameterizedConstructorTest) {
	string name = "- y*z + x*y*z + 2.2*x^2*y^2*z^2 + 3.35*x^3*y^3*z^3 - x*z";
	EXPECT_NO_THROW(TPolynom p(name));
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom) {
	string name = "- y*z + x*y*z + 2.2*x^2*y^2*z^2 + 3.35*x^3*y^3*z^3 - x*z";
	string exp_str = "-1.000000*y*z-1.000000*x*z+1.000000*x*y*z+2.200000*x^2*y^2*z^2+3.350000*x^3*y^3*z^3";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom1) {
	string name = "x^2 + y^2 + z^2";
	string exp_str = "1.000000*z^2+1.000000*y^2+1.000000*x^2";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom2) {
	string name = "x^3 + 2*x*y - 3*z";
	string exp_str = "-3.000000*z+2.000000*x*y+1.000000*x^3";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom3) {
	string name = "x^2*y*z + x*y^2*z + x*y*z^2";
	string exp_str = "1.000000*x*y*z^2+1.000000*x*y^2*z+1.000000*x^2*y*z";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom4) {
	string name = "x^3 + y^3 + z^3 - 3.35*x*y*z";
	string exp_str = "1.000000*z^3+1.000000*y^3-3.350000*x*y*z+1.000000*x^3";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom5) {
	string name = "x^2 + 2.2*x*y + y^2 - 3.35*z";
	string exp_str = "-3.350000*z+1.000000*y^2+2.200000*x*y+1.000000*x^2";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_Throw_LargeDegree) {
	string name = "x^2 + 2*x*y + y^2 - 3*z^10";

	EXPECT_ANY_THROW(TPolynom p(name));
}

TEST(TPolynom, ParameterizedConstructorTest_Throw_VetyLargeDegree) {
	string name = "x^2 + 2*x*y + y^200 - 3*z^3";

	EXPECT_ANY_THROW(TPolynom p(name));
}

TEST(TPolynom, ParameterizedConstructorTest_Throw_NegativeDegree) {
	string name = "x^2 + 2*x*y + y^(-2) - 3*z^10";

	EXPECT_ANY_THROW(TPolynom p(name));
}

TEST(TPolynom, ParameterizedConstructorTest_Conversion) {
	TPolynom p("0 + x^3 - y^2 - x^3");
	TPolynom expP("-y^2");

	EXPECT_EQ(expP.get_string(), p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_Conversion_Null) {
	TPolynom p("x^3 - x^3");
	string exp = "0.000000";

	EXPECT_EQ(exp, p.get_string());
}

// AssignmentOperatorTest
TEST(TPolynom, AssignmentOperatorTest_NoThrow) {
	TPolynom p1("2.2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2*x*y - 5*y^3");
	
	EXPECT_NO_THROW(p2 = p1);
}

TEST(TPolynom, AssignmentOperatorTest_Correctness) {
	TPolynom p1("2.2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2.2*x*y - 5*y^3");
	p2 = p1;

	string exp = "4.000000*y^2+3.000000*x*y+2.200000*x^2";
	EXPECT_EQ(exp, p2.get_string());
}

// AdditionTest
TEST(TPolynom, AdditionTest) {
	TPolynom p1("2*x^2 + 3.3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2.2*x*y - 5*y^3");
	TPolynom expP("3*x^3 + 2*x^2 + 5.5*x*y - 5*y^3 + 4*y^2");

	TPolynom p3(p1 + p2);
	EXPECT_EQ(expP.get_string(), p3.get_string());
}

// SubtractionTest
TEST(TPolynom, SubtractionTest) {
	TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2*x*y - 5*y^3");
	TPolynom expP("-3*x^3 + 2*x^2 + x*y + 5*y^3 + 4*y^2");

	TPolynom p3(p1 - p2);
	EXPECT_EQ(expP.get_string(), p3.get_string());
}

TEST(TPolynom, SubtractionTest_Double) {
	TPolynom p1("3.2*x*y - 1.1*x^2");
	TPolynom p2("5.2*x*y - 2.2*x^2");
	TPolynom expP("-2*x*y + 1.1*x^2");

	TPolynom p3(p1 - p2);
	EXPECT_EQ(expP.get_string(), p3.get_string());
}

// MultiplicationTest
TEST(TPolynom, MultiplicationTest) {
	TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2*x*y - 5*y^3");
	TPolynom expP("6*x^5 + 4*x^3*y - 10*x^2*y^3 + 9*x^4*y + 6*x^2*y^2 - 15*x*y^4 + 12*x^3*y^2 + 8*x*y^3 - 20*y^5");

	TPolynom p3(p1 * p2);
	EXPECT_EQ(expP.get_string(), p3.get_string());
}

TEST(TPolynom, MultiplicationTest_Throw_LargeDegree) {
	TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^8 + 2*x*y - 5*y^3");

	EXPECT_ANY_THROW(TPolynom p3(p1 * p2));
}

TEST(TPolynom, MultiplicationTest_Throw_VeryLargeDegree) {
	TPolynom p1("2*x^9 + 3*x^9*y^9 + 4*y^9");
	TPolynom p2("3*x^9 + 2*x^9*y^9 - 5*y^9");

	EXPECT_ANY_THROW(TPolynom p3(p1 * p2));
}

// CalculateValueTest
TEST(TPolynom, CalculateValueTest) {
	TPolynom p("2*x^2 + 3*x*y + 4*y^2");

	EXPECT_EQ(62, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_NullPolynom) {
	TPolynom p("2*x^2 - 2*x^2");

	EXPECT_EQ(0, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_Null) {
	TPolynom p("0");

	EXPECT_EQ(0, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_EmptyPolynom) {
	TPolynom p("");

	EXPECT_EQ(0, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_WithoutVariables) {
	TPolynom p("4");

	EXPECT_EQ(4, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_WithoutVariables_Negative) {
	TPolynom p("-4");

	EXPECT_EQ(-4, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_OneVariable) {
	TPolynom p("y");

	EXPECT_EQ(3, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_OneVariable_Negative) {
	TPolynom p("-y");

	EXPECT_EQ(-3, p(2, 3, 4));
}

TEST(TPolynom, CalculateValueTest_OneVariable_WithDegree) {
	TPolynom p("y^2");

	EXPECT_EQ(9, p(2, 3, 4));
}


// DifferentiationXTest
TEST(TPolynom, DifferentiationXTest) {
	TPolynom p("x^3*y*z + x*y^3*z + x*y*z^3 + x + y + z");
	TPolynom expP("3*x^2*y*z + y^3*z + y*z^3 + 1");

	TPolynom res(p.dif_x());
	EXPECT_EQ(expP.get_string(), res.get_string());
}

// DifferentiationYTest
TEST(TPolynom, DifferentiationYTest) {
	TPolynom p("x^3*y*z + x*y^3*z + x*y*z^3 + x + y + z");
	TPolynom expP("x^3*z + 3*x*y^2*z + x*z^3 + 1");

	TPolynom res(p.dif_y());
	EXPECT_EQ(expP.get_string(), res.get_string());
}

// DifferentiationZTest
TEST(TPolynom, DifferentiationZTest) {
	TPolynom p("x^3*y*z + x*y^3*z + x*y*z^3 + x + y + z");
	TPolynom expP("x^3*y + x*y^3 + 3*x*y*z^2 + 1");

	TPolynom res(p.dif_z());
	EXPECT_EQ(expP.get_string(), res.get_string());
}