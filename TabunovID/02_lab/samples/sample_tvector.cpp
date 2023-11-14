#include <iostream>
#include "tvector.h"

int main()
{
    cout << "Input a size of vectors\n";
    int size;
    cin >> size;
    Vector<int> A(size), B(size);
    cout << "Input vector A and B" << endl;
    cin >> A >> B;
    cout << A << B;

    Vector<int> C(size);
    C = A + 3;
    cout << "C = A + 3: " << C << endl;

    Vector<int> D(size);
    D = A - 3;
    cout << "d = a - 3: " << D << endl;

    Vector<int> E(size);
    E = A * 3;
    cout << "E = A * 3: " << E << endl;

    Vector<int> F(size);
    F = A + B;
    cout << "F = A + B: " << F << endl;

    Vector<int> G(size);
    G = A - B;
    cout << "G = A - B: " << G << endl;

    int h;
    h = A * B;
    cout << "G = A * B: " << h << endl;

    return 0;
}
