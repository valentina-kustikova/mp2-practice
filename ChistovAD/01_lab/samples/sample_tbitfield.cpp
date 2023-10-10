#include "tbitfield.h"
const int n = 5;

void bitfield()
{
	TBitField bf1(n);
	cin >> bf1;
	cout << "1:" << bf1 << endl;
	TBitField bf2(n);
	bf2.SetBit(1);
	bf2.SetBit(2);
	bf2.SetBit(4);
	cout << "2:" << bf2 << endl;
	bf2.ClrBit(1);
	cout << "2:" << bf2 << endl;
	cout << "1&2:" << (bf1 & bf2) << endl;
	cout << "1|2:" << (bf1 | bf2) << endl;
	cout << "1==2:" << (bf1 == bf2) << endl;
	cout << "~1:" << (~bf1) << endl;
	cout << "Bitfield length: " << bf1.GetLength() << endl;
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
