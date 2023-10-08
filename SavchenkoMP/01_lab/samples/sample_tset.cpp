#include <iostream>
#include "tset.h"

using namespace std;

int main()
{
    std::cout << "TSet\n" << std::endl;

    try {
        TSet s1(6);
        TSet s2(6);

        // s1 = 001011
        s1.InsElem(2);
        s1.InsElem(4);
        s1.InsElem(5);

        // s2 = 110101
        s2.InsElem(0);
        s2.InsElem(1);
        s2.InsElem(3);
        s2.InsElem(5);

        cout << "s1 = " << s1 << endl;
        cout << "s2 = " << s2 << "\n" << endl;

        s1.InsElem(0);
        cout << "s1.InsElem(0): " << s1 << endl;
        s1.DelElem(0);
        cout << "s1.DelElem(0): " << s1 << endl;
        cout << "~s1: " << ~s1 << "\n" << endl;

        cout << "s1.IsMember(0): " << s1.IsMember(0) << endl;
        cout << "s1.IsMember(5): " << s1.IsMember(5) << "\n" << endl;

        cout << "operator==: " << (s1 == s2) << endl;
        cout << "operator!=: " << (s1 != s2) << endl;
        cout << "operator+: " << (s1 + s2) << endl;
        cout << "operator+ (elem): " << (s1 + 0) << endl;
        cout << "operator- (elem): " << (s1 - 5) << endl;
        cout << "operator*: " << (s1 * s2) << endl;
    }
    catch (string exp) {
        cout << exp << endl;
    }

    return 0;
}
