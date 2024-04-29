#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "tpolynom.h"

void test_polynom()
{
    string s1, s2;
    cout << "Input 2 polynom\n";
    
    getline(cin, s1);
    getline(cin, s2);
    TPolynom p;
    TPolynom p1(s1), p2(s2);
   
    cout << "First polynom\n" << p1 << endl;
    cout << "Second polynom\n" << p2 << endl;
    TPolynom p3(p1);
    cout << "Copy constuctor\n" << endl;
    cout << p3 << endl << endl;;

    cout << "SUM\n";
    cout << (p1 + p2) << endl;
    cout << "SUB\n";
    cout << (p1 - p2) << endl;
    TPolynom t(p1 * p2);
    cout << "prod\n";
    cout << t << endl;
    cout << "diff x\n";
    cout << p2.dif_x() << endl;
    cout << "diff y\n";
    cout << p2.dif_y() << endl;
    cout << "diff z\n";
    cout << p2.dif_z() << endl;
    cout << p2(1, 1, 1) << endl;
}
int main() {
    test_polynom();
}