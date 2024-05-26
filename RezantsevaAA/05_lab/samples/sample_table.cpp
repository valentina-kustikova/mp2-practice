#include <iostream>
#include "table.h"
#include "scanTable.h"
#include "sortedTable.h"
#include "tpolynom.h"
#include "arrayHashTable.h"

TScanTable<std::string, TPolinom> scan_table(101);
SortedTable<std::string, TPolinom> sorted_table(101);
TArrayHashTable<std::string, TPolinom> hash_table(101, 1);

int Correct(int type)
{
	while (type != 1 && type != 2 && type != 3 && type != 4)
	{
		std::cout << " Please, choose correctly: \n 1 - Scan table \n 2 - Sorted table \n 3 - Hash table\n 4 - All\n";
		std::cin >> type;
	}
	return type;
}

void Print()
{
	int type;
	std::cout << " Which table you want to print: \n 1 - Scan table \n 2 - Sorted table \n 3 - Hash table\n 4 - All\n";
	std::cin >> type;
	type = Correct(type);
	switch (type)
	{
	case 1:
		std::cout << "Table: " << std::endl;
		std::cout << scan_table << std::endl;
		break;
	case 2:
		std::cout << "Sorted table: " << std::endl;
		std::cout << sorted_table << std::endl;
		break;
	case 3:
		std::cout << "Hash table: " << std::endl;
		std::cout << hash_table << std::endl;
		break;
	case 4:
		std::cout << "Table: " << std::endl;
		std::cout << scan_table << std::endl;
		std::cout << "Sorted table: " << std::endl;
		std::cout << sorted_table << std::endl;
		std::cout << "Hash table: " << std::endl;
		std::cout << hash_table << std::endl;
		break;
	}
}
void insertResult(TPolinom res, int type)
{
	type = Correct(type);

	switch (type)
	{
	case 1:
		if (!scan_table.IsFull()) {
			scan_table.Insert(res.getFormula(), res);
			break;
		}
		else
		{
			std::cout << " Sorry. Table is full.Please, choose another table: \n 2 - Sorted table \n 3 - Hash table\n ";
			std::cin >> type;
			while (type != 2 && type != 3)
				std::cin >> type;
			insertResult(res, type);
			break;
		}

	case 2:
		if (!sorted_table.IsFull())
		{
			sorted_table.Insert(res.getFormula(), res);
			break;
		}
		else
		{
			std::cout << " Sorry. Sorted table is full.Please, choose another table: \n 1 - Scan table \n 3 - Hash table\n ";
			std::cin >> type;
			while (type != 1 && type != 3)
				std::cin >> type;
			insertResult(res, type);
			break;
		}

	case 3:
		if (!hash_table.IsFull())
		{
			hash_table.Insert(res.getFormula(), res);
			break;
		}
		else
		{
			std::cout << " Sorry. Hash table is full.Please, choose another table: \n 1 - Scan table \n 2 - Sorted table\n ";
			std::cin >> type;
			while (type != 1 && type != 2)
				std::cin >> type;
			insertResult(res, type);
			break;
		}

	case 4:
		if (!sorted_table.IsFull() && !scan_table.IsFull() && !hash_table.IsFull())
		{
			scan_table.Insert(res.getFormula(), res);
			sorted_table.Insert(res.getFormula(), res);
			hash_table.Insert(res.getFormula(), res);
			break;
		}
		else
		{
			std::cout << " Sorry. All tables are full." << std::endl;
			break;
		}
	}
}
void Insert()
{
	std::string s1;
	std::cout << "Please, enter polynom to insert \n";
	std::cin >> s1;
	TPolinom p1(s1);

	int type;
	std::cout << " In which table you want to insert: \n 1 - Scan table \n 2 - Sorted table \n 3 - Hash table\n 4 - All\n";
	std::cin >> type;
	insertResult(p1, type);
}

void Remove()
{
	std::string s1;
	std::cout << "Please, enter polynom to remove \n";
	std::cin >> s1;
	TPolinom p1(s1);
	p1.getFormula();
	int type;
	std::cout << " In which table you want to remove polynom: \n 1 - Scan table \n 2 - Sorted table \n 3 - Hash table\n 4 - All\n";
	std::cin >> type;
	type = Correct(type);
	switch (type)
	{
	case 1:


		if (scan_table.Find(p1.getFormula()) != nullptr)
		{
			scan_table.Remove(p1.getFormula());
		}
		else
		{
			std::cout << "Sorry. Scan table doesn't contain this polynom\n";
		}
		break;
	case 2:

		if (sorted_table.Find(p1.getFormula()) != nullptr)
		{
			sorted_table.Remove(p1.getFormula());
		}
		else
		{
			std::cout << "Sorry. Sorted table doesn't contain this polynom\n";
		}
		break;
	case 3:

		if (hash_table.Find(p1.getFormula()) != nullptr)
		{
			hash_table.Remove(p1.getFormula());
		}
		else
		{
			std::cout << "Sorry. Hash table doesn't contain this polynom\n";
		}
		break;
	case 4:

		if (hash_table.Find(p1.getFormula()) != nullptr && scan_table.Find(p1.getFormula()) != nullptr && sorted_table.Find(p1.getFormula()) != nullptr)
		{
			scan_table.Remove(p1.getFormula());
			sorted_table.Remove(p1.getFormula());
			hash_table.Remove(p1.getFormula());
		}
		else
		{
			std::cout << "Sorry. Not all tables have this polynom\n";
		}
		break;
		scan_table.Insert(p1.getFormula(), p1);
		sorted_table.Insert(p1.getFormula(), p1);
		hash_table.Insert(p1.getFormula(), p1);
		break;
	}
}

