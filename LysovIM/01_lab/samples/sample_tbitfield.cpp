#include "tbitfield.h"
const int n = 7;

void bitfield()
{
	TBitField bf1(n);
	cin >> bf1;
	cout << "1:" << bf1 << endl;
	TBitField bf2(n);
	bf2.SetBit(1);
	bf2.SetBit(2);
	bf2.SetBit(4);
	bf2.SetBit(3);
	bf2.SetBit(5);
	bf2.SetBit(6);
	cout << "2:" << bf2 << endl;
	bf2.ClrBit(1);
	cout << "2:" << bf2 << endl;
	cout << "1|2:" << (bf1 | bf2) << endl;
	cout << "1&2:" << (bf1 & bf2) << endl;
	cout << "1==2:" << (bf1 == bf2) << endl;
	cout << "~1:" << (~bf1) << endl;
	cout << "Bitfield Length: " << bf1.GetLength() << endl;
}

int main()
{
	try {
		bitfield();
	}
	catch (string exp) {
		cout << exp << endl;
	}
}