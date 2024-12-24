#include "postfix_form.h"
#include <iostream>
using namespace std;
int main()
{
    string infix = setInfix();
    PostfixForm tmp(infix, setStackType());
    tmp.setOperands();
    cout << tmp.getInfix() << "\n" << tmp.getPostfix() << "\n" << tmp.calculate();
    return 0;
}
