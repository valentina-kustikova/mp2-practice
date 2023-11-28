#include "stack.h"
#include <iostream>

using namespace std;

int main() {
	try {
		int n;
		int answer;
		string answer2;
		cout << "Enter n:";
		cin >> n;
		TStack<string> stack(n);
		while (true) {
			cout << "1)Push" << endl;
			cout << "2)Pop" << endl;
			cout << "3)Top" << endl;
			cout << "0)Exit" << endl;
			cout << "Enter: ";
			cin >> answer;
			switch (answer) {
			case 1: {
				cout << "Enter element:";
				cin >> answer2;
				stack.Push(answer2);
				break;
			}
			case 2: {stack.Pop(); break; }
			case 3: {cout << "Top:" << stack.Top() << endl; break; }
			case 0: return 0;
			}
			}
		}
	catch (string exp) {
		cout << exp << endl;
	}
	return 0;

}
