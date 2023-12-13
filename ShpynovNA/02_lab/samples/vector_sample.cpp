#include <iostream>
#include "vector.h"

using namespace std;

int main(){
    int n;
    cout << "1st vector length:";
    cin >> n;
    TVector<double> vect1(n, 0);
    cout << "2nd vector length:";
    cin >> n;
    TVector<double> vect2(n, 0);
    cout << "1st vector:";
    cin >> vect1;
    cout << "got " << vect1 << endl;
    cout << "2nd vector:";
    cin >> vect2;
    cout << "got " << vect2 << endl;
    try {
        cout << "they are";
        if (vect1 != vect2)
            cout << " NOT ";
        cout << "equal" << endl;
        cout << "1st vector + 2: " << vect1 + 2 << endl;
        cout << "1st vector - 2: " << vect1 - 2 << endl;
        cout << "1st vector * 2: " << vect1 * 2 << endl;
        cout << "sum: " << vect1 + vect2 << endl;
        cout << "subtr: " << vect1 - vect2 << endl;
        cout << "mult: " << vect1 * vect2 << endl;
    }
    catch (const char* s) { cout << s; }
    return 0;
}