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

TEST(TArithmeticExpression, can_get_postfix)
{
    string str = "A+B*C";
    TArithmeticExpression expression(str);
    ASSERT_NO_THROW(expression.GetPostFix());
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
