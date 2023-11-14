#include <iostream>
#include "tmatrix.h"


int main()
{
    cout << "TMatrix" << endl;
    TMatrix<int> a(3), b(3);
    cout << "Input int matrix a(size = 3) and b(size = 3)" << endl;
    cin >> a >> b;
    cout << a << "\n" << b;


    TMatrix<int> c(3);
    c = a + b;
    cout << "c = a + b: " << '\n' << c << endl;

    TMatrix<int> d(3);
    d = a - b;
    cout << "d = a - b: " << '\n' << d << endl;

    TMatrix<int> e(3);
    e = a * b;
    cout << "e = a * b: " << '\n' << e << endl;

    bool res;
    res = (d == e);
    cout << "d == e:  " << res << endl;

    res = (d != e);
    cout << "d != e:  " << res << endl;

    system("PAUSE");
    return 0;
}
