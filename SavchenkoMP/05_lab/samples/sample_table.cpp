#include <iostream>
#include "tableslib.h"
#include "tpolynom.h"

using namespace std;


#define EXIT   0
#define INSERT 1
#define DELETE 2
#define FIND   3
#define PRINT  4
#define CHOOSE_TABLES 5


int main() {
	ScanTable	  <string, TPolynom> scan_table  (DEFAULT_SIZE);
	SortedTable	  <string, TPolynom> sorted_table(DEFAULT_SIZE);
	ArrayHashTable<string, TPolynom> hash_table  (DEFAULT_SIZE, DEFAULT_HASHSTEP);

	int flag_scan = 1;
	int flag_sort = 1;
	int flag_hash = 1;

	int ans = 0;

	do {

	} while (ans >= INSERT && ans <= CHOOSE_TABLES);

	system("cls");
	cout << "TABLES\n" << endl;

	cout << "1. Insert record" << endl;
	cout << "2. Delete record" << endl;
	cout << "3. Find record" << endl;
	cout << "4. Print table\n" << endl;

	cout << "";




	return 0;
}




/*
#include <iostream>

using namespace std;


#include <unordered_map>
#include "tpolynom.h"
#include "tableslib.h"

#define INSERT 1
#define DELETE 2
#define FIND 3
#define PRINT 4

ScanTable<TPolynom, string> scan_table(101);
SortedTable<TPolynom, string> sorted_table(101);
HashTable<TPolynom, string> hash_table(101);


void action(int table, int tag)
{
	TPolynom polynom;
	string polynom_string;
	if (tag != PRINT)
	{
		std::cout << "input a polynom:\n";
		cin >> polynom_string;
		cout << "\n";
		polynom = TPolynom(polynom_string);
	}

	if (tag == INSERT)
	{
		if (table == 1 || table == 4)
		{
			try
			{
				scan_table.insert(polynom, polynom_string);
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("insert scan table\n");
			}
		}
		if (table == 2 || table == 4)
		{
			try
			{
				sorted_table.insert(polynom, polynom_string);
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("insert sorted table\n");
			}
		}
		if (table == 3 || table == 4)
		{
			try
			{
				hash_table.insert(polynom, polynom_string);
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("insert hash table\n");
			}
		}
	}
	else if (tag == FIND)
	{
		if (table == 1 || table == 4)
		{
			try
			{
				Record<TPolynom, string>* t = scan_table.find(polynom);
				if (!t)
				{
					cout << "Polynom wasn`t found\n";
				}
				else cout << "Polynom was found\n";
			}
			catch (string ex)
			{
				throw string("find scan table\n");
			}
		}
		if (table == 2 || table == 4)
		{
			try
			{
				Record<TPolynom, string>* t = sorted_table.find(polynom);
				if (!t)
				{
					cout << "Polynom wasn`t found\n";
				}
				else cout << "Polynom was found";
			}
			catch (string ex)
			{
				throw string("find sorted table\n");
			}
		}
		if (table == 3 || table == 4)
		{
			try
			{
				Record<TPolynom, string>* t = hash_table.find(polynom);
				if (!t)
				{
					cout << "Polynom wasn`t found\n";
				}
				else cout << "Polynom was found";
			}
			catch (string ex)
			{
				throw string("find hash table\n");
			}
		}
	}
	else if (tag == DELETE)
	{
		if (table == 1 || table == 4)
		{
			try
			{
				scan_table.remove(polynom);
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("remove scan table\n");
			}
		}
		if (table == 2 || table == 4)
		{
			try
			{
				sorted_table.remove(polynom);
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("remove sorted table\n");
			}
		}
		if (table == 3 || table == 4)
		{
			try
			{
				hash_table.remove(polynom);
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("remove hash table\n");
			}
		}
	}
	else if (tag == PRINT)
	{
		if (table == 1 || table == 4)
		{
			try
			{
				cout << scan_table << endl;
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("cout scan table\n");
			}
		}
		if (table == 2 || table == 4)
		{
			try
			{
				cout << sorted_table << endl;
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("cout sorted table\n");
			}
		}
		if (table == 3 || table == 4)
		{
			try
			{
				cout << hash_table << endl;
				cout << "OK\n";
			}
			catch (string ex)
			{
				throw string("cout hash table\n");
			}
		}
	}
}

void kind(int table_tag)
{
	int teg = 0;
	std::cout << "1.Insert\n2.Remove\n3.Find\n4.Print\n";
	int option; cin >> option;
	if (option == 1)
	{
		teg = INSERT;
	}
	else if (option == 2)
	{
		teg = DELETE;
	}
	else if (option == 3)
	{
		teg = FIND;
	}
	else if (option == 4)
	{
		teg = PRINT;
	}
	else if (option == 0)
	{
		return;
	}
	else
	{
		throw string("wrong tag\n");
	}

	try
	{
		action(table_tag, teg);
	}
	catch (string ex)
	{
		throw ex;
	}
}

void user()
{
	while (1)
	{
		std::cout << "0.Kill the programm\n1.scan table\n2.sorted table\n3.hash table\n4.All tables\n";
		int option; std::cin >> option;
		if (option == 1)
		{
			kind(1);
		}
		else if (option == 2)
		{
			kind(2);
		}
		else if (option == 3)
		{
			kind(3);
		}
		else if (option == 4)
		{
			kind(4);
		}
		else if (option == 0)
		{
			return;
		}
		else
		{
			std::cout << "Wrong \n";
		}
	}
}


int main()
{
	try
	{
		user();
		return 0;
	}
	catch (string ex)
	{
		cout << ex << endl;
		return -1;
	}
}*/