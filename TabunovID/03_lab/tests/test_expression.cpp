#include "expression.h"

#include <gtest.h>

TEST(Expression, checking_constructor)
{
    string str = "A+B*C";
    ASSERT_NO_THROW(Expression expression(str));
}

TEST(Expression, can_get_infix)
{
    string str = "A+B*C";
    Expression expression(str);
    ASSERT_NO_THROW(expression.GetInfix());
}

TEST(Expression, can_get_postfix)
{
    string str = "A+B*C";
    Expression expression(str);
    ASSERT_NO_THROW(expression.GetPostFix());
}

TEST(Expression, checking_correct_infix_form1)
{
    string str = "(A+B)*C";
    Expression expression(str);
    EXPECT_EQ(1, expression.isCorrectInfixExpression());
}

TEST(Expression, checking_correct_infix_form2)
{
    string str = "(A+B*C";
    Expression expression(str);
    EXPECT_EQ(0, expression.isCorrectInfixExpression());
}

TEST(Expression, can_calculate_expressions_from_letters)
{
    string str = "(A+B)*C";
    map<string, double> values = {
        {"A",1},{"B",2},{"C",4}
    };
    Expression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(Expression, can_calculate_expressions_from_digits)
{
    string str = "(1+2)*4";
    map<string, double> values = {
        {"A",1},{"B",2},{"C",4}
    };
    Expression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(Expression, can_calculate_expressions_from_words)
{
    string str = "(const+elem)*digit";
    map<string, double> values = {
        {"const",1},{"elem",2},{"digit",4}
    };
    Expression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(Expression, can_calculate_expressions_from_lettersand_numbers)
{
    string str = "(A+2)*B";
    map<string, double> values = {
        {"A",1},{"B",4}
    };
    Expression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(Expression, can_calculate_expressions_from_lettersand_numbersand_words)
{
    string str = "(A+2)*digit";
    map<string, double> values = {
        {"A",1},{"digit",4}
    };
    Expression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(Expression, cant_divide_by_zero)
{
    string str = "(A+2)/digit";
    map<string, double> values = {
        {"A",1},{"digit",0}
    };
    Expression expression(str);
    ASSERT_ANY_THROW(expression.Calculate(values));
}

TEST(Expression, checking_the_record)
{
    string str = "(a+b*c)*(c/d-e)";

    Expression expression(str);
    EXPECT_EQ("abc*+cd/e-*", expression.GetPostFix_str());
}

TEST(Expression, checking_the_record_with_words_and_numbers)
{
    string str = "(a+b*const)*(5/d-e)";

    Expression expression(str);
    EXPECT_EQ("abconst*+5d/e-*", expression.GetPostFix_str());
}