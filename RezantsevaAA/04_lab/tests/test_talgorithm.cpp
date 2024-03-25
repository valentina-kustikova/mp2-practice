#include "talgorithm.h"
#include <gtest.h>
#include <math.h>
#include <map> 
/*
double abs_error = 0.00001;

class PostfixTest : public testing::Test {
private:
	Postfix object;

protected:
	PostfixTest() {
		object = Postfix();
	}
	double Pow(double a, double degree) {
		double result = 1.0;

		for (int i = 0; i < degree; i++)
		{
			result = result * a;
		}
		return result;

	}
	void setup(const Postfix& postf) {
		object = postf;
	}
	int GetPriority(const char& c) {
		return object.GetPriority(c);
	}
	bool isOperator(const char& c)
	{
		return object.isOperator(c);
	}

	bool isOperator(const std::string& str)
	{
		return object.isOperator(str);
	}

	int getCountNotSpecified()
	{
		return object.getCountNotSpecified();
	}

	double calculateOperator(char operatorName, double a, double b) const {
		return object.calculateOperator(operatorName, a, b);
	}

	std::pair<std::string, int> getOperand(const std::string& s, int pos)
	{
		return object.getOperand(s, pos);
	}

	std::vector<std::string> getRawPostfix()
	{
		return object.postfixArray;
	}

	std::string getRawStringView()
	{
		return object.s_postfix;
	}

	std::map<std::string, double> getRawOperands()
	{
		return object.operands;
	}

	void setValuesFromVector(const std::vector<double>& values)
	{
		object.setValuesFromVector(values);
	}
};


// Check Private methods of Postfix
TEST_F(PostfixTest, can_get_priority)
{
	ASSERT_EQ(1, GetPriority(')'));
	ASSERT_EQ(1, GetPriority('('));
	ASSERT_EQ(2, GetPriority('+'));
	ASSERT_EQ(2, GetPriority('-'));
	ASSERT_EQ(3, GetPriority('*'));
	ASSERT_EQ(3, GetPriority('/'));
	ASSERT_EQ(4, GetPriority('^'));
	ASSERT_ANY_THROW(GetPriority('!'));
}

TEST_F(PostfixTest, can_check_is_operator)
{
	ASSERT_EQ(true, isOperator(')'));
	ASSERT_EQ(true, isOperator('('));
	ASSERT_EQ(true, isOperator('+'));
	ASSERT_EQ(true, isOperator('-'));
	ASSERT_EQ(true, isOperator('*'));
	ASSERT_EQ(true, isOperator('^'));
	ASSERT_EQ(true, isOperator('/'));
	ASSERT_EQ(false, isOperator('4'));
	ASSERT_EQ(false, isOperator('!'));
}

TEST_F(PostfixTest, can_check_is_operator_for_string)
{
	ASSERT_EQ(true, isOperator(")"));
	ASSERT_EQ(true, isOperator("("));
	ASSERT_EQ(true, isOperator("+"));
	ASSERT_EQ(true, isOperator("-"));
	ASSERT_EQ(true, isOperator("*"));
	ASSERT_EQ(true, isOperator("/"));
	ASSERT_EQ(true, isOperator("^"));
	ASSERT_EQ(false, isOperator("4"));
	ASSERT_EQ(false, isOperator("!"));
}

TEST_F(PostfixTest, check_getCountNotSpecified)
{
	std::string s = "A+B*C-XY-Z1+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	setup(postfix);

	int c = getCountNotSpecified();
	EXPECT_EQ(5, c);
}


TEST_F(PostfixTest, check_CalculateOperator_plus)
{
	char c = '+';
	double a = 1, b = 4, tmp;
	tmp = a + b;
	EXPECT_EQ(tmp, calculateOperator(c, a, b));
}

TEST_F(PostfixTest, check_CalculateOperator_minus)
{
	char c = '-';
	double a = 1, b = 4, tmp;
	tmp = a - b;
	EXPECT_EQ(tmp, calculateOperator(c, a, b));
}

TEST_F(PostfixTest, check_CalculateOperator_proiz)
{
	char c = '*';
	double a = 1, b = 4, tmp;
	tmp = a * b;
	EXPECT_EQ(tmp, calculateOperator(c, a, b));
}

TEST_F(PostfixTest, check_CalculateOperator_del)
{
	char c = '/';
	double a = 1, b = 4, tmp;
	tmp = a / b;
	EXPECT_EQ(tmp, calculateOperator(c, a, b));
}
//DEGREE
TEST_F(PostfixTest, check_CalculateOperator_degree)
{
	char c = '^';
	double a = 2, b = 3, tmp;
	tmp = Pow(a,b);
	EXPECT_NEAR(tmp, 8,abs_error);
}

TEST_F(PostfixTest, check_getOperand)
{
	std::string s = "A+B*C-XY-Z1+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	setup(postfix);

	std::pair<std::string, int> calculatedPair = getOperand(s, 6);
	std::pair<std::string, int> expectedPair = { "XY", 8 };
	EXPECT_EQ(expectedPair, calculatedPair);
}

// check raw convertToPol
TEST_F(PostfixTest, can_convert_to_postfix_raw)
{
	std::string s = "7+5";
	Postfix postfix = postfix.ConvertToPol(s);
	setup(postfix);

	ASSERT_EQ(getRawPostfix(), std::vector<std::string>({"7", "5", "+"}));
}

// check raw getStringView
TEST_F(PostfixTest, can_getStringView_raw)
{
	std::string s = "7.5+5.6+A+XY+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	setup(postfix);

	ASSERT_EQ(getRawStringView(), postfix.getStringView());
}

// check raw operands and setValuesFromVector
TEST_F(PostfixTest, check_setValuesFromVector_raw)
{
	std::string s = "A+B*C-XY-Z1+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	setup(postfix);

	std::vector<double> tmp = { 1.2, -0.3, 0, 3, 10009 };
	setValuesFromVector(tmp);
	ASSERT_NEAR(getRawOperands()["A"], 1.2, abs_error);
	ASSERT_NEAR(getRawOperands()["B"], -0.3, abs_error);
	ASSERT_NEAR(getRawOperands()["C"], 0, abs_error);
	ASSERT_NEAR(getRawOperands()["XY"], 3, abs_error);
	ASSERT_NEAR(getRawOperands()["Z1"], 10009, abs_error);
}


// Check Public methods
//check convertToPol with getStringView
TEST(Postfix, can_convert_to_postfix_int_num)
{
	std::string s = "7+5";
	Postfix postfix = postfix.ConvertToPol(s);

	ASSERT_EQ(postfix.getStringView(), "7 5 + ");	
}

TEST(Postfix, can_convert_to_postfix_double_num)
{
	std::string s = "7.5+5.6";
	Postfix postfix = postfix.ConvertToPol(s);

	ASSERT_EQ(postfix.getStringView(), "7.5 5.6 + ");
}

TEST(Postfix, can_convert_to_postfix_double_num_and_letters)
{
	std::string s = "7.5+5.6+A+XY+Z1";
	Postfix postfix = postfix.ConvertToPol(s);

	ASSERT_EQ(postfix.getStringView(), "7.5 5.6 + A + XY + Z1 + ");
}

//class Postfix
TEST(Postfix, can_create_Postfix)
{
	ASSERT_NO_THROW(Postfix());
}

TEST(Postfix, can_create_Postfix_with_param)
{
	ASSERT_NO_THROW(Postfix(postf));
}

TEST(Postfix, right_string_check_getStringView)
{
	std::string s = "G+5.6+A+XY+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	std::string tmp = postfix.getStringView();

	EXPECT_EQ("G 5.6 + A + XY + Z1 + ", tmp);
}

TEST(Postfix, false_string_check_getStringView)
{
	std::string s = "G+5.6+A^2+XY+Z1";
	Postfix postfix = postfix.ConvertToPol(s);
	std::string tmp = postfix.getStringView();

	EXPECT_NE("G + 5.6 + A + XY + Z1 ", tmp);
}


//check calculate
TEST(Postfix, right_check_calculate_int_numbers)
{
	std::string s = "7+5^2+1+0+2";
	Postfix postfix = postfix.ConvertToPol(s);
	double tmp = postfix.calculate();
	EXPECT_EQ(35, tmp);
}

TEST(Postfix, right_check_calculate_double_numbers1)
{
	std::string s = "(7.1+6+1*0+2.9)/8";
	Postfix postfix = postfix.ConvertToPol(s);
	double tmp = postfix.calculate();
	EXPECT_EQ(2, tmp);
}

TEST(Postfix, right_check_calculate_double_numbers2)
{
	std::string s = "7^2+5.6+1+0+2";
	Postfix postfix = postfix.ConvertToPol(s);
	double tmp = postfix.calculate();
	ASSERT_NEAR(57.6, tmp, abs_error);
}

TEST(Postfix, right_check_calculate_with_letters)
{
	std::string s = "A+B-XY-Z1";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, -0.3, 3, 10009 };
	postfix.setValuesFromVector(tmp);
	double result = postfix.calculate();
	ASSERT_NEAR(-10011.1, result, abs_error);
}

TEST(Postfix, right_check_calculate_with_equal_letters)
{
	std::string s = "A+B*C-XY-Z1+Z1";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, -0.3, 0, 3, 10009};
	postfix.setValuesFromVector(tmp);
	double result = postfix.calculate();
	ASSERT_NEAR(-1.8, result, abs_error);
}

TEST(Postfix, right_check_calculate_with_equal_letters_and_all_operations)
{
	std::string s = "A+(B-A)/(D-A)*K-(A+B)/B";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, -0.3, 0, 3};
	postfix.setValuesFromVector(tmp);
	double result = postfix.calculate();
	ASSERT_NEAR(7.95, result, abs_error);
}
TEST(Postfix, check_degree_string)
{
	std::string s = "A+B^2*6-C";
	Postfix postfix = postfix.ConvertToPol(s);

	std::vector<double> tmp = { 1.2, 2, 4 };
	postfix.setValuesFromVector(tmp);
	double result = postfix.calculate();
	ASSERT_NEAR(21.2, result, abs_error);
}*/