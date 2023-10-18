#include <iostream>
#include "tset.h"
int main()
{
    std::cout << "TSet" << std::endl;
    TSet a(10);
    a.InsElem(5);
    a.InsElem(3);
    a.InsElem(0);
    a.InsElem(9);
    cout << "Set a: " << a << endl;

    TSet c(10);
    c = a;
    c.DelElem(3);

    TSet d(10);
    d = a + c;
    cout << "(b + c) " << d << endl;
    cout << "(a + c) " << d << endl;

    TSet e(10);
    e = ~a;
    cout << "(~a) " << e << endl;

    TSet f(10);
    f = e * c;
    cout << "(e * c) " << f << endl;

    cout << "a == a? " << (a == a) << endl;
    cout << "a != a ? " << (a != a) << endl;
    return 0;
}
