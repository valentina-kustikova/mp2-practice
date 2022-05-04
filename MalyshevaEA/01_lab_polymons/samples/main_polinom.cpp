#include "polinom.h"

using namespace std;

void menu()
{
    //cout << "1. Ввести полином" << endl;
    cout << "1. Умножить полином на число" << endl;
    cout << "2. Умножить полином на моном" << endl;
    cout << "3. Умножить полином на полином" << endl;
    cout << "4. Сложить полином с полиномом" << endl;
    cout << "5. Вычесть полином из полинома" << endl;
    cout << "0. Выход" << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    
    int v = 1;
    while (v != 0)
    {
        menu();
        cin >> v;
        switch (v)
        {
        case 1:
            {
                string str1;
                double a;
                cout << "Введите полином" << endl;
                cin >> str1;
                polinom p1(str1);
                cout << "Введите число" << endl;
                cin >> a;
                polinom p2(p1 * a);
                cout << p2 << endl;
            }
            break;
        case 2:
            {
                string str1, str2;
                cout << "Введите полином" << endl;
                cin >> str1;
                polinom p1(str1);
                cout << "Введите моном" << endl;
                cin >> str2;
                polinom p3(str2);
                polinom p2(p1 * p3.mon[0]);
                cout << p2 << endl;
            }
            break;
        case 3:
            {
                string str1, str2;
                cout << "Введите полином" << endl;
                cin >> str1;
                polinom p1(str1);
                cout << "Введите полином" << endl;
                cin >> str2;
                polinom p3(str2);
                polinom p2(p1 * p3);
                cout << p2 << endl;
            }
            break;
        case 4:
            {
                string str1, str2;
                cout << "Введите полином" << endl;
                cin >> str1;
                polinom p1(str1);
                cout << "Введите полином" << endl;
                cin >> str2;
                polinom p3(str2);
                polinom p2(p1 + p3);
                cout << p2 << endl;
            }
            break;
        case 5:
            {
                string str1, str2;
                cout << "Введите полином" << endl;
                cin >> str1;
                polinom p1(str1);
                cout << "Введите полином" << endl;
                cin >> str2;
                polinom p3(str2);
                polinom p2(p1 - p3);
                cout << p2 << endl;
            }
            break;
        default:
            break;
        }
    }
    //polinom p1("y^2-3x+xy");
    //polinom p2("x");
    //polinom p3(p1 + p2);
    //cout << p3 << endl;
    //polinom p3;
    //p1 = p1 * 4;
    //cout << p2 << endl;
    /*monom m1(1, 1, 0, 0);
    monom m2(, 1, 0, 0);
    monom m3(m1 + m2);
    cout << m3 << endl;*/
    //cin >> p2;
    //cout << p2 << endl;
    return 0;
}//2x^2y^4+x^2+4xy^5z