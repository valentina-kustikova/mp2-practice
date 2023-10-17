#include <iostream>
#include "tbitfield.h"
using namespace std;

void workitwillis()
{
    cout << "1st length: ";
    int n;
    cin >> n;
    TBitField TBF1(n);
    cout << "2nd length: ";
    cin >> n;
    TBitField TBF2(n);
    cout << "1st set: ";
    cin >> TBF1;
    cout << "got " << TBF1 << endl;
    cout << "2st set: ";
    cin >> TBF2;
    cout << "got " << TBF2 << endl;
    cout << "They are ";
    if (TBF1 != TBF2)
        cout << "NOT ";
    cout << "equal" << endl;
    cout << "Thier union: " << (TBF1|TBF2) << endl;
    cout << "Their intersection: " << (TBF1&TBF2) << endl;
    cout << "Elements that are not in the 1st field: " << (~TBF1) << endl;
    cout << "Let's add a 1 to a 1st set on its second position: ";
    TBF1.SetBit(1);
    cout << TBF1 << endl;
    cout << "and now we delete its first one: ";
    TBF1.ClrBit(0);
    cout << TBF1 << endl;
}
int main() {
    try { workitwillis(); }
    catch (const char* s) {
        cout << s << endl;
    }
    char wait;
    cout << "done" << endl << "press any key to close" << endl;
    cin >> wait;
    return 0;
}
