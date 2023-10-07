#include "tset.h"
#include <iomanip>
int main()
{
    int n, m, k, count;

    cout << "Input a number:  ";
    cin >> n;
    TSet s(n + 1);
    // ���������� ���������
    for (m = 2; m <= n; m++)
        s.InsElem(m);
    // �������� �� sqrt(n) � �������� �������
    for (m = 2; m * m <= n; m++)
        // ���� � � s, �������� �������
        if (s.IsMember(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    // ���������� � s �������� - ������� �����
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