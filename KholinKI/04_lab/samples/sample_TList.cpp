#include <iostream>
#include "TList.h"

#define count_links 4

int main() {
	cout << "Creating ";
	TList<int> my_list;
	if (my_list.IsEmpty()) {
		cout << "empty list" << endl;
	}
	cout << "Quantity nodes: " << my_list.GetSize() << endl << endl;

	cout << "Let's add some data to the list: " << endl;
	cout << "For this, let's use all varieties of inserts" << endl;

	cout << "1. Insert 3 first" << endl;
	my_list.insert_first(3);

	cout << "2. Insert 1 last." << endl;
	my_list.insert_last(1);


	cout << "3. Insert 2 before 1." << endl;
	my_list.insert_before(2, 1);

	cout << "4. Insert 4 after 3." << endl;
	my_list.insert_after(4, 3);
	cout << endl;

	cout << "Result inserts" << endl;
	cout << my_list;
	cout << "Quantity nodes: " << my_list.GetSize() << endl;
	cout << endl;

	cout << "Now let's do a data search. For example, find 3" << endl;
	cout << "Searching 3..." << endl;
	Node<int>* found = my_list.search(3);
	if (found != nullptr) {
		cout << found->data << " exist in list!" << endl << endl;
	}
	else {
		cout << "Data not exist!" << endl << endl;
	}

	cout << "But 7 not exist" << endl;
	cout << "Searching 7..." << endl;
	found = my_list.search(7);
	if (found != nullptr) {
		cout << found->data << " exist in list!" << endl << endl;
	}
	else {
		cout << "Data not exist!" << endl << endl;
	}

	cout << "Let's delete some list node and try search. Assume 3" << endl;
	my_list.remove(3);
	cout << "Searching 3..." << endl;
	found = my_list.search(3);
	if (found != nullptr) {
		cout << found->data << " exist in list!" << endl << endl;
	}
	else {
		cout << "Data not exist!" << endl << endl;
	}

	cout << "Result removing" << endl;
	cout << my_list;
	cout << "Quantity nodes: " << my_list.GetSize() << endl;

	cout << "Let's do some more-just inserts..." << endl;
	my_list.insert_last(6);
	my_list.insert_last(8);
	my_list.insert_last(4);
	my_list.insert_last(20);
	cout << "Done!" << endl;
	cout << my_list;
	cout << endl;

	bool mode = true;
	int choice = 0;
	Node<int>* tmp = my_list.GetCurrent();
	cout << "Welcome to test system navigation list!" << endl;
	do {
		cout << "1. Get current data" << "		" << "2. Next node " << endl;
		cout << "3. Return start	" << "		" << "4. Exit " << endl;
		cout << endl << endl << endl;
		do {
			cin >> choice;
		} while (choice < 0 || choice > 4);
		switch (choice) {
		case 1:{
			cout << "|										" << endl;
			cout << "|	Current node:" << endl;
			cout << "|										" << endl;
			cout << "|	data: " << tmp->data << "			" << endl;
			cout << "|										" << endl;
			break;
			}
		case 2:{
			if (!my_list.Is_End()) {
				my_list.next();
				tmp = my_list.GetCurrent();
				}
			else {
				cout << "You've reached the end of the list,";
				cout << "so you're back at the beginning" << endl;
				my_list.reset();
				tmp = my_list.GetCurrent();
				}
			break;
			}
		case 3:{
			my_list.reset();
			tmp = my_list.GetCurrent();
			break;
			}
		case 4:{
			mode = false;
			my_list.reset();
			break;
			}
		}
	} while (mode != false);
}