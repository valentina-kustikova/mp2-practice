#include <iostream>
#include "Monom.h"
#include "Polynom.h"
#include "ListHeader.h"

using namespace std;

int main()
{
    
    string s1;
    string s2;
    cout << "Enter first polynom:" << endl;
    cin >> s1;
    cout << "Enter second polynom:" << endl;
    cin >> s2;
    try {
        TPolynom p1(s1);
        TPolynom p2(s2);
        cout << p1;
        cout << p2;

        TPolynom p3;
        p3 = p1 + p2;
        cout << "p3 = p2+p1" << endl;
        cout << p3;

        TPolynom p4;
        p4 = p1 - p2;
        cout << "p4 = p1-p2" << endl;
        cout << p4;

        TPolynom p5;
        p5 = p1 * p2;
        cout << "p5 = p1*p2" << endl;
        cout << p5;

        TPolynom p6;
        p6 = p1.difx();
        cout << "p6 = p1.dif_x" << endl;
        cout << p6;

        TPolynom p7;
        p7 = p2.dify();
        cout << "p7 = p2.dif_y" << endl;
        cout << p7;

        TPolynom p8;
        p8 = p2.difz();
        cout << "p8 = p2.dif_z" << endl;
        cout << p8;

        double _x, _y, _z;
        cout << "Enter x: ";
        cin >> _x;
        cout << "Enter y: ";
        cin >> _y;
        cout << "Enter z: ";
        cin >> _z;
        cout << "p5 result:" << endl;
        double r = p5(_x, _y, _z);
        cout << r << endl;

    }
    catch (string msg) {
        cout << msg << endl;
    }
    

    /*
    TList<int> list;
    list.InsertFirst(42);
    list.InsertEnd(10);
    list.Next();
    list.InsertAfterCurr(5);

    TRingList<int> rlist(list);
    TRingList<int> rlist2(rlist);
   
    TRingList<int> rl;
    rl.InsertFirst(5);
    rl.InsertEnd(3);
    rl.InsertEnd(4);
    rl.InsertFirst(10);
    rl.InsertEnd(2);
    rl.InsertBefore(7,4);
    rl.InsertAfter(8,2);
    cout << rl << endl;
    rl.Remove(2);
    TRingList<int> rl2(rl);
    cout << rl2 << endl;
    */
    return 0;
}