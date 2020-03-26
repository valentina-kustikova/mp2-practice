#include"Calculating.h"
Calculating::Calculating(int tipe, int size)
{
	switch (tipe)
	{
	case 1:
	{
		operators = new TArrayStack<char>(size);
		operands = new TArrayStack<char>(size);
		finalvolue = new TArrayStack<double>(size);
		break;
	}
	case 2:
	{
		operators = new TListStack<char>;
		operands = new TListStack<char>;
		finalvolue = new TListStack<double>;
		break;
	}
	default:
		throw "unreal tipe:)";
	}
}
bool Calculating::priority(char a, char b)
{
	if (((a == '+' || a == '-') && (b == '*' || b == '/' || b == '+' || b == '-')) || ((a == '*' || a == '/') && (b == '*' || b == '/')))
		return false;
	return true;
}
double Calculating::calculator(double a, double b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	if (c == '/')
	{
		if (b == 0)
			throw"EROR";
		return a / b;
	}
}
string Calculating::create_postfix(const string s)
{
	int flag = 0, flag1 = 0, flag2 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			flag++;
		if (s[i] == ')')
			flag--;
	}
	if (flag != 0)
		throw "EROR";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ')')
		{
			flag2++;
			for (int k = 0; k < i; k++)
			{
				if (s[k] == '(')
					flag1++;
			}
			if (flag1 != flag2)
				throw"EROR";
		}
	}
	for (int i = 1; i < s.length(); i++)
		if (((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/')) && ((s[i - 1] == '+') || (s[i - 1] == '-') || (s[i - 1] == '*') || (s[i - 1] == '/')))
			throw "EROR";
	for (int i = 1; i < s.length(); i++)
		if (((s[i] != '+') && (s[i] != '-') && (s[i] != '*') && (s[i] != '/') && (s[i] != '(') && (s[i] != ')')) && ((s[i - 1] != '+') && (s[i - 1] != '-') && (s[i - 1] != '*') && (s[i - 1] != '/') && (s[i - 1] != '(') && (s[i - 1] != ')')))
			throw "EROR";
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (s[i] == ')') || (s[i] == '('))
		{
			if (operators->IsEmpty()) operators->Push(s[i]);
			else
			{
				if (s[i] == '(') operators->Push(s[i]);
				else
				{
					if (s[i] == ')')
					{
						while (operators->Top() != '(')
						{
							operands->Push(operators->Top());
							operators->Pop();
						}
						operators->Pop();
					}
					else
					{
						if (priority(s[i], operators->Top()) == true) {
							operators->Push(s[i]);
						}
						else
						{
							while ((!operators->IsEmpty()) && (operators->Top() != '(') && (priority(s[i], operators->Top()) != true))
							{
								operands->Push(operators->Top());
								operators->Pop();
							}
							operators->Push(s[i]);
						}
					}
				}
			}
		}
		else
			operands->Push(s[i]);
	}
	while (!operators->IsEmpty())
	{
		operands->Push(operators->Top());
		operators->Pop();
	}
	string result;
	while (!operands->IsEmpty())
	{
		result += operands->Top();
		operands->Pop();
	}
	reverse(result.rbegin(), result.rend());
	return result;
}
void Calculating::get_operands(const string postfixform, double *&volue, char *&uniqueoperands, int & size)
{
	double a, flag = 0;
	for (int i = 0; i < postfixform.length(); i++)
	{
		if ((postfixform[i] != '+') && (postfixform[i] != '-') && (postfixform[i] != '*') && (postfixform[i] != '/'))
		{
			for (int k = 0; k < i; k++)
				if (postfixform[i] == postfixform[k])
				{
					flag = 1;
				}
			if (flag == 0)
			{
				uniqueoperands[size] = postfixform[i];
				cout << "Enter the meaning of " << postfixform[i] << endl;
				cin >> a;
				volue[size] = a;
				size++;
			}
			flag = 0;
		}
	}
}
double Calculating::calculate(const string postfixform, double * volue, char * uniqueoperands, int size)
{
	double b;
	double Top = 0;
	for (int i = 0; i < postfixform.length(); i++)
	{
		if ((postfixform[i] == '+') || (postfixform[i] == '-') || (postfixform[i] == '*') || (postfixform[i] == '/'))
		{
			Top = finalvolue->Top();
			finalvolue->Pop();
			b = calculator(finalvolue->Top(), Top, postfixform[i]);
			finalvolue->Pop();
			finalvolue->Push(b);
		}
		else
		{
			for (int k = 0; k < size; k++)
				if (postfixform[i] == uniqueoperands[k])
				{
					finalvolue->Push(volue[k]);
					break;
				}
		}
	}
	return finalvolue->Top();
}
double Calculating::sizeforarray(const string postfixform)
{
	double flag0 = 0, sizeforarray = 0;
	for (int i = 0; i < postfixform.length(); i++)
	{
		if ((postfixform[i] != '+') && (postfixform[i] != '-') && (postfixform[i] != '*') && (postfixform[i] != '/'))
		{
			for (int k = 0; k < i; k++)
				if (postfixform[i] == postfixform[k])
				{
					flag0 = 1;
				}
			if (flag0 == 0)
			{
				sizeforarray++;
			}
			flag0 = 0;
		}
	}
	return sizeforarray;
}
