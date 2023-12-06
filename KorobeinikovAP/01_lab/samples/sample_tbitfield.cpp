#include <iostream>
#include "tbitfield.h"


int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "TBitField:" << std::endl;
    TBitField a(8);
    a.SetBit(3);
    a.SetBit(5);
    a.SetBit(7);
    std::cout <<"BitField a:\n" << a << endl;

    TBitField b(8);
    b = a;
    b.ClrBit(5);
    b.ClrBit(7);
    b.SetBit(4);
    std::cout << "BitField b:\n" << b << endl;

    TBitField c(8);
    c = a | b;
    std::cout << "BitField c = a | b:\n" << c << endl;

    TBitField d(8);
    d = c & b;
    std::cout << "BitField d = a & c:\n" << d << endl;

    TBitField e(8);
    e = ~c;
    std::cout << "BitField e = ~c:\n" << e << endl;

    TBitField f(8);
    cin >> f;
    cout << "Your input bitfield: " << f;


    return 0;
}
