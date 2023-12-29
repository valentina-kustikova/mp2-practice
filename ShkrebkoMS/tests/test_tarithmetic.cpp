#include "tarithmetic.h"

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

TEST(TArithmeticExpression, cheking_correct_infix_form1)
{
    string str = "(A+B)*C";
    TArithmeticExpression expression(str);
    EXPECT_EQ(1, expression.isCorrectInfixExpression());
}

TEST(TArithmeticExpression, cheking_correct_infix_form2)
{
    string str = "A+B*C(";
    TArithmeticExpression expression(str);
    EXPECT_EQ(0, expression.isCorrectInfixExpression());
}
TEST(TArithmeticExpression, can_get_postfix)
{
    string str = "A+B*C";
    TArithmeticExpression expression(str);
    ASSERT_NO_THROW(expression.GetPostfix());
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_postfix)
{
    string str = "A+B*C";
    string postfix = "ABC*+";
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix, expression.GetPostfix_str());
}

TEST(TArithmeticExpression, can_calculate_expressions_letters)
{
    string str = "A+B*C";
    map<string, double> values = {
        {"A",1},{"B",2},{"C",4}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(9, expression.Calculate(values));
}

TEST(TArithmeticExpression, checking_constructor_2)
{
    string str = "(1+2)/(3+3*4)-5*6";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_postfix_2)
{
    string str = "(1+2)/(3+3*4)-5*6";
    string postfix = "12+334*+/56*-";;
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix, expression.GetPostfix_str());
}


TEST(TArithmeticExpression, checking_constructor_3)
{
    string str = "(a+b*c)/(c/d-e)";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_postfix_3)
{
    string str = "(a+b*c)/(c/d-e)";
    string postfix = "abc*+cd/e-/";
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix, expression.GetPostfix_str());
}



