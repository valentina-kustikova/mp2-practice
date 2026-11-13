#include "postfix_form.h"
#include <gtest/gtest.h>

TEST(ArithmeticExpression, can_create_correct_ar_exp) {
	EXPECT_NO_THROW(ArithmeticExpression("(a+b)*c"));
}

TEST(ArithmeticExpression, unfinished_parentheses_sequence) {
	EXPECT_ANY_THROW(ArithmeticExpression("(a+b))"));
}

TEST(ArithmeticExpression, incorrect_parentheses_sequence) {
	EXPECT_ANY_THROW(ArithmeticExpression("(a+(b)"));
}

TEST(ArithmeticExpression, missing_operator_between_brackets) {
	EXPECT_ANY_THROW(ArithmeticExpression("(a+b)(c-d)"));
}

TEST(ArithmeticExpression, cant_start_with_not_unary_minus_operation) {
	EXPECT_ANY_THROW(ArithmeticExpression("*a+(b+c)"));
}

TEST(ArithmeticExpression, can_start_with_unary_minus) {
	EXPECT_NO_THROW(ArithmeticExpression("-a+(b+c)"));
}

TEST(ArithmeticExpression, operand_right_before_bracket_case) {
	EXPECT_ANY_THROW(ArithmeticExpression("a(b+c)"));
}

TEST(ArithmeticExpression, operand_right_after_bracket_case) {
	EXPECT_ANY_THROW(ArithmeticExpression("(b+c)a"));
}

TEST(ArithmeticExpression, two_operations_in_a_row) {
	EXPECT_ANY_THROW(ArithmeticExpression("a(b+-c)"));
}

TEST(ArithmeticExpression, two_operands_in_a_row) {
	EXPECT_ANY_THROW(ArithmeticExpression("a(bc-d)"));
}

TEST(ArithmeticExpression, operation_right_after_bracket) {
	EXPECT_ANY_THROW(ArithmeticExpression("a(*b+c)"));
}

TEST(ArithmeticExpression, can_use_unary_minus_after_bracket) {
	EXPECT_NO_THROW(ArithmeticExpression("a*(-b+c)"));
}

TEST(ArithmeticExpression, operation_right_before_bracket) {
	EXPECT_ANY_THROW(ArithmeticExpression("a(*b+c/)"));
}

TEST(ArithmeticExpression, cant_use_minus_before_bracket) {
	EXPECT_ANY_THROW(ArithmeticExpression("a(b+c-)"));
}

TEST(ArithmeticExpression, cant_end_with_any_operation) {
	EXPECT_ANY_THROW(ArithmeticExpression("-a+(b+c)+"));
}

TEST(isOperation, isOperation_is_true_on_operation) {
	EXPECT_TRUE(isOperation('-'));
}

TEST(isOperation, isOperation_is_false_on_operand) {
	EXPECT_FALSE(isOperation('a'));
}

TEST(isOperand, isOperand_is_false_on_operation) {
	EXPECT_FALSE(isOperand('-'));
}

TEST(isOperand, isOperand_is_true_on_operand) {
	EXPECT_TRUE(isOperand('a'));
}

TEST(ArithmeticExpression, can_get_postfix_form) {
	ArithmeticExpression ae("a + b");
	EXPECT_NO_THROW(ae.GetPostfixForm());
}
TEST(ArithmeticExpression, correct_postfix_form_on_simple_expression) {
	ArithmeticExpression ae("a - b");
	EXPECT_EQ(ae.GetPostfixForm(), "ab-");
}
TEST(ArithmeticExpression, correct_postfix_form_on_expression_with_brackets) {
	ArithmeticExpression ae("(a - b) + (c / d)");
	EXPECT_EQ(ae.GetPostfixForm(), "ab-cd/+");
}

TEST(ArithmeticExpression, correct_postfix_form_on_expression_with_unary_minus_in_the_beggining) {
	ArithmeticExpression ae("-a - b");
	EXPECT_EQ(ae.GetPostfixForm(), "a-b-");
}

TEST(ArithmeticExpression, correct_postfix_form_on_expression_with_unary_minus_in_the_middle) {
	ArithmeticExpression ae("a + b / (-c * d)");
	EXPECT_EQ(ae.GetPostfixForm(), "ab0cd*-/+");
}

TEST(ArithmeticExpression, correct_postfix_form_multiplication_early_then_addition) {
	ArithmeticExpression ae("a + b * c");
	EXPECT_EQ(ae.GetPostfixForm(), "abc*+");
}

TEST(ArithmeticExpression, correct_postfix_form_of_complicated_expression) {
	ArithmeticExpression ae("(a * b + c) - (a / (f - g)) - ((a + b) * c)");
	EXPECT_EQ(ae.GetPostfixForm(), "ab*c+afg-/-ab+c*-");
}

TEST(ArithmeticExpression, can_compute_on_correct_data) {
	ArithmeticExpression ae("a + b / c");
	vector<pair<char, double>> v = { {'a', 12.0}, {'b', 5.0}, {'c', 2.0} };
	EXPECT_NO_THROW(ae.compute(v));
}

TEST(ArithmeticExpression, cant_compute_on_incorrect_data) {
	ArithmeticExpression ae("a + b / c");
	vector<pair<char, double>> v = { {'a', 12.0}, {'b', 5.0}, {'c', 0.0} };
	EXPECT_ANY_THROW(ae.compute(v));
}

TEST(ArithmeticExpression, compute_is_correct_simple) {
	ArithmeticExpression ae("a + b / c");
	vector<pair<char, double>> v = { {'a', 12.0}, {'b', 6.0}, {'c', 2.0} };
	EXPECT_EQ(ae.compute(v), 15.0);
}

TEST(ArithmeticExpression, compute_is_correct_with_unary_minus_in_the_middle) {
	ArithmeticExpression ae("a + b / (-c)");
	vector<pair<char, double>> v = { {'a', 12.0}, {'b', 6.0}, {'c', 2.0} };
	EXPECT_EQ(ae.compute(v), 9.0);
}

TEST(ArithmeticExpression, compute_is_correct_with_unary_minus_in_the_begginig) {
	ArithmeticExpression ae("-a + b / c");
	vector<pair<char, double>> v = { {'a', 12.0}, {'b', 6.0}, {'c', 2.0} };
	EXPECT_EQ(ae.compute(v), -9.0);
}

TEST(ArithmeticExpression, compute_is_correct_complicated) {
	ArithmeticExpression ae("(a * b + c) - (a / (f - g)) - ((a + b) * c)");
	vector<pair<char, double>> v = { {'a', 1.0}, {'b', 2.0}, {'c', 3.0},
									 {'g', 4.0}, {'f', 5.0} };
	EXPECT_EQ(ae.compute(v), -5.0);
}