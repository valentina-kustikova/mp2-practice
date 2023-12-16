#include "tset.h"
#include <iostream>

using namespace std;

int main() {
    try {
        int maxsize;
        cout << "Enter Set maxSize: ";
        cin >> maxsize;
        cout << endl;

        TSet set1(maxsize);
        TSet set2(maxsize);

        cin >> set1;
        cout << endl;
        cin >> set2;
        cout << endl;

        cout << "Set 1: " << set1 << endl;
        cout << "Set 2: " << set2 << endl;
        cout << endl;

        cout << "Set 1 == Set 2? " << (set1 == set2) << endl;
        cout << "Set 1 != Set 2? " << (set1 != set2) << endl;
        cout << endl;

        int elem;
        cout << "Enter element: ";
        cin >> elem;
        cout << endl;

        cout << "Set 1 + " << elem << ": " << (set1 + elem) << endl;
        cout << "Set 2 - " << elem << ": " << (set2 - elem) << endl;
        cout << endl;

        cout << "Set 1 + Set 2: " << (set1 + set2) << endl;
        cout << "Set 1 * Set 2: " << (set1 * set2) << endl;
        cout << "NOT Set 1: " << ~set1 << endl;
        cout << endl;

        cout << "Enter additional element: ";
        cin >> elem;
        cout << endl;

        set1.InsElem(elem);
        cout << "Set 1: " << set1 << endl;
        cout << endl;

        cout << "Enter deductible element: ";
        cin >> elem;
        cout << endl;

        set2.DelElem(elem);
        cout << "Set 2: " << set2 << endl;
    }
    catch (exception exp) {
        cout << exp.what();
    }
    return 0;
}
