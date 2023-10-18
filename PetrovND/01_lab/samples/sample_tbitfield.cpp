#include <iostream>
#include "tset.h"

int main() {
    try {
        int a, b,c;
        cout << "Enter Bit Field 1 size" << endl;
        cin >> a;
        cout << "Enter Bit Field 2 size" << endl;
        cin >> b;
        cout << "Enter Bit Field 3 size" << endl;
        cin >> c;

        TBitField bf1(a);
        TBitField bf2(b);
        TBitField bf3(c);

        cin >> bf3;

        bf1.SetBit(2);
        bf1.SetBit(5);
        bf1.SetBit(8);

        bf2.SetBit(4);
        bf2.SetBit(5);
        bf2.SetBit(7);

        cout << "Bit Field 1: " << bf1 << endl;
        cout << "Bit Field 2: " << bf2 << endl;
        cout << "Bit Field 3: " << bf3 << endl;

        cout << "Bit Field 1 OR Bit Field 2: " << (bf1 | bf2) << endl;
        cout << "Bit Field 1 AND Bit Field 2: " << (bf1 & bf2) << endl;
        cout << "NOT Bit Field 1: " << ~bf1 << endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}