#include <gtest.h>
#include <vector>
#include "tarithmetic_expression.h"

//на создание

TEST(TArithmeticExpression, can_create_Ar_expression)
{
	string infix = "-2.0+A+B*(B/A)+3.1+2";

	ASSERT_NO_THROW(TArithmeticExpression expr(infix));
}

TEST(TArithmeticExpression, can_create_empty_expression)
{
	string infix = "";

	ASSERT_NO_THROW(TArithmeticExpression expr(infix));
}

//тесты на корректность постфиксной формы и вычислений

TEST(TArithmeticExpression, test_correct_expressions_1)
{
	string infix = "(a-b)   + c*3.2/3";
	string postfix = "ab-c3.2*3/+";

	map<string, double> operands = { {"a", 1}, {"b", 10}, {"c", 0} };

	double result = -9;

	TArithmeticExpression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Calculate());
}



TEST(TArithmeticExpression, test_correct_expressions_2)
{
	string infix = "(aA*b)*5   + c*1/3";
	string postfix = "aAb*5*c1*3/+";

	map<string, double> operands = { {"aA", 2}, {"b", 3}, {"c", 3} };

	double result = 31;

	TArithmeticExpression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Calculate());
}


TEST(TArithmeticExpression, test_correct_expressions_3)
{
	string infix = "a+A-c+A-c";
	string postfix = "aA+c-A+c-";

	map<string, double> operands = { {"a", 1}, {"A", 2}, {"c", 3} };

	double result = -1;

	TArithmeticExpression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Calculate());
}

TEST(TArithmeticExpression, test_correct_expressions_4)
{
	string infix = "-3+10*(1.2)+a*bvgd -c";
	string postfix = "03-101.2*+abvgd*+c-";

	map<string, double> operands = { {"a", 1}, {"bvgd", 2}, {"c", 3} };

	double result = 8;

	TArithmeticExpression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Calculate());
}

TEST(TArithmeticExpression, test_correct_expressions_5)
{
	string infix = "1.5*(-a)+c*(-b)";
	string postfix = "1.50a-*c0b-*+";

	map<string, double> operands = { {"a", 1}, {"b", 2}, {"c", 3} };

	double result = -7.5;

	TArithmeticExpression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Calculate());
}


TEST(TArithmeticExpression, test_correct_expressions_6)
{
	string infix = "13*(1.5 -a) -c/b + a*b -c/a";
	string postfix = "131.5a-*cb/-ab*+ca/-";

	map<string, double> operands = { {"a", 1}, {"b", 2}, {"c", 3} };

	double result = 4;

	TArithmeticExpression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Calculate());
}

TEST(TArithmeticExpression, test_correct_expressions_7)
{
	string infix = "a+ab-abc*ab - (-ab)";
	string postfix = "aab+abcab*-0ab--";

	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };

	double result = -1;

	TArithmeticExpression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Calculate());
}


TEST(TArithmeticExpression, test_incorrect_expressions_two_point)
{
	string infix = "a+A*1.1.2";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW (TArithmeticExpression exp(infix, operands));
}


TEST(TArithmeticExpression, test_incorrect_expressions_more_closing_brackets)
{
	string infix = "a+b-c + (3*a))";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW(TArithmeticExpression exp(infix, operands));
}

TEST(TArithmeticExpression, test_incorrect_expressions_more_opening_brackets)
{
	string infix = "a+b-c + ((3*a)";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW(TArithmeticExpression exp(infix, operands));
}

TEST(TArithmeticExpression, test_incorrect_expressions_minus_after_brackets)
{
	string infix = "a+b-c + (3*a)-";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW(TArithmeticExpression exp(infix, operands));
}

TEST(TArithmeticExpression, test_incorrect_expressions_multi_for_one_operand)
{
	string infix = "*a+b-c + (3*a)";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW(TArithmeticExpression exp(infix, operands));
}

TEST(TArithmeticExpression, test_incorrect_expressions_start_with_point)
{
	string infix = ".02+*a+b-c + (3*a)";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW(TArithmeticExpression exp(infix, operands));
}

TEST(TArithmeticExpression, test_incorrect_expressions_two_multi)
{
	string infix = "c**a+b-c + (3*a)";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW(TArithmeticExpression exp(infix, operands));
}

TEST(TArithmeticExpression, test_incorrect_expressions_missing_brackets)
{
	string infix = "a+b-c) + (3*a";
	map<string, double> operands = { {"a", 1}, {"ab", 2}, {"abc", 3} };
	ASSERT_ANY_THROW(TArithmeticExpression exp(infix, operands));
}
