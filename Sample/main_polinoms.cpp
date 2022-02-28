// реализация пользовательского приложения

#include "monom.h"
#include "polinom.h"
#include <iostream>

using namespace std;
#define RANDOM 100
void menu() {
	cout << "1.________ " << endl;
	cout << "2.________ " << endl;
	cout << ">>";
}

int  main()
{
	setlocale(LC_CTYPE, ".1251");
	int t;
	Monom a(1, 0, 2, 2);
	Monom b(7, 3, 3, 3);
	Monom c(10, 4, 4, 4);
	

	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.showList2();


	Polinoms M;
	M.addFirst(a);
	M.addFirst(Monom(2, 2, 2, 2));
	M.addFirst(Monom(1, 30, 30, 30));
	M.addLast(Monom(-6, 2, 2, 2));
	auto it1 = M.begin();

	M.showList2();

	Polinoms R;
	Polinoms();
	
	M *= 7.0;

	R.str_to_poly("-100x^900y^30z^234+100x^900y^30z^234");
//	R += 60;
	
	R.showList2();

	cout << (*it1).coef << endl;
	//R += 222;

	M = R - 222;
//	M = M + 333;
	M.showList2();
	M.podobnyi();
	M.showList();

	R.podobnyi();
	R.showList();

	
	cout << "d/dx"<<endl;
	Polinoms B=R;
	B.differents(1);
	B.showList();
	A.fulldiff();
	A.showList2();
	A.showList();
	//menu();
	/*cin >> t;
	if ((t == 0) || ((t != 1) && (t != 2)))
	{
		throw "WARNING";
	}

	switch (t)
	{
	case 1:
	{

		Monom a(1, 2, 3, 4);
		Monom b(a);
		if ((a.coef == b.coef) && (a.degx == b.degx) && (a.degy == b.degy) && (a.degz == b.degz)) cout << "DICKS";
		
		break;
	}
	case 2:
	{
		cout << "Vibral 2 sluchai";
		break;
	}
	}
	system("Pause");
	*/


	return 0;
}
