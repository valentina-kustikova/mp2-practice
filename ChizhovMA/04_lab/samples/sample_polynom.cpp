#include <iostream>
#include "Monom.h"
#include "ListHeader.h"

using namespace std;

int main()
{
   
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    TPolynom p1(s1);
    TPolynom p2(s2);
    p1.Parse_Polynom(s1);
    p2.Parse_Polynom(s2);
    p1.Print_Polynom();
    p2.Print_Polynom();

    TPolynom p3;
    p3 = p1 + p2;
    p3.Print_Polynom();

   TPolynom p4;
    p4 = p1 - p2;
    p4.Print_Polynom();

    TPolynom p5;
    p5 = p1.difx();
    p5.Print_Polynom();

    TPolynom p6;
    p6 = p2.dify();
    p6.Print_Polynom();

    TPolynom p7;
    p7 = p2.difz();
    p7.Print_Polynom();

    TPolynom p8;
    p8 = p1 * p2;
    p8.Print_Polynom();
    cout << "p3 result:" << endl;
    double r = p3.operator()(2,3,4);
    cout << r << endl;
    return 0;
}