#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    try {
		int userInput;
		cout << "Enter the number of vector components" << endl;
		cin >> userInput;
		
        Vector<int> v1(5);
		Vector<int> v2(5);
		Vector<int> v3(userInput);
		
		cin >> v3;
	
		for (int i = 0; i < 5; ++i) {
			v1[i] = i * 2;
			v2[i] = i * 3;
		}
		
		cout << "Vector v1: " << v1 << endl;
		cout << "Vector v2: " << v2 << endl;
		
		cout << "v1 + v2 = " << v1 + v2 << endl;
		cout << "v1 - v2 = " << v1 - v2 << endl;
		cout << "v1 * v2 = " << v1 * v2 << endl;
		
		int scalar;
		cout << "Enter scalar" << endl;
		cin >> scalar;
		cout << "v3 * " << scalar << " = " << v3 * scalar << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}