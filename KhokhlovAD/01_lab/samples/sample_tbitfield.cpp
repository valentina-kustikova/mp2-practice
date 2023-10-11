#include <iostream>
#include "tbitfield.h"

int main()
{
    const int size1 = 4, size2 = 6;
    TBitField set1(size1), set2(size2);
    bool a = (set1 != set2);
    bool b = (set1 == set2);
    cout << "bf1 = " << set1 << endl << "b2 = " << set2 << endl;
    std::cout <<"bf1 != bf2 -> " << a << endl <<"bf1 == bf 2 -> " << b << std::endl;
    TBitField c;
    TBitField d(set1);
    d.SetBit(2);
    d.SetBit(3);
    cout << "bf3 = " << d << endl;
    int z = d.GetLength();
    cout << "bf3.lenght = " << z << endl;
    d.ClrBit(2);
    cout << "bf3.clrbit(2) = " << d << endl;
    c = set2;
    cout << "bf4 = bf2 -> " << c << endl;
    c.SetBit(0);
    cout << "bf4.setbit(0) -> " << c << endl;
    set1 = c | d;
    cout << "bf1 = bf3 | bf4 -> " << set1 << endl;
    set2 = c & d;
    cout <<"bf2 = bf3 & bf4 -> "<< set2  << endl;
    c = ~d;
    cout <<"bf3 = ~bf4 -> " << c << endl;
    return 0;
}
