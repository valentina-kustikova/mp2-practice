#include <iostream>
#include "TPolynom.h"
using namespace std;

int main()
{
    try
    {
        TPolynom first, second;
        cout << "First polynom:" <<endl;
        cin >> first;
        cout << "Second polynom:" <<endl;
        cin >> second;
        cout << "Sum:" <<endl;
        cout << first + second <<endl;
        cout << "Substraction" <<endl;
        cout << first - second <<endl;
        cout << "Multiplication" <<endl;
        cout << first * second << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    system("pause");
}