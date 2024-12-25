#include "postfix_form.h"
#include <iostream>
using namespace std;
int main()
{
    string infix = setInfix();
    PostfixForm bob(infix, setStackType());
    bob.setOperands();
    cout << bob.getInfix() << "\n" << bob.getPostfix() << "\n" << bob.calculate();
    return 0;
}