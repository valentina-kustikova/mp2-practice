#include <unordered_map>
#include "tpolynom.h"
#include "table.h"
#include "scan_table.h"
#include "hash_table.h"
#include "sorted_table.h"

#define INSERT 1
#define DELETE 2
#define FIND 3
#define PRINT 4

#define none 0
#define SUM 1
#define SUB 2
#define MUL 3
#define DIFF_X 4
#define DIFF_Y 5
#define DIFF_Z 6



ScanTable<string, TPolynom> scan_table(101);
SortedTable<string, TPolynom> sorted_table(101);
HashTable<string, TPolynom> hash_table(101);

string operation()
{
	int op;
	TPolynom result, polynom1, polynom2;
	string polynom_string1, polynom_string2;
	std::cout << "1.SUM\n2.SUB\n3.MUL\n4.DIFF_x\n5.diff_y\n6.diff_z\n7.none\n";
	cin >> op;

	std::cout << "input a polynom:\n";
	cin >> polynom_string1;
	cout << "\n";
	polynom1 = TPolynom(polynom_string1);

	if (op < 4)
	{
		std::cout << "input the second polynom:\n";
		cin >> polynom_string2;
		cout << "\n";
		polynom2 = TPolynom(polynom_string2);
	}


	switch (op)
	{
	case SUM:
		result = polynom1 + polynom2;
		break;
	case SUB:
		result = polynom1 - polynom2;
		break;
	case MUL:
		result = polynom1 * polynom2;
		break;
	case DIFF_X:
		result = polynom1.dif_x();
		break;
	case DIFF_Y:
		result = polynom1.dif_y();
		break;
	case DIFF_Z:
		result = polynom1.dif_z();
		break;
	default:
		result = polynom1;
		break;
	}

	return (op == 7) ? polynom_string1 : result.get_name();

}



void action(int table, int tag)
{
	TPolynom polynom;
	string polynom_string;
	if (tag != PRINT)
	{
		polynom_string = operation();
		polynom = TPolynom(polynom_string);
	}
	
	if (tag == INSERT)
	{
		if (table == 1 || table == 4)
		{
			try
			{
				scan_table.insert(polynom_string, polynom);
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
				sorted_table.insert(polynom_string, polynom);
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
				hash_table.insert(polynom_string, polynom);
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
				Record<string, TPolynom>* t = scan_table.find(polynom_string);
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
				Record<string, TPolynom>* t = sorted_table.find(polynom_string);
				if (!t)
				{
					cout << "Polynom wasn`t found\n";
				}
				else cout << "Polynom was found\n";
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
				Record<string, TPolynom>* t = hash_table.find(polynom_string);
				if (!t)
				{
					cout << "Polynom wasn`t found\n";
				}
				else cout << "Polynom was found\n";
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
				scan_table.remove(polynom_string);
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
				sorted_table.remove(polynom_string);
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
				hash_table.remove(polynom_string);
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
}