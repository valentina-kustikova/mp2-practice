#include "tlist.h"
#include "tringlist.h"

void list_test()
{
	TList<int> list;

	cout << list.empty() << endl;
	
	cin >> list;
	cout << "Your linked list: \n";
	cout << list << endl;
	
	list.sort(true);
	cout << list << endl;

	cout << list.find(3)->value << endl;
	cout << list.find_prev(3)->value << endl;

	list.pop_first();
	cout << list << endl;
	list.pop_last();
	cout << list << endl;
	list.next();
	list.pop_curr();
	cout << list << endl;


	list.push_after_curr(10000);
	cout << list << endl;
	
	list.clear();

	cout << list << endl;
	list.push_front(1);
	cout << list << endl;
}


void ring_list_test()
{
	TRingList<int> list;

	cout << list.empty() << endl;

	cin >> list;
	cout << "Your ring linked list: \n";
	cout << list << endl;

	list.sort(true);
	cout << list;

	cout << list.find(3)->value << endl;
	cout << list.find_prev(3)->value << endl;

	list.pop_first();
	cout << list << endl;
	list.pop_last();
	cout << list << endl;
	list.next();
	list.pop_curr();
	cout << list << endl;


	list.push_after_curr(10000);
	cout << list << endl;
	list.clear();

	cout << list << endl;
	list.push_front(1);
	cout << list << endl;
}


int main()
{
	list_test();
	ring_list_test();
	return 0;
}