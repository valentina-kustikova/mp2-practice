#include <iostream>
#include <string>
#include "STack.h"
using namespace std;

int main()
{
	int lenght = 0;

	cout << "Enter lenght of string Stack: ";
	cin >> lenght;
	cout << endl;

	TStack<string> stack(lenght);
	string element;
	bool answer;
	int choice;

	do {
		cout << "1: PUSH" << endl;
		cout << "2: POP" << endl;
		cout << "3: TOP" << endl;
		cout << "4: IS FULL ?" << endl;
		cout << "5: IS EMPTY ?" << endl;
		cout << "6: EXIT" << endl;
		cout << "Choose: ";
		cin >> choice;
		if (!cin) {
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "ERROR. Please enter numbers only: 1 - 6" << endl;
		}
		switch (choice) {
		case 1:
			cout << "Enter element you would like push : ";
			cin >> element;
			stack.Push(element);
			break;
		case 2:
			stack.Pop();
			break;
		case 3:
			element=stack.Top();
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
	} while (choice != 6);

	return 0;
}