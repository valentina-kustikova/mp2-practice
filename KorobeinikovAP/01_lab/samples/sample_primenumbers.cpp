#include <iostream>
#include "tset.h"

int main()
{
    cout << "Prime numbers" << std::endl;
    int n;
    cout << "Enter the maximum integer: ";
    cin >> n;
    TSet s(n + 1);
    // ����������
    for (int m = 2; m <= n; m++)
        s.InsElem(m);
    // �������� �� sqrt(n) � �������� �������
    for (int m = 2; m * m <= n; m++)
        // ���� m � s, �������� �������
        if (s.IsMember(m))
            for (int k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    cout << s;
    return 0;
}
