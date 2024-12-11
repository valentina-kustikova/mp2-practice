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
        STACK_IMPL impl; 
        std::map<std::string, int> priority_s = { { "+", 0},{"-", 1},{"!",1},{"*", 2},{"/", 3},{"(",4} };
        std::map<std::string, double> var;
    public:
        ArExpression(const std::string&, STACK_IMPL impl = ARRAY_STACK);
        void GetValue();
        double Calculate();
    };
};
#endif 


