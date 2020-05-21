#include "TPolynom.h"
#include <locale.h>
#include <iostream>
#include <string>

using namespace std;

void main() {
    setlocale(LC_ALL, "Russian");
    string str = "26x^3y^7z^9+2y^8-3x^6+5";
    try {
        cout << "Введите первый полином:" << endl;
        cin >> str;
        TPolynom pol1(str);
        cout << "Введите второй полином:" << endl;
        cin >> str;
        TPolynom pol2(str);
        cout << "Полином 1:" << endl;
        cout << pol1 << endl;
        cout << "Полином 2:" << endl;
        cout << pol2 << endl;
        TPolynom pol0;
        pol0 = pol1 + pol2;
        cout << "Полином 1 + Полином 2" << endl;
        cout << pol0 << endl;
        pol0 = pol1 - pol2;
        cout << "Полином 1 - Полином 2" << endl;
        cout << pol0 << endl;
        pol0 = pol1 * pol2;
        cout << "Полином 1 * Полином 2" << endl;
        cout << pol0 << endl;
    }
    catch (const exception & e) {
        cout << e.what() << endl;
    }
}