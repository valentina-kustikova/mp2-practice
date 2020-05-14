#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include "../Polinom/Polynom.h"

using namespace std;

int main()
{

    string s1;
    string s2;

    cout << "--------Polynom--------" << endl << endl;
    //пример
    cout << "Enter the first polynom :" << endl;
    cin >> s1;
    cout << "Insert 2nd polynom" << endl;
    cin >> s2;

    Polynom p1(s1);
    Polynom p2(s2);
    try
    {
        cout << "1 polynom:" << endl << p1 << endl;
        cout << "2 polynom:" << endl << p2 << endl;
        cout << "Sum: " << p1 + p2 << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "Substraction: " << p1 - p2 << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << "Multiplication: " << p1 * p2 << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    system("pause");
}
