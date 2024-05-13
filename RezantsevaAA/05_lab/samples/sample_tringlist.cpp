#include <iostream>
#include "tringlist.h"
using namespace std;
int main()
{
    TRingList<int> ringList;
	int size, data, data2;
	std::cout << "Let's create a new ringlist with insert First! Enter numbers of ringlist's elements" << endl;
	std::cin >> size;
	std::cout << "Now let's fill our ringlist:" << endl;
	std::cout << "Please enter data " << endl;
	for (int i = 0; i < size; i++)
	{
		std::cin >> data;
		ringList.InsertFirst(data);
	}
	std::cout << "Our ringlist:" << endl;
	std::cout << ringList << std::endl;
	ringList.Reset();

	std::cout << "Let's remove first element" << endl;
	ringList.RemoveFirst();
	std::cout << "Our ringlist:" << endl;
	std::cout << ringList << std::endl;
    return 0;
}