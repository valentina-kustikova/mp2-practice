#include <iostream>
#include "TVector.h"

using namespace std;

int main()
{
    cout << "Input a size of vectors\n";
    int size;
    cin >> size;
    TVector<int> A(size), B(size);
    cout << "Input vector A and B" << endl;
    cin >> A >> B;
    cout << A << B;

    TVector<int> C(size);
    C = A + 3;
    cout << "C = A + 3: " << C << endl;

    TVector<int> D(size);
    D = A - 3;
    cout << "d = a - 3: " << D << endl;

    TVector<int> E(size);
    E = A * 3;
    cout << "E = A * 3: " << E << endl;

    TVector<int> F(size);
    F = A + B;
    cout << "F = A + B: " << F << endl;

    TVector<int> G(size);
    G = A - B;
    cout << "G = A - B: " << G << endl;

    int h;
    h = A * B;
    cout << "G = A * B: " << h << endl;

    return 0;
}