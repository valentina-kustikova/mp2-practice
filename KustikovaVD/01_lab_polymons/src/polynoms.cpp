#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <polinom.h>
#include <data.h>

enum type {
	COEFFICIENT,
	JACK,
	OPERATOR,
	VARIABLE
};

class Term
{
public:
	type token;
	type GetType()
	{
		return token;
	}
	virtual void print() = 0;
};

class Coeff : public Term
{
public:
	double value; 

	Coeff(double Cf)
	{
		token = type::COEFFICIENT;
		value = Cf;
	};
	void print()
	{
		std::cout << value << " ";
	}
	
};

class Operator : public Term
{
public:
	char value;
	char plus;
	char minus;
	Operator(char oper) : plus(' '), minus(' ')
	{
		token = type::OPERATOR;
		value = oper;
	}
	void definition()
	{
		if (value == '+')
		{
			plus = value; 
		}
		if (value = '-')
		{
			minus = value;
		}
	}
	void print()
	{
		std::cout << value << " ";
	}
};

class Variables : public Term
{
public:

	char X;
	char Y; 
	char Z;
	char value; 
	Variables(char var)
	{
		token = type::VARIABLE;
		value = var; 
	};
	void definition()
	{
		if (value == 'x')
			X = value;
		if (value == 'y')
			Y = value;
		if (value == 'z')
			Z = value; 
	}
	void print()
	{
		std::cout << value << " ";
	}

};

class Jack : public Term
{
public:
	char value; 

	Jack(char br) {
		token = type::JACK;
		value = br;
	}
	void print()
	{
		std::cout << value << " ";
	}
};


class Expression {
private:
	std::string str;
	std::vector<Term*> str_terms; 

	bool LexicalAnalysis();
	bool SyntacticAnalysis();
	double Calculation();
public:
	Expression(std::string s): str(s){}
	~Expression()
	{
		for (int i = 0; i < str_terms.size(); ++i)
		{
			delete str_terms[i];
		}
	}
	double solve() {
		if (!LexicalAnalysis()) throw "error in Lexical analysis";
		if (!SyntacticAnalysis()) throw "erroy in syntactic analysis";
		for (int i = 0; i < str.size(); ++i)
			std::cout << str[i];
		std::cout << "\n";
		for (int i = 0; i < str_terms.size(); ++i)
			str_terms[i]->print();
		std::cout << "\n";
		double d = Calculation();
		std::cout << d << "\n";
		return d;

	}
};

bool Expression::LexicalAnalysis()
{
	std::string tmp_str = str; 
	while (!tmp_str.empty()) {
		if (tmp_str[0] == '+' || tmp_str[0] == '-')
		{
			str_terms.push_back(new Operator(tmp_str[0]));
			tmp_str.erase(tmp_str.begin(), tmp_str.begin() + 1);
		}
		else if (tmp_str[0] == 'x' || tmp_str[0] == 'y' || tmp_str[0] == 'y')
		{
			str_terms.push_back(new Variables(tmp_str[0]));
			tmp_str.erase(tmp_str.begin(), tmp_str.begin() + 1);
		}
		else if (tmp_str[0] == '^')
		{
			str_terms.push_back(new Jack(tmp_str[0]));
			tmp_str.erase(tmp_str.begin(), tmp_str.begin() + 1);
		}
		else if (tmp_str[0] >= '0' && tmp_str[0] <= '9') {
			std::string::size_type sz;
			str_terms.push_back(new Coeff(std::stod(tmp_str, &sz)));
			tmp_str.erase(tmp_str.begin(), tmp_str.begin() + sz);
		}
		else return false;
	}
	return true;
}
bool Expression::SyntacticAnalysis() {
	for (int i = 0; i <= str_terms.size() - 1; ++i) {
		type term = str_terms[i + 1]->GetType();
		switch (str_terms[i]->GetType()) {
		case type::COEFFICIENT:
		{
			if (term == JACK)
				return false;
			break;
		}

		case type::JACK:
		{
			if (term == OPERATOR || term == VARIABLE || term == '=')
				return false;
			if (term == COEFFICIENT && COEFFICIENT >= 9)
				return false;
			break; 		
		}
		case type::OPERATOR: 
		{
			if (term == '=' || term == JACK)
				return false; 
			break;
		}
		case type::VARIABLE:
		{
			if (term == OPERATOR)
				return false;
			break;
		}
		}
	}
	if (str_terms[1]->GetType() == JACK || str_terms[1]->GetType() == OPERATOR || str_terms[1]->GetType() == '=')
		return false;
	return true; 
}

double Expression::Calculation()
{

}





TPolinom TPolinom:: operator+(const TPolinom& a)
{
	TPolinom res = *this; 
	TNode* tmppoltwo;
	



	
};