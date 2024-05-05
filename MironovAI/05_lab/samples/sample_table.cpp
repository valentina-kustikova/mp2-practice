#include <unordered_map>
#include "tpolynom.h"
#include "table.h"
#include "scan_table.h"
#include "hash_table.h"
#include "sorted_table.h"

#define INSERT 1
#define DELETE 2
#define FIND 3

ScanTable<TPolynom, bool> scan_table(101);
SortedTable<TPolynom, bool> sorted_table(101);
HashTable<TPolynom, bool> hash_table(101);


void action(int table, int tag)
{
	std::cout << "input a polynom:\n";
	TPolynom polynom; cin >> polynom;
	cout << "\n";
	if (tag == INSERT)
	{
		if (table == 1 || table == 4)
		{
			try
			{
				scan_table.insert(polynom, true);
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
				sorted_table.insert(polynom, true);
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
				hash_table.insert(polynom, true);
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
				Record<TPolynom, bool>* t = scan_table.find(polynom);
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
				Record<TPolynom, bool>* t = sorted_table.find(polynom);
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
				Record<TPolynom, bool>* t = hash_table.find(polynom);
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


}

void kind(int table_tag)
{
	int teg = 0;
	std::cout << "1.Insert\n2.Remove\n3.Find\n";
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
}