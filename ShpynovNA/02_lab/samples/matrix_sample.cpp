#include <iostream>
#include "matrix.h"

using namespace std;

int main(){
    cout << "1st matrix size:";
    int n;
    cin >> n;
    TMatrix<int> mat1(n);
    cout << "2nd matrix size:";
    cin >> n;
    TMatrix<int> mat2(n);
    cout << "1st vector:";
    cin >> mat1;
    cout << "got " << endl<< mat1;
    cout << "2nd vector:";
    cin >> mat2;
    cout << "got " <<endl << mat2;
    try {
        cout << "they are ";
        if (mat1 != mat2)
            cout << "NOT ";
        cout << "equal" << endl;
        cout << "sum: " << (mat1 + mat2) << endl;
        cout << "subtr: " << mat2 - mat2 << endl;
        cout << "mult: " << mat1 * mat2 << endl;
    }
    catch (const char* s) { cout << s; }
    return 0;
}