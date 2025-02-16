#include <iostream>

#include <iomanip> 
#include "array_stack.h"
#include "list_stack.h"
#include "string"
#include <map>
#include <vector>
using namespace std;


enum Stack_type
{
	arraystack = 0, 
	liststack = 1
};


template <typename TElem> void stack_allocate(Stack<TElem>*& Stack, enum Stack_type type)
{
	if (type == arraystack)
	{
		Stack = new array_stack<TElem>(MAX_STACK_SIZE);
	}
	else if (type == liststack)
	{
		Stack = new list_stack<TElem>();
	}
	else
	{
		throw std::invalid_argument("Invalid stack type");
	}
}


class TArithmeticExpression
{
	std::string infix;
	std::string postfix;
	std::vector<std::string> postfixx;
	Stack_type type;
	std::map<char, int> priority;
	std::map<std::string, double> operands;
	void ToPostfix();
	void allocation_operand(int &i, char item);
	void input_value();
	void input_value(map<std::string, double>);
public:
	TArithmeticExpression(const std::string& infx, Stack_type type);
	std::string GetInfix() const
	{
		return infix;
	}
	std::string GetPostfix() const
	{
		return postfix;
	}

	friend ostream& operator<<(ostream& ostr, const TArithmeticExpression& AE)
	{
		std::cout << "infix form = " << AE.infix << std::endl;
		std::cout << std::endl << "postfix form = ";
		for (int i = 0; i < AE.postfixx.size(); i++)
		{
			std::cout << AE.postfixx[i] << " ";
		}
		std::cout << std::endl;
		return ostr;
	}

	
	double Calculate();
	double Calculate(map<std::string, double>);
};