#include <iostream>
#include "tset.h"

int main()
{
    cout << "Input a size of your set:\n";
    int size; 
    cin >> size;
    cout << "Input your 1 set:\n";
    TSet s1(size);
    cin >> s1;
    cout << "Input your 2 set:\n";
    TSet s2(size);
    cin >> s2;

    std::cout << "s1 = " << s1 << endl;
    std::cout << "s2 = " << s2 << "\n" << endl;

    std::cout << "~s1: " << ~s1 << "\n" << endl;

    std::cout << "operator==: " << (s1 == s2) << endl;
    std::cout << "operator!=: " << (s1 != s2) << endl;
    std::cout << "operator+: " << (s1 + s2) << endl;
    std::cout << "operator*: " << (s1 * s2) << endl;

    std::cout << "operator+ (elem = 0): " << (s1 + 0) << endl;
    std::cout << "operator- (elem = 3): " << (s1 - 3) << endl;

    return 0;
}