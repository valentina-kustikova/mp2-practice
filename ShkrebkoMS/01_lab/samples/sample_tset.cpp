#include <iostream>
#include "tset.h"



void set() {
    int n;
    cout << "Enter len" << endl;
    cin >> n;
    TSet s1(n);
    TSet s2(n);
    cout << "Enter s1" << endl;
    cin >> s1;
    cout << "1:" << s1 << endl;
    cout << "Enter s2" << endl;
    cin >> s2;
    cout << "2:" << s2 << endl;


    cout << "1==2:" << (s1 == s2) << "\n" << endl;
    cout << "+:" << (s1 + s2) << endl;
    cout << "+(Element):" << (s2 + 2) << endl;
    cout << "-(Element):" << (s1 - 4) << endl;
    cout << "*:" << (s1 * s2) << endl;
    cout << "~1:" << ~s1 << endl;
}

int main()
{
    try { 
        set(); 
    }
    catch (const char* exception) {
        cout << exception << endl;
    }
}