#include <iomanip>
//#define USE_SET 
#ifndef USE_SET // Использовать класс TBitField

#include "tbitfield.h"

int main()
{
    int n, m, k, count;

    cout << "Input a number:  ";
    cin >> n;
    TBitField s(n + 1);
    // заполнение множества
    for (m = 2; m <= n; m++)
        s.SetBit(m);
    // проверка до sqrt(n) и удаление кратных
    for (m = 2; m * m <= n; m++)
        // если m в s, удаление кратных
        if (s.GetBit(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.GetBit(k))
                    s.ClrBit(k);
    // оставшиеся в s элементы - простые числа
    cout << endl << "Set all digits: " << endl << s << endl;
    cout << endl << "Set prime digits: " << endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.GetBit(m))
        {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }
    cout << endl;
    cout << "Count of prime digits: " << count << endl;
    system("pause"); //Чтобы сразу не пропадало окно
}
#else

#include "tset.h"

int main()
{
    int n, m, k, count;

    cout << "Input a number:  ";
    cin >> n;
    TSet s(n + 1);
    // заполнение множества
    for (m = 2; m <= n; m++)
        s.InsElem(m);
    // проверка до sqrt(n) и удаление кратных
    for (m = 2; m * m <= n; m++)
        // если м в s, удаление кратных
        if (s.IsMember(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    // оставшиеся в s элементы - простые числа
    cout << endl << "Set all digits: " << endl << s << endl;
    cout << endl << "Set prime digits: " << endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.IsMember(m))
        {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }
    cout << endl;
    cout << "Count of prime digits: " << count << endl;
}

#endif