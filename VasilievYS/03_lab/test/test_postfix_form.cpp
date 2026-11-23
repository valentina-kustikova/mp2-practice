#include"postfix_form.h"
#include<gtest.h>

TEST(ArithmeticExpression, can_create_expression_with_single_operand)
{
	ASSERT_NO_THROW(ArithmeticExpression e("a"));
}

TEST(ArithmeticExpression, can_create_valid_expressions)
{
	const std::string good[] = {
		"a", "A", "(a)", "((a))", "a+b", "a - b", " a + b ", "a+b*c",
		"(a+b)*c", "a*(b+c)/d", "(a)+(b)", "a-(b-c)", "((((a+b))))*c"
	};
	for (const std::string& s : good)
	{
		EXPECT_NO_THROW(ArithmeticExpression exp(s));
	}
}

TEST(ArithmeticExpression, cant_create_empty_expression)
{
	ASSERT_ANY_THROW(ArithmeticExpression exp(""));
}

TEST(ArithmeticExpression, throws_with_wrong_brackets)
{
	const std::string bad[] = {
		"(a", "a)", "(a+b", "a+b)", "(a+b))", ")a(", "a+b)(", "((a)"
	};
	for (const std::string& s : bad)
	{
		EXPECT_ANY_THROW(ArithmeticExpression e(s));
	}
}

TEST(ArithmeticExpression, throws_with_wrong_operations)
{
	const std::string bad[] = {
		"+a", "*a", "a+", "a-", "a++b", "a+*b", "a*/b", "(+a)", "(a+)", "a+)b("
	};
	for (const std::string& s : bad)
	{
		EXPECT_ANY_THROW(ArithmeticExpression exp(s));
	}
}

TEST(ArithmeticExpression, throws_without_operations)
{
	const std::string bad[] = { "ab", "a(b)", "(a)(b)", "(a)b", "a()" };
	for (const std::string& s : bad)
	{
		EXPECT_ANY_THROW(ArithmeticExpression exp(s));
	}
}

TEST(ArithmeticExpression, throws_when_unknown_symbols)
{
	const std::string bad[] = { "1+a", "a$", "a+b#", "a.b" };
	for (const std::string& s : bad)
	{
		EXPECT_ANY_THROW(ArithmeticExpression exp(s));
	}
}

TEST(ArithmeticExpression, postfix_of_single_operand)
{
	EXPECT_EQ("a", ArithmeticExpression("a").GetPostfix());
}

TEST(ArithmeticExpression, postfix_of_operand_in_brackets)
{
	EXPECT_EQ("a", ArithmeticExpression("((a))").GetPostfix());
}

TEST(ArithmeticExpression, postfix_of_simple_sum)
{
	EXPECT_EQ("ab+", ArithmeticExpression("a+b").GetPostfix());
}

TEST(ArithmeticExpression, postfix_of_mixed_expression)
{
	EXPECT_EQ("abc+*d/", ArithmeticExpression("a*(b+c)/d").GetPostfix());
}

TEST(ArithmeticExpression, postfix_complex_expression)
{
	EXPECT_EQ("ab/ka-kb+/s*-", ArithmeticExpression("a/b-(k-a)/(k+b)*s").GetPostfix());
}

TEST(ArithmeticExpression, can_compute_single_operand)
{
	EXPECT_DOUBLE_EQ(5.0, ArithmeticExpression("a").Compute({ { 'a', 5.0 } }));
}

TEST(ArithmeticExpression, can_compute_negative_values)
{
	EXPECT_DOUBLE_EQ(-2.0, ArithmeticExpression("a-b").Compute({ { 'a', -5.0 }, {'b', -3.0} }));
}

TEST(ArithmeticExpression, zero_divided_by_number_is_zero)
{
	EXPECT_DOUBLE_EQ(0.0, ArithmeticExpression("a/b").Compute({ { 'a', 0.0 }, {'b', 5.0} }));
}

TEST(ArithmeticExpression, cant_divide_by_zero)
{
	ASSERT_ANY_THROW(ArithmeticExpression("a/b").Compute({ { 'a', 5.0 }, {'b', 0.0} }));
}

TEST(ArithmeticExpression, cant_divide_by_zero_expression)
{
	ASSERT_ANY_THROW(ArithmeticExpression("a/(b-b)").Compute({ { 'a', 5.0 }, {'b', 7.0} }));
}

TEST(ArithmeticExpression, can_compute_mixed_expression)
{
	EXPECT_DOUBLE_EQ(4.0, 
		ArithmeticExpression("a*(b+c)/d").Compute({ {'a', 2.0}, {'b', 3.0}, {'c', 5.0}, {'d', 4.0} }));
}