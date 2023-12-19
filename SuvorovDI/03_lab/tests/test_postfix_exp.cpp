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
	std::string orig = "x { y /(Sd ^ z)* dfs";
	ArithmeticExp exp(orig);

	EXPECT_EQ(exp.GetPostfix(), "there are invalid characters...");
}

TEST(ArithmeticExp, cannot_create_expression_with_invalid_brackets) {
	std::string orig = "x ( y /(Sd - z))))* dfs";
	ArithmeticExp exp(orig);

	EXPECT_EQ(exp.GetPostfix(), "there are invalid characters...");
}

TEST(ArithmeticExp, cammot_create_empty_expression) {
	std::string orig = "";
	ArithmeticExp exp(orig);

	EXPECT_EQ(exp.GetPostfix(), "there are invalid characters...");
}


TEST(ArithmeticExp, test_correct_conversion) {
	std::string orig = "x +y /(Sd - z)* dfs";
	std::string postfix = "x y Sd z - / dfs * + ";

	ArithmeticExp exp(orig);
	EXPECT_EQ(exp.GetPostfix(), postfix);
}

TEST(ArithmeticExp, test_correct_calculation) {
	std::string orig = "a +b /(c - d)* e";

	ArithmeticExp exp(orig);

	std::vector<std::string> operands = exp.GetOperands();

	std::map<std::string, double> values;
	double val = 1.0;
	for (const std::string op : operands) {
		values[op] = val;
		val += 1;
	}
	EXPECT_EQ(exp.Calculate(values), -9.0);
}