#include "postfix_form.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "�������, ����� ���� ���������\n" <<
        "0 - ArrayStack   1 - ListStack\n";
    char stack_type;
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
    return 0;
}
