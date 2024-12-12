#include <iostream>
#include "array_stack.h"
#include "list_stack.h"
#include "postfix_form.h"
using namespace std;

int main()
{
    // -(A+B-C*g)+15*g/7*kl

    setlocale(LC_ALL, "Russian");

    cout << "¬ведите, какой стек тестируем\n" <<
        "0 - ArrayStack   1 - ListStack\n";
    char stack_type;
    cin >> stack_type;
    cin.ignore();
    while (stack_type != '0' && stack_type != '1') {
        cout << "¬ведите правильный тип\n";
        cin >> stack_type;
        cin.ignore();
    }


    string s;
    cout << "\n¬ведите выражение:\n";
    getline(cin, s);

    STACK_IMPL stack_impl;
    switch (stack_type)
    {
        case '0': stack_impl = ARRAY_STACK;
        case '1': stack_impl = LIST_STACK;
    }
    ArithmeticExpression expr(s, stack_impl);

    double res = expr.compute({});
    cout << "\nRes = " << res;

    return 0;
}