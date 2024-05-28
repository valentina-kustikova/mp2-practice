#include <iostream>
#include "tpolynom.h"

int main()
{
    try{
        int x, y, z;
        TPolynom a, b;
        cout << "enter first polynom = ";
        cin >> a;
        cout << endl << "first polynom =" << a << endl;

        cout << "enter second polynom = ";
        cin >> b;
        cout << endl << "first polynom =" << b << endl;
        string abc =  "-2*x^2*y^4*z^7+34*x^3*y"; // x^3*y^2*z-27*z^4


        cout << "a.dif(): " << a.dif();
        cout << "b-a: " << b - a;
        cout << "b * a" << b * a;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
        cout << "z = ";
        cin >> z;
        double res = a(x, y, z);
        cout <<"a(x, y, z) = " << res;
    }
    catch (const std::exception& ex)
    {
        cout << ex.what();
    }
    return 0;
}
