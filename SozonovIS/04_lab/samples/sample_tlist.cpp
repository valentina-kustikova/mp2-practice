#include "tlist.h"
#include "tnode.h"
#include <iostream>

using namespace std;

int main() {
	TList<int> list;
	cin >> list;
	cout << endl;
	cout << list;
	cout << endl;

	cout << "Is list empty? " << list.IsEmpty() << endl;
	cout << endl;

	int elem;
	cout << "Enter element to insert at the beginning: ";
	cin >> elem;
	list.InsertFirst(elem);
	cout << list << endl;
	cout << endl;

	cout << "Enter element to insert at the end: ";
	cin >> elem;
	list.InsertLast(elem);
	cout << list << endl;
	cout << endl;

	int pos;
	cout << "Enter element to insert before: ";
	cin >> pos;
	cout << "Enter element to insert: ";
	cin >> elem;
	list.InsertBefore(elem, pos);
	cout << list << endl;
	cout << endl;

	cout << "Enter element insert after: ";
	cin >> pos;
	cout << "Enter element to insert: ";
	cin >> elem;
	list.InsertAfter(elem, pos);
	cout << list << endl;
	cout << endl;

	cout << "Enter element to remove: ";
	cin >> elem;
	list.Remove(elem);
	cout << list << endl;

	list.Clear();
}
