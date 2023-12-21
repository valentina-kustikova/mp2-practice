#ifndef _TPOSTFIX_
#define _TPOSTFIX_

#include "tstack.h"
#include <cstring>
#include <cctype>
#include <cmath>

class Lexems {
private:
	int length;
	int Type;
	double number;
	char Name[5];
public:
	void Printvar();
	int GetType();
	char* GetName();
	double GetNumber();
	int GetLength();
	void SetType(int i);
	void SetChar(char* a);
	void SetNumber(double a);
	void SetLength(int i);
};

class Arifmetics {
private:
	const char priority[6] = { ')','(','+','-','*','/' };
	const int m_priority[6] = { -1,0,1,1,2,2 };
	bool error = false;
	char onestring[1000];
	Stack<int> a;
	Stack <int> b;
	Lexems * c;
	Lexems * d;
public:
	Lexems* GetPolish() {
		return d;
	}
	char* GetOnestring();
	int  SetVariable();
	double calculate();
	int Num(int i);
	Arifmetics();
	void Lexem();
	void Polsky();
	void PrintString();
	int getPriority(int z);
	bool Check();
	void PrintPolsky();
	void PrintLexem();
	void SetStroka();
	void PushStroka(char* a);
	friend class Stack<int>;
};
#endif