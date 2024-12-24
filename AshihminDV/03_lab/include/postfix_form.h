#include <iostream>

#include <iomanip> 
#include "stack.h"
#include "string"
#include <map>
#include <vector>
using namespace std;


class TArithmeticExpression
{
	std::string infix;
	std::string postfix;
	std::vector<std::string> postfixx;
	std::vector<char> SequenceOperators;
	std::vector<std::string>SequenceOperands;
	std::map<char, int> priority;
	std::map<std::string, double> operands; //std::unordered_map
	void ToPostfix();
public:
	TArithmeticExpression(std::string infx);
	std::string GetInfix() const
	{
		return infix;
	}
	//std::vector<std::string> GetPostfix() const
	std::string GetPostfix() const
	{
		return postfix;
	}

	friend ostream& operator<<(ostream& ostr, const TArithmeticExpression& AE)
	{
		std::cout << "infix form = " << AE.infix << std::endl;
		//std::cout << "postfix form = ";
		for (int i = 0; i < AE.postfix.size(); i++)
		{
			std::cout << AE.postfix[i] << " ";
		}
		std::cout << std::endl << "-------------------VECTRO POSTFIX----------------" << std::endl;
		for (int i = 0; i < AE.postfixx.size(); i++)
		{
			std::cout << AE.postfixx[i] << " ";
		}
		return ostr;
	}

	double Calculate();

};

TArithmeticExpression::TArithmeticExpression(std::string infx) : infix(infx)
{
	priority = { {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} };
	ToPostfix();
}

void TArithmeticExpression::ToPostfix()
{
	//array_stack<std::string> operands(MAX_STACK_SIZE);
	array_stack<char> operators(MAX_STACK_SIZE);
	std::string VremPerem;
	char stackItem;
	std::cout << std::endl;

	for (int i = 0; i < infix.length(); i++)
	{
		char item = infix[i];
		switch (item)
		{
		case '(':
			operators.Push(item);
			break;
		case ')':
			stackItem = operators.Top();
			operators.pop();
			while (stackItem != '(')
			{
				postfix += stackItem;
				postfixx.push_back(std::string(1, stackItem));
				std::cout << stackItem << " =?= " << std::string(1, stackItem) << std::endl;
				stackItem = operators.Top();
				operators.pop();
			}
			break;
		case'+':case'-':case'*':case'/':
			while (!operators.is_empty())
			{
				stackItem = operators.Top();
				if (priority[item] <= priority[stackItem])
				{
					postfix += stackItem;
					std::cout << stackItem << " =?= " << std::string(1, stackItem) << std::endl;;
					postfixx.push_back(std::string(1, stackItem));
					operators.pop();
				}
				else
				{
					break;
				}
			}
			operators.Push(item);
			break;
		default:
			VremPerem = item;
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
			if (isdigit(item)) //?
			{
				operands.insert({ VremPerem, stod(VremPerem) });
			}
			operands.insert({ VremPerem, 0.0 });
			postfix += VremPerem;
			postfixx.push_back(VremPerem);
			SequenceOperands.push_back(VremPerem);
			break;
		}
	}
	while (!operators.is_empty())
	{
		postfix += operators.Top();
		postfixx.push_back(std::string(1, operators.Top()));
		std::cout << stackItem << " =?= " << std::string(1, stackItem) << std::endl;
		operators.pop();
	}
}

double TArithmeticExpression::Calculate()
{
	std::string Vrem;
	array_stack<double> promPodsch(postfixx.size());
	double top1, top2;
	double inValue;
	for (const auto& element : operands)
	{
		if (!isdigit(element.first[0]))
		{
			std::cout << "Input Value of " << element.first << " = ";
			std::cin >> inValue;
			operands[element.first] = double(inValue);
		}
	}
	std::cout << "----------------------" << std::endl << std::endl;

	/*for (const auto& element : operands)
	{
		std::cout << element.first << " = " << element.second << std::endl;
	}*/

	for (int i = 0; i < this->postfixx.size(); i++)
	{
		if (operands.find(postfixx[i]) != operands.end())
		{
			promPodsch.Push(operands.find(postfixx[i])->second);
		}
		else
		{
			switch (postfixx[i][0])
			{
			case'+':
				top1 = promPodsch.Top();
				promPodsch.pop();
				top2 = promPodsch.Top();
				promPodsch.pop();
				promPodsch.Push(top1 + top2);
				break;
			case'-':
				top1 = promPodsch.Top();
				promPodsch.pop();
				top2 = promPodsch.Top();
				promPodsch.pop();
				promPodsch.Push(top2 - top1);
				break;
			case'*':
				top1 = promPodsch.Top();
				promPodsch.pop();
				top2 = promPodsch.Top();
				promPodsch.pop();
				promPodsch.Push(top1 * top2);
				break;
			case'/':

				top1 = promPodsch.Top();
				promPodsch.pop();
				top2 = promPodsch.Top();
				promPodsch.pop();
				promPodsch.Push(top2 / top1);
				break;

			default:
				std::cout << "default";
				break;
			}
		}
	}



	return promPodsch.Top();
}

//A*F-V/D+G