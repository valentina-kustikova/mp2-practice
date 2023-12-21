#include <postfix.h>

void Arifmetics::SetStroka() {
	cout << "set stroca" << endl;
	cin >> onestring;
}
void Arifmetics::PushStroka(char* a) {
	strcpy(onestring, a);
	cout << endl;
}
char* Arifmetics::GetOnestring() {
	return onestring;
}
int Arifmetics::SetVariable() {
	int t = 0;
	for (int i = 0; i < c[0].GetLength(); i++)

		if (c[i].GetType() == -3) {
			t = 1;
			double k;
			int y = 0;

			for (int j = 0; j < i; j++) {

				if ((c[j].GetType() == -3) && (!strcmp(c[j].GetName(), c[i].GetName()))) {
					c[i].SetNumber(c[j].GetNumber());
					y = 1;
					break;
				}

				if ((c[j].GetType() == -3) && (!strcmp(c[j].GetName(), &c[i].GetName()[1]))) {
					c[i].SetNumber(-1 * c[j].GetNumber());
					y = 1;
					break;
				}
				if ((c[j].GetType() == -3) && (!strcmp(&c[j].GetName()[1], c[i].GetName()))) {
					c[i].SetNumber(-1 * c[j].GetNumber());
					y = 1;
					break;
				}
			}

			if (y == 0) {
				if ((c[i].GetName())[0] != '-') {
					cout << "vvedite peremennuu ";
					c[i].Printvar();
					cin >> k;
				}
				else {
					cout << "vvedite peremennuu ";
					char a[10] = "";
					strcpy(a, c[i].GetName());
					string b(a);
					b.erase(0, 1);
					int i = 0;
					while (i < b.length()) {
						a[i] = b[i];
						i++;
					}
					a[i] = '\0';
					c[i].SetChar(a);
					c[i].Printvar();
					cin >> k;
					k = k * (-1);
				}
				c[i].SetNumber(k);
			}





		}
	return t;
}
void Arifmetics::PrintLexem() {
	cout << endl;
	cout << "Lexemu " << endl;
	for (int i = 0; i < c[0].GetLength(); i++)
		switch (c[i].GetType()) {
		case 1: {
			cout << "+ ";
			break;
		}
		case 2: {
			cout << "|-| ";
			break;
		}
		case 3: {
			cout << "|*| ";
			break;
		}
		case 4: {
			cout << "|/| ";
			break;
		}
		case -2: {
			cout << "|";
			cout.precision(10);
			cout << c[i].GetNumber();
			cout << "| ";
			break;
		}
		case -3: {
			cout << c[i].GetName() << " ";
			break;
		}
		{
		default:
			break;
		}
		}
	cout << endl << "Lexemy" << endl;
}
void Arifmetics::PrintPolsky() {
	for (int i = 0; i < d[0].GetLength(); i++)
		switch (d[i].GetType()) {
		case 1: {
			cout << "+ ";
			break;
		}
		case 2: {
			cout << "- ";
			break;
		}
		case 3: {
			cout << "* ";
			break;
		}
		case 4: {
			cout << "/ ";
			break;
		}
		case -2: {
			cout << d[i].GetNumber() << " ";
			break;
		}
		case -3: {
			cout << d[i].GetName() << " ";
			break;
		}
		{
		default:
			break;
		}
		}
}
void Arifmetics::Polsky() {
	cout << "Polskaya" << endl;
	int i = 0;
	int q = 0;
	while (i < c[0].GetLength()) {
		switch (c[i].GetType())
		{
		case -3: {
			d[q++] = c[i];
			break;
		}
		case -2: {
			d[q++] = c[i];
			break;
		}
		case -1: {
			int z = b.getInd();
			while (b.check() != 0)
				d[q++].SetType(b.pop());
			b.pop(); //óäàëÿåì îòêðûòóþ ñêîáêó

			break;
		}
		case 0: {
			b.push(0);
			break;
		}
		case 1: { //+
			int z = 0;
			if (b.check() < 2) b.push(1); else while (b.check() >= 2) {
				d[q++].SetType(b.pop());
				z = 1;
			}
			if (z == 1) b.push(1);
			break;
		}
		case 2: { //-
			int z = 0;
			if ((b.check() < 2) || (b.IsEmpty())) b.push(2); else while (b.check() >= 2) {
				d[q++].SetType(b.pop());
				z = 1;
			}
			if (z == 1) b.push(2);
			break;
		}
		case 3: {
			b.push(3);
			break;
		}
		case 4: {
			b.push(4);
			break;
		}

		default:
			break;
		}
		i++;
	}

	while (!b.IsEmpty()) d[q++].SetType(b.pop());
	d[0].SetLength(q);
}
int Arifmetics::Num(int i) {
	return onestring[i] - '0';
}
Arifmetics::Arifmetics() : a(1000), b(1000) {
	c = new Lexems[1000];
	d = new Lexems[1000];
}
void Arifmetics::PrintString() {
	for (int i = 0; i < strlen(onestring); i++) cout << onestring[i];
}

