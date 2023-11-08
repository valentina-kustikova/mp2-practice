#include <iostream>
#include "tbitfield.h"
#define N 8

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "TBitField:" << std::endl;
    TBitField a(N);
    cin >> a;
    std::cout << "BitField a:\n" << a << endl;

    TBitField b(N);
    cin >> b;
    std::cout << "BitField b:\n" << b << endl;

    TBitField c(N);
    c = a | b;
    std::cout << "BitField c = a | b:\n" << c << endl;

    TBitField d(N);
    d = c & b;
    std::cout << "BitField d = a & c:\n" << d << endl;

    TBitField e(N);
    e = ~c;
    std::cout << "BitField e = ~c:\n" << e << endl;

    TBitField f(N);
    cin >> f;
    cout << "Your input bitfield: " << f;


    return 0;
}