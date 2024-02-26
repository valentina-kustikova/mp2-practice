#include <iostream>
#include "tvector.h"

int main()
{
    std::cout << "TVec" << std::endl;
    TVec<int> a(3), b(3);
    cout << "Input int TVec a(size = 3) and b(size = 3)" << endl;
    cin >> a >> b;
    cout << a << b;

    TVec<int> c(3);
    c = a + 3;
    cout << "c = a + 3: " << c << endl;

    TVec<int> d(3);
    d = a - 3;
    cout << "d = a - 3: " << d << endl;

    TVec<int> e(3);
    e = a * 3;
    cout << "e = a * 3: " << e << endl;

    TVec<int> f(3);
    f = a + b;
    cout << "f = a + b: " << f << endl;

    TVec<int> g(3);
    g = a - b;
    cout << "g = a - b: " << g << endl;

    int h;
    h = a * b;
    cout << "h = a * b: " << h << endl;

    cout << "a == b : " << (a == b) << endl << "a != b : " << (a != b) << endl;
    system("PAUSE");
    return 0;
}
