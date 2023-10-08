#include <iostream>
#include "tset.h"

using namespace std;


int main()
{
    std::cout << "Prime numbers\n" << std::endl;

    int n;
    cout << "Enter the count of numbers: ";
    cin >> n;

    TSet s(n + 1);
    for (int m = 2; m <= n; m++)
        s.InsElem(m);
    for (int m = 2; m * m <= n; m++)
        if (s.IsMember(m))
            for (int k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);

    cout << "Prime numbers under " << n << ": " << endl;
    for (int i = 0; i <= n; i++)
        if (s.IsMember(i))
            cout << i << ' ';
    cout << endl;

    return 0;
}
