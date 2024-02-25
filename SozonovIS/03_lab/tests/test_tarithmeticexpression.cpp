#include "tarithmeticexpression.h"
#include <gtest.h>

TEST(TArithmeticExpression, throws_when_got_emplty_string) {
	ASSERT_ANY_THROW(TArithmeticExpression expr(""));
}

TEST(TArithmeticExpression, throws_when_arithmetic_expression_start_with_operator) {
	ASSERT_ANY_THROW(TArithmeticExpression expr("+A-B"));
}

TEST(TArithmeticExpression, throws_when_operator_after_opening_bracket) {
	ASSERT_ANY_THROW(TArithmeticExpression expr("A*(-B+C)"));
}

TEST(TArithmeticExpression, throws_when_operator_before_closing_bracket) {
	ASSERT_ANY_THROW(TArithmeticExpression expr("A*(B+C-)"));
}

TEST(TArithmeticExpression, throws_when_division_by_zero) {
	ASSERT_ANY_THROW(TArithmeticExpression expr("A+B/0"));
}

TEST(TArithmeticExpression, throws_when_repeat_operator) {
	ASSERT_ANY_THROW(TArithmeticExpression expr("A++B"));
}

TEST(TArithmeticExpression, can_get_infix) {
	std::string str = "num1+A/2-B*(num2-num3)";
	TArithmeticExpression expr("num1+A/2-B*(num2-num3)");
	EXPECT_EQ(str, expr.GetInfix());
}

TEST(TArithmeticExpression, can_get_postfix) {
	TArithmeticExpression expr("num1+A/2-B*(num2-num3)");
	std::string str = "num1 A 2 / + B num2 num3 - * -";
	EXPECT_EQ(str, expr.GetPostfix());
}

TEST(TArithmeticExpression, can_get_operands) {
	TArithmeticExpression expr("num1+A/2-B*(num2-num3)");
	ASSERT_NO_THROW(std::vector<std::string> operands = expr.GetOperands());
}

TEST(TArithmeticExpression, can_set_values) {
	TArithmeticExpression expr("num1+A/2-B*(num2-num3)");
	ASSERT_NO_THROW(std::vector<std::string> operands = expr.GetOperands());
}

TEST(TArithmeticExpression, can_calculate_with_single_character_operands) {
	TArithmeticExpression expr("A+B*(C-D)");
	std::vector<std::string> operands = expr.GetOperands();
	std::map<std::string, double> values = { {"A", 3}, {"B", 1}, {"C", 4}, {"D", 2}};
	EXPECT_EQ(5, expr.Calculate(values));
}

TEST(TArithmeticExpression, can_calculate_with_multi_character_operands) {
	TArithmeticExpression expr("num1+A*(num2-B)");
	std::vector<std::string> operands = expr.GetOperands();
	std::map<std::string, double> values = { {"A", 1}, {"B", 2}, {"num1", 3}, {"num2", 4}};
	EXPECT_EQ(5, expr.Calculate(values));
}

TEST(TArithmeticExpression, can_calculate_with_constants) {
	TArithmeticExpression expr("3.14*num1+A*(num2-2/B)");
	std::vector<std::string> operands = expr.GetOperands();
	std::map<std::string, double> values = {{"A", 1}, {"B", 2}, {"num1", 3}, {"num2", 4}, {"3.14", 3.14}, {"2", 2}};
	EXPECT_EQ(12.42, expr.Calculate(values));
}

TEST(TArithmeticExpression, throws_when_zero_division) {
	TArithmeticExpression expr("A/B");
	std::vector<std::string> operands = expr.GetOperands();
	std::map<std::string, double> values = { {"A", 1}, {"B", 0}};
	ASSERT_ANY_THROW(expr.Calculate(values));
}

TEST(TArithmeticExpression, unary_minus_in_start_of_expression) {
	TArithmeticExpression expr("-5+4");
	std::vector<std::string> operands = expr.GetOperands();
	std::map<std::string, double> values = expr.SetValues();
	double result = expr.Calculate(values);
	EXPECT_EQ(result, -1);
}

TEST(TArithmeticExpression, can_calculate_an_expression) {
	TArithmeticExpression expr("A+(C-A)/(B-A)*K-A/B");
	std::vector<std::string> operands = expr.GetOperands();
	std::map<std::string, double> values = { {"A", 1}, {"B", 2}, {"C", 3}, {"K", 4}};
	EXPECT_EQ(8.5, expr.Calculate(values));
}