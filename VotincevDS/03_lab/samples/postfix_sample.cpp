#include <iostream>
#include "array_stack.h"
#include "list_stack.h"
#include "postfix_form.h"
using namespace std;

int main()
{
    const string s = "A + B - C - D + -1";
    ArithmeticExpression expr(s);
    for (int i = 0; i < expr.expr.size(); i++) {
        cout << expr.expr[i] << '_';
    }

    //  что делает программа?
    // 1) спрашивает какой стек используем (лучше Enum) +
    // 2) пользователь вводит строку +
    // 3) строка преобразовывается в постфиксную форму ( строка в строку) (class Arifmetic)
    // 4) считаем само выражение
    //  4.1 заполняю стек
    //  4.2 запрашиваем данные
    //  4.3 считаю
    // 5) ввод на экран ответа



    //ArrayStack<int> l;
    /*ListStack<int> l;
    cout << l.IsEmpty() << '\n';
    cout << l.IsFull() << '\n';
    l.push(10);
    l.pop();
    l.push(15);
    l.push(15);
    l.push(15);
    l.push(15);
    l.push(15);
    cout << l.Top() << '\n';*/
    
    
    
    

    /*setlocale(LC_ALL, "Russian");

    cout << "Введите, какой стек тестируем\n" <<
        "0 - ArrayStack   1 - ListStack\n";*/
        /*char stack_type;
        cin >> stack_type;
        cin.ignore();
        while (stack_type != '0' && stack_type != '1') {
            cout << "Неверно выбран стек\n";
            cin >> stack_type;
            cin.ignore();
        }

        if (stack_type == '0') {
            ArrayStack<string> pf_stack;
            string expr;
            cout << "Введите выражение\n";
            getline(cin, expr);
            string pf = postfixform(expr, pf_stack);
            cout << "Постфиксная форма:\n" << pf << '\n';
            cout << "Result: " << solvepf(pf_stack);
        } else {
            ListStack<string> pf_stack;
            string expr;
            cout << "Введите выражение\n";
            getline(cin, expr);
            string pf = postfixform(expr, pf_stack);
            cout << "Постфиксная форма:\n" << pf << '\n';
            cout << "Result: " << solvepf(pf_stack);
        }
        return 0;*/

    return 0;
}