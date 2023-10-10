#include "tset.h"

void test_tset()
{
	TSet a(5);
	a.InsElem(1);
	a.InsElem(3);
	cout << "A: " << a << endl;	
	TSet b(a);
	cout << "B " << b << endl;
	cout << "B 1 bit: " << a.IsMember(1) << endl;
	b.DelElem(1);
	cout << "B 1 bit after clear: " << b.IsMember(1) << endl;
 
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "A&B " << (a * b) << endl;
	cout << "A|B " << (a + b) << endl;
	cout << "A==B " << (a == b) << endl;
	cout << "~A  " << (~a) << endl;

	cout << "A.GetMaxPower(): " << a.GetMaxPower()  << endl;
	cout << "OK" << endl;
}



int main()
{
	test_tset();
}