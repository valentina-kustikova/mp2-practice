#include <iostream>
#include "tset.h"
const int n=5;
using namespace std;

void set() {
    TSet s1(n);
    TSet s2(n);
    cin >> s1;
    cout << "1:" << s1 << endl;
    s2.InsElem(0);
    s2.InsElem(1);
    s2.InsElem(2);
    s2.InsElem(3);
    s2.InsElem(4);
    cout << "2:" << s2 <<endl;
    cout << "1==2:" << (s1 == s2) << "\n" << endl;
    cout << "+:" << (s1 + s2) << endl;
    cout << "+(Element):" << (s1 + 0) << endl;
    cout << "-(Element):" << (s1 - 1) << endl;
    cout << "*:" << (s1 * s2) << endl;
    cout << "~1:" << ~s1 << endl;
}

int main()
{
    try {set();}
    catch (string exp) {
        cout << exp << endl;
    }
}
