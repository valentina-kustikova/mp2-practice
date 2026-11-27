#include "postfix_form.h"

#include <gtest/gtest.h>

TEST(ArExpression, can_create_expression_with_positive_string)
{
  string s = "A+B-C";
  ASSERT_NO_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_negative_front_or_back)
{
  string s = "+A+";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_unfinished_parentheses_sequence)
{
  string s = "(A+B))";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_incorrect_parentheses_sequence)
{
  string s = "(a+(b)";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_missing_operator_between_brackets)
{
  string s = "(a+b)(c+d)";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_operation_before_bracket)
{
  string s = "(A+B/)";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_several_operations_in_a_row)
{
  string s = "A+-B";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_unknown_charecters)
{
  string s = "A~B";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, throws_when_create_expression_with_two_letters_in_a_row)
{
  string s = "AC+B";
  ASSERT_ANY_THROW(ArExpression ae(s));
}

TEST(ArExpression, can_get_postfix_form)
{
  string s = "A+B-C";
  ArExpression ae(s);
  ASSERT_NO_THROW(ae.GetPostfix());
}

TEST(ArExpression, postfix_form1_is_correct)
{
  string s = "A+B-C";
  ArExpression ae(s);
  ASSERT_EQ(ae.GetPostfix(),"AB+C-" );
}

TEST(ArExpression, postfix_form2_is_correct)
{
	string s = "-A";
	ArExpression ae(s);
	ASSERT_EQ(ae.GetPostfix(), "0A-");
}

TEST(ArExpression, postfix_form3_is_correct)
{
	string s = "(A+B)*C/A";
	ArExpression ae(s);
	ASSERT_EQ(ae.GetPostfix(), "AB+C*A/");
}

TEST(ArExpression, postfix_form4_is_correct)
{
	string s = "A-B*(A-C)/(F-K)*S";
	ArExpression ae(s);
	ASSERT_EQ(ae.GetPostfix(), "ABAC-*FK-/S*-");
}

TEST(ArExpression, postfix_form5_is_correct)
{
  string s = "-A+B/(C-E)*R+I*(-E-R)";
  ArExpression ae(s);
  ASSERT_EQ(ae.GetPostfix(), "0A-BCE-/R*+I0E-R-*+");
}

TEST(ArExpression, postfix_form6_is_correct)
{
  string s = "(A*B+C)-(A/(F-G))-((A+B)*C)";
  ArExpression ae(s);
  ASSERT_EQ(ae.GetPostfix(), "AB*C+AFG-/-AB+C*-");
}

TEST(ArExpression, postfix_form7_is_correct)
{
  string s = "A+B/(-C*D)";
  ArExpression ae(s);
  ASSERT_EQ(ae.GetPostfix(), "AB0CD*-/+");
}


