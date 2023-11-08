#include <iostream>

#include "tset.h"

int main()
{
    std::cout << "TSet" << std::endl;

    try {
        TSet s1(6);
        TSet s2(6);

        // s1 = 0010110 
        s1.InsElem(2);
        s1.InsElem(4);
        s1.InsElem(5);

        // s2 = 1101010
        s2.InsElem(0);
        s2.InsElem(1);
        s2.InsElem(3);
        s2.InsElem(5);

        std::cout << "s1 = " << s1 << endl;
        std::cout << "s2 = " << s2 << "\n" << endl;

        s1.InsElem(0);
        std::cout << "s1.InsElem(0): " << s1 << endl;
        s1.DelElem(0);
        std::cout << "s1.DelElem(0): " << s1 << endl;
        std::cout << "~s1: " << ~s1 << "\n" << endl;

        std::cout << "s1.IsMember(0): " << s1.IsMember(0) << endl;
        std::cout << "s1.IsMember(5): " << s1.IsMember(5) << "\n" << endl;

        std::cout << "operator==: " << (s1 == s2) << endl;
        std::cout << "operator!=: " << (s1 != s2) << endl;
        std::cout << "operator+: " << (s1 + s2) << endl;
        std::cout << "operator*: " << (s1 * s2) << endl;

        std::cout << "operator+ (elem = 0): " << (s1 + 0) << endl;
        std::cout << "operator- (elem = 5): " << (s1 - 5) << endl;
      
    }
    catch (string exp) {
        cout << exp << endl;
    }
    return 0;
}
