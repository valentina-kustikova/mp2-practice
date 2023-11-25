#include "stack.h"
#include "structures.h"

#include <gtest.h>

TEST(IsSymbolTestTest, is_symbol_true)
{
	ArithmeticSymbol symbols[] = {
		{"*", 3},
		{"/", 3},
		{"+", 2},
		{"-", 2},
		{"(", 1},
		{")", 1},
	};
	string s = "+";
	EXPECT_EQ(2, Is_Symbol(symbols,s));
}

TEST(IsSymbolTestTest, is_symbol_false)
{
	ArithmeticSymbol symbols[] = {
		{"*", 3},
		{"/", 3},
		{"+", 2},
		{"-", 2},
		{"(", 1},
		{")", 1},
	};
	string s = "!";
	EXPECT_EQ(-1, Is_Symbol(symbols, s));
}

TEST(GetPriorityTest, get_priority_multiplication)
{
	string s = "*";
	EXPECT_EQ(3, Get_Priority(s));
}

TEST(GetPriorityTest, get_priority_addition)
{
	string s = "+";
	EXPECT_EQ(2, Get_Priority(s));
}

TEST(IsNumberTest, is_number_true)
{
	string s = "123";
	EXPECT_EQ(1, Is_Number(s));
}

TEST(IsNumberTest, is_number_false)
{
	string s = "1c3";
	EXPECT_EQ(0, Is_Number(s));
}

TEST(IsOperandTest, is_operand_digit)
{
	char c = '3';
	EXPECT_EQ(1, isOperand(c));
}

TEST(IsOperandTest, is_operand_symbol)
{
	char c = 'x';
	EXPECT_EQ(1, isOperand(c));
}

TEST(IsOperandTest, is_operand_header_symbol)
{
	char c = 'B';
	EXPECT_EQ(1, isOperand(c));
}

TEST(IsOperatorTest, is_operator_true)
{
	string c = "+";
	EXPECT_EQ(1, isOperator(c));
}

TEST(IsOperatorTest, is_operator_false)
{
	string c = "(";
	EXPECT_EQ(0, isOperator(c));
}

TEST(FiltExpressionTest, removing_spaces)
{
	string s1 = "(a-b)*c+a";
	string s2 = "(a - b)*c + a";
	EXPECT_EQ(s1, FilteredExpression(s2));
}

TEST(ValidExpressionTest, no_bracket)
{
	string s = "(a-b*c+a";
	EXPECT_EQ(0, isValidExpression(s));
}

TEST(ValidExpressionTest, two_identical_brackets)
{
	string s = "(a-b(*c+a";
	EXPECT_EQ(0, isValidExpression(s));
}

TEST(ValidExpressionTest, operand_before_brackets_without_operator)
{
	string s = "a(c-b)*k";
	EXPECT_EQ(0, isValidExpression(s));
}

TEST(ValidExpressionTest, correctly_placed_brackets)
{
	string s = "(a-b)*(c+a)";
	EXPECT_EQ(1, isValidExpression(s));
}

TEST(ValidExpressionTest, two_operators)
{
	string s = "(a-b)-*c+a";
	EXPECT_EQ(0, isValidExpression(s));
}

TEST(ValidExpressionTest, operand_after_bracket)
{
	string s = "(a-b)c+a";
	EXPECT_EQ(0, isValidExpression(s));
}

TEST(ValidExpressionTest, first_symbol_is_operator)
{
	string s = "/(a-b)*c+a";
	EXPECT_EQ(0, isValidExpression(s));
}

TEST(ValidExpressionTest, last_symbol_is_operator)
{
	string s = "(a-b)*c+a*";
	EXPECT_EQ(0, isValidExpression(s));
}

TEST(ValidExpression, correct_input)
{
	string s = "a+(b-a)/(d-a)*12-(x2+b)/x1";
	EXPECT_EQ(1, isValidExpression(s));
}

TEST(GetVariablesTest, variables_exist)
{
	TStack<string> s;
	s.Push("x");
	s.Push("5");
	s.Push("+");

	std::istringstream iss("10");
	std::cin.rdbuf(iss.rdbuf()); // Перенаправляем ввод, чтобы избежать ввода с клавиатуры во время теста

	map<string, double> m = { {"x", 10} };
	EXPECT_EQ(m, GetVariables(s));
}

TEST(GetVariablesTest, no_variables) 
{
	TStack<string> s;
	s.Push("5");
	s.Push("7");
	s.Push("+");

	std::istringstream iss("");
	std::cin.rdbuf(iss.rdbuf()); // Перенаправляем ввод, чтобы избежать ввода с клавиатуры во время теста

	map<string, double> m = {};
	EXPECT_EQ(m, GetVariables(s));
}


TEST(PostfixFormTest, translation_into_postfix_form)
{
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
	s2 = Postfix_Form(ex);
	for(int i =0; i<s2.Length();i++)
		EXPECT_EQ(s.GetElement(i), s2.GetElement(i));
}

TEST(CalculateTest, Addition)
{
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("+");

	map<string, double> values = { {"a", 10}, {"b", 3} };
	double result = Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(13, result);
}

TEST(CalculateTest, Subtraction)
{
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("-");

	map<string, double> values = { {"a", 10}, {"b", 3} };;
	double result = Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(7, result);
}

TEST(CalculateTest, Multiplication)
{
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("*");

	map<string, double> values = { {"a", 10}, {"b", 3} };;
	double result = Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(30, result);
}

TEST(CalculateTest, Division)
{
	TStack<string> inputStack;
	inputStack.Push("a");
	inputStack.Push("b");
	inputStack.Push("/");

	map<string, double> values = { {"a", 10}, {"b", 4} };;
	double result = Calculate(inputStack, values);

	EXPECT_DOUBLE_EQ(2.5, result);
}