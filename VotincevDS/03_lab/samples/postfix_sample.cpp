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

    //  ��� ������ ���������?
    // 1) ���������� ����� ���� ���������� (����� Enum) +
    // 2) ������������ ������ ������ +
    // 3) ������ ����������������� � ����������� ����� ( ������ � ������) (class Arifmetic)
    // 4) ������� ���� ���������
    //  4.1 �������� ����
    //  4.2 ����������� ������
    //  4.3 ������
    // 5) ���� �� ����� ������



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

    cout << "�������, ����� ���� ���������\n" <<
        "0 - ArrayStack   1 - ListStack\n";*/
        /*char stack_type;
        cin >> stack_type;
        cin.ignore();
        while (stack_type != '0' && stack_type != '1') {
            cout << "������� ������ ����\n";
            cin >> stack_type;
            cin.ignore();
        }

        if (stack_type == '0') {
            ArrayStack<string> pf_stack;
            string expr;
            cout << "������� ���������\n";
            getline(cin, expr);
            string pf = postfixform(expr, pf_stack);
            cout << "����������� �����:\n" << pf << '\n';
            cout << "Result: " << solvepf(pf_stack);
        } else {
            ListStack<string> pf_stack;
            string expr;
            cout << "������� ���������\n";
            getline(cin, expr);
            string pf = postfixform(expr, pf_stack);
            cout << "����������� �����:\n" << pf << '\n';
            cout << "Result: " << solvepf(pf_stack);
        }
        return 0;*/

    return 0;
}