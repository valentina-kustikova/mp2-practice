#include <iostream> 
#include "tstack.h"
#include <cstring>
#include "postfix.h"

int main()
{
	char b[5] = "";
	do {
		system("cls");
		Arifmetics a;
		a.PushStroka("34*2-(32-34)*(21-4.4/3)");
		if ((a.Check()) == true) {
			a.Lexem();
			int t;
			do {
				system("cls");
				cout << "set stroca" << endl;
				cout << a.GetOnestring();
				cout << "vse normalno";
				a.PrintLexem();
				t = a.SetVariable();
				a.Polsky();
				a.PrintPolsky();
				cout << endl << "calculate" << endl;
				cout << a.calculate() << endl;
				if (t != 0) {
					cout << "perecalculate?";
					cin >> b;
				}
			} while ((t != 0) && (!strcmp(b, "yes")));
		}
		else  cout << "vse ne normalno" << endl;
		cout << "to end programm enter cls";
		cin >> b;
	} while (!strcmp(b, "yes"));
	system("cls");
	return 0;
}
