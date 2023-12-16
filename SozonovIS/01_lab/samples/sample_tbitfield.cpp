#include "tbitfield.h"
#include <iostream>

using namespace std;

int main() {
    try {
        int maxsize;
        cout << "Enter Bit Field maxSize: ";
        cin >> maxsize;
        cout << endl;

        TBitField bf1(maxsize);
        TBitField bf2(maxsize);

        cin >> bf1;
        cout << endl;
        cin >> bf2;
        cout << endl;

        cout << "Bit Field 1: " << bf1 << endl;
        cout << "Bit Field 2: " << bf2 << endl;
        cout << endl;

        cout << "Bit Field 1 == Bit Field 2? " << (bf1 == bf2) << endl;
        cout << "Bit Field 1 != Bit Field 2? " << (bf1 != bf2) << endl;
        cout << endl;

        cout << "Bit Field 1 OR Bit Field 2: " << (bf1 | bf2) << endl;
        cout << "Bit Field 1 AND Bit Field 2: " << (bf1 & bf2) << endl;
        cout << "NOT Bit Field 1: " << ~bf1 << endl;
        cout << endl;

        int bit;
        cout << "Enter additional bit: ";
        cin >> bit;
        cout << endl;

        bf1.SetBit(bit);
        cout << "Bit Field 1: " << bf1 << endl;
        cout << endl;

        cout << "Enter deductible bit: ";
        cin >> bit;
        cout << endl;

        bf2.ClrBit(bit);
        cout << "Bit Field 2: " << bf2 << endl;
    }
    catch (exception exp) {
        cout << exp.what();
    }
    return 0;
}
