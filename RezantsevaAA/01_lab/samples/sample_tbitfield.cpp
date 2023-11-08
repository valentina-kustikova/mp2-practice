#include <iostream>
#include "tbitfield.h"

int main()
{
    std::cout << "TBitField" << std::endl;
    try {
        TBitField bf1(6);
        TBitField bf2(6);

        // bf1 = 001011
        bf1.SetBit(2);
        bf1.SetBit(4);
        bf1.SetBit(5);

        // bf2 = 110101
        bf2.SetBit(0);
        bf2.SetBit(1);
        bf2.SetBit(3);
        bf2.SetBit(5);

        std::cout << "bf1 = " << bf1 << endl;
        std::cout << "bf2 = " << bf2 << "\n" << endl;

        bf1.SetBit(0);
        std::cout << "bf1.SetBit(0): " << bf1 << endl;
        bf1.ClrBit(0);
        std::cout << "bf1.ClrBit(0): " << bf1 << endl;
        std::cout << "~bf1: " << ~bf1 << "\n" << endl;

        std::cout << "bf1.GetBit(0): " << bf1.GetBit(0) << endl;
        std::cout << "bf1.GetBit(5): " << bf1.GetBit(5) << "\n" << endl;

        std::cout << "operator==: " << (bf1 == bf2) << endl;
        std::cout << "operator!=: " << (bf1 != bf2) << endl;
        std::cout << "operator|: " << (bf1 | bf2) << endl;
        std::cout << "operator&: " << (bf1 & bf2) << endl;
    }
    catch (string exp) {
        std::cout << exp << endl;
    }
    return 0;
}
