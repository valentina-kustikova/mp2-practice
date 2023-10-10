#include <iostream>
#include "tset.h"

int main() {
    try {
        TBitField bf1(10);
        TBitField bf2(10);

        bf1.SetBit(2);
        bf1.SetBit(5);
        bf1.SetBit(8);

        bf2.SetBit(4);
        bf2.SetBit(5);
        bf2.SetBit(7);

        std::cout << "Bit Field 1: " << bf1 << std::endl;
        std::cout << "Bit Field 2: " << bf2 << std::endl;

        TBitField bf3 = bf1 | bf2;
        std::cout << "Bit Field 1 OR Bit Field 2: " << bf3 << std::endl;

        TBitField bf4 = bf1 & bf2;
        std::cout << "Bit Field 1 AND Bit Field 2: " << bf4 << std::endl;

        TBitField bf5 = ~bf1;
        std::cout << "NOT Bit Field 1: " << bf5 << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}