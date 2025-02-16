#include "postfix_form.h"
#include <gtest.h>

TEST(Postfix_Form, can_create_postfix_on_astack) {
	ASSERT_NO_THROW(ReversePolishNotation temp("A+B", arraystack));
}

TEST(Postfix_Form, can_create_postfix_on_lstack) {
	ASSERT_NO_THROW(ReversePolishNotation temp("A+B", liststack));
}

TEST(Postfix_Form, can_convert_expression_to_RPN_on_astack) {
	ReversePolishNotation temp("A+B", arraystack);
	EXPECT_EQ(temp.get_postfix(), "AB+" );
}

TEST(Postfix_Form, can_convert_expression_to_RPN_on_lstack) {
	ReversePolishNotation temp("A+B", liststack);
	EXPECT_EQ(temp.get_postfix(), "AB+");
}

TEST(Postfix_Form, can_evaluate_on_astack) {
	ReversePolishNotation temp("A+B", arraystack);
	map<string, double> operands{ {"A", 1}, {"B", 2} };
	EXPECT_EQ(3, temp.evaluate_postfix(operands));
}

TEST(Postfix_Form, can_evaluate_on_ôstack) {
	ReversePolishNotation temp("A+B", liststack);
	map<string, double> operands{ {"A", 1}, {"B", 2} };
	EXPECT_EQ(3, temp.evaluate_postfix(operands));
}

TEST(Postfix_Form, can_convert_expression_to_RPN_on_astack2) {
	ReversePolishNotation temp("(A-B)/(C-A)*(K+B)+A", arraystack);
	EXPECT_EQ(temp.get_postfix(), "AB-CA-/KB+*A+");
}

TEST(Postfix_Form, can_convert_expression_to_RPN_on_lstack2) {
	ReversePolishNotation temp("(A-B)/(C-A)*(K+B)+A", liststack);
	EXPECT_EQ(temp.get_postfix(), "AB-CA-/KB+*A+");
}