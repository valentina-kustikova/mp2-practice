#include "postfix_form.h"

TArithmeticExpression::TArithmeticExpression(const std::string& infx, Stack_type type) : infix(infx)
{
	this->type = type;
	priority = { {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} };
	ToPostfix();
}

void TArithmeticExpression::ToPostfix()
{
	Stack<char>* operators = nullptr;
	stack_allocate(operators, this->type);
	std::string VremPerem;
	char stackItem;
	int i = 0;
	while(i < infix.length())
	{
		char item = infix[i];
		switch (item)
		{
		case '(':
			operators->Push(item);
			break;
		case ')':
			stackItem = operators->Top();
			operators->pop();
			while (stackItem != '(')
			{
				postfix += stackItem;
				postfixx.push_back(std::string(1, stackItem));
				stackItem = operators->Top();
				operators->pop();
			}
			break;
		case'+':case'-':case'*':case'/':
			while (!operators->is_empty())
			{
				stackItem = operators->Top();
				if (priority[item] <= priority[stackItem])
				{
					postfix += stackItem;
					postfixx.push_back(std::string(1, stackItem));
					operators->pop();
				}
				else
				{
					break;
				}
			}
			operators->Push(item);
			break;
		default:
			allocation_operand(i, item);
			break;
		}
		i++;
	}
	while (!operators->is_empty())
	{
		postfix += operators->Top();
		postfixx.push_back(std::string(1, operators->Top()));
		operators->pop();
	}
	delete operators;
}

void TArithmeticExpression::allocation_operand(int &i, char item)
{
	int idx = i;
	std::string VremPerem;
	VremPerem += item;
	while (infix[i + 1] != '\0')
	{
		if (infix[i + 1] == '(' || infix[i + 1] == ')' || infix[i + 1] == '-' || infix[i + 1] == '+' ||
			infix[i + 1] == '*' || infix[i + 1] == '/')
		{
			break;
		}
		item = infix[++i];
		VremPerem += item;

	}
	if (isdigit(item))
	{
		operands.insert({ VremPerem, stod(VremPerem) });
	}
	operands.insert({ VremPerem, 0.0 });
	postfix += VremPerem;
	postfixx.push_back(VremPerem);
}

void TArithmeticExpression::input_value()
{
	int inValue;
	for (const auto& element : operands)
	{
		if (!isdigit(element.first[0]))
		{
			std::cout << "Input Value of " << element.first << " = ";
			std::cin >> inValue;
			operands[element.first] = double(inValue);
		}
	}
}
double TArithmeticExpression::Calculate()
{
	std::string Vrem;
	Stack<double>* promPodsch = nullptr;
	stack_allocate(promPodsch, this->type);
	double top1, top2;
	double inValue;
	this->input_value();

	for (int i = 0; i < this->postfixx.size(); i++)
	{
		if (operands.find(postfixx[i]) != operands.end())
		{
			promPodsch->Push(operands.find(postfixx[i])->second);
		}
		else
		{
			switch (postfixx[i][0])
			{
			case'+':
				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top1 + top2);
				break;
			case'-':
				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top2 - top1);
				break;
			case'*':
				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top1 * top2);
				break;
			case'/':

				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top2 / top1);
				break;

			default:
				std::cout << "default";
				break;
			}
		}
	}
	double result = promPodsch->Top();
	delete promPodsch;
	return result;
}

void TArithmeticExpression::input_value(map<std::string, double> inp)
{
	int i = 0;
	for (const auto& element : inp)
	{
		if (this->operands.find(element.first) != this->operands.end())
		{
			this->operands[element.first] = element.second;
		}
	}
}

double TArithmeticExpression::Calculate(const map<std::string, double>& inp)
{
	std::string Vrem;
	Stack<double>* promPodsch = nullptr;
	stack_allocate(promPodsch, this->type);
	double top1, top2;
	double inValue;
	this->input_value(inp);

	for (int i = 0; i < this->postfixx.size(); i++)
	{
		if (operands.find(postfixx[i]) != operands.end())
		{
			promPodsch->Push(operands.find(postfixx[i])->second);
		}
		else
		{
			switch (postfixx[i][0])
			{
			case'+':
				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top1 + top2);
				break;
			case'-':
				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top2 - top1);
				break;
			case'*':
				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top1 * top2);
				break;
			case'/':
				top1 = promPodsch->Top();
				promPodsch->pop();
				top2 = promPodsch->Top();
				promPodsch->pop();
				promPodsch->Push(top2 / top1);
				break;

			default:
				std::cout << "default";
				break;
			}
		}
	}
	double result = promPodsch->Top();
	delete promPodsch;
	return result;
}

//A*F-V/D+G