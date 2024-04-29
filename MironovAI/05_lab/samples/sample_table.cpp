#include <unordered_map>
#include "tpolynom.h"
#include "table.h"
#include "scan_table.h"
#include "hash_table.h"
#include "sorted_table.h"

#define INSERT 1
#define DELETE 2
#define FIND 3

ScanTable<TPolynom, bool> scan_table;
SortedTable<TPolynom, bool> sorted_table;
HashTable<TPolynom, bool> hash_table;

void scan1(int teg)
{

}


void sorted1(int teg)
{

}

void hash1(int teg)
{

}


void user()
{
	while (1)
	{
		std::cout << "1.Add\n2.Erase\n3.Print\n4.PrintAll\n5.find\n6.Action with polynom\n";
		int option; std::cin >> option;
		if (option == 1)
		{
			Add();
			continue;
		}
		else if (option == 2)
		{
			Erase();
			continue;
		}
		else if (option == 3)
		{
			Print();
			continue;
		}
		else if (option == 4)
		{
			PrintAll();
			continue;
		}
		else if (option == 5)
		{
			Find();
			continue;
		}
		else if (option == 6)
		{
			Actions_with_polynom();
			continue;
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

void Add()
{
	TPolynom polynom; std::cin >> polynom;
	std::cout << "Where to add?\n";
	std::cout << "1.Scan table\n2.Sorted table\n3.Hash table\n4.All tables\n";
	int option; std::cin >> option;
	if (option == 1)
	{
		scan(INSERT);
	}
	else if (option == 2)
	{
		sorted(INSERT);
	}
	else if (option == 3)
	{
		hash(INSERT);
	}
	else if (option == 4)
	{
		scan(INSERT);
		hash(INSERT);
		sorted(INSERT);
	}
	else
	{
		cout << "Wrong\n";
	}
	
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->add(name, polynom);
	}
	wait();
}

void Erase()
{
	std::string name;
	std::cout << "Input name:";
	std::cin >> name;
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->erase(name);
	}
	wait();
}

void Print()
{
	std::string name;
	std::cout << "Input name:";
	std::cin >> name;
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->print(name);
	}
	wait();
}

void PrintAll()
{
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->print_all();
	}
	wait();
}

void Find()
{
	std::string name;
	std::cout << "Input name:";
	std::cin >> name;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << Tables[i]->find(name) << "\n";
	}
	wait();
}

void Actions_with_polynom()
{
	std::cout << "The polinoms you have:";
	Tables[0]->print_all();
	std::cout << "\nType name of two polynoms which ones you what to sum/multiply\n";
	std::string name1, name2;
	std::cin >> name1 >> name2;
	while (!Tables[1]->find(name1) || !Tables[1]->find(name2))
	{
		std::cout << "Wrong Input!\n";
		std::cin >> name1 >> name2;
	}
	Polynom t1 = Tables[1]->get_polynom(name1);
	Polynom t2 = Tables[1]->get_polynom(name2);
	std::cout << "Input what you want to do(+/* another symbol will be interpreted as *):";
	char c; std::cin >> c;
	Polynom tmp;
	if (c == '+')
	{
		tmp = t1 + t2;
	}
	else
	{
		tmp = t1 * t2;
	}
	std::cout << "Your polynom is: " << tmp << "\nYou want to save it? (Y/N another symbol = N)";
	std::cin >> c;
	if (c == 'Y')
	{
		std::string name;
		std::cout << "Input name:";
		std::cin >> name;
		while (Tables[1]->find(name))
		{
			std::cout << "Table with this name is exist!";
			std::cin >> name;
		}
		for (int i = 0; i < 3; ++i)
		{
			Tables[i]->add(name, tmp);
		}
	}
	else
		tmp.clear();
}

int main()
{
	


}

int main()
{
	return 0;

	std::unordered_map<int, int> k;
}