#include <iostream>
#include "tbitfield.h"

using namespace std;
int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");

    cout << "������ ����������" << endl;
    cout << "������������� ������ \"������� ����\"" << endl;

    cout << "������� ������������ ����� �����: ";
    cin >> n;

    TBitField s(n + 1);
    // ���������� ���������
    for (m = 2; m <= n; m++)
        s.SetBit(m);
    // �������� �� sqrt(n) � �������� �������
    for (m = 2; m * m <= n; m++)
        // ���� m � s, �������� �������
        if (s.GetBit(m))
            for (k = 2 * m; k <= n; k += m)
                s.ClrBit(k);

    //���������� � s �������� - ������� �����
    cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
    cout << endl << "������ ������� �����" << endl;

    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.GetBit(m)) {
            count++;
            cout << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }

    cout << endl;
    /*cout << "� ������ " << n << " ������ " << count << " �������" << endl;*/

    return 0;
}
