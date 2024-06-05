#include <iostream>
#include "TList.h"

using namespace std;

int EnterNum() {
	int num;
	cout << "Enter the number: ";
	cin >> num;
	return num;
}

int main() { 
	TList<int> lst;
	int num;
	int ex;

	cout << endl << "---------- Creating a list with 5 elements ----------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> num;
		lst.insertLast(num);
	}
	cout << "List: " << lst;

	cout << endl << "---------- Searching ----------" << endl;
	num = EnterNum();
	cout << num << " in list? - " << (lst.Search(num) != nullptr) << endl;
	num = EnterNum();
	cout << num << " not in list? - " << (lst.Search(num) == nullptr) << endl;

	cout << endl << "---------- Insert and Remove ----------" << endl;

	cout << ">>> Remove <<<" << endl;
	num = EnterNum();
	try {
		lst.Remove(num);
	}
	catch (...) {
		cout << "Not find" << endl;
	}
	cout << lst << endl;

	cout << ">>> Insert first <<<" << endl;
	num = EnterNum();
	lst.insertFirst(num);
	cout << lst << endl;

	cout << ">>> Insert last <<<" << endl;
	num = EnterNum();
	lst.insertLast(num);
	cout << lst << endl;

	cout << ">>> Insert before element <<<" << endl;
	cout << "Enter inserting element: "; cin >> num;
	cout << "Enter existing element: "; cin >> ex;
	try {
		lst.insertBefore(ex, num);
	}
	catch (...) {
		cout << "Not find" << endl;
	}
	cout << lst << endl;

	cout << ">>> Insert after element <<<" << endl;
	cout << "Enter inserting element: "; cin >> num;
	cout << "Enter existing element: "; cin >> ex;
	try {
		lst.insertAfter(ex, num);
	}
	catch (...) {
		cout << "Not find" << endl;
	}
	cout << lst << endl;

	lst.Reset();
	lst.Next(); lst.Next(); lst.Next();

	cout << endl << "--------- Navigation ---------" << endl;
	cout << "Count of element: " << lst.getSize() << endl;
	cout << "Current element: " << lst.getCurrent()->key << endl;
	cout << "First element: " << lst.getFirst()->key << endl;
	cout << "Last element: " << lst.getLast()->key << endl;
	cout << "Current element: " << lst.getCurrent()->key << endl;
	lst.Reset();
	cout << "Current element after Reset(): " << lst.getCurrent()->key << endl;
	lst.Next();
	cout << "Current element after Next(): " << lst.getCurrent()->key << endl;

	cout << endl << "---------- Clear ----------" << endl;
	lst.Clear();
	cout << "List is empty? - " << lst.isEmpty() << endl;

	cout << endl << "--------- The end ----------" << endl;

	return 0; 
}