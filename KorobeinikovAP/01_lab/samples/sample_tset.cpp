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
    
    TSet b(10);
    b = a;
    b.DelElem(3);
    b.DelElem(9);
    b.InsElem(8);
    b.InsElem(4);
    cout << "Set b: (in a insert 8, 4; from a delete 3, 9) " << b << endl;

    TSet c(11);
    c = a;
    c = c - 5;
    c = c - 0;
    c = c + 2;
    c = c + 7;
    cout << "Set c: (a - 0 - 5 + 2 + 7) " << c << endl;

    TSet d(10);
    d = a + c;
    cout << "Set d: (a + c) " << d << endl;

    TSet e(10);
    e = ~a;
    cout << "Set e: (~a) " << e << endl;

    TSet f(10);
    f = e * c;
    cout << "Set f: (e * c) " << f << endl;

    cout << "a == a? " << (a == a) << endl;
    cout << "a != a ? " << (a != a) << endl;
    return 0;
}
