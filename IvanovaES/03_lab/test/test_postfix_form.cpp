#include "postfix_form.h"
#include <gtest.h>

TEST(PostfixForm, can_create_postfix_form)
{
    ASSERT_NO_THROW(PostfixForm pf("2+3"));
}

TEST(PostfixForm, can_calculate_addition)
{
    PostfixForm pf("2+3");
    EXPECT_DOUBLE_EQ(5.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_subtraction)
{
    PostfixForm pf("8-3");
    EXPECT_DOUBLE_EQ(5.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_multiplication)
{
    PostfixForm pf("4*3");
    EXPECT_DOUBLE_EQ(12.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_division)
{
    PostfixForm pf("10/2");
    EXPECT_DOUBLE_EQ(5.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_expression_with_operator_priority)
{
    PostfixForm pf("2+3*4");
    EXPECT_DOUBLE_EQ(14.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_expression_with_parentheses)
{
    PostfixForm pf("(2+3)*4");
    EXPECT_DOUBLE_EQ(20.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_expression_with_nested_parentheses)
{
    PostfixForm pf("(2+(3*4))");
    EXPECT_DOUBLE_EQ(14.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_expression_with_several_operations)
{
    PostfixForm pf("10+6/2-3");
    EXPECT_DOUBLE_EQ(10.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_decimal_numbers)
{
    PostfixForm pf("2.5+1.5");
    EXPECT_DOUBLE_EQ(4.0, pf.Calculate());
}

TEST(PostfixForm, can_calculate_expression_with_decimal_numbers)
{
    PostfixForm pf("2.5*2+1.5");
    EXPECT_DOUBLE_EQ(6.5, pf.Calculate());
}

TEST(PostfixForm, can_calculate_division_with_decimal_result)
{
    PostfixForm pf("5/2");
    EXPECT_DOUBLE_EQ(2.5, pf.Calculate());
}

TEST(PostfixForm, can_calculate_expression_with_left_associativity)
{
    PostfixForm pf("8/4/2");
    EXPECT_DOUBLE_EQ(1.0, pf.Calculate());
}

TEST(PostfixForm, throws_when_divide_by_zero)
{
    PostfixForm pf("5/0");
    ASSERT_ANY_THROW(pf.Calculate());
}





