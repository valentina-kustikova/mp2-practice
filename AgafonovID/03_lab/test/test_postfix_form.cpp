#include <gtest.h>
#include "postfix_form.h"

TEST(ArExpressionTest, convert_to_postfix) {
    ArExpression expr("3 + 4", ARRAY_STACK);
    std::vector<std::string> expected = { "3", "4", "+" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, convert_to_postfix_with_parentheses) {
    ArExpression expr("( 3 + 4 ) * 2", LIST_STACK);
    std::vector<std::string> expected = { "3", "4", "+", "2", "*" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, convert_to_postfix_complex_expr) {
    ArExpression expr("3 + 4 * 2 / ( 1 - 5 )", ARRAY_STACK);
    std::vector<std::string> expected = { "3", "4", "2", "*", "1", "5", "-", "/", "+" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, evaluate_simple_expression) {
    ArExpression expr("3 + 4", LIST_STACK);
    std::map<std::string, double> values;
    EXPECT_EQ(expr.evaluate(values), 7);
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

TEST(ArExpressionTest, convert_to_postfix_multiple_operators) {
    ArExpression expr("3 + 4 - 2 * 6 / 3", LIST_STACK);
    std::vector<std::string> expected = { "3", "4", "+", "2", "6", "*", "3", "/", "-" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

TEST(ArExpressionTest, Evaluate_NegativeNumbers) {
    ArExpression expr("-3 + 5", ARRAY_STACK);
    std::map<std::string, double> values;
    EXPECT_EQ(expr.evaluate(values), 2);
}

TEST(ArExpressionTest, evaluate_complex_expression) {
    ArExpression expr("( x + y ) * ( z - w )", LIST_STACK);
    std::map<std::string, double> values = { {"x", 2}, {"y", 3}, {"z", 5}, {"w", 1} };
    EXPECT_EQ(expr.evaluate(values), 20);
}

TEST(ArExpressionTest, convert_to_postfix_with_nested_parentheses) {
    ArExpression expr("( ( 1 + 2 ) * 3 ) - 4", ARRAY_STACK);
    std::vector<std::string> expected = { "1", "2", "+", "3", "*", "4", "-" };
    EXPECT_EQ(expr.getPostfix(), expected);
}

//разбить тесты отдельно постфикс отдельно вычисления + тесты готового выражения

TEST(ArExpressionTest, convert_to_postfix_1) {
    ArExpression expr("A+B", ARRAY_STACK);
    std::vector<std::string> expected = { "A", "B", "+"};
    EXPECT_EQ(expr.getPostfix(), expected);
}

