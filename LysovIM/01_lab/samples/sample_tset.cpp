#include <iostream>
#include "tset.h"
using namespace std;

void set() {
    cout << "Scan n - count numbers in set" << endl;
    int n;
    cin >> n;
    TSet s1(n);
    cin >> s1;
    cout << "Set 1:" << s1 << endl;
    TSet s2(n+1);
    cin >> s2;
    cout << "Set 2:" << s2 << endl;
    cout << "Set 1 == Set 2?: " <<"\t"<< (s1 == s2) << "\n" << endl;
    cout << "Set 1 + Set 2:" << "\t" << (s1 + s2) << endl;
    cout << "Set 1 + Element (0):" << "\t" << (s1 + 0) << endl;
    cout << "Set 1 - Element (1):" << "\t" << (s1 - 1) << endl;
    cout << "Set 1 * Set 2:" << "\t" << (s1 * s2) << endl;
    cout << "~ Set 1:" << "\t" << ~s1 << endl;
}

int main()
{
    try 
    { 
        set();
    }
    catch (string exp)
    {
        cout << exp << endl;
    }
}