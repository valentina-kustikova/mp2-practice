#include "stack.h"
#include "structures.h"

#include <gtest.h>

class TestEx : public ArithmeticExpression
{
public:
	using ArithmeticExpression::Is_Symbol;
	using ArithmeticExpression::Get_Priority;
	using ArithmeticExpression::Add_to_Stack1;
	using ArithmeticExpression::Is_Number;
	using ArithmeticExpression::isValidExpression;
	using ArithmeticExpression::isOperand;
	using ArithmeticExpression::FilteredExpression;
};

TEST(IsSymbolTest, is_symbol_true)
{
	TestEx exp;
	string s = "+";
	ASSERT_TRUE(exp.Is_Symbol(s));
}

TEST(IsSymbolTest, is_symbol_false)
{
	TestEx exp;
	string s = "!";
	ASSERT_FALSE(exp.Is_Symbol(s));
}

TEST(GetPriorityTest, get_priority_multiplication)
{
	TestEx exp;
	string s = "*";
	EXPECT_EQ(3, exp.Get_Priority(s));
}

TEST(GetPriorityTest, get_priority_addition)
{
	TestEx exp;
	string s = "+";
	EXPECT_EQ(2, exp.Get_Priority(s));
}

TEST(IsNumberTest, is_number_true)
{
	TestEx exp;
	string s = "123";
	ASSERT_TRUE(exp.Is_Number(s));
}

TEST(IsNumberTest, is_number_false)
{
	TestEx exp;
	string s = "1c3";
	ASSERT_FALSE(exp.Is_Number(s));
}

TEST(IsOperandTest, is_operand_digit)
{
	TestEx exp;
	char c = '3';
	ASSERT_TRUE(exp.isOperand(c));
}

TEST(IsOperandTest, is_operand_symbol)
{
	TestEx exp;
	char c = 'x';
	ASSERT_TRUE(exp.isOperand(c));
}

TEST(IsOperandTest, is_operand_header_symbol)
{
	TestEx exp;
	char c = 'B';
	ASSERT_TRUE(exp.isOperand(c));
}

TEST(FiltExpressionTest, removing_spaces)
{
	TestEx exp;
	string s1 = "(a-b)*c+a";
	string s2 = "(a - b)*c + a";
	EXPECT_EQ(s1, exp.FilteredExpression(s2));
}

TEST(ValidExpressionTest, no_bracket)
{
	TestEx exp;
	string s = "(a-b*c+a";
	ASSERT_FALSE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, two_identical_brackets)
{
	TestEx exp;
	string s = "(a-b(*c+a";
	ASSERT_FALSE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, operand_before_brackets_without_operator)
{
	TestEx exp;
	string s = "a(c-b)*k";
	ASSERT_FALSE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, correctly_placed_brackets)
{
	TestEx exp;
	string s = "(a-b)*(c+a)";
	ASSERT_TRUE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, two_operators)
{
	TestEx exp;
	string s = "(a-b)-*c+a";
	ASSERT_FALSE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, operand_after_bracket_without_operator)
{
	TestEx exp;
	string s = "(a-b)c+a";
	ASSERT_FALSE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, first_symbol_is_operator)
{
	TestEx exp;
	string s = "/(a-b)*c+a";
	ASSERT_FALSE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, last_symbol_is_operator)
{
	TestEx exp;
	string s = "(a-b)*c+a*";
	ASSERT_FALSE(exp.isValidExpression(s));
}

TEST(ValidExpressionTest, correct_input)
{
	TestEx exp;
	string s = "a+(b-a)/(d-a)*12-(x2+b)/x1";
	ASSERT_TRUE(exp.isValidExpression(s));
}

TEST(AddToStack1Test, add_elements_to_stack1_from_stack_2)
{
	TestEx exp;
	TStack<string> s1(5);
	TStack<string> s2(5);
	TStack<string> s3(5);
	s1.Push("x");
	s1.Push("5");
	s1.Push("+");

	s2.Push("a");
	s2.Push("b");
	s2.Push("*");

	s3.Push("x");
	s3.Push("5");
	s3.Push("+");
	s3.Push("*");
	s3.Push("b");
	s3.Push("a");

	while (!s2.IsEmpty())
	{
		string a = s2.Top();
		exp.Add_to_Stack1(s1, s2, a);
	}
	EXPECT_EQ(s1.Top(), s3.Top());
}

TEST(GetVariablesTest, variables_exist)
{
	ArithmeticExpression exp;
	TStack<string> s;
	s.Push("x");
	s.Push("5");
	s.Push("+");

	std::istringstream iss("10");
	std::cin.rdbuf(iss.rdbuf()); // Перенаправляем ввод, чтобы избежать ввода с клавиатуры во время теста

	map<string, double> m = { {"x", 10} };
	EXPECT_EQ(m, exp.GetVariables(s));
}

TEST(GetVariablesTest, no_variables) 
{
	ArithmeticExpression exp;
	TStack<string> s;
	s.Push("5");
	s.Push("7");
	s.Push("+");

	std::istringstream iss("");
	std::cin.rdbuf(iss.rdbuf()); // Перенаправляем ввод, чтобы избежать ввода с клавиатуры во время теста

	map<string, double> m = {};
	EXPECT_EQ(m, exp.GetVariables(s));
}


TEST(PostfixFormTest, translation_into_postfix_form)
{
	ArithmeticExpression exp;
	TStack<string> s(10);
	TStack<string> s2(10);
	string ex = "(a-b)*(c+a)";
	s.Push("a");
	s.Push("b");
	s.Push("-");
	s.Push("c");
	s.Push("a");
	s.Push("+");
	s.Push("*");
	s2 = exp.Postfix_Form(ex);
	EXPECT_EQ(s.Top(), s2.Top());
}

TEST(CalculateTest, Addition)
{
	ArithmeticExpression exp;
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("+");

	map<string, double> values = { {"a", 10}, {"b", 3} };
	double result = exp.Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(13, result);
}

TEST(CalculateTest, Subtraction)
{
	ArithmeticExpression exp;
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("-");

	map<string, double> values = { {"a", 10}, {"b", 3} };;
	double result = exp.Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(7, result);
}

TEST(CalculateTest, Multiplication)
{
	ArithmeticExpression exp;
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("*");

	map<string, double> values = { {"a", 10}, {"b", 3} };;
	double result = exp.Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(30, result);
}

TEST(CalculateTest, Division)
{
	ArithmeticExpression exp;
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("/");

	map<string, double> values = { {"a", 10}, {"b", 4} };
	double result = exp.Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(2.5, result);
}

TEST(CalculateTest, Exception_Division)
{
	ArithmeticExpression exp;
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("/");

	map<string, double> values = { {"a", 10}, {"b", 0} };
	ASSERT_ANY_THROW(exp.Calculate(inputStack, values));
}