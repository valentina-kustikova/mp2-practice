#include <iostream>
#include "tset.h"
const int n = 5;
using namespace std;

void set() {
    TSet s1(n);
    TSet s2(n);
    cin >> s1;
    cout << "Set 1:" << s1 << endl;
    cin >> s2;
    cout << "Set 1:" << s2 << endl;
    cout << "Set 1 == Set 2?: " <<"\t"<< (s1 == s2) << "\n" << endl;
    cout << "Set 1 + Set 2:" << "\t" << (s1 + s2) << endl;
    cout << "Set 1 + Element (0):" << "\t" << (s1 + 0) << endl;
    cout << "Set 1 - Element (1):" << "\t" << (s1 - 1) << endl;
    cout << "Set 1 * Set 2:" << "\t" << (s1 * s2) << endl;
    cout << "~ Set 1:" << "\t" << ~s1 << endl;
}

int main()
{
    try { set(); }
    catch (string exp) {
        cout << exp << endl;
    }
}