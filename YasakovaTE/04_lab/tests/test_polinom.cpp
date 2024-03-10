#include <gtest.h>
#include "talgorithm.h"
#include <iostream>

using namespace std;

TEST(TalgorithmTest, SplitTalgorithm_ValidExpression) {
    Talgorithm talgorithm;
    string expression = "3+5*2";
    ASSERT_NO_THROW(talgorithm.splitTalgorithm(expression), invalid_argument);
}

TEST(TalgorithmTest, GetPrecedence_ValidOperatorPrecedence) {
    Talgorithm talgorithm;
    string op = "+";
    ASSERT_EQ(talgorithm.getPrecedence(op), 1);
}

TEST(TalgorithmTest, IsOperator_InvalidToken) {
    Talgorithm talgorithm;
    string token = "!";
    ASSERT_FALSE(talgorithm.isOperator(token));
}

TEST(TalgorithmTest, IsValidTalgorithm_InvalidStartOperator) {
    Talgorithm talgorithm;
    vector<string> infixTalgorithm = { "+", "2", "3" };
    ASSERT_THROW(talgorithm.isValidTalgorithm(infixTalgorithm), invalid_argument);
}

TEST(TalgorithmTest, IsValidTalgorithm_InvalidEndOperator) {
    Talgorithm talgorithm;
    vector<string> infixTalgorithm = { "2", "3", "+" };
    ASSERT_THROW(talgorithm.isValidTalgorithm(infixTalgorithm), invalid_argument);
}

TEST(TalgorithmTest, IsValidTalgorithm_ConsecutiveOperators) {
    Talgorithm talgorithm;
    vector<string> infixTalgorithm = { "2", "+", "-", "3" };
    ASSERT_THROW(talgorithm.isValidTalgorithm(infixTalgorithm), invalid_argument);
}

TEST(TalgorithmTest, IsValidTalgorithm_DivisionByZero) {
    Talgorithm talgorithm;
    vector<string> infixTalgorithm = { "2", "/", "0" };
    ASSERT_THROW(talgorithm.isValidTalgorithm(infixTalgorithm), invalid_argument);
}

TEST(TalgorithmTest, InfixToPostfix_ValidExpression) {
    Talgorithm talgorithm;
    vector<string> infixTalgorithm = { "2", "+", "3" };
    ASSERT_NO_THROW(talgorithm.infixToPostfix(infixTalgorithm));
}

TEST(TalgorithmTest, EvaluatePostfixTalgorithm_MissingOperandValue) {
    Talgorithm talgorithm;
    map<string, double> operandValues = { {"x", 5.0} };
    Stack<string> postfixTalgorithm;
    postfixTalgorithm.push("x");
    postfixTalgorithm.push("y");
    postfixTalgorithm.push("+");
    ASSERT_DOUBLE_EQ(talgorithm.evaluatePostfixTalgorithm(operandValues, postfixTalgorithm), 0.0);
}

TEST(TalgorithmTest, EvaluatePostfixTalgorithm_DivisionByZero) {
    Talgorithm talgorithm;
    map<string, double> operandValues = { {"x", 1.0}, {"y", 0.0} };
    Stack<string> postfixTalgorithm;
    postfixTalgorithm.push("x");
    postfixTalgorithm.push("y");
    postfixTalgorithm.push("/");
    ASSERT_DOUBLE_EQ(talgorithm.evaluatePostfixTalgorithm(operandValues, postfixTalgorithm), 0.0);
}

TEST(TalgorithmTest, EvaluatePostfixTalgorithm_InvalidOperator) {
    Talgorithm talgorithm;
    map<string, double> operandValues = { {"x", 2.0}, {"y", 3.0} };
    Stack<string> postfixTalgorithm;
    postfixTalgorithm.push("x");
    postfixTalgorithm.push("y");
    postfixTalgorithm.push("%");
    ASSERT_DOUBLE_EQ(talgorithm.evaluatePostfixTalgorithm(operandValues, postfixTalgorithm), 0.0);
}

TEST(TalgorithmTest, EvaluatePostfixTalgorithm_ValidExpression) {
    Talgorithm talgorithm;
    map<string, double> operandValues = { {"x", 2.0}, {"y", 3.0} };
    Stack<string> postfixTalgorithm;
    postfixTalgorithm.push("x");
    postfixTalgorithm.push("y");
    postfixTalgorithm.push("+");
    double result = talgorithm.evaluatePostfixTalgorithm(operandValues, postfixTalgorithm);
    ASSERT_DOUBLE_EQ(result, 5.0);
}
















