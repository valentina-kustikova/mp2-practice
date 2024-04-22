#include <iostream>
#include "tringlist.h"

using namespace std;

template<typename T>
void PrintList(TRingList<T>& rl) {
	rl.Reset();
	while (!rl.IsEnded()) {
		cout << rl.GetCurrent()->data << " ";
		rl.Next();
	}
	rl.Reset();
}

template<typename T>
void InsertInterface(TRingList<T>& rl) {
	int ans = 0;
	T ins;
	T find;
	do {
		system("cls");

		PrintList(rl);
		cout << endl;
		cout << "Current: " << rl.GetCurrent()->data << endl;

		cout << endl;
		cout << "1. Insert First" << endl;
		cout << "2. Insert Last" << endl;
		cout << "3. Insert Before" << endl;
		cout << "4. Insert After" << endl;
		cout << "5. Insert Before Current" << endl;
		cout << "6. Insert After Current" << endl;
		cout << "7. Next element" << endl;
		cout << "8. Reset list" << endl;
		cout << "0. EXIT\n" << endl;

		cin >> ans;
		cout << endl;

		switch (ans) {
		case 1:
			cout << "Insert: ";
			cin >> ins;
			rl.InsertFirst(ins);
			break;

		case 2:
			cout << "Insert: ";
			cin >> ins;
			rl.InsertLast(ins);
			break;

		case 3:
			cout << "Insert: ";
			cin >> ins;
			cout << "Before: ";
			cin >> find;
			rl.InsertBefore(ins, find);
			break;

		case 4:
			cout << "Insert: ";
			cin >> ins;
			cout << "After: ";
			cin >> find;
			rl.InsertAfter(ins, find);
			break;

		case 5:
			cout << "Insert: ";
			cin >> ins;
			if (rl.IsEnded()) rl.Reset();
			rl.InsertBefore(ins);
			break;

		case 6:
			cout << "Insert: ";
			cin >> ins;
			if (rl.IsEnded()) rl.Reset();
			rl.InsertAfter(ins);
			break;

		case 7:
			rl.Next();
			break;

		case 8:
			rl.Reset();
			break;

		default:

			break;
		}

	} while (ans >= 1 && ans <= 8);
}


int main() {
	cout << "TRingList\n" << endl;

	try {
		TRingList<int> rl;
		int ans = 0;
		do {
			system("cls");

			PrintList(rl);
			cout << endl;
			cout << "Current: " << rl.GetCurrent()->data << endl;

			cout << endl;
			cout << "1. Insert" << endl;
			cout << "2. Remove" << endl;
			cout << "3. Clear" << endl;
			cout << "4. Next element" << endl;
			cout << "5. Reset list" << endl;
			cout << "0. EXIT\n" << endl;

			cin >> ans;
			cout << endl;

			switch (ans) {
			case 1:
				InsertInterface(rl);
				break;

			case 2:
				int rm;
				cout << "Remove: ";
				cin >> rm;
				rl.Remove(rm);
				break;

			case 3:
				int sure;
				cout << "Are you sure? (1/0): ";
				cin >> sure;
				if (sure == 1) rl.Clear();
				break;

			case 4:
				rl.Next();
				break;

			case 5:
				rl.Reset();
				break;

			default:

				break;
			}

		} while (ans >= 1 && ans <= 5);
	}
	catch (string exp) {
		cout << exp << endl;
	}

	return 0;
}
