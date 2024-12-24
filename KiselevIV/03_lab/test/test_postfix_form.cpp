#include "postfix_form.h"
#include <gtest.h>

TEST(Postfix_form, can_create_postfix_on_arr_stack)
{
    ASSERT_NO_THROW(PostfixForm tmp("A+B", 'A'));
}

TEST(Postfix_form, can_create_postfix_on_Lstack)
{
    ASSERT_NO_THROW(PostfixForm bob("A+B", 'L'));
}

TEST(Postfix_form, can_get_infix_on_Astack)
{
    PostfixForm bob("1+3", 'A');
    EXPECT_EQ(bob.getInfix(), "1+3");
}

TEST(Postfix_form, can_get_infix_on_Lstack)
{
    PostfixForm bob("1+3", 'L');
    EXPECT_EQ(bob.getInfix(), "1+3");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Astack)
{
    PostfixForm bob("1+3", 'A');
    EXPECT_EQ(bob.getPostfix(), "1 3 + ");
}

TEST(Postfix_form, can_turn_infix_to_postfix_on_Lstack)
{
    PostfixForm bob("1+3", 'L');
    EXPECT_EQ(bob.getPostfix(), "1 3 + ");
}

TEST(Postfix_form, can_calculate_on_Astack)
{
    PostfixForm bob("1+3", 'A');
    ASSERT_NO_THROW(bob.calculate());
}

TEST(Postfix_form, can_calculate_on_Lstack)
{
    PostfixForm bob("1+3", 'L');
    ASSERT_NO_THROW(bob.calculate());
}

TEST(Postfix_form, calculation_is_correct_on_Astack)
{
    PostfixForm bob("1+3", 'A');
    EXPECT_EQ(bob.calculate(), 4);
}

TEST(Postfix_form, calculation_is_correct_on_Lstack)
{
    PostfixForm bob("1+3", 'L');
    EXPECT_EQ(bob.calculate(), 4);
}