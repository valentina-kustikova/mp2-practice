#include "tbitfield.h"

void bitfield()
{
	cout << "Enter n - count numbers in bitfield:";
	int n;
	cin >> n;
	TBitField bf1(n);
	cout << "Enter bitfield 1:" << endl;;
	cin >> bf1;
	cout << "Bitfield 1:" << "\t" << bf1 << endl;
	TBitField bf2(n + 1);
	cout << "Enter bitfield 2: " << endl;;
	cin >> bf2;
	cout << "Bitfield 2:" << "\t" << bf2 << endl;
	cout << "Bietfield 1 or Bietfield 2: " << "\t" << (bf1 | bf2) << endl;
	cout << "Bietfield and Bietfield 2: " << "\t" << (bf1 & bf2) << endl;
	cout << "Bietfield 1 = Bietfield 2? : " << "\t" << (bf1 == bf2) << endl;
	cout << "~Bietfield 1:" << (~bf1) << endl;
	cout << "Bitfield 1 length: " << bf1.GetLength() << endl;
	cout << "Bitfield 2 length: " << bf2.GetLength() << endl;
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