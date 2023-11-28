#include "tstack.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "TStack\n" << endl;

	try {
		cout << "Length of stack<string>:";
		int sleng;
		cin >> sleng;

		TStack<string> stack(sleng);

		int ans;
		string elem;
		while (true) {
			system("cls");
			cout << "1) Push()" << endl;
			cout << "2) Pop()" << endl;
			cout << "3) Top()" << endl;
			cout << "0) Exit\n" << endl;
			cout << "Enter: ";

			cin >> ans;
			if (ans == 1) {
				system("cls");
				cout << "Enter element to push: ";
				//getline(cin, elem);
				cin >> elem;
				stack.Push(elem);
			}
			else if (ans == 2) {
				stack.Pop();
			}
			else if (ans == 3) {
				system("cls");
				cout << "Element on the top of stack: " << stack.Top() << endl;
				cout << "Enter any value to continue: ";
				cin >> ans;
			}
			else {
				break;
			}
		}
	}
	catch (string exp) {
		cout << exp << endl;
	}

	return 0;
}