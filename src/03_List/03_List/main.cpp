#include "List.h"
#include "VirtualStack.h"
#include "Calculating.h"
#include <iostream>
int main()
{
	int a[1] = { 1 };
	int b[1] = { 2 };
	int c[1] = { 3 };
	int d[1] = { 4 };
	cout << "LIST TESTING" << endl;
	TList<int, int> L1;
	cout << "L1IsEnded" << " " << L1.IsEnded() << endl << endl;
	L1.InsertStart(1, a);
	TList<int, int> L2(L1);
	cout << "L1InsertStart:" << endl << L1 << endl;
	cout << "L2(L1):" << endl << L2 << endl;
	L2.InsertEnd(2, b);
	cout << "L2InsertEnd:" << endl << L2 << endl;
	try
	{
		L2.InsertAfter(1, 3, c);
	}
	catch (const char* str)
	{
		cout << str;
	}
	cout << "L2InsertAfter:" << endl << L2 << endl;
	try
	{
		L2.InsertBefore(2, 4, d);
	}
	catch (const char* str)
	{
		cout << str;
	}
	cout << "L2InsertBefore:" << endl << L2 << endl;
	cout << "L2Search:" << " " << L2.Search(1)->key << " " << *L2.Search(1)->pData << endl << endl;
	try
	{
		L2.Delete(1);
	}
	catch (const char* str)
	{
		cout << str;
	}
	cout << "L2Delete:" << endl << L2 << endl;
	L2.Reset();
	cout << "L2Reset:" << " " << L2.Get_pCur_key() << " " << L2.Get_pCur_data() << endl << endl;
	try
	{
		L2.Next();
	}
	catch (const char* str)
	{
		cout << str;
	}
	cout << "L2Next:" << " " << L2.Get_pCur_key() << " " << L2.Get_pCur_data() << endl << endl;
	string s;
	string postfixform;
	int tipe;
	double postfixformvolue = 0;
	int size = 0;
	int sizesize;
	cout << "Enter string" << endl;
	cin >> s;
	cout << "Enter 1 to creat TArrayStack, enter 2 to create TListStack" << endl;
	cin >> tipe;
	Calculating Postfix(tipe, s.length());
	try
	{
		postfixform = Postfix.create_postfix(s);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "postfix_form:" << endl;
	cout << postfixform << endl;
	sizesize = Postfix.sizeforarray(postfixform);
	double *volue = new double[sizesize];
	char * uniqueoperands = new char[sizesize]; //// 
	try
	{
		Calculating::get_operands(postfixform, volue, uniqueoperands, size);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	try
	{
		postfixformvolue = Postfix.calculate(postfixform, volue, uniqueoperands, size);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "postfixform volue:" << endl;
	cout << postfixformvolue;
	system("pause");
}//добавлены конструкторы TNode, упростил функция delete, изменил выделение памяти под массив уникальных переменных