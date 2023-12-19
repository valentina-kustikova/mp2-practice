#include "stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    Stack<int> a;
    
    int n;
    cout << "Enter number N - number of stack elements: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        int el;
        cout << "Enter new integer element: ";
        cin >> el;
        cout << endl;

        a.Push(el);
    }

    cout << a;

    cout << "last element: " << a.Top() << endl;
    a.Pop();
    cout << "last element was deleted:" << endl;
    cout << "last element: " << a.Top() << endl;

    return 0;
}