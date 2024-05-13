#include <iostream>
#include "list.h" 
using namespace std;

int main()
{
	TList<int> list;
	int size, data, data2;
	std::cout << "Let's create a new list! Enter numbers of list's elements" << endl;
	std::cin >> size;
	std::cout << "Now let's fill our list:" << endl;
	std::cout << "Please enter data " << endl;
	for (int i = 0; i < size; i++)
	{
		std::cin >> data;
		list.InsertLast(data);
	}
	std::cout << "Our list:" << endl;
	std::cout << list << std::endl;
	list.Reset();
	std::cout << "Let's insert something to the beginning of the list  and in the end" << endl;
	std::cout << "Please enter data to insert to the beginning " << endl;
	std::cin >> data;
	list.InsertFirst(data);
	std::cout << "Please enter data to insert in the end " << endl;
	std::cin >> data;
	list.InsertLast(data);
	std::cout << "Our list:" << endl;
	std::cout << list << std::endl;
	list.Reset();
	std::cout << "Let's insert something before element you want. At first, enter the element before which you want to insert " << endl;
	std::cin >> data2;
	while (list.Search(data2) == nullptr)
	{
		std::cout << "Error. List don't have this element. Please, enter correct element" << endl;
		std::cin >> data2;
	}
	std::cout << "Please enter data to insert" << endl;
	std::cin >> data;
	list.InsertBefore(data, data2);
	std::cout << "Our list:" << endl;
	std::cout << list << std::endl;
	list.Reset();
	std::cout << "Let's insert something after element you want. At first, enter the element after which you want to insert " << endl;
	std::cin >> data2;
	while (list.Search(data2) == nullptr)
	{
		std::cout << "Error. List don't have this element. Please, enter correct element" << endl;
		std::cin >> data2;
	}
	std::cout << "Please enter data to insert" << endl;
	std::cin >> data;
	list.InsertAfter(data, data2);
	std::cout << "Our list:" << endl;
	std::cout << list << std::endl;
	list.Reset();
	std::cout << "Let's remove first element in our list" << endl;
	list.RemoveFirst();
	std::cout << "Our list:" << endl;
	std::cout << list << std::endl;
	return 0;
}