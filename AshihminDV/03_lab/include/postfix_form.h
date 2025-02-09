#include <iostream>

#include <iomanip> 
#include "array_stack.h"
#include "list_stack.h"
#include "string"
#include <map>
#include <vector>
using namespace std;


class TArithmeticExpression
{
	std::string infix;
	std::string postfix;
	std::vector<std::string> postfixx;
	std::map<char, int> priority;
	std::map<std::string, double> operands; //std::unordered_map
	void ToPostfix();
	void allocation_operand(int &i, char item);
public:
	TArithmeticExpression(const std::string& infx);
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
		//std::cout << "postfix form = " << AE.postfixx << std::endl;
		/*for (int i = 0; i < AE.postfix.size(); i++)
		{
			std::cout << AE.postfix[i] << " ";
		}*/
		std::cout << std::endl << "postfix form = ";
		for (int i = 0; i < AE.postfixx.size(); i++)
		{
			std::cout << AE.postfixx[i] << " ";
		}
		std::cout << std::endl;
		return ostr;
	}

	void input_value();
	double Calculate();
	void input_value(map<std::string, double>);
	double Calculate(map<std::string, double>);


};