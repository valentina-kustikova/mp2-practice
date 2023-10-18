#include <iostream>
#include "tset.h"
using namespace std;
void workitwillis()
{
    cout << "max length: ";
    int n;
    cin >> n;
    TSet TS1(n);
    TSet TS2(n);
    cout << "1st set: " << endl;
    cin >> TS1;
    cout << "got " << TS1 << endl;
    cout << "2st set: " << endl;
    cin >> TS2;
    cout << "got " << TS2 << endl;
    cout << "They are ";
    if (TS1 != TS2)
        cout << "NOT ";
    cout << "equal" << endl;
    cout << "All their elements: " << TS1+TS2 << endl;
    cout << "Their mutual elements: " << (TS1*TS2) << endl;
    cout << "Elements that are not in the 1st set: " << ~TS1 << endl;
    cout << "Let's add a 1 to a 1st set on its second position: " << (TS1 + 1) << endl;
    cout << "and now we delete its first one: " << (TS1 - 0) << endl;
}
int main(){
    try {workitwillis();}
    catch (const char* s) {
        cout << s << endl;
    }
    char wait;
    cout << "done" << endl << "press any key to close" << endl;
    cin >> wait;
    return 0;
}
