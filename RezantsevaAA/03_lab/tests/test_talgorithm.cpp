#include "talgorithm.h"
#include <gtest.h>
#include <map> 

double abs_error = 0.00001;

//namespace Polsk
TEST(Polsk, can_get_priority)
{
	ASSERT_EQ(1, Postfix::GetPriority(')'));
	ASSERT_EQ(1, Postfix::GetPriority('('));
	ASSERT_EQ(2, Postfix::GetPriority('+'));
	ASSERT_EQ(2, Postfix::GetPriority('-'));
	ASSERT_EQ(3, Postfix::GetPriority('*'));
	ASSERT_EQ(3, Postfix::GetPriority('/'));
	ASSERT_ANY_THROW(Postfix::GetPriority('!'));
}

TEST(Polsk, can_check_is_operator)
{
	ASSERT_EQ(true, Postfix::isOperator(')'));
	ASSERT_EQ(true, Postfix::isOperator('('));
	ASSERT_EQ(true, Postfix::isOperator('+'));
	ASSERT_EQ(true, Postfix::isOperator('-'));
	ASSERT_EQ(true, Postfix::isOperator('*'));
	ASSERT_EQ(true, Postfix::isOperator('/'));
	ASSERT_EQ(false, Postfix::isOperator('4'));
	ASSERT_EQ(false, Postfix::isOperator('!'));
}

//check convert
TEST(Polsk, can_convert_to_postfix_int_num)
{
	std::string s = "7+5";
	Postfix postfix = postfix.ConvertToPol(s);

	ASSERT_EQ(postfix.getStringView(), "7 5 + ");	
}

TEST(Polsk, can_convert_to_postfix_double_num)
{
	std::string s = "7.5+5.6";
	Postfix postfix = postfix.ConvertToPol(s);

	ASSERT_EQ(postfix.getStringView(), "7.5 5.6 + ");
}

TEST(Polsk, can_convert_to_postfix_double_num_and_letters)
{
	std::string s = "7.5+5.6+A+XY+Z1";
	Postfix postfix = postfix.ConvertToPol(s);

	ASSERT_EQ(postfix.getStringView(), "7.5 5.6 + A + XY + Z1 + ");
}

//class Postfix
TEST(Polsk, can_create_Postfix)
{
	ASSERT_NO_THROW(Postfix());
}

TEST(Polsk, can_create_Postfix_with_param)
{
	ASSERT_NO_THROW(Postfix(postf));
}

TEST(Polsk, right_string_check_getStringView)
{
	std::string s = "G+5.6+A+XY+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	std::string tmp = postfix.getStringView();

	EXPECT_EQ("G 5.6 + A + XY + Z1 + ", tmp);
}

TEST(Polsk, false_string_check_getStringView)
{
	std::string s = "G+5.6+A+XY+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	std::string tmp = postfix.getStringView();

	EXPECT_NE("G + 5.6 + A + XY + Z1 ", tmp);
}

TEST(Polsk, check_getCountNotSpecified)
{
	std::string s = "A+B*C-XY-Z1+Z1";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, -0.3, 0, 3, 10009 };
	int c = postfix.getCountNotSpecified();
	EXPECT_EQ(5, c);
}

TEST(Polsk, check_CalculateOperator_plus)
{
	char c = '+';
	double a = 1, b = 4, tmp;
	tmp = a + b;
	Postfix i;
	EXPECT_EQ(tmp, i.calculateOperator(c, a, b));
}

TEST(Polsk, check_CalculateOperator_minus)
{
	char c = '-';
	double a = 1, b = 4, tmp;
	tmp = a - b;
	Postfix i;
	EXPECT_EQ(tmp, i.calculateOperator(c, a, b));
}

TEST(Polsk, check_CalculateOperator_proiz)
{
	char c = '*';
	double a = 1, b = 4, tmp;
	tmp = a * b;
	Postfix i;
	EXPECT_EQ(tmp, i.calculateOperator(c, a, b));
}

TEST(Polsk, check_CalculateOperator_del)
{
	char c = '/';
	double a = 1, b = 4, tmp;
	tmp = a / b;
	Postfix i;
	EXPECT_EQ(tmp, i.calculateOperator(c, a, b));
}

//Operand

TEST(Polsk, check_isSpecified_false)
{
	Operand op;
	op.name = "A";
	op.isSign = false;
	op.value = INFINITY;
	EXPECT_FALSE(op.isSpecified());
}

TEST(Polsk, check_isSpecified_true)
{
	Operand op;
	op.name = "+";
	EXPECT_TRUE(op.isSpecified());
}


//check calculate
TEST(Polsk, right_check_calculate_int_numbers)
{
	std::string s = "7+5+1+0+2";
	Postfix postfix = postfix.ConvertToPol(s);
	double tmp = postfix.calculate();
	EXPECT_EQ(15, tmp);
}

TEST(Polsk, right_check_calculate_double_numbers1)
{
	std::string s = "(7.1+6+1*0+2.9)/8";
	Postfix postfix = postfix.ConvertToPol(s);
	double tmp = postfix.calculate();
	EXPECT_EQ(2, tmp);
}

TEST(Polsk, right_check_calculate_double_numbers2)
{
	std::string s = "7+5.6+1+0+2";
	Postfix postfix = postfix.ConvertToPol(s);
	double tmp = postfix.calculate();
	ASSERT_NEAR(15.6, tmp, abs_error);
}

TEST(Polsk, right_check_calculate_with_letters)
{
	std::string s = "A+B-XY-Z1";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, -0.3, 3, 10009 };
	postfix.setValuesFromVector(tmp);
	double result = postfix.calculate();
	ASSERT_NEAR(-10011.1, result, abs_error);
}

TEST(Polsk, right_check_calculate_with_equal_letters)
{
	std::string s = "A+B*C-XY-Z1+Z1";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, -0.3, 0, 3, 10009};
	postfix.setValuesFromVector(tmp);
	double result = postfix.calculate();
	ASSERT_NEAR(-1.8, result, abs_error);
}

TEST(Polsk, right_check_calculate_with_equal_letters_and_all_operations)
{
	std::string s = "A+(B-A)/(D-A)*K-(A+B)/B";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, -0.3, 0, 3};
	postfix.setValuesFromVector(tmp);
	double result = postfix.calculate();
	ASSERT_NEAR(7.95, result, abs_error);
}