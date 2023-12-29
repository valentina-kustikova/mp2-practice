#include "stack.h"
#include <iostream>

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
    if (!a.isEmpty()) {
      cout << "last element was deleted:" << endl;
      cout << "last element: " << a.Top() << endl;
    }
    else {
      cout << "Your stack is empty now!" << endl;
    }


    int new_element;
    cout << "Enter some integer number - new stack element: " << endl;
    cin >> new_element;
    a.Push(new_element);

    cout << "Stack after pushing your last added element:" << endl;
    cout << a;

    return 0;
}