void Result(TPolinom result)
{
	int type;
	std::cout << "Result = " << result.getFormula() << std::endl;
	std::cout << " In which table you want to insert the result: \n 1 - Scan table \n 2 - Sorted table \n 3 - Hash table\n 4 - All\n";
	std::cin >> type;
	insertResult(result, type);
}

//-------------In Table----------------------\\

bool inScanTable(TPolinom p1, TPolinom p2)
{
	if (scan_table.Find(p1.getFormula()) != nullptr && scan_table.Find(p2.getFormula()) != nullptr)
		return true;
	return false;
}
bool inSortedTable(TPolinom p1, TPolinom p2)
{
	if (sorted_table.Find(p1.getFormula()) != nullptr && sorted_table.Find(p2.getFormula()) != nullptr)
		return true;
	return false;
}
bool inHashTable(TPolinom p1, TPolinom p2)
{
	if (hash_table.Find(p1.getFormula()) != nullptr && hash_table.Find(p2.getFormula()) != nullptr)
		return true;
	return false;
}

bool inOneTable(TPolinom p1, TPolinom p2)
{
	if (inScanTable(p1, p2) || inSortedTable(p1, p2) || inHashTable(p1, p2))
		return true;
	return false;
}

void Dif()// DIF - to take the derivative
{
	std::string s1, dif;
	std::cout << "Please, enter polynom which one you want to derivative " << std::endl;
	std::cin >> s1;
	TPolinom p1(s1);
	TPolinom result;
	while (scan_table.Find(p1.getFormula()) == nullptr && sorted_table.Find(p1.getFormula()) == nullptr && hash_table.Find(p1.getFormula()) == nullptr)
	{
		std::cout << "Sorry. All tables doesn't have this polynom." << std::endl;
		Print();
		std::cout << "Please, enter exist polynom " << std::endl;
		std::cin >> s1;
		TPolinom p1(s1);
	}
	std::cout << "Now choose the variable with respect to which you want to take the derivative: x, y, z" << std::endl;
	std::cin >> dif;
	while (dif != "x" && dif != "y" && dif != "z")
	{
		std::cout << " Please, choose correctly: \n  x, y, z\n";
		std::cin >> dif;
	}

	if (dif == "x")
	{
		result = p1.defX();
		Result(result);
	}
	if (dif == "y")
	{
		result = p1.defY();
		Result(result);
	}
	if (dif == "z")
	{
		result = p1.defZ();
		Result(result);
	}
}

void Arithmetic() //+, -, *
{
	std::string func, s1, s2;

	std::cout << "To do arithmetic operations with polynoms they must be in one table!" << std::endl;
	std::cout << "Please, enter first polynom with which one you want to work" << std::endl;
	std::cin >> s1;
	TPolinom p1(s1);
	bool flag;
	//проверка, есть ли первый полином в одной из таблиц
	while (scan_table.Find(p1.getFormula()) == nullptr && sorted_table.Find(p1.getFormula()) == nullptr && hash_table.Find(p1.getFormula()) == nullptr)
	{
		std::cout << "Sorry. All tables doesn't have this polynom." << std::endl;
		Print();
		std::cout << "Please, enter exist polynom " << std::endl;
		std::cin >> s1;
		TPolinom p1(s1);
	}
	std::cout << "Please, enter second polynom with which one you want to work" << std::endl;
	std::cin >> s2;
	TPolinom p2(s2);
	TPolinom result;

	while (!inOneTable(p1, p2))
	{
		std::cout << "Polynoms in different tables or second polynom doesn't exist in tables, please, enter exist second polynom" << std::endl;
		std::cin >> s2;
		TPolinom p2(s2);
	}
	std::cout << "Choose what ou want to do with polynoms. ADD, SUB to substruct, MULT  to multiply" << std::endl;
	std::cin >> func;

	while (func != "ADD" && func != "SUB" && func != "MULT")
	{
		std::cout << " Please, choose correctly: \n  ADD, SUB to substruct, MULT  to multiply\n";
		std::cin >> func;
	}

	if (func == "ADD")
	{
		result = p1 + p2;
		Result(result);
	}
	if (func == "SUB")
	{
		result = p1 - p2;
		Result(result);
	}
	if (func == "MULT")
	{
		result = p1 * p2;
		Result(result);
	}
}

void user()
{
	std::string func;
	while (func != "Exit")
	{

		std::cout << " What you want to do? \n Print \n Insert\n Remove\n Arithmetic - to do arithmetic operations with polynoms \n Dif - to take the derivative of polynom \n Exit" << std::endl;
		std::cin >> func;
		while (func != "Print" && func != "Insert" && func != "Remove" && func != "Arithmetic" && func != "Dif" && func != "Exit")
		{
			std::cout << "Error. Plese, enter correct action" << std::endl;
			std::cin >> func;
		}
		if (func == "Print")
			Print();
		if (func == "Insert")
			Insert();
		if (func == "Remove")
			Remove();
		if (func == "Arithmetic")
			Arithmetic();
		if (func == "Dif")
			Dif();
	}
}


int main()
{
	TPolinom p("3*x^5");
	TPolinom t1("1-x");
	TPolinom t2("x-1");
	TPolinom t3("2*x^2");

	hash_table.Insert(t1.getFormula(), t1);
	hash_table.Insert(t2.getFormula(), t2);
	hash_table.Insert(t3.getFormula(), t3);
	
	scan_table.Insert(t1.getFormula(), t1);
	scan_table.Insert(t2.getFormula(), t2);
	scan_table.Insert(t3.getFormula(), t3);

	sorted_table.Insert(t1.getFormula(), t1);
	sorted_table.Insert(t2.getFormula(), t2);
	sorted_table.Insert(t3.getFormula(), t3);
	sorted_table.Insert(p.getFormula(), p);
	
	user();

	return 0;
}
