#include <iostream>
#include "../include/Polinom.h"
#include "../include/Exception.h"

using namespace std;

int main()
{
    TPolinom P1, P2;
    try
    {
        cout << "Enter the first polynom:" << endl;
        cin >> P1;
        cout << "Enter the second polynom:" << endl;
        cin >> P2;
    

        cout << "Sum:" << endl;
        cout << P1 + P2 << endl;
        cout << "Substraction" << endl;
        cout << P1 - P2 << endl;
        cout << "Multiplication" << endl;
        cout << P1 * P2 << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    system("pause");
}