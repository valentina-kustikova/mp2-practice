#include "postfix_form.h"
#include<gtest.h>

TEST(postfix_form, correct_convert_to_postfix_form1)
{
	TArithmeticExpression v("A+B", arraystack);
	EXPECT_EQ("AB+", v.GetPostfix());
}
TEST(postfix_form, correct_convert_to_postfix_form2)
{
	TArithmeticExpression v("A-B", arraystack);
	EXPECT_EQ("AB-", v.GetPostfix());
}
TEST(postfix_form, correct_convert_to_postfix_form3)
{
	TArithmeticExpression v("A-B*(A+C)", arraystack);
	EXPECT_EQ("ABAC+*-", v.GetPostfix());
}
TEST(postfix_form, correct_convert_to_postfix_form4)
{
	TArithmeticExpression v("(A-B)/(C-A)*(K+B)+A", arraystack);
	EXPECT_EQ("AB-CA-/KB+*A+", v.GetPostfix());
}
TEST(postfix_form, correct_calculate_form1)
{
	TArithmeticExpression v("A+B", arraystack);
	map<std::string, double> ma
	{
		std::pair<std::string, double>{"A", 30}, std::pair<std::string, double>{"B", 70}
	};
	EXPECT_EQ(100.0, v.Calculate(ma));
}
TEST(postfix_form, correct_calculate_form2)
{
	TArithmeticExpression v("A-B", arraystack);
	map<std::string, double> ma
	{
		std::pair<std::string, double>{"A", 30}, std::pair<std::string, double>{"B", 70}
	};
	EXPECT_EQ(-40.0, v.Calculate(ma));
}
TEST(postfix_form, correct_calculate_form3)
{
	TArithmeticExpression v("A-B*(A+C)", arraystack);
	map<std::string, double> ma
	{
		std::pair<std::string, double>{"A", 1}, std::pair<std::string, double>{"B", 2}, 
		std::pair<std::string, double>{"C", 3}
	};
	EXPECT_EQ(-7.0, v.Calculate(ma));
}
TEST(postfix_form, correct_calculate_form4)
{
	TArithmeticExpression v("(A-B)/(C-A)*(K+B)+A", arraystack);
	map<std::string, double> ma
	{
		std::pair<std::string, double>{"A", 1}, std::pair<std::string, double>{"B", 3},
		std::pair<std::string, double>{"C", 2}, std::pair<std::string, double>{"K", -2}
	};
	EXPECT_EQ(-1.0, v.Calculate(ma));
}
TEST(postfix_form, can_use_const)
{
	TArithmeticExpression v("A+4", arraystack);
	EXPECT_EQ("A4+", v.GetPostfix());
}