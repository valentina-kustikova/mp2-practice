#include "TArithmeticExpression.h"

#include <gtest.h>

TEST(TArithmeticExpression, checking_constructor)
{
    string str = "A+B*C";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, can_get_infix)
{
    string str = "A+B*C";
    TArithmeticExpression expression(str);
    ASSERT_NO_THROW(expression.GetInfix());
}

TEST(TArithmeticExpression, can_get_postfix)
{
    string str = "A+B*C";
    TArithmeticExpression expression(str);
    ASSERT_NO_THROW(expression.GetPostFix());
}

TEST(TArithmeticExpression, chcking_correct_infix_form1)
{
    string str = "(A+B)*C";
    TArithmeticExpression expression(str);
    EXPECT_EQ(1,expression.isCorrectInfixExpression());
}

TEST(TArithmeticExpression, chcking_correct_infix_form2)
{
    string str = "(A+B*C";
    TArithmeticExpression expression(str);
    EXPECT_EQ(0, expression.isCorrectInfixExpression());
}

TEST(TArithmeticExpression, can_calculate_expressions_from_letters)
{
    string str = "(A+B)*C";
    map<string, double> values = {
        {"A",1},{"B",2},{"C",4}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(TArithmeticExpression, can_calculate_expressions_from_digits)
{
    string str = "(1+2)*4";
    map<string, double> values = {
        {"A",1},{"B",2},{"C",4}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(TArithmeticExpression, can_calculate_expressions_from_words)
{
    string str = "(const+elem)*digit";
    map<string, double> values = {
        {"const",1},{"elem",2},{"digit",4}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(TArithmeticExpression, can_calculate_expressions_from_lettersand_numbers)
{
    string str = "(A+2)*B";
    map<string, double> values = {
        {"A",1},{"B",4}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(TArithmeticExpression, can_calculate_expressions_from_lettersand_numbersand_words)
{
    string str = "(A+2)*digit";
    map<string, double> values = {
        {"A",1},{"digit",4}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(12, expression.Calculate(values));
}

TEST(TArithmeticExpression, cant_divide_by_zero)
{
    string str = "(A+2)/digit";
    map<string, double> values = {
        {"A",1},{"digit",0}
    };
    TArithmeticExpression expression(str);
    ASSERT_ANY_THROW(expression.Calculate(values));
}


