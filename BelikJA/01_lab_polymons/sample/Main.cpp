#include <iostream>
#include "TPolynom.h"
#include <string>

using namespace std;

void main()
{
    string st = "26x^3y^7z^9+2y^8-3x^6+5";
    cout << "Polynom " << endl;
    cin >> st;
    int i;
    try
    {
        TPolynom a(st);
        cout << "Choose test:" << endl <<
            "1 - + polynom" << endl <<
            "2 - - polynom" << endl <<
            "3 - * polynom" << endl <<
            "4 - + monom" << endl <<
            "5 - - monom" << endl <<
            "6 - * monom" << endl <<
            "7 - * const" << endl <<
            "8 - += polynom" << endl <<
            "9 - -= polynom" << endl <<
            "10 - *= polynom" << endl <<
            "11 - += monom" << endl <<
            "12 - -= monom" << endl <<
            "13 - *= monom" << endl <<
            "14 - *= const" << endl <<
            "15 - unary minus" << endl;
        cin >> i;
        switch (i)
        {
        case 1:
            try
            {
                cin >> st;
                TPolynom b(st);
                TPolynom c = a + b;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 2:
            try
            {
                cin >> st;
                TPolynom b(st);
                TPolynom c = a - b;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 3:
            try
            {
                cin >> st;
                TPolynom b(st);
                TPolynom c = a * b;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 4:
            try
            {
                cin >> st;
                TNode<unsigned int, double> b(st);
                TPolynom c = a + b;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 5:
            try
            {
                cin >> st;
                TNode<unsigned int, double> b(st);
                TPolynom c = a - b;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 6:
            try
            {
                cin >> st;
                TNode<unsigned int, double> b(st);
                TPolynom c = a * b;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 7:
            try
            {
                double b;
                cin >> b;
                TPolynom c = a * b;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 8:
            try
            {
                cin >> st;
                TPolynom b(st);
                a += b;
                cout << a;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 9:
            try
            {
                cin >> st;
                TPolynom b(st);
                a -= b;
                cout << a;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 10:
            try
            {
                cin >> st;
                TPolynom b(st);
                a *= b;
                cout << a;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 11:
            try
            {
                cin >> st;
                TNode<unsigned int, double> b(st);
                a += b;
                cout << a;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 12:
            try
            {
                cin >> st;
                TNode<unsigned int, double> b(st);
                a -= b;
                cout << a;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 13:
            try
            {
                cin >> st;
                TNode<unsigned int, double> b(st);
                a *= b;
                cout << a;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 14:
            try
            {
                double b;
                cin >> b;
                a *= b;
                cout << a;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        case 15:
            try
            {
                TPolynom c = -a;
                cout << c;
            }
            catch (char* er)
            {
                cout << er;
            }
            break;
        default:
            break;
        }
    }
    catch (char* er)
    {
        cout << er;
    }
    cout << endl << "Test passed" << endl;
    cin >> st;
}