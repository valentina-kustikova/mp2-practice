#ifndef Postfix_form_H
#define Postfix_form_H

#include "stack.h"
#include "arr_stack.h"
#include "list_stack.h"
#include <map>
#include <vector>
#include <string.h>


namespace posfix_form
{
    enum STACK_IMPL
    {
        ARRAY_STACK = 0,
        LIST_STACK = 1,
    };

    class ArExpression
    {
    private:
        std::string infix;
        Stack<std::string>* postfix;
        Stack<double>* res;
        STACK_IMPL impl;
        std::map<std::string, int> priority_s = { { "+", 1},{"-", 1},{"!",5},{"*", 2},{"/", 2},{"(",0} };
        std::map<std::string, double> var;
    public:
        ArExpression(const std::string&, STACK_IMPL impl = ARRAY_STACK);
        void GetVariable();
        void GetVariable(std::map<std::string, double> &variable);
        std::string GetPostfix();
        double Calculate();
    };
};


bool check_Symb(char s);
bool check_Numb(char s);
bool check_Oper(char s);
void StackToStack(Stack<std::string>& s1, Stack<std::string>& s2);



void Check_Start(int&, char, std::string&, Stack<std::string>*&, Stack<std::string>*&);
void Check_After_Minus(int&, char, std::string&, Stack<std::string>*&, Stack<std::string>*&);
void Check_After_Oper(int&, char, std::string&, Stack<std::string>*&, Stack<std::string>*&);
void Check_After_Symb(int&, char, std::map<std::string, int>, std::string&, Stack<std::string>*&, Stack<std::string>*&);
void Check_After_Numb(int&, char, std::map<std::string, int> , std::string&, Stack<std::string>*&, Stack<std::string>*&);
void Check_After_Right_Br(int& , char,std::map<std::string, int>, std::string&, Stack<std::string>*&, Stack<std::string>*&);


void Oper_After(int&, char, std::map<std::string, int> , std::string&, Stack<std::string>*&, Stack<std::string>*&);
void Right_Br_After(int&, char, std::map<std::string, int>, std::string&, Stack<std::string>*&, Stack<std::string>*&);

#endif 


