#ifndef Fnc_H
#define Fnc_H
#include "TLink.h"
#include "TList.h"
#include "TStack.h"
#include <iostream>
#include <string>
#include <map>
class Fnc
{
public:
	static int prioretet(char a);
	static string correct(string s);
	static string postfix_form(string s);
	static float calculations(string s);
	static map<char, float> readtoken(const string&s);
};
#endif 