#include <iostream>
#include "array_stack.h"
#include "list_stack.h"
#include "postfix_form.h"
using namespace std;

int main()
{
    // A+(B-C)*D-F/(G+H)
    setlocale(LC_ALL, "Russian");

    cout << "�������, ����� ���� ���������\n" <<
        "0 - ArrayStack   1 - ListStack\n";
    char stack_type;
    cin >> stack_type;
    cin.ignore();
    while (stack_type != '0' && stack_type != '1') {
        cout << "������� ���������� ���\n";
        cin >> stack_type;
        cin.ignore();
    }

    string s;
    cout << "\n������� ���������:\n";
    getline(cin, s);

    ArithmeticExpression expr;
    if (stack_type == '0') {
        expr = ArithmeticExpression::ArithmeticExpression(s,ARRAY_STACK);
    }
    else {
        expr = ArithmeticExpression::ArithmeticExpression(s, LIST_STACK);
    }
    
    double res = expr.compute({});
    cout << "\nRes = " << res;

    return 0;
}