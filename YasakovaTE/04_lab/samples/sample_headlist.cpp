#include <iostream>
#include "headlist.h" 

int main() {
	headlist<int> list;
	int size, data, data2;
	std::cout << "Let's create a new ringlist with insert First! Enter numbers of ringlist's elements" << endl;
	std::cin >> size;
	std::cout << "Now let's fill our ringlist:" << endl;
	std::cout << "Please enter data " << endl;
	for (int i = 0; i < size; i++)
	{
		std::cin >> data;
		list.InsertFirst(data);
	}
	std::cout << "Our ringlist:" << endl;
	std::cout << list << std::endl;
	list.Reset();

	std::cout << "Let's remove first element" << endl;
	list.RemoveFirst();
	std::cout << "Our ringlist:" << endl;
	std::cout << list << std::endl;
	return 0;
}