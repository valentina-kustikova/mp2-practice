#include "TArithmeticExpression.h"

#include <gtest.h>


TEST(TArithmeticExpression, checking_constructor_1)
{
    string str = "A+B*C";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}
//-----error--------------------------------------------------------
TEST(TArithmeticExpression, error_in_parentheses_constructor_check_1)
{
    string str = "((a*p)/2";
    ASSERT_ANY_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, error_in_parentheses_constructor_check_2)
{
    string str = "(a*c-(b-1))*s)";
    ASSERT_ANY_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, error_multiple_statements_in_a_row_checking_the_constructor)
{
    string str = "(const+A)*c-*b";
    ASSERT_ANY_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, error_multiple_statements_in_a_row_checking_the_constructor_2)
{
    string str = "a-b-1++2";
    ASSERT_ANY_THROW(TArithmeticExpression expression(str));
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
//--------------------------------------------------------------

//________________A+B*C_______________
TEST(TArithmeticExpression, can_get_infix_1)
{
    string str = "A+B*C";
    TArithmeticExpression expression(str);
    ASSERT_NO_THROW(expression.GetInfix());
}

TEST(TArithmeticExpression, can_get_postfix_1)
{
    string str = "A+B*C";
    TArithmeticExpression expression(str);
    ASSERT_NO_THROW(expression.GetPostFix_str());
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_a_postfix_expression_1)
{
    string str = "A+B*C";
    string postfix = "ABC*+";
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix,expression.GetPostFix_str());
}

TEST(TArithmeticExpression, can_calculate_expressions_from_letters_1)
{
    string str = "A+B*C";
    map<string, double> values = {
        {"A",1},{"B",2},{"C",4}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(9, expression.Calculate(values));
}
//______________________________________________________________

//________________(1+2)/(4+4*6.5)-5.5*4.4_______________
TEST(TArithmeticExpression, checking_constructor_2)
{
    string str = "(1+2)/(4+4*6.5)-5.5*4.4";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_a_postfix_expression_2)
{
    string str = "(1+2)/(4+4*6.5)-5.5*4.4";
    string postfix = "12+446.5*+/5.54.4*-";;
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix, expression.GetPostFix_str());
}

TEST(TArithmeticExpression, can_calculate_expressions_from_digits)
{
    string str = "(1+2)/(4+4*6.5)-5.5*4.4";
    
    TArithmeticExpression expression(str);
    EXPECT_EQ(-24.1, expression.Calculate());
}
//______________________________________________________________

//________________(a+b*c)*(c/d−e)_______________
TEST(TArithmeticExpression, checking_constructor_3)
{
    string str = "(a+b*c)*(c/d-e)";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_a_postfix_expression_3)
{
    string str = "(a+b*c)*(c/d-e)";
    string postfix = "abc*+cd/e-*";
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix, expression.GetPostFix_str());
}

TEST(TArithmeticExpression, can_calculate_expressions_from_words)
{
    string str = "(a+b*c)*(c/d-e)";
    map<string, double> values = {
        {"a",10},{"b",4.7},{"c",8},{"d",4},{"e",0.8}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(57.12, expression.Calculate(values));
}
//__________________________________________________________

//________________((const+5)*2)-(b+4)_______________
TEST(TArithmeticExpression, checking_constructor_4)
{
    string str = "((const+5)*2)-(b+4)";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, can_calculate_expressions_from_lettersand_numbers_4)
{
    string str = "((const+5)*2)-(b+4)";
    map<string, double> values = {
        {"const",11},{"b",8}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(20, expression.Calculate(values));
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_a_postfix_expression_4)
{
    string str = "((const+5)*2)-(b+4)";
    string postfix = "const5+2*b4+-";
    map<string, double> values = {
        {"const",11},{"b",8}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix, expression.GetPostFix_str());
}
//__________________________________________________________

//________________((10*5+20)/3-15)*2+((7-3)*8+(10/2))-20_______________
TEST(TArithmeticExpression, checking_constructor_5)
{
    string str = "((number*5+20)/3-15)*2+((7-a)*8+(10/2))-20";
    ASSERT_NO_THROW(TArithmeticExpression expression(str));
}

TEST(TArithmeticExpression, can_calculate_expressions_from_lettersand_numbers_5)
{
    string str = "((number*5+20)/3-15)*2+((7-a)*8+(10/2))-20";
    map<string, double> values = {
        {"number",10},{"a",3}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(33.6666666666666667, expression.Calculate(values));
}

TEST(TArithmeticExpression, checking_for_the_correct_entry_of_a_postfix_expression_5)
{
    string str = "((number*5+20)/3-15)*2+((7-a)*8+(10/2))-20";
    string postfix = "number5*20+3/15-2*7a-8*102/++20-";
    map<string, double> values = {
        {"number",10},{"a",3}
    };
    TArithmeticExpression expression(str);
    EXPECT_EQ(postfix, expression.GetPostFix_str());
}
//__________________________________________________________






