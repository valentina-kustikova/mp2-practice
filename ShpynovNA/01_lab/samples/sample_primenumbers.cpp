#include <iostream>
#include "tbitfield.h"
using namespace std;

int main()
{
    int n;
    cout << "enter a number:";
    cin >> n;
    TBitField TBFtmp(n + 1);
    for (int i = 2; i < n + 1; i++)
        TBFtmp.SetBit(i);
    for (int i = 2; i * i < n + 1; i++)
        if (TBFtmp.GetBit(i))
            for (int j = 2 * i; j <= n; j += i)
                TBFtmp.ClrBit(j);
    cout << "prime numerals before " << n << ": ";
    for (int i = 2; i < n + 1; i++) {
        if (TBFtmp.GetBit(i))
            cout << i << " ";
    }
    cout << endl;
    char wait;
    cout << "done" << endl << "press any key to close" << endl;
    cin >> wait;
    return 0;
}
