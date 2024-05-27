#include "tab_record.h"
#include "table.h"
#include "scan_table.h"
#include "sorted_table.h"
#include "array_hash_table.h"
#include "tpolynom.h"

#include <iostream>

using namespace std;

int main() {
	ScanTable<string, TPolynom> scan_table(100);
	SortedTable<string, TPolynom> sorted_table(100);
	ArrayHashTable<string, TPolynom> hash_table(10, 1);
	int action = 0;
	int table;
	string str;
	do {
		cout << "Select the action:" << endl;
		cout << "1) Add the polynom;" << endl;
		cout << "2) Remove the polynom;" << endl;
		cout << "3) Print the status;" << endl;
		cout << "4) Perform an operation on the polynoms" << endl;
		cout << "5) Finish" << endl;
		cin >> action;
		cout << endl;
		if (action == 1) {
			cout << "Enter the polynom to add: ";
			cin >> str;
			cout << endl;
			TPolynom p(str);
			cout << "Select the table:" << endl;
			cout << "1) Scan table;" << endl;
			cout << "2) Sorted table;" << endl;
			cout << "3) Hash table;" << endl;
			cout << "4) All the tables;" << endl;
			cin >> table;
			cout << endl;
			if (table == 1) {
				scan_table.Insert(str, &p);
			}
			else if (table == 2) {
				sorted_table.Insert(str, &p);
			}
			else if (table == 3) {
				hash_table.Insert(str, &p);
			}
			else if (table == 4) {
				scan_table.Insert(str, &p);
				sorted_table.Insert(str, &p);
				hash_table.Insert(str, &p);
			}
			else {
				cout << "Invalid value!" << endl;
				cout << endl;
				continue;
			}
		}
		else if (action == 2) {
			cout << "Enter the polynom to remove: ";
			cin >> str;
			cout << endl;
			cout << "Select the table:" << endl;
			cout << "1) Scan table;" << endl;
			cout << "2) Sorted table;" << endl;
			cout << "3) Hash table;" << endl;
			cout << "4) All the tables;" << endl;
			cin >> table;
			cout << endl;
			if (table == 1) {
				scan_table.Remove(str);
			}
			else if (table == 2) {
				sorted_table.Remove(str);
			}
			else if (table == 3) {
				hash_table.Remove(str);
			}
			else if (table == 4) {
				scan_table.Remove(str);
				sorted_table.Remove(str);
				hash_table.Remove(str);
			}
			else {
				cout << "Invalid value!" << endl;
				cout << endl;
				continue;
			}
		}
		else if (action == 3) {
			cout << "Select the table:" << endl;
			cout << "1) Scan table;" << endl;
			cout << "2) Sorted table;" << endl;
			cout << "3) Hash table;" << endl;
			cout << "4) All the tables;" << endl;
			cin >> table;
			cout << endl;
			if (table == 1) {
				cout << "SCAN TABLE" << endl;
				cout << scan_table;
				cout << endl;
			}
			else if (table == 2) {
				cout << "SORTED TABLE" << endl;
				cout << sorted_table;
				cout << endl;
			}
			else if (table == 3) {
				cout << "HASH TABLE" << endl;
				cout << hash_table;
				cout << endl;
			}
			else if (table == 4) {
				cout << "SCAN TABLE" << endl;
				cout << scan_table;
				cout << endl;
				cout << "SORTED TABLE" << endl;
				cout << sorted_table;
				cout << endl;
				cout << "HASH TABLE" << endl;
				cout << hash_table;
				cout << endl;
			}
			else {
				cout << "Invalid value!" << endl;
				cout << endl;
				continue;
			}
		}
		else if (action == 4) {
			cout << "Select operator: ";
			char oper;
			cin >> oper;
			cout << endl;
			cout << "Select the table:" << endl;
			cout << "1) Scan table;" << endl;
			cout << "2) Sorted table;" << endl;
			cout << "3) Hash table;" << endl;
			cin >> table;
			cout << endl;
			cout << "Select the first polynom: ";
			string str1;
			cin >> str1;
			cout << endl;
			cout << "Select the second polynom: ";
			string str2;
			cin >> str2;
			cout << endl;
			if (oper == '+') {
				if (table == 1) {
					TPolynom p1 = *scan_table.Search(str1)->data;
					TPolynom p2 = *scan_table.Search(str2)->data;
					scan_table.Insert(str1 + '+' + str2, &(p1 + p2));
				}
				else if (table == 2) {
					TPolynom p1 = *sorted_table.Search(str1)->data;
					TPolynom p2 = *sorted_table.Search(str2)->data;
					sorted_table.Insert(str1 + '+' + str2, &(p1 + p2));
				}
				else if (table == 3) {
					TPolynom p1 = *hash_table.Search(str1)->data;
					TPolynom p2 = *hash_table.Search(str2)->data;
					hash_table.Insert(str1 + '+' + str2, &(p1 + p2));
				}
				else {
					cout << "Invalid value!" << endl;
					cout << endl;
					continue;
				}
			}
			else if (oper == '-') {
				if (table == 1) {
					TPolynom p1 = *scan_table.Search(str1)->data;
					TPolynom p2 = *scan_table.Search(str2)->data;
					scan_table.Insert(str1 + '-' + str2, &(p1 - p2));
				}
				else if (table == 2) {
					TPolynom p1 = *sorted_table.Search(str1)->data;
					TPolynom p2 = *sorted_table.Search(str2)->data;
					sorted_table.Insert(str1 + '-' + str2, &(p1 - p2));
				}
				else if (table == 3) {
					TPolynom p1 = *hash_table.Search(str1)->data;
					TPolynom p2 = *hash_table.Search(str2)->data;
					hash_table.Insert(str1 + '-' + str2, &(p1 - p2));
				}
				else {
					cout << "Invalid value!" << endl;
					cout << endl;
					continue;
				}
			}
			else if (oper == '*') {
				if (table == 1) {
					TPolynom p1 = *scan_table.Search(str1)->data;
					TPolynom p2 = *scan_table.Search(str2)->data;
					scan_table.Insert(str1 + '*' + str2, &(p1 * p2));
				}
				else if (table == 2) {
					TPolynom p1 = *sorted_table.Search(str1)->data;
					TPolynom p2 = *sorted_table.Search(str2)->data;
					sorted_table.Insert(str1 + '*' + str2, &(p1 * p2));
				}
				else if (table == 3) {
					TPolynom p1 = *hash_table.Search(str1)->data;
					TPolynom p2 = *hash_table.Search(str2)->data;
					hash_table.Insert(str1 + '*' + str2, &(p1 * p2));
				}
				else {
					cout << "Invalid value!" << endl;
					cout << endl;
					continue;
				}
			}
			else {
				cout << "Invalid value!" << endl;
				cout << endl;
				continue;
			}
		}
		else if (action == 5) {
			break;
		}
		else {
			cout << "Invalid value!" << endl;
			cout << endl;
			continue;
		}
	} while (action != 5);
	return 0;
}