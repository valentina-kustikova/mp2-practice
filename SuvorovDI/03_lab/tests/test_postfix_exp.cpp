#include "postfix_exp.h"
#include "stack.h"
#include <gtest.h>
#include <vector>
#include <map>

TEST(ArithmeticExp, can_create_expression) {
	std::string orig = "x +y /(Sd - z)* dfs";

	ASSERT_NO_THROW(ArithmeticExp::ArithmeticExp(orig));
}

TEST(ArithmeticExp, cannot_create_expression_with_invalid_operations) {
	std::string orig = "x { Y";

	ASSERT_ANY_THROW(ArithmeticExp exp(orig));
}

TEST(ArithmeticExp, cannot_create_expression_with_invalid_brackets) {
	std::string orig = "x * )a+b( ";

	ASSERT_ANY_THROW(ArithmeticExp exp(orig));
}

TEST(ArithmeticExp, cannot_create_empty_expression) {
	std::string orig = "";

	ASSERT_ANY_THROW(ArithmeticExp exp(orig));
}

TEST(ArithmeticExp, test_convert_to_postfix_simple_addition_expression) {
	std::string orig = "x +y";
	std::string postfix = "x y + ";

	ArithmeticExp exp(orig);
	EXPECT_EQ(exp.GetPostfix(), postfix);
}

TEST(ArithmeticExp, test_calculate_simple_addition_expression_) {
	std::string orig = "x + y";

	ArithmeticExp exp(orig);

	std::vector<std::string> operands = exp.GetOperands();

	std::map<std::string, double> values;
	double val = 1.0;
	for (const std::string op : operands) {
		values[op] = val;
		val += 1;
	}
	EXPECT_EQ(exp.Calculate(values), 3.0);
}

TEST(ArithmeticExp, test_convert_to_postfix_simple_subtruction_expression) {
	std::string orig = "x -y";
	std::string postfix = "x y - ";

	ArithmeticExp exp(orig);
	EXPECT_EQ(exp.GetPostfix(), postfix);
}

TEST(ArithmeticExp, test_calculate_simple_subtruction_expression) {
	std::string orig = "x - y";

	ArithmeticExp exp(orig);

	std::vector<std::string> operands = exp.GetOperands();

	std::map<std::string, double> values;
	double val = 1.0;
	for (const std::string op : operands) {
		values[op] = val;
		val += 1;
	}
	EXPECT_EQ(exp.Calculate(values), -1.0);
}

TEST(ArithmeticExp, test_convert_to_postfix_expression_with_dublicated_operand) {
	std::string orig = "(x -y)*x";
	std::string postfix = "x y - x * ";

	ArithmeticExp exp(orig);
	EXPECT_EQ(exp.GetPostfix(), postfix);
}

TEST(ArithmeticExp, test_calculate_expression_with_dublicated_operand) {
	std::string orig = "(x -y)*x";

	ArithmeticExp exp(orig);

	std::vector<std::string> operands = exp.GetOperands();

	std::map<std::string, double> values;
	
	values[operands[0]] = 4;
	values[operands[1]] = 6;

	EXPECT_EQ(exp.Calculate(values), -8.0);
}

TEST(ArithmeticExp, test_convert_to_postfix_simple_division_expression) {
	std::string orig = "x /y";
	std::string postfix = "x y / ";

	ArithmeticExp exp(orig);
	EXPECT_EQ(exp.GetPostfix(), postfix);
}

TEST(ArithmeticExp, test_calculate_simple_division_expression) {
	std::string orig = "x / y";

	ArithmeticExp exp(orig);

	std::vector<std::string> operands = exp.GetOperands();

	std::map<std::string, double> values;
	double val = 1.0;
	for (const std::string op : operands) {
		values[op] = val;
		val += 1;
	}
	EXPECT_EQ(exp.Calculate(values), 0.5);
}

TEST(ArithmeticExp, test_zero_division) {
	std::string orig = "x / y";

	ArithmeticExp exp(orig);

	std::vector<std::string> operands = exp.GetOperands();

	std::map<std::string, double> values;
	values[operands[0]] = 4.0;
	values[operands[1]] = 0.0;

	ASSERT_ANY_THROW(exp.Calculate(values));
}

TEST(ArithmeticExp, test_convert_to_postfix_fully_expression) {
	std::string orig = "a + (b-c)/(a-c) - d*b";
	std::string postfix = "a b c - a c - / + d b * - ";

	ArithmeticExp exp(orig);
	EXPECT_EQ(exp.GetPostfix(), postfix);
}

TEST(ArithmeticExp, test_calculate_fully_expression) {
	std::string orig = "a + (b-c)/(a-c) - d*b";

	ArithmeticExp exp(orig);

	std::vector<std::string> operands = exp.GetOperands();

	std::map<std::string, double> values;
	double val = 1.0;
	for (const std::string op : operands) {
		values[op] = val;
		val += 1;
	}
	EXPECT_EQ(exp.Calculate(values), -0.5);
}