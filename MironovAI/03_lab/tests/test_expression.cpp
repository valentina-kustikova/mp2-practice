#include <gtest.h>
#include <vector>
#include <map>

#include "expression.h"


TEST(Expression, create_expression)
{
	string infix = "-2.0+A+B*(B/A)+3.1+2";
	string postfix = "02.0-A+BBA/*+3.1+2+";
	map<string, double> operands = { {"A", 1}, {"B", 2} };

	ASSERT_NO_THROW(Expression::Expression(infix, operands));
}
/*
TEST(Expression, create_expression_with_wrong_operands)
{
	string infix = "-2.0+A+B*(B/A)+3.1+2";
	string postfix = "02.0-A+BBA/*+3.1+2+";
	map<string, double> operands = { {"A", 1}, {"X", 2} };

	ASSERT_ANY_THROW(Expression::Expression(infix, operands));
}

TEST(Expression, create_expression_without_operand)
{
	string infix = "-2.0+A+B*(B/A)+3.1+2";
	string postfix = "02.0-A+BBA/*+3.1+2+";
	map<string, double> operands = { {"A", 1} };
	double result = 8.1;

	ASSERT_ANY_THROW(Expression::Expression(infix, operands));
}
*/

TEST(Expression, create_empty_expression)
{
	string infix = "";
	string postfix = "";
	map<string, double> operands = { };
	double result = 8.1;

	ASSERT_ANY_THROW(Expression::Expression(infix, operands));
}
/*
TEST(Expression, create_expression_with_empty_operands)
{
	string infix = "1+1";
	string postfix = "11+";
	map<string, double> operands = { };
	double result = 2;
	ASSERT_NO_THROW(Expression exp(infix, operands));

	Expression exp(infix, operands);
	EXPECT_EQ(result, exp.Get_res());
	
}

TEST(Expression, create_expression_with_wrong_empty_operands)
{
	string infix = "A+B";
	string postfix = "AB+";
	map<string, double> operands = { {"A", 1} };

	double result = 2;
	ASSERT_ANY_THROW(Expression exp(infix, operands));
}
*/


TEST(Expression, test_correct_expressions1)
{
	string infix = "3 + 2 * x / (y - z)";
	string postfix = "32x*yz-/+";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = 2;

	Expression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Get_res());	
}

TEST(Expression, test_correct_expressions2)
{
	string infix = "(x + y) * y - z / x";
	string postfix = "xy+y*zx/-";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = -2;

	Expression exp(infix, operands);
	EXPECT_EQ(postfix, exp.GetPostfix());
	EXPECT_EQ(result, exp.Get_res());	
}

TEST(Expression, test_correct_expressions3)
{
	string infix = "((5 * y) + 7 / (z + 2))";
	string postfix = "5y*7z2+/+";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = (double)7/4;

	Expression exp(infix, operands);
	EXPECT_EQ(result, exp.Get_res());
	EXPECT_EQ(postfix, exp.GetPostfix());
}

TEST(Expression, test_correct_expressions4)
{
	
	string infix = "2 * (x + 4) - 3 * y / (z - x)";
	string postfix = "2x4+*3y*zx-/-";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = 10;

	Expression exp(infix, operands);
	EXPECT_EQ(result, exp.Get_res());
	EXPECT_EQ(postfix, exp.GetPostfix());
}

TEST(Expression, test_correct_expressions5)
{
	string infix = "(x + y) * (x - y) / z + z";
	string postfix = "xy+xy-*z/z+";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = (double)5/2;

	Expression exp(infix, operands);
	EXPECT_EQ(result, exp.Get_res());
	EXPECT_EQ(postfix, exp.GetPostfix());
}

TEST(Expression, test_correct_expressions6)
{
	string infix = "(-0.5) * x / (-3.5 + 3) + 2 * (z - x)";
	string postfix = "00.5-x*03.5-3+/2zx-*+";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = 3;

	Expression exp(infix, operands);
	EXPECT_EQ(result, exp.Get_res());
	EXPECT_EQ(postfix, exp.GetPostfix());
}

TEST(Expression, test_correct_expressions7)
{
	string infix = "(xy - y) * x";
	string postfix = "xyy-x*";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"xy", 2} };
	double result = 2;

	Expression exp(infix, operands);
	EXPECT_EQ(result, exp.Get_res());
	EXPECT_EQ(postfix, exp.GetPostfix());
}

TEST(Expression, test_correct_expressions8)
{
	string infix = "-3 * 3";
	string postfix = "xy+xy-*z/z+";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = -9;
	Expression exp(infix, operands);
	EXPECT_EQ(result, exp.Get_res());
}

// closed bracket
TEST(Expression, test_incorrect_expressions1)
{
	string infix = "3 + 2 * x / (y - z))";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"xy", 2} };
	double result = 2;

	ASSERT_ANY_THROW(Expression exp(infix, operands));
	
}
// devision by 0
TEST(Expression, test_incorrect_expressions2)
{
	string infix = "(x + y) * y - z / y";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	ASSERT_ANY_THROW(Expression exp(infix, operands));
}

// missed operator
TEST(Expression, test_incorrect_expressions3)
{
	string infix = "((5 * y) x + 7 / (z + 2))";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };

	ASSERT_ANY_THROW(Expression exp(infix, operands));
}

// excess operator (undefined operator ++)
TEST(Expression, test_incorrect_expressions4)
{

	string infix = "2 ++ (x + 4) - 3 * y / (z - x)";
	string postfix = "2x4+*3y*zx-/-";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = 10;

	ASSERT_ANY_THROW(Expression exp(infix, operands));
}


// two dots
TEST(Expression, test_incorrect_expressions5)
{
	string infix = "(-0..5) * x / (-3.5 + 3) + 2 * (z - x)";
	string postfix = "00.5-x*03.5-3+/2zx-*+";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"z", 2} };
	double result = 3;

	ASSERT_ANY_THROW(Expression exp(infix, operands));
}


// missing brackets
TEST(Expression, test_incorrect_expressions6)
{
	string infix = "(3 - -0.5) * x";
	string postfix = "xyy-x*";
	map<string, double> operands = { {"x", 1}, {"y", 0}, {"xy", 2} };
	double result = 2;

	ASSERT_ANY_THROW(Expression exp(infix, operands));
}


