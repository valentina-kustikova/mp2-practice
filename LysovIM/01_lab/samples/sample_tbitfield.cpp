#include "tbitfield.h"
const int n = 7;

void bitfield()
{
	TBitField bf1(n);
	cin >> bf1;
	cout << " Bietfield 1:" << bf1 << endl;
	TBitField bf2(n);
	//bf2.SetBit(1);
	//bf2.SetBit(2);
	//bf2.SetBit(4);
	//bf2.SetBit(3);
	//bf2.SetBit(5);
	//bf2.SetBit(6);
	cout << "Bietfield 2:" << bf2 << endl;
	cout << "Bietfield 1 or Bietfield 2" << "\t" << (bf1 | bf2) << endl;
	cout << "Bietfield and Bietfield 2:" << "\t" << (bf1 & bf2) << endl;
	cout << "Bietfield 1 = Bietfield 2? :" << "\t" << (bf1 == bf2) << endl;
	cout << "~1:" << (~bf1) << endl;
	cout << "Bitfield 1 Length: " << bf1.GetLength() << endl;
	cout << "Bitfield 2 Length: " << bf2.GetLength() << endl;
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