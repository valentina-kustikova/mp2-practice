#include <iostream>
#include "tstack.h"

int main()
{
    TStack <int> a(5);
    a.Push(1);
    a.Push(2);
    a.Push(3);
    a.Push(4);
    a.Push(5);

    cout << "Initially, the stack 'a' looks like this and it is full" << endl;
    cout << "-----" << endl;
    cout << "| 5 |" << endl;
    cout << "-----" << endl;
    cout << "| 4 |" << endl;
    cout << "-----" << endl;
    cout << "| 3 |" << endl;
    cout << "-----" << endl;
    cout << "| 2 |" << endl;
    cout << "-----" << endl;
    cout << "| 1 |" << endl;
    cout << "-----" << endl;

    cout << "a.Top() = " << a.Top() << endl;

    if (a.IsFull()) cout << "a.IsFull() - true" << endl;;


    a.Pop();
    a.Pop();
    a.Pop();
    
    cout << "The top element was removed three times and a.Top() = " << a.Top() << endl;

    a.Push(3);
    cout << "Added '3' to the top of the stack and a.Top() = " << a.Top() << endl;

    a.Pop();
    a.Pop();
    a.Pop();

    if (a.IsEmpty()) cout << "The top element was removed three times again and a.IsEmpty() = 1" << endl;

    return 0;
}
