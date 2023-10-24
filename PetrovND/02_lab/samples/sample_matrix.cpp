#include <iostream>
#include "matrix.h"

int main() {
    try{
        Matrix<int> m1(3);
        m1[0][0] = 1;
        m1[0][1] = 2;
        m1[0][2] = 3;
        m1[1][0] = 4;
        m1[1][1] = 5;
        m1[2][0] = 6;

        Matrix<int> m2(3);
        m2[0][0] = 7;
        m2[0][1] = 8;
        m2[0][2] = 9;
        m2[1][0] = 10;
        m2[1][1] = 11;
        m2[2][0] = 12;

		cout << m1 << endl;
		cout << m2 << endl;
        Matrix<int> m3 = m1 * m2;
        cout << "m1 * m2 = "<< m3 << endl;

        cout << "Enter matrix dimension:" << endl;
        int userInput;
        cin >> userInput;
        Matrix<int> m4(userInput);
        cin >> m4;

        cout << m4 << endl;
    }
    catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}