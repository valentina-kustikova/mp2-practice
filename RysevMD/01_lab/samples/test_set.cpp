#include <iostream>
#include "TSet.h"

using namespace std;

int main(){
    //создание множеств
    TSet s1(5), s2(4);
    s1.InsElem(0);
    s1.InsElem(1);
    s1.InsElem(3);
    s1.InsElem(4);
    cin >> s2;
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    //объединение, пересечение, дополнение множеств
    TSet s3 = s1 + s2, s4 = s1 * s2, s5 = ~s1;
    cout << "s3 = s1 + s2: " << s3 << endl << "s4 = s1 * s2: " << s4 << endl << "s5 = ~s1: " << s5 << endl;
    //объединение, разность с элементом
    TSet s6 = s1 + 2, s7 = s1 - 4;
    cout << "s6 = s1 + 2: " << s6 << endl << "s7 = s1 - 4: f" << s7 << endl;

    //сравнение множеств, проверка наличия элемента
    TSet s8 = s1, s9(5);
    s9.InsElem(2);
    s9.InsElem(4);
    s9.InsElem(1);
    cout << "s8: " << s8 << endl << "s9: " << s9 << endl;
    cout << "s8 == s1? - " << (s8 == s1) << endl << "s8 == s9? - " << (s8 == s9) << endl << "s9 != s2? - " << (s9 != s2) << endl;
    cout << "0 in s1? - " << s1.IsMember(0) << endl << "2 in s1? - " << s1.IsMember(2) << endl;
    return 0;
}