#include <iostream>
#include <iomanip>
#include "tset.h"

using namespace std;

int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");
    cout << "������������ �������� ��������� ���������" << endl;
    cout << "              ������ ����������" << endl;
    cout << "������� ������� ������� ����� �������� - ";
    cin >> n;
    TSet s(n + 1);
    for (m = 2; m <= n; m++)
        s.InsElem(m);
    for (m = 2; m * m <= n; m++)
        if (s.IsMember(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
    cout << endl << "������ ������� �����" << endl;
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
    cout << "� ������ " << n << " ������ " << count << " �������" << endl;
    system("PAUSE");
    return 0;
}
