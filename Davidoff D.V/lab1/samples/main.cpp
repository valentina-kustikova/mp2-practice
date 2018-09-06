#include "TLink.h"
#include "TList.h"
#include "TStack.h"
#include "Fnc.h"
#include <iostream>
#include <string>
using namespace std;


void main()
{
	string s;
	float Result;
	cout << "Write your expression: " << endl;
	getline(cin, s);
	try
	{
		s = Fnc::correct(s);
	}
	catch (const char*ex)
	{
		cout << endl << ex << endl;
		return;
	}
	s = Fnc::postfix_form(s);
	
	try
	{
		Result = Fnc::calculations(s);
	}
	catch (const char*ex)
	{
		cout << endl << ex << endl;
		return;
	}
	
	cout << endl << "The result is: " << Result << endl;
	
}