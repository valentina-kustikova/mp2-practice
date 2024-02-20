#include "tPostfixNotation.h"
#include <gtest.h>

TEST(tPostfix, can_create_postfix) {
	ASSERT_NO_THROW(tPostfix P("a+b-c"));
}
TEST(tPostfix, cant_create_postfix_with_0_length) {
	ASSERT_ANY_THROW(tPostfix P(""));
}
TEST(tPostfix, throw_on_less_that_two_operators) {
	ASSERT_ANY_THROW(tPostfix P("a+"));
}
TEST(tPostfix, operator_is_operator_index) {
	tPostfix P("a+b");
	EXPECT_TRUE(P.is_operator(1));
}
TEST(tPostfix, non_operator_is_non_operator_index) {
	tPostfix P("a+b");
	EXPECT_FALSE(P.is_operator(0));
}
TEST(tPostfix, operator_is_operator_char) {
	tPostfix P("a+b");
	EXPECT_TRUE(P.is_operator('-'));
}
TEST(tPostfix, non_operator_is_non_operator_char) {
	tPostfix P("a+b");
	EXPECT_FALSE(P.is_operator('a'));
}
TEST(tPostfix, operator_is_operator_string) {
	tPostfix P("a+b");
	EXPECT_TRUE(P.is_operator("-"));
}
TEST(tPostfix, non_operator_is_non_operator_string) {
	tPostfix P("a+b");
	EXPECT_FALSE(P.is_operator("ds"));
}
TEST(tPostfix, operation_is_correct) {
	tPostfix P("a+b");
	double test = P.operation(2, '-', 4);
	double test_ex = -2;
	EXPECT_EQ(test, test_ex);
}
TEST(tPostfix, calculation_is_correct) {
	tPostfix P("5+3-2");
	double test_ex = 6;
	P.get_values_for_variables();
	EXPECT_EQ(P.calculate_the_result(), test_ex);
}
TEST(tPostfix, postfix_is_correct) {
	tPostfix P("(a*b-c)/(d-a)-b");
	string test_ex = "ab*c-da-/b-";
	vector<string> tmp = P.get_postfixed();
	string tmp2;
	for (int i = 0; i < tmp.size(); i++)
		tmp2 += tmp[i];
	EXPECT_EQ(tmp2, test_ex);
}
TEST(tPostfix, string_division_is_correct) {
	tPostfix P("(a*b-c)");
	vector<string> test_ex = { "(", "a","*","b" ,"-" ,"c" ,")" };
	EXPECT_EQ(P.get_refined(), test_ex);
}
TEST(tPostfix, can_use_constants) {
	tPostfix P("5+3-2");
	double test_ex = 6;
	P.get_values_for_variables();
	EXPECT_EQ(P.calculate_the_result(), test_ex);
}
TEST(tPostfix, can_use_non_single_element_variables) {
	tPostfix P("st*nd-rd");
	vector<string> test_ex = { "st","*","nd" ,"-" ,"rd" };
	EXPECT_EQ(P.get_refined(), test_ex);
}
TEST(tPostfix, can_use_variables_multiple_times) {
	tPostfix P("st*nd-st");
	int test_ex = 2;
	EXPECT_EQ(P.get_variables_amount(), test_ex);
}
TEST(tPostfix, throws_on_dividing_by_0) {
	tPostfix P("4-2/0");
	P.get_values_for_variables();
	ASSERT_ANY_THROW(P.calculate_the_result());
}