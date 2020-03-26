#pragma once
#include "Stack.h"
#include <string>
using namespace std;
class Calculating
{
private:
	static bool priority(char, char);
	static double calculator(double, double, char);
public:
	static string create_postfix(const string);
	static void get_operands(const string, double *&, char *&, int &);
	static double calculate(const string, const double *, const char *, int);
};
