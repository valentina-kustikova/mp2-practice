#include <iostream>
#include "tstack.h"
using namespace std;
int main()
{
    try {

        int tmp;
        cout << "your stack size: " ;
        cin >> tmp;
                TStack<int> Stack(tmp);
        cout << "add some numbers:" << endl << "amount: ";
        int k;
        do {
            cin >> k;
            if (k > tmp)
                cout << "Stack is smaller";
        } while (k > tmp);
        
        for (int i = 0; i < k; i++){
            cout << "new number: ";
            int j;
            cin >> j;
            Stack.add(j);
        }
        cout << "got a stack with " << Stack.get_size() + 1 << " elements" << endl;
        cout << "last one is " << Stack.top() << endl;
        cout << "previous one is ";
        Stack.del();
        cout << Stack.top() <<endl;
    }
    catch (const char* s){
        cout << s << endl;
    }
}