#include <iostream>
#include "tset.h"

int main() {
    try {
        int a, b, c;
        cout << "Enter Set 1 maxSize" << endl;
        cin >> a;
        cout << "Enter Set 2 maxSize" << endl;
        cin >> b;
        cout << "Enter Set 3 maxSize" << endl;
        cin >> c;

        TSet set1(a);
        TSet set2(b);
        TSet set3(c);

        cin >> set3;

        set1.InsElem(2);
        set1.InsElem(5);
        set1.InsElem(8);

        set2.InsElem(4);
        set2.InsElem(5);
        set2.InsElem(7);

        cout << "Set 1: " << set1 << endl;
        cout << "Set 2: " << set2 << endl;
        cout << "Set 3: " << set3 << endl;

        cout << "Set 1 + Set 2: " << set1 + set2 << endl;
        cout << "Set 1 * Set 2: " << set1 * set2 << endl;
        cout << "NOT Set 3: " << ~set3 << endl;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}