bool Arifmetics::Check() {
	int i = 0;
	while ((i < strlen(onestring)) && (error != true)) {

		switch (getPriority(i))
		{
		case 0:
		{
			a.push(0);
			if (i > 0) if (getPriority(i - 1) == -2) {
				error = true;
				cout << "error on the " << i << "position";
			}
			break;
		}
		//(onestring(i+1)=='.')
		case 1:
			if (i > 0) if ((onestring[i - 1] == '.')) {
				error = true; cout << "error on the " << i << "position";
			}
			{              if (i < strlen(onestring) - 1)
				if ((getPriority(i + 1) >= 1) || (getPriority(i + 1) == -1) || (onestring[i + 1] == '.')) { error = true; cout << "error on the " << i + 2 << "position"; }
				else a.push(1); else {
					error = true; cout << "error on the " << i + 1 << "position";
				}
			break;
			}
		case 2:
		{
			if (i > 0) if (onestring[i - 1] == '.') {
				error = true; cout << "error on the " << i << "position";
			}
			if (i < strlen(onestring) - 1)
				if ((getPriority(i + 1) >= 1) || (getPriority(i + 1) == -1) || (onestring[i + 1] == '.')) {
					error = true; cout << "error on the " << i + 2 << "position";
				}
				else a.push(2); else {
					error = true; cout << "error on the " << i + 1 << "position";
				}
			break;
		}

		case -1:
		{
			if (i < strlen(onestring) - 1)  if (getPriority(i + 1) == -2) { error = true; cout << "error on the " << i + 2 << "position"; }

			int i = 0;
			while ((a.check() != 0) && (!a.IsEmpty()))
				i = a.pop();
			if ((a.check() == 0) && (!a.IsEmpty()))
				i = a.pop();
			else { error = true; cout << "error more ')' "; }
			break;
		}

		case -2:
		{
			if (i > 0) if (getPriority(i - 1) == -3) if (!(onestring[i - 1] == '.')) {
				error = true; cout << "error on the " << i << "position";
			}
			else a.push(-2);
			else a.push(-2);
			else if (onestring[i] == '.') { error = true; cout << "error on the " << i + 1 << "position"; }
			break;
		}
		case -3:
		{

			if (i > 0) if ((getPriority(i - 1) == -2) || (onestring[i - 1] == '.') || (onestring[i + 1] == '.')) {
				error = true; cout << "error on the " << i + 2 << "position";
			}
			else a.push(-2);
			break;
		}
		default:
		{
			error = true;
			cout << "unchoun char, position " << i + 1;
		}
		}
		++i;
	}
	int h = a.getInd();
	if (error != true) {
		for (int i = 0; i <= h; i++)
			if (a.pop() == 0) {
				error = true; cout << "error more '(' ";
			}
	}
	if (!error) return true; else return false;
}

int Arifmetics::getPriority(int z) {
	for (int i = 0; i < 6; i++)
		if (onestring[z] == priority[i]) return m_priority[i];
	if ((!isalpha(onestring[z])) || (onestring[z] == '.')) {
		if (!isalpha(onestring[z]) && (!isdigit(onestring[z])) && ((onestring[z] != '.'))) return -40;
		return -2;
	}
	else return -3;
}

