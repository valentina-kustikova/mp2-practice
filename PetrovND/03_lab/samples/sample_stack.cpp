#include "stack.h"
using namespace std;

int main() {
    // Test the default constructor and push operation
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Test the copy constructor
    Stack<int> anotherStack(myStack);

    // Test the assignment operator
    Stack<int> assignedStack;
    assignedStack = myStack;

    // Test pop and top operations
    cout << "Top element of myStack: " << myStack.top() << endl;

    cout << "Pop elements from myStack:" << endl;
    while (!myStack.isEmpty()) {
        cout << myStack.pop() << " ";
    }
    cout << endl;

    // Test isEmpty and isFull
    cout << "Is anotherStack empty? " << (anotherStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is assignedStack full? " << (assignedStack.isFull() ? "Yes" : "No") << endl;

    return 0;
}