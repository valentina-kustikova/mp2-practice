#include "tvector.h"

#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter vector size:";
    cin >> size;

    TVector<int> a(size), b(size), c(size);
    cin >> a;
    cin >> b;

    cout << "a:" << endl << a << endl;
    cout << "b:" << endl << b << endl;

    cout << "Size a:" << a.GetSize() << endl;
    cout << "Size b:" << a.GetSize() << endl;

    cout << "a + b:" << endl << a + b << endl;
    cout << "a - b:" << endl << a - b << endl;
    cout << "a * b:" << endl << a * b << endl;

    int t;
    cout << "Enter a random number:";
    cin >> t;

    cout << "a + t:" << endl << a + t << endl;
    cout << "a - t:" << endl << a - t << endl;
    cout << "a * t:" << endl << a * t << endl;

    c = a;
    cout << "c:" << endl << c << endl;

    std::cout << "a == b ? " << (a == b) << std::endl;
    std::cout << "a != b ? " << (a != b) << std::endl;
    std::cout << "a == c ? " << (a == c) << std::endl;

	return 0;
}