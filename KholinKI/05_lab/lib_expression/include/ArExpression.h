#ifndef _AREXPRESSION_H
#define _AREXPRESSION_H

#include <iostream>
#include <Stack.h>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include "SupFunctions.h"
using namespace std;




class ArithmeticExpression {
private:
	string infix;
	vector<string> postfix;
	vector<string> lexemes;
	map<char, int> priority;
	map<string, double> operands;
	
	void Parse();
	void ToPostfix();
public:
	ArithmeticExpression(const string& infix_);

	string GetInfix()const { return infix; }
	vector<string> GetPostfix()const { return postfix; }
	vector<string> GetOperands()const;
	
	map<string, double> SetOperands(const vector<string> operands);//ручной ввод
	map<string, double> SetOperands_v2(const vector<string> operands,const map<string,double> your_values);//автоматический ввод
	

	double Calculate(const map<string, double>& values);
private:
	void Check()const;
	bool Is_Operator(char c)const;
	bool Is_Operand_String(char c)const;
	bool Is_Operand_const(char c)const;
	double Transform(string str)const;	
};


#endif