void Arifmetics::Lexem() {
	int i = 0;
	if (error == false) {
		int q = 0;
		while (i < strlen(onestring)) {

			switch (getPriority(i))
			{
			case 2: {
				if (onestring[i] == '*') c[q].SetType(3); else c[q].SetType(4);
				++q;
				++i;
				break;
			}
			case 1: {
				int z = 0;
				if (onestring[i] == '+') {
					if ((i == 0) || (getPriority(i - 1) == 0)) {
						if (getPriority(i + 1) == -3) {
							z = 1;
							int k = 0;
							int d = i;
							++i;
							while (getPriority(i) == -3) {
								k++;
								i++;
							}
							char a[20] = "";
							strncpy(a, &onestring[d], k + 1);
							a[k + 1] = '\0';
							c[q].SetType(-3);
							c[q].SetChar(a);
							q++;
						}
						else {
							z = 1;
							int k = 0;
							int d = i;
							++i;
							while (getPriority(i) == -2) {
								k++;
								i++;
							}
							char a[20] = "";
							strncpy(a, &onestring[d], k + 1);
							a[k + 1] = '\0';
							double res = atof(a);
							c[q].SetType(-2);
							c[q].SetNumber(res);
							q++;
						}
					}
					else c[q].SetType(1);


				}
				else {
					if ((i == 0) || (getPriority(i - 1) == 0)) {

						if (getPriority(i + 1) == -3) {
							z = 1;
							int k = 0;
							int d = i;
							++i;
							while (getPriority(i) == -3) {
								k++;
								i++;
							}
							char a[20] = "";
							strncpy(a, &onestring[d], k + 1);
							a[k + 1] = '\0';
							c[q].SetType(-3);
							c[q].SetChar(a);
							q++;
						}
						else {
							z = 1;
							int k = 0;
							int d = i;
							++i;
							while (getPriority(i) == -2) {
								k++;
								i++;
							}
							char a[20] = "";
							strncpy(a, &onestring[d], k + 1);
							a[k + 1] = '\0';
							double res = atof(a);
							c[q].SetType(-2);
							c[q].SetNumber(res);
							q++;
						}
					}
					else c[q].SetType(2);

				}
				if (z == 0) {
					++q;
					++i;
				}
				break;
			}
			case 0: {
				c[q].SetType(0);
				++q;
				++i;
				break;
			}
			case -1: {
				c[q].SetType(-1);
				++q;
				++i;
				break;
			}
			case -3: {
				c[q].SetType(-3);
				int z = 1;
				while ((getPriority(++i) == -3)&(i != strlen(onestring))) ++z;
				char name[10] = "";
				strncpy(name, &onestring[i - z], z);
				c[q].SetChar(name);
				q++;
				break;
			}
			case -2: {
				int z = 1;
				c[q].SetType(-2);
				double res = Num(i);
				int y = 0;

				while ((i != strlen(onestring) && (getPriority(++i) == -2) && (y == 0)))
					if (onestring[i] == '.')
						y = 1;
					else
					{
						res = res * 10 + Num(i);
						++z;
					}

				int u = i - 1; // èíäåêñ òî÷êè
				while ((i != strlen(onestring)) && (getPriority(i) == -2) && (y == 1)) {
					res = res * 10 + Num(i);
					++z;
					++i;
				}
				if (z != 1)
					res = res / (pow(10, i - u - 1));
				c[q].SetNumber(res);
				++q;
				break;
			}

			default:
				break;
			}


		}
		c[0].SetLength(q);
	}

}
double Arifmetics::calculate() {
	cout << "Answer =  ";
	Stack <double> f(d[0].GetLength());
	int i = 0;
	while (i < d[0].GetLength()) {
		double one;
		double two;
		switch (d[i].GetType())
		{
		case 1: {

			one = f.pop();
			two = f.pop();
			f.push(one + two);
			i++;
			break;
		}
		case -2: {
			f.push(d[i++].GetNumber());
			break;
		}
		case -3: {
			f.push(d[i++].GetNumber());
			break;
		}
		case 2: {
			one = f.pop();
			two = f.pop();
			f.push(two - one);
			i++;
			break;
		}
		case 3: {
			one = f.pop();
			two = f.pop();
			f.push(one*two);
			i++;
			break;
		}
		case 4: {
			one = f.pop();
			two = f.pop();
			f.push(two / one);
			i++;
			break;
		}
		default:
			break;
		}
	}
	return f.pop();

}

//////////////////////////////////////////////////////////////////////////////

void Lexems::Printvar() {
	for (int i = 0; i < strlen(Name); i++) cout << Name[i];
	cout << endl;
}
void Lexems::SetLength(int i) {
	length = i;
}
int Lexems::GetLength() {
	return length;
}

double Lexems::GetNumber() {
	return number;
}
char* Lexems::GetName() {
	return Name;
}
void Lexems::SetNumber(double a) {
	number = a;
}

void Lexems::SetChar(char* a) {
	if (strlen(a) < 5)
		strcpy(Name, a); else cout << "slischom big name peremennoy";
}
void Lexems::SetType(int i) {
	Type = i;
}

int Lexems::GetType() {
	return Type;
}