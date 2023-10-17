#include <iostream>
#include "tset.h"

using namespace std;

int main()
{
    std::cout << "Prime numbers" << std::endl;

    int n;
    cout << "enter the maximum integer: ";
    cin >> n;
    TSet s(n + 1);
    for (int m = 2; m <= n; m++)
        s.InsElem(m);
    for (int m = 2; m <= n; m++)
        if (s.IsMember(m))
            for (int k = 2 * m; k <= n; k += m)
                s.DelElem(k);
    cout << s << endl;
    for (int i = 0; i < s.GetMaxPower(); i++)
    {
        if (s.IsMember(i))
            cout << i << endl;
    }

    return 0;
}
