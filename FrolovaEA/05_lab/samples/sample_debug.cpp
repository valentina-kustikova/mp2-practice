#include <iostream>
#include"Arrayhashtable.h"

int main()
{
	TArrayHashTable<int, std::string> table;
	cout << table.GetMaxSize() << endl;
	cout << table.GetCount() << endl;
	


	return 0;
}


