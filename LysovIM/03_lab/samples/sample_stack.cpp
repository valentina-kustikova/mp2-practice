#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	try 
	{
		int max_size_stack;
		cout << "Enter max size stack:";
		cin >> max_size_stack;
		TStack<int> stack(max_size_stack);
		int answer, element;
		string elem;
		while (true) {
			cout << "Menu:" << endl;
			cout << "Select the menu item" << endl;
			cout << "1 - Push()" << endl;
			cout << "2 - Pop()" << endl;
			cout << "3 - Top()" << endl;
			cout << "0 - Exit\n" << endl;
			cout << "Enter:";
			cin >> answer;
			switch (answer) {
			default:
			{
				return 0;
			}
			case 1: 
			{
				cout << "Enter element please:";
				cin >> element;
				stack.Push(element);
				break;
			}
			case 2: 
			{
				cout << "Pop:" << stack.Pop() << endl; 
				break;
			}
			case 3: 
			{
				cout << "Element on the top of Stack: " << stack.Top() << endl;
				break;
			}
			}
		}
	}
	catch (char* exp)
	{
		cout << exp << endl;
	}
}