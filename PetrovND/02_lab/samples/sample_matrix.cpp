#include <iostream>
#include "matrix.h"

int main() {
    try{
        Matrix<int> m1(3);
        cin >> m1;

        Matrix<int> m2(3);
        cin >> m2;

        cout << "Enter matrix dimension:" << endl;
        int userInput;
        cin >> userInput;
        Matrix<int> m4(userInput);
        cout << "Enter matrix(m3): " << endl;
        cin >> m4;

		cout << "Matrix 1: \n" << m1 << endl;
		cout << "Matrix 2: \n" << m2 << endl;
        Matrix<int> m3 = m1 * m2;
        cout << "m1 * m2 = \n" << m3 << endl;

        Matrix<int> m5 = m4 - m1;
        cout << "m3 - m1 = \n" << m5 << endl;
    }
    catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}