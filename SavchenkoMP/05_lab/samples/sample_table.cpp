#include <iostream>
#include <string>
#include "tableslib.h"
#include "tpolynom.h"

using namespace std;


#define EXIT   0
#define INSERT 1
#define DELETE 2
#define OPERATIONS 3
#define PRINT  4
#define SELECT_TABLES 5

#define SUM 1
#define SUB 2
#define MUL 3
#define DIFF_X 4
#define DIFF_Y 5
#define DIFF_Z 6

#define SCAN 1
#define SORTED 2
#define ARRAY_HASH 3

ScanTable	  <string, TPolynom> scan_table		 (DEFAULT_SIZE);
SortedTable	  <string, TPolynom> sorted_table	 (DEFAULT_SIZE);
ArrayHashTable<string, TPolynom> array_hash_table(DEFAULT_SIZE, DEFAULT_HASHSTEP);

TabRecord<string, TPolynom>* tr_scan	   = nullptr;
TabRecord<string, TPolynom>* tr_sorted	   = nullptr;
TabRecord<string, TPolynom>* tr_array_hash = nullptr;

bool flag_scan		= true;
bool flag_sorted	= true;
bool flag_array_hash= true;


void menu();
void insert();
void remove();
void operations();
void print_tables();
void select_tables();
void print_selected_tables();


int main() {
	
	try {

		menu();

	}
	catch (string exp) {
		cout << exp << endl;
		return -1;
	}
	return 0;
}


void menu() {
	int ans;

	while (1) {
		system("cls");
		cout << "PATH:menu\\" << endl;
		print_selected_tables();
		cout << endl;

		cout << "1. Insert polynom" << endl;
		cout << "2. Remove polynom" << endl;
		cout << "3. Operations" << endl;
		cout << "4. Print tables" << endl;
		cout << "5. Select tables" << endl;
		cout << "0. EXIT" << endl << endl;
			

		cin >> ans;

		if (ans == INSERT) {
			insert();
		}

		else if (ans == DELETE) {
			remove();
		}

		else if (ans == OPERATIONS) {
			operations();
		}

		else if (ans == PRINT) {
			print_tables();
		}

		else if (ans == SELECT_TABLES) {
			select_tables();
		}

		else if (ans == EXIT) {
			return;
		}
	}
}

void insert() {
	system("cls");
	cout << "PATH:menu\\insertion\\" << endl;

	if (!(flag_scan || flag_sorted || flag_array_hash)) {
		cout << "Tables not selected." << endl;
		system("pause");
		return;
	}
	print_selected_tables();
	cout << endl;

	cout << "Enter the polynomial you want to add to the tables." << endl << endl;
	

	try {
		string name;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);

		TPolynom new_polynom(name);
		string new_polynom_name = new_polynom.get_string();

		if (flag_scan) {
			try {
				scan_table.insert(new_polynom_name, &new_polynom);
				cout << "\nScanTable.insert(): OK" << endl;
			}
			catch (string exp) {
				cout << "\nScanTable.insert(): " << exp << endl;
			}
		}

		if (flag_sorted) {
			try {
				sorted_table.insert(new_polynom_name, &new_polynom);
				cout << "\nSortedTable.insert(): OK" << endl;
			}
			catch (string exp) {
				cout << "\nSortedTable.insert(): " << exp << endl;
			}
		}

		if (flag_array_hash) {
			try {
				array_hash_table.insert(new_polynom_name, &new_polynom);
				cout << "\nArrayHashTable.insert(): OK" << endl;
			}
			catch (string exp) {
				cout << "\nArrayHashTable.insert(): " << exp << endl;
			}
		}
	}
	catch (string exp) {
		cout << exp << endl;

		system("pause");
	}
	
	system("pause");
}

void remove() {
	system("cls");
	cout << "PATH:menu\\removing\\" << endl;

	if (!(flag_scan || flag_sorted || flag_array_hash)) {
		cout << "Tables not selected." << endl;
		system("pause");
		return;
	}
	print_selected_tables();
	cout << endl;

	cout << "Enter the polynomial you want to remove from the table." << endl << endl;
	

	try {
		string name;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);

		TPolynom polynom(name);
		string polynom_name = polynom.get_string();

		if (flag_scan) {
			try {
				scan_table.remove(polynom_name);
				cout << "\nScanTable.remove(): OK" << endl;
			}
			catch (string exp) {
				cout << "\nScanTable.remove(): " << exp << endl;
			}
		}

		if (flag_sorted) {
			try {
				sorted_table.remove(polynom_name);
				cout << "\nSortedTable.remove(): OK" << endl;
			}
			catch (string exp) {
				cout << "\nSortedTable.remove(): " << exp << endl;
			}
		}

		if (flag_array_hash) {
			try {
				array_hash_table.remove(polynom_name);
				cout << "\nArrayHashTable.remove(): OK" << endl;
			}
			catch (string exp) {
				cout << "\nArrayHashTable.remove(): " << exp << endl;
			}
		}
	}
	catch (string exp) {
		cout << exp << endl;

		system("pause");
		return;
	}

	system("pause");
}

