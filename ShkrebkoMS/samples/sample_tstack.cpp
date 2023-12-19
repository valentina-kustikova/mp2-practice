#include <iostream>
#include <string>
#include "tstack.h"
using namespace std;

int main()
{
	
	cout << "Enter lenght of string Stack: ";
	int len;
	cin >> len;

	Stack<string> stack(len);

	int answer;
	string element;
	do {

		cout << "1: PUSH" << endl;
		cout << "2: POP" << endl;
		cout << "3: TOP" << endl;
		cout << "4: IS FULL ?" << endl;
		cout << "5: IS EMPTY ?" << endl;
		cout << "6: EXIT" << endl;
		cout << "Choose: ";

		cin >> answer;
		switch (answer) {
		case 1:
			cout << "Enter element you would like push : ";
			cin >> element;
			stack.Push(element);
			break;
		case 2:
			stack.Pop();
			break;
		case 3:
			element = stack.Top();
			cout << element << endl;
			break;
		case 4:
			answer = stack.IsFull();
			cout << answer << endl;
			break;
		case 5:
			answer = stack.IsEmpty();
			cout << answer << endl;
		default:
			break;
		}
	} while (answer != 6);
	



	return 0;
}
