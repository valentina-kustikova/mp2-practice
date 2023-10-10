#include <iostream>
#include "tbitfield.h"

int main()
{
    const int size1 = 4, size2 = 6;
    TBitField set1(size1), set2(size2);
    bool a = (set1 != set2);
    bool b = (set1 == set2);
    std::cout << a << endl << b << std::endl;
    TBitField c;
    TBitField d(set1);
    d.SetBit(2);
    d.SetBit(3);
    cout << d.GetLength() << endl;
    d.ClrBit(3);
    c = set2;
    c.SetBit(0);
    set1 = c | d;
    set2 = c & d;
    cout << set1 << endl << set2 << endl;
    c = ~d;
    cout << c << endl;
    return 0;
}
