#include "arexp.h"
#include "tstack.h"

int main() {
	system("chcp 1251");

	TStack<int> stack(5);
	cout << "���� ������. ������ �� ����(����� ������ IsEmpty())? - " << stack.IsEmpty() << endl;
	cout << "���������� �����. ������� 5 �����: ";
	for (int i = 0; i < 5; i++) {
		int val;
		cin >> val;
		stack.Push(val);
	}
	cout << "���� ����� (����� ������ IsFull())? - " << stack.IsFull() << endl;
	cout << "������� �� ������� ����� - " << stack.Top() << endl;
	cout << "����������� �����: " << endl;
	for (int i = 0; i < 5; i++) cout << stack.Pop() << " ";
	return 0;
}