#include "arexp.h"
#include "tstack.h"

int main() {
	system("chcp 1251");

	TStack<int> stack(5);
	cout << "Стек создан. Сейчас он пуст(вызов метода IsEmpty())? - " << stack.IsEmpty() << endl;
	cout << "Заполнения стека. Введите 5 чисел: ";
	for (int i = 0; i < 5; i++) {
		int val;
		cin >> val;
		stack.Push(val);
	}
	cout << "Стек полон (вызов метода IsFull())? - " << stack.IsFull() << endl;
	cout << "Элемент на вершине стека - " << stack.Top() << endl;
	cout << "Опустошение стека: " << endl;
	for (int i = 0; i < 5; i++) cout << stack.Pop() << " ";
	return 0;
}