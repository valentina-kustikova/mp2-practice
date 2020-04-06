#include <iostream>
#include "Polinom.h"

using namespace std;

void main()
{
    TList<double, unsigned int>* l1 = new TList<double, unsigned int>();
    l1->InsertEnd(4, -60);
    l1->InsertEnd(43, -50);
    l1->InsertEnd(326, 1.5);

    TNode<double, unsigned int>* node1 = new TNode<double, unsigned int>(200, 5);
    TNode<double, unsigned int>* node2 = new TNode<double, unsigned int>(17, 500);
    cout << "node1 " << *node1 << endl;
    cout << "node2 " << *node2 << endl;

    Polinom p1(l1);
    Polinom p2("-27.4x^2 + 5z^4 -2x^4y^4 +55z^4");
    Polinom p3("15z^2 - 13y^2z^2");
    Polinom p4;

    cout << "p1 " << p1 << endl;
    cout << "p2 " << p2 << endl;
    cout << "p3 " << p3 << endl;
    cout << "p4 is empty" << endl;
    Polinom res;

    cout << endl << "Tests" << endl;

    try
    {
        cout << endl << "1)  p1 + p2" << endl;
        res = p1 + p2;
        cout << "result:" << res << endl;
        cout << "p4 + p3" << endl;
        res = p4 + p3;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "2)  p1 - p2" << endl;
        res = p1 - p2;
        cout << "result:" << res << endl;
        cout << "p4 - p3" << endl;
        res = p4 - p3;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "3)  p2 * p3" << endl;
        res = p2 * p3;
        cout << "result:" << res << endl;
        cout << "p1 * p2" << endl;
        res = p1 * p2;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "4)  p1 += p2" << endl;
        p1 += p2;
        cout << "result:" << p1 << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "5)  p1 -= p2" << endl;
        p1 -= p2;
        cout << "result:" << p1 << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "6)  p2 + node1" << endl;
        res = p2 + *node1;
        cout << "result:" << res << endl;
        cout << "p2 + node2" << endl;
        res = p2 + *node2;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "7)  p2 - node1" << endl;
        res = p2 - *node1;
        cout << "result:" << res << endl;
        cout << "p2 - node2" << endl;
        res = p2 - *node2;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "8)  p2 * node1" << endl;
        res = p2 * *node1;
        cout << "result:" << res << endl;
        cout << "p2 * node2" << endl;
        res = p2 * *node2;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "9)  p1 += node1" << endl;
        p1 += *node1;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "10)  p1 -= node1" << endl;
        p1 += *node1;
        cout << "result:" << res << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "11)  p2 *= node2" << endl;
        p2 *= *node2;
        cout << "result:" << p2 << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    try
    {
        cout << endl << "12)  p3 = -p3" << endl;
        p3 = -p3;
        cout << "result:" << p3 << endl;
    }
    catch (const char* str)
    {
        cout << str << endl;
    }
}