void operations() {
	system("cls");
	cout << "PATH:menu\\operations\\" << endl;

	cout << "Select table." << endl << endl;
	cout << "0. none" << endl;
	cout << "1. ScanTable" << endl;
	cout << "2. SortedTable" << endl;
	cout << "3. ArrayHashTable" << endl << endl;

	int tab = 0;
	cin >> tab;
	if (tab < SCAN || tab > ARRAY_HASH) return;

	system("cls");
	cout << "PATH:menu\\operations\\" << endl;
	cout << "Selected table: ";
	if (tab == SCAN) cout << "ScanTable" << endl;
	if (tab == SORTED) cout << "SortedTable" << endl;
	if (tab == ARRAY_HASH) cout << "ArrayHashTable" << endl << endl;

	cout << "Select an operation to apply it on table polynomials." << endl << endl;
	cout << "0. none" << endl;
	cout << "1. +" << endl;
	cout << "2. -" << endl;
	cout << "3. *" << endl;
	cout << "4. diff_x" << endl;
	cout << "5. diff_y" << endl;
	cout << "6. diff_z" << endl << endl;

	int op = 0;
	cin >> op;
	if (op < SUM || op > DIFF_Z) return;

	system("cls");
	cout << "PATH:menu\\operations\\" << endl;
	TabRecord<string, TPolynom> *tab_polynom1 = nullptr, *tab_polynom2 = nullptr;

	try {
		cout << "Enter the polynom to find it in the table: " << endl;
		
		string name1;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name1);
		TPolynom polynom1(name1);
		
		if (tab == SCAN) {
			tab_polynom1 = scan_table.find(polynom1.get_string());
		}
		if (tab == SORTED) {
			tab_polynom1 = sorted_table.find(polynom1.get_string());
		}
		if (tab == ARRAY_HASH) {
			tab_polynom1 = array_hash_table.find(polynom1.get_string());
		}
		if (tab_polynom1 == nullptr) {
			cout << "ERROR: polynom not found" << endl;
			system("pause");
			return;
		}
		cout << endl;

		if (op >= SUM && op <= MUL) {
			cout << "Enter the second polynom to find it in the table: " << endl;
			
			string name2;
			getline(cin, name2);
			TPolynom polynom2(name2);
			
			if (tab == SCAN) {
				tab_polynom2 = scan_table.find(polynom2.get_string());
			}
			if (tab == SORTED) {
				tab_polynom2 = sorted_table.find(polynom2.get_string());
			}
			if (tab == ARRAY_HASH) {
				tab_polynom2 = array_hash_table.find(polynom2.get_string());
			}
			if (tab_polynom2 == nullptr) {
				cout << "ERROR: second polynom not found" << endl;
				system("pause");
				return;
			}
		}
		cout << endl;

		system("cls");
		cout << "PATH:menu\\operations\\" << endl;
		TPolynom result("0");
		if (op == SUM) {
			result = *tab_polynom1->data + *tab_polynom2->data;
			cout << "polynom1 + polynom2 = " << result << endl << endl;
		}

		else if (op == SUB) {
			result = *tab_polynom1->data - *tab_polynom2->data;
			cout << "polynom1 - polynom2 = " << result << endl << endl;
		}

		else if (op == MUL) {
			result = *tab_polynom1->data * *tab_polynom2->data;
			cout << "polynom1 * polynom2 = " << result << endl << endl;
		}

		else if (op == DIFF_X) {
			result = tab_polynom1->data->diff_x();
			cout << "polynom.diff_x() = " << result << endl << endl;
		}

		else if (op == DIFF_Y) {
			result = tab_polynom1->data->diff_y();
			cout << "polynom.diff_x() = " << result << endl << endl;
		}

		else if (op == DIFF_Z) {
			result = tab_polynom1->data->diff_z();
			cout << "polynom.diff_x() = " << result << endl << endl;
		}

		cout << "Add result to this table? 1/0" << endl;
		int ans = 0;
		cin >> ans;
		if (ans) {
			try {
				if (tab == SCAN) {
					scan_table.insert(result.get_string(), &result);
				}
				if (tab == SORTED) {
					sorted_table.insert(result.get_string(), &result);
				}
				if (tab == ARRAY_HASH) {
					array_hash_table.insert(result.get_string(), &result);
				}
			}
			catch (string exp) {
				cout << exp << endl;
			}
		}
		system("pause");
	}
	catch (string exp) {
		cout << exp << endl;
		system("pause");
		return;
	}
}

void print_tables() {
	system("cls");
	cout << "PATH:menu\\print\\" << endl;

	if (!(flag_scan || flag_sorted || flag_array_hash)) {
		cout << "Tables not selected." << endl;
		system("pause");
		return;
	}
	print_selected_tables();
	cout << endl;

	if (flag_scan) {
		cout << "ScanTable:" << endl;
		cout << scan_table << endl;
	}
	if (flag_sorted) {
		cout << "SortedTable:" << endl;
		cout << sorted_table << endl;
	}
	if (flag_array_hash) {
		cout << "ArrayHashTable:" << endl;
		cout << array_hash_table << endl;
	}

	system("pause");
}

void select_tables() {
	int st = 0;

	do {
		system("cls");
		cout << "# table_name     is_selected" << endl;
		cout << "1 ScanTable      " << flag_scan << endl;
		cout << "2 SortedTable    " << flag_sorted << endl;
		cout << "3 ArrayHashTable " << flag_array_hash << endl << endl;

		cout << "Select # of table to enable/disable." << endl;
		cout << "Press 0 to go back to previous menu." << endl << endl;

		cin >> st;

		if (st == 0) return;
		else if (st == 1) flag_scan = !flag_scan;
		else if (st == 2) flag_sorted = !flag_sorted;
		else if (st == 3) flag_array_hash = !flag_array_hash;

	} while (st != 0);
}

void print_selected_tables() {
	cout << "SELECTED TABLES: ";
	if (flag_scan) cout << "ScanTable ";
	if (flag_sorted) cout << "SortedTable ";
	if (flag_array_hash) cout << "ArrayHashTable ";
	cout << endl;
}
