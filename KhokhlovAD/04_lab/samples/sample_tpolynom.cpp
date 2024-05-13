#include <iostream>
#include "tpolynom.h"

int main()
{
    try{
        string a =  "-2*x^2*y^4*z^7+34*x*y";
        TPolynom b(a);
        TPolynom c;
    }
    catch (const std::exception& ex)
    {
        cout << ex.what();
    }
    return 0;
}
