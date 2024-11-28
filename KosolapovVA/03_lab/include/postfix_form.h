#ifndef Postfix_form_H
#define Postfix_form_H

#include "stack.h"
#include "arr_stack.h"
#include <map>



ArrStack<char> InfToPost(std::string inf);
bool check_Symb(char s);
bool check_Numb(char s);
bool check_Oper(char s);
void StackToStack(ArrStack<char> &s1, ArrStack<char> &s2);
void GetValue(std::map<char, double>& variety, ArrStack<char> temp);
double Counting(std::map<char, double>& variety, ArrStack<char>& temp);

std::string Convert_Oper(char s);
#endif // !Postfix_form_H




