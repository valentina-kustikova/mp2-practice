#include "tbitfield.h"

void test_tbitfield()
{
	TBitField a(5), b(5);
	cout << "Input bitfield A with length 5: ";
	cin >> a;
	cout << "A: " << a << endl;
	cout << "Input bitfield B with length 5: ";
	cin >> b;
	cout << "B: " << b << endl;

	cout << "B 1 bit: " << b.GetBit(1) << endl;
	b.ClrBit(1);
	cout << "B 1 bit after clear: " << b.GetBit(1) << endl;

	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "A&B " << (a & b) << endl;
	cout << "A|B " << (a | b) << endl;
	cout << "A==B " << (a == b) << endl;
	cout << "~A  " << (~a) << endl;
	cout << "A.GetLength(): " << a.GetLength() << endl;
	cout << "OK" << endl;
}



int main()
{
	test_tbitfield();
}