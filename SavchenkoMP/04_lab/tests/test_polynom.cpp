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
	string name = "- y*z + x*y*z + 2*x^2*y^2*z^2 + 3*x^3*y^3*z^3 - x*z";
	EXPECT_NO_THROW(TPolynom p(name));
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom) {
	string name = "- y*z + x*y*z + 2*x^2*y^2*z^2 + 3*x^3*y^3*z^3 - x*z";
	string exp_str = "-1.000000*y*z-1.000000*x*z+1.000000*x*y*z+2.000000*x^2*y^2*z^2+3.000000*x^3*y^3*z^3";
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
	string name = "x^3 + y^3 + z^3 - 3*x*y*z";
	string exp_str = "1.000000*z^3+1.000000*y^3-3.000000*x*y*z+1.000000*x^3";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

TEST(TPolynom, ParameterizedConstructorTest_StringPolynom5) {
	string name = "x^2 + 2*x*y + y^2 - 3*z";
	string exp_str = "-3.000000*z+1.000000*y^2+2.000000*x*y+1.000000*x^2";
	TPolynom p(name);

	EXPECT_EQ(exp_str, p.get_string());
}

// AssignmentOperatorTest
TEST(TPolynom, AssignmentOperatorTest_NoThrow) {
	TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2*x*y - 5*y^3");
	
	EXPECT_NO_THROW(p2 = p1);
}

TEST(TPolynom, AssignmentOperatorTest_Correctness) {
	TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2*x*y - 5*y^3");
	p2 = p1;

	string exp = "4.000000*y^2+3.000000*x*y+2.000000*x^2";
	EXPECT_EQ(exp, p2.get_string());
}

// AdditionTest
TEST(TPolynom, AdditionTest) {
	TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2*x*y - 5*y^3");
	TPolynom expP("3*x^3 + 2*x^2 + 5*x*y - 5*y^3 + 4*y^2");

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

// MultiplicationTest
TEST(TPolynom, MultiplicationTest) {
	TPolynom p1("2*x^2 + 3*x*y + 4*y^2");
	TPolynom p2("3*x^3 + 2*x*y - 5*y^3");
	TPolynom expP("6*x^5 + 4*x^3*y - 10*x^2*y^3 + 9*x^4*y + 6*x^2*y^2 - 15*x*y^4 + 12*x^3*y^2 + 8*x*y^3 - 20*y^5");

	TPolynom p3(p1 * p2);
	EXPECT_EQ(expP.get_string(), p3.get_string());
}

// CalculateValueTest
TEST(TPolynom, CalculateValueTest) {
	TPolynom p("2*x^2 + 3*x*y + 4*y^2");

	EXPECT_EQ(62, p(2, 3, 4));
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


// TODO:
// Constructors, op=, op+, op-, op*, op(), dif