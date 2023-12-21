#ifndef _TSTACK_
#define _TSTACK_

#include <iostream>

using namespace std;

template <class ValType>
class Stack {
private:
	ValType * arr;
	int SM;
	int ind;
public:
	Stack(int Size_Max);
	~Stack();
	Stack(const Stack& a);
	void push(const ValType a);
	ValType pop();
	ValType check();
	bool IsEmpty();
	int Size();
	void Clear();
	void Print();
	int getInd();
	int GetSizeMax();
};
template <class ValType>
int Stack <ValType> ::GetSizeMax() {
	return SM;
}
template <class ValType>
Stack <ValType> ::Stack(int Size_Max)
{
	SM = Size_Max;
	ind = -1;
	arr = new ValType[SM];
}

template <class ValType>
Stack <ValType> ::~Stack()
{
	delete[] arr;
}
template <class ValType>
Stack <ValType> ::Stack(const Stack& a)
{
	SM = a.SM;
	arr = new ValType[SM];
	for (int i = 0; i <= ind; i++)
		arr[i] = a.arr[i];
}

template <class ValType>
void Stack <ValType> ::push(const ValType a) {
	if (ind + 1 >= SM) {
		Stack <ValType> b(*this);
		delete[] arr;
		SM = SM * 2;
		arr = new ValType[SM];
		for (int i = 0; i <= ind; i++) arr[i] = b.arr[i];
		arr[++ind] = a;
	}
	else
		arr[++ind] = a;
}
template <class ValType>
ValType Stack <ValType> ::pop() {
	if (ind == -1) throw "negative"; else
		return arr[ind--];
}
template <class ValType>
ValType Stack <ValType> ::check() {
	if (ind == -1) return 0; else
		return arr[ind];
}

template <class ValType>
bool  Stack <ValType> ::IsEmpty() {
	if (ind == -1) return 1; else return 0;
}

template <class ValType>
int  Stack <ValType> ::Size() {
	return (ind + 1);
}
template <class ValType>
void Stack <ValType> ::Clear() {
	ind = -1;
}

template <class ValType>
void Stack <ValType> ::Print() {
	for (int i = 0; i <= ind; i++) cout << arr[i] << endl;
}
template <class ValType>
int Stack <ValType> ::getInd() {
	return ind;
}
#endif