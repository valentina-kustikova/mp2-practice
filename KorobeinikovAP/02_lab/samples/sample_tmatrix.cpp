#include <iostream>
#include "tmatrix.h"

int main()
{
    std::cout << "TMatrix" << std::endl;
    TMatrix<int> a(3), b(3);
    cout << "Input int matrix a(size = 3) " << endl;
    cin >> a;
    cout << "Input int matrix b(size = 3) " << endl;
    cin >> b;
    cout << a << "\n" << b;
    

    TMatrix<int> c(3);
    c = a + b;
    cout << "c = a + b: "<< '\n' << c << endl;

    TMatrix<int> d(3);
    d = a - b;
    cout << "d = a - b: " << '\n' << d << endl;

    TMatrix<int> e(3);
    e = a * b;
    cout << "e = a * b: " << '\n' << e << endl;

    bool x = (a == a);
    cout << "(a == a) = " << x << endl;
    x = (a == b);
    cout << "(a == b) = " << x << endl;
    x = (a != a);
    cout << "(a != a) = " << x << endl;
    x = (a != b);
    cout << "(a != b) = " << x << endl;

    return 0;
}
