#include"Stack.h"
#include <string>
#include"Funcs.h"

using namespace std;

int funcs::checkpriority(char x)
{
	int res = 0;
	if (x == '!') return 0;
	if (((x >= 'A') && (x <= 'Z')) || ((x >= 'a') && (x <= 'z')))return 5;
	if ((x == '/') || (x == '*')) return 3;
	if ((x == '+') || (x == '-')) return 2;
	if (x == '(')return 0;
	if (x == ')')return 4;
	throw"error";
}

void funcs::calculate(string string)
{
	float op, op1, op2;
	Stack<float> Tstack;
	map<char, float> valuemap = readvalue(string);
	for (const char& k : string)
	{
		if (((k >= 'A') && (k <= 'Z')) || ((k >= 'a') && (k <= 'z')))
		{
			op = valuemap[k];
			Tstack.Push(op);
		}

		switch (k)
		{
		case'-':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			Tstack.Push(op2 - op1);
			break;
		}
		case'+':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			Tstack.Push(op2 + op1);
			break;
		}
		case'*':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			Tstack.Push(op2*op1);
			break;
		}
		case'/':
		{
			op1 = Tstack.Pop();
			op2 = Tstack.Pop();
			Tstack.Push(op2 / op1);
			break;
		}
		}
	}
	cout << "���������: " << Tstack.Pop() << endl;


}


string funcs::postfixform(string string)
{
	Stack<char> first;
	Stack<char> second;
	int priority, oppriority;
	for (char el : string)
	{
		priority = checkpriority(el);
		if (priority == 0)//������ ����� ������
		{
			second.Push(el);
		}

		if (priority == 5)//������ �������-������ � 1� ����
		{
			first.Push(el);
		}
		if (priority == 2)//������ �������� "+" ��� "-"
		{
			oppriority = checkpriority(second.checktop());
			if (oppriority <= 2)//���� ��������� �������� �� ������� ����� ������ ���� ����� ���������� ��������-������ �������� �� 2� ����
			{
				second.Push(el);

			}
			else//����������� ��� �������� �� ��.2 � ������� ��������� ���� ���� ����� ��������� �������� � ������������� � ��.1
			{
				while (checkpriority(second.checktop()) >= 2)
				{
					first.Push(second.Pop());
				}
				second.Push(el);
			}
		}
		if (priority == 3)//�.�. ������������ ���������-3,�� ������ ������ � ���� 3;
		{
			second.Push(el);
		}
		if (priority == 4)
		{
			while (checkpriority(second.checktop()) != 0)//������������� �������� �� ��.2 � ��.1 �� "("
			{
				first.Push(second.Pop());
			}
			second.Pop();//������� "(" �� ��.2
		}
	}
	while (!second.IsEmpty())
	{
		first.Push(second.Pop());
	}

	std::string tmpstring;
	int j = first.Size();
	for (int i = 0; i <j; i++)//������������� �� ��.1 ������� �� ����� � ������
	{
		tmpstring = tmpstring + first.Pop();
	}
	string.clear();
	j = tmpstring.size();
	for (int i = 1; i <= j; i++)
	{
		char x = tmpstring[j - i];
		string = string + x;
	}
	return string;
};

bool funcs::checkcorrectness(string a)
{
	int	count = 0;
	char prev;
	bool flag = false;
	for (char k : a)
	{
		if (k == '(')
			count++;

		if (k == ')')
			count--;
	}
	return (count == 0);

};

map<char, float>funcs::readvalue(string str)
{
	map<char, float > res;
	float value;
	for (const char& c : str)
	{
		if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))) {
			if (res.count(c) == 0)
			{
				cout << "�������: " << c << endl;
				cin >> value;
				res.insert(pair<char, float>(c, value));
			}
		}
	}
	return res;
}