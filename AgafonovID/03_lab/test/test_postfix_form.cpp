#include <gtest.h>
#include "postfix_form.h"

TEST(ArExpressionTest, convert_to_postfix_simple) {
    ArExpression expr("3 + 4", ARRAY_STACK);
    std::vector<std::string> expected = { "3", "4", "+" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, convert_to_postfix_with_parentheses) {
    ArExpression expr("( 3 + 4 ) * 2", LIST_STACK);
    std::vector<std::string> expected = { "3", "4", "+", "2", "*" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, convert_to_postfix_multiple_operators) {
    ArExpression expr("3 + 4 - 2 * 6 / 3", LIST_STACK);
    std::vector<std::string> expected = { "3", "4", "+", "2", "6", "*", "3", "/", "-" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, convert_to_postfix_with_nested_parentheses) {
    ArExpression expr("( ( 1 + 2 ) * 3 ) - 4", ARRAY_STACK);
    std::vector<std::string> expected = { "1", "2", "+", "3", "*", "4", "-" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, evaluate_with_variables) {
    ArExpression expr("x * y + 2", ARRAY_STACK);
    std::map<std::string, double> values = { {"x", 3}, {"y", 4} };
    EXPECT_EQ(expr.evaluate(values), 14);
}

TEST(ArExpressionTest, evaluate_division_by_zero) {
    ArExpression expr("4 / 0", LIST_STACK);
    std::map<std::string, double> values;
    EXPECT_THROW(expr.evaluate(values), std::exception);
}

TEST(ArExpressionTest, evaluate_negative_numbers) {
    ArExpression expr("-3 + 5", ARRAY_STACK);
    std::map<std::string, double> values;
    EXPECT_EQ(expr.evaluate(values), 2);
}

TEST(ArExpressionTest, evaluate_complex_expression) {
    ArExpression expr("( x + y ) * ( z - w )", LIST_STACK);
    std::map<std::string, double> values = { {"x", 2}, {"y", 3}, {"z", 5}, {"w", 1} };
    EXPECT_EQ(expr.evaluate(values), 20);
}

TEST(ArExpressionTest, convert_to_postfix1) {
    ArExpression expr("A + B", ARRAY_STACK);
    std::vector<std::string> expected = { "A", "B", "+" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, evaluate1) {
    ArExpression expr("A + B", LIST_STACK);
    std::map<std::string, double> values = { {"A", 1}, {"B", 3} };
    EXPECT_EQ(expr.evaluate(values), 4);
}

TEST(ArExpressionTest, convert_to_postfix2) {
    ArExpression expr("A - B", ARRAY_STACK);
    std::vector<std::string> expected = { "A", "B", "-" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, evaluate2) {
    ArExpression expr("A - B", LIST_STACK);
    std::map<std::string, double> values = { {"A", 1}, {"B", 3} };
    EXPECT_EQ(expr.evaluate(values), -2);
}

TEST(ArExpressionTest, convert_to_postfix3) {
    ArExpression expr("A - B * (A + C)", ARRAY_STACK);
    std::vector<std::string> expected = { "A", "B", "A", "C", "+", "*", "-" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, evaluate3) {
    ArExpression expr("A - B * (A + C)", LIST_STACK);
    std::map<std::string, double> values = { {"A", 1}, {"B", 2}, {"C", 3} };
    EXPECT_EQ(expr.evaluate(values), -7);
}

TEST(ArExpressionTest, convert_to_postfix4) {
    ArExpression expr("(A - B) / (C - A) * (K + B) + A", ARRAY_STACK);
    std::vector<std::string> expected = { "A", "B", "-", "C", "A", "-", "/", "K", "B", "+", "*", "A", "+" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, evaluate4) {
    ArExpression expr("(A - B) / (C - A) * (K + B) + A", LIST_STACK);
    std::map<std::string, double> values = { {"A", 1}, {"B", 3}, {"C", 2}, {"K", -2} };
    EXPECT_EQ(expr.evaluate(values), -1);
}
