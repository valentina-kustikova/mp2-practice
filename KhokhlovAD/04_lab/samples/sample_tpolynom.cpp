#include <iostream>
#include "tpolynom.h"

int main()
{
    try{
        string a =  "-2*x^2*y^4*z^7+34*x^3*y";
        string abc = "x^2*y^4*z^7";
        TPolynom b(a);
        cout << "b: " << b;
        TPolynom c(abc);
        cout << "c: " << c;
        cout << "b.dif(): " << b.dif();
        cout << "b-c" << b - c;
        cout << "c=b: " << (c = b);
    }
    catch (const std::exception& ex)
    {
        cout << ex.what();
    }
    return 0;
}
