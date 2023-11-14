#include <iostream>
#include "tvector.h"

int main()
{
    std::cout << "Vector" << std::endl;
    Vector<int> a(3), b(3);
    cout << "Input int vector a(size = 3) and b(size = 3)" << endl;
    cin >> a >> b;
    cout << a << b;

    Vector<int> c(3);
    c = a + 3;
    cout << "c = a + 3: " << c << endl;

    Vector<int> d(3);
    d = a - 3;
    cout << "d = a - 3: " << d << endl;

    Vector<int> e(3);
    e = a * 3;
    cout << "e = a * 3: " << e << endl;

    Vector<int> f(3);
    f = a + b;
    cout << "f = a + b: " << f << endl;

    Vector<int> g(3);
    g = a - b;
    cout << "g = a - b: " << g << endl;

    int h;
    h = a * b;
    cout << "h = a * b: " << h << endl;

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
