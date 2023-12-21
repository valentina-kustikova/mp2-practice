#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

class Expression
{
private:
	string infix; //input a+b
	string str_postfix; //postfix is a string AB+ 
	vector<string> postfix; //vector<string> "A""B""+"
	vector<string> lexems; //vector<string> "A""+""B"
	map<string, int> priority; // { {"(",1},{")",1},{"+",2},{"-",2}, {"*",3},{"/",3} }
	map<string, double> operands; // {{"A",1},{"B",2},{"C",4}}

	void Parse();
	void ToPostfix();
	bool IsOperator(const string& lecsem) const;
	bool IsConst(const string& lecsem) const;


public:

	Expression(const string& infix);

	string GetInfix() const { return infix; }
	vector<string> GetPostFix() const { return postfix; }
	string GetPostFix_str() const { return str_postfix; }


	bool isCorrectInfixExpression();
	vector<string> GetOperands() const;
	void SetValues();
	double Calculate(const map<string, double>& values);
	double Calculate();
	void ShowPostfix();
	void InToPostfix();

};

#endif
