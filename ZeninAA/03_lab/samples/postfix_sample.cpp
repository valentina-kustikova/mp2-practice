#include "postfix_form.h"
#include <iostream>
using namespace std;
int main()
{
    string infix = setInfix();

    PostfixForm let(infix, set_type_of_stack());
    let.setOp();

    cout << let.getInfix() << "\n" << let.getPostfix() << "\n" << let.count();

    return 0;
}