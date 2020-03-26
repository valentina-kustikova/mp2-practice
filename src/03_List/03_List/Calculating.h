#pragma once
#include "VirtualStack.h"
#include <string>
using namespace std;
class Calculating
{
private:
	TStack<char>* operators;
	TStack<char>* operands;
	TStack<double>* finalvolue;
private:
	static bool priority(char, char);
	static double calculator(double, double, char);
public:
	string create_postfix(const string);
	static void get_operands(const string, double *&, char *&, int &);
	double calculate(const string, double *, char *, int);
	double sizeforarray(const string);
public:
	Calculating(int, int);
};

