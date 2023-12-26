#include "arexp.h"

#include <gtest.h>

TEST(ArithmeticExpression, can_create_arexp) {
	string a1 = "A+B*(C-D)";
	ArithmeticExpression a(a1);

	EXPECT_EQ(a1, a.InfixForm());
}

TEST(ArithmeticExpression, can_create_postfix_form) {
	string a1 = "abc+d4-+*10+";
	ArithmeticExpression a("a * (b + c + (d - 4)) + 10");
	EXPECT_EQ(a1, a.PostfixForm());
}

TEST(ArithmeticExpression, throw_when_get_invalid_name___first_symbol_is_num) {
	ASSERT_ANY_THROW(ArithmeticExpression a("1abc + bca"));
}

TEST(ArithmeticExpression, throw_when_get_invalid_name___have_invalid_sign) {
	ASSERT_ANY_THROW(ArithmeticExpression a("a^bc + bca"));
}

TEST(ArithmeticExpression, throw_when_left_brackets_more_then_right_brackets) {
	ASSERT_ANY_THROW(ArithmeticExpression a("a + ( c + (d + 3) +"));
}

TEST(ArithmeticExpression, throw_when_left_brackets_less_then_right_brackets) {
	ASSERT_ANY_THROW(ArithmeticExpression a("a + ( c + d + 3)) +"));
}

TEST(ArithmeticExpression, throw_when_have_zero_division){
	ArithmeticExpression a("1/0");
	ASSERT_ANY_THROW(a.Calculate());
}

TEST(ArithmeticExpression, can_get_integer_const) {
	ArithmeticExpression a("1 + (-5)");
	
	EXPECT_EQ(-4, a.Calculate());
}

TEST(ArithmeticExpression, can_get_float_const) {
	ArithmeticExpression a("-2.5 + 2.1");
	string s = "2.5-2.1+";
	EXPECT_EQ(s, a.PostfixForm());
}