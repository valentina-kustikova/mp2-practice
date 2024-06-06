
#include "tlist.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{


	try {
		int element, element2;
		bool answer;
		TList<int> list;
		int flag;
		do {
			cout << "1: InsertFirst" << endl;
			cout << "2: InsertLast" << endl;
			cout << "3: InsertBefore Current" << endl;
			cout << "4: InsertAfter Current" << endl;
			cout << "5: InsertBefore(data you wont add, before this data wont add)" << endl;
			cout << "6: InsertAfter(data you wont add, after this data wont add)" << endl;
			cout << "7: pop_front()" << endl;
			cout << "8: GetSize()" << endl;
			cout << "9: Reset()" << endl;
			cout << "10: Next()" << endl;
			cout << "11: Show list" << endl;
			cout << "12: IsEmpty()" << endl;
			cout << "13: IsFull()" << endl;
			cout << "14: Sort" << endl;
			cout << "15: Clear" << endl;
			cout << "16: Remove" << endl;
			cout << "17: Remove Current node" << endl;
			cout << "18: EXIT" << endl;
			cout << "Choice: ";
			cin >> flag;

			switch (flag) {
			case 1:
				cout << "Enter element you would like InsertFirst : ";
				cin >> element;
				list.InsertFirst(element);
				cout << endl;
				break;

			case 2:
				cout << "Enter element you would like InsertLast : ";
				cin >> element;
				list.InsertLast(element);
				cout << endl;
				break;

			case 3:
				cout << "Enter element you would like InsertBefore Current : ";
				cin >> element;
				list.InsertBefore(element);
				cout << endl;
				break;

			case 4:
				cout << "Enter element you would like InsertAfter Current : ";
				cin >> element;
				list.InsertAfter(element);
				cout << endl;
				break;

			case 5:
				cout << "Enter data you wont add: ";
				cin >> element;
				cout << endl;
				cout << "before this data wont add: ";
				cin >> element2;
				cout << endl;
				list.InsertBefore(element, element2);
				cout << endl;
				break;

			case 6:
				cout << "Enter data you wont add: ";
				cin >> element;
				cout << endl;
				cout << "after this data wont add: ";
				cin >> element2;
				cout << endl;
				list.InsertAfter(element, element2);
				cout << endl;
				break;

			case 7:
				list.pop_front();
				cout << "popfront done" << endl;
				break;

			case 8:
				cout << "Size of list : " << list.GetSize() << endl;
				break;

			case 9:
				list.Reset();
				cout << "Reset done " << endl;
				break;

			case 10:
				list.Next();
				cout << "Next done " << endl;
				break;

			case 11:
				cout << "list: " << list << endl;
				break;

			case 12:
				cout << "list if empty? : " << list.IsEmpty() << endl;
				break;

			case 13:
				cout << "list is full? : " << list.IsFull() << endl;
				break;

			case 14:
				cout << "Sort list : ";
				list.sort();
				cout << list << endl;
				break;

			case 15:
				cout << "Clear list : ";
				list.Clear();
				cout << "Size:" << list.GetSize() << endl;
				break;

			case 16:
				cout << "Remove from list : ";
				cin >> element;
				cout << endl;
				list.Remove(element);
				cout << "Size:" << list.GetSize() << endl;
				break;

			case 17:
				cout << "Remove current node from list : ";
				list.removeCurrentNode();
				cout << "Size:" << list.GetSize() << endl;
				break;
			}

		} while (flag != 18);
	}

	catch (const char* exp)
	{
		cout << exp;
		return -1;
	}



	return 0;
}


