#include <iostream>
#include "tset.h"


int main()
{
    const int size1 = 4, size2 = 6;
    TSet set1(size1), set2(size2);
    bool a = (set1 != set2);
    bool b = (set1 == set2);
    std::cout << a << endl << b << std::endl;
    TSet c;
    TSet d(set1);
    d.InsElem(3);
    cout << d << endl;
    int g = d.GetMaxPower();
    cout << g << endl;
    c = d;
    d.DelElem(3);
    cout << c << endl;
    cout << d << endl;
    d = c + set2;
    cout << d << endl;
    set1 = ~d;
    cout << set1 << endl;
    set2 = set1 * d;
    cout << set2 << endl;
    return 0;
}
