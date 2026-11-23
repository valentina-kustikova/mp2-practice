#include "postfix_form.h"
#include<stdexcept>
#include<iostream>

bool ArithmeticExpression::isOperation(char c) const
{
	return all_operations.find(c) != std::string::npos;
}

bool ArithmeticExpression::isOperand(char c) const
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int ArithmeticExpression::getPriority(char c) const
{
	if (c == '*' || c == '/') return 3;   
	if (c == '+' || c == '-') return 2;
	if (c == '(') return 1;
	return 0;
}

void ArithmeticExpression::validate() const
{
	int balance = 0;
	enum class State
	{
		Expect_Operand,
		Expect_Operation
	};
	State state = State::Expect_Operand;
	for (char c : expression)
	{
		if (c == ' ') continue;
		if (c == '(') balance++;
		else if (c == ')') balance--;
		if (balance < 0) throw std::invalid_argument("Wrong bracket order");

		if (state == State::Expect_Operand)
		{
			if (isOperand(c))
			{
				state = State::Expect_Operation;
				continue;
			}
			else if (isOperation(c) && c != '(')
				throw std::invalid_argument("Operation or ')' when operand expected");
			else if (c == '(') continue;
			else throw std::invalid_argument("Unknown expression");
		}
		else
		{
			if (isOperation(c) && c != ')' && c != '(')
			{
				state = State::Expect_Operand;
				continue;
			}
			if (c == ')') continue;
			else throw std::invalid_argument("Operand or '(' when operation expected");
		}
	}
	if(balance != 0) throw std::invalid_argument("Wrong bracket order");
	if (state != State::Expect_Operation)
		throw std::invalid_argument("Expression is empty or ends with operation");
}

std::string ArithmeticExpression::GetPostfix() const
{
	Stack<char> operands(STACK_SIZE);
	Stack<char> operations(STACK_SIZE);
	for (char c : expression)
	{
		if (c == ' ') continue;
		if (isOperand(c)) operands.push(c);
		else if (isOperation(c))
		{
			if (c == '(') operations.push(c);
			else if (c == ')')
			{
				while (operations.top() != '(')
				{
					operands.push(operations.top());
					operations.pop();
				}
				operations.pop();
			}
			else
			{
				while (!operations.is_empty() && 
					getPriority(operations.top()) >= getPriority(c) 
					&& operations.top() != '(')
				{
					operands.push(operations.top());
					operations.pop();
				}
				operations.push(c);
			}
		}
	}
	while (!operations.is_empty())
	{
		operands.push(operations.top());
		operations.pop();
	}
	std::string res = "";
	while (!operands.is_empty())
	{
		res = operands.top() + res;
		operands.pop();
	}
	return res;
}

double ArithmeticExpression::
Compute(const std::vector<std::pair<char, double>>& vars) const
{
	std::string postfix = GetPostfix();
	Stack<double> operand_val(STACK_SIZE);
	for (char c : postfix)
	{
		if (isOperand(c))
		{
			double x = 0.0;
			bool found = false;
			for (const auto& p : vars)
			{
				if (p.first == c)
				{
					x = p.second;
					found = true;
					break;
				}
			}
			if (!found) throw std::invalid_argument(std::string("No value") + c);
			operand_val.push(x);
		}
		else
		{
			double op2 = operand_val.top();
			operand_val.pop();
			double op1 = operand_val.top();
			operand_val.pop();
			double res = 0.0;
			switch (c)
			{
			case('+'): res = op1 + op2; break;
			case('-'): res = op1 - op2; break;
			case('*'): res = op1 * op2; break;
			case('/'):
				if (op2 == 0) throw std::invalid_argument("Division by zero!");
				res = op1 / op2; break;
			}
			operand_val.push(res);
		}
	}
	return operand_val.top();
}

std::vector<char> ArithmeticExpression::GetUnique() const
{
	std::vector<char> uniq;
	for (char c : expression)
	{
		if (isOperand(c))
		{
			bool is_uniq_var = true;
			for (char var : uniq)
			{
				if (c == var)
				{
					is_uniq_var = false;
					break;
				}
			}
			if(is_uniq_var) uniq.push_back(c);
		}
	}
	return uniq;
}

std::vector<std::pair<char, double>> ArithmeticExpression::MakeVectorPair() const
{
	std::vector<char> uniq_vars = GetUnique();
	std::vector<std::pair<char, double>> vars_val;
	std::cout << "Enter the variable values";
	for (char c : uniq_vars)
	{
		double val;
		std::cout << '\n' << c << " = ";
		if (!(std::cin >> val)) throw std::invalid_argument("Invalid value");
		vars_val.push_back(std::make_pair(c, val));
	}
	return vars_val;
}