#include "postfix_form.h"
#include <iostream>
using namespace std;
int main()
{
    string infix_form = setInfix();

    PostfixForm let(infix_form, set_type_of_stack());
    let.setOp();

    cout << let.getInfix() << "\n" << let.getPostfix() << "\n" << let.count();

    return 0;
}