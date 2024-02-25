#include "tvector.h"

#include <iostream>

using namespace std;

int main()
{
    try {
        int size;
        cout << "Enter vector size: ";
        cin >> size;
        cout << endl;

        TVector<int> a(size);
        cout << "Enter vector: ";
        cin >> a;
        cout << endl;

        cout << "Enter vector size: ";
        cin >> size;
        cout << endl;

        TVector<int> b(size);
        cout << "Enter vector: ";
        cin >> b;
        cout << endl;

        cout << "Vector a: " << a << endl;
        cout << "Vector b: " << b << endl;
        cout << endl;

        std::cout << "a == b ? " << (a == b) << endl;
        std::cout << "a != b ? " << (a != b) << endl;
        cout << endl;

        cout << "a + b: " << a + b << endl;
        cout << "a - b: " << a - b << endl;
        cout << "a * b: " << a * b << endl;
        cout << endl;

        int t;
        cout << "Enter a random number: ";
        cin >> t;
        cout << endl;

        cout << "a + " << t << ": " << a + t << endl;
        cout << "a - " << t << ": " << a - t << endl;
        cout << "a * " << t << ": " << a * t << endl;
    }
    catch (exception exp) {
        cout << exp.what();
    }
	return 0;
}