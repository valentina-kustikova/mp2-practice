#include <iostream>
#include "tbitfield.h"

using namespace std;

int main() {
	//создание битового поля, все ячейки изначально 0
	TBitField f1(5);

	//приведение поля к виду 10101
	f1.SetBit(0);
	f1.SetBit(2);
	f1.SetBit(4);
	cout << "f1: " << f1 << endl;

	TBitField f2(4), f3(7);
	
	f2.SetBit(1);
	f2.SetBit(2);

	f3.SetBit(0);
	f3.SetBit(1);
	f3.SetBit(6);

	cout << "f2: " << f2 << endl;
	cout << "f3: " << f3 << endl;

	// или, и, отрицание, копипрование
	TBitField f4 = f1 | f2, f5 = f1 & f3, f6 = ~f1;
	cout << "f4 = f1 | f2: " << f4 << endl << "f5 = f1 & f3: " << f5 << endl << "f6 = ~f1: " << f6 << endl;

	TBitField f7(5);
	cin >> f7;
	cout << "f7: " << f7 << endl;

	//сравнения
	TBitField f8 = f1, f9 = f7;
	cout << "f8: " << f8 << endl;
	cout << "f9: " << f9 << endl;
	cout << "f8 == f1? - " << (f8 == f1) << endl << "f8 == f9? - " << (f8 == f9) << endl << "f1 != f9? - " << (f1 != f9) << endl;

	//Get- Clear- Bit;
	cout << "f1[0]: " << f1.GetBit(0) << endl;
	f1.ClrBit(0);
	cout << "f1[0]: " << f1.GetBit(0) << endl;

	return 0;
}