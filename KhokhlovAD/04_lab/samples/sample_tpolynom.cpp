#include <iostream>
#include "tpolynom.h"

int main()
{
    try{
        int x, y, z;
        TPolynom tmp;
        cout << "enter polynom = ";
        cin >> tmp;
        cout << endl << "new polynom =" << tmp << endl;
        string a =  "-2*x^2*y^4*z^7+34*x^3*y"; // x^3*y^2*z-27*z^4
        TPolynom b(a);
        cout << "b: " << b;
        TPolynom c(tmp);
        cout << "c: " << c;

        cout << "b.dif(): " << c.dif();
        cout << "b-c: " << b - c;
        cout << "c=b: " << (c = b);
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
        cout << "z = ";
        cin >> z;
        double res = c(x, y, z);
        cout <<"c(x, y, z) = " << res;
    }
    catch (const std::exception& ex)
    {
        cout << ex.what();
    }
    return 0;
}
