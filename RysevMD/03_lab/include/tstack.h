#pragma once

template <typename T>
class TStack {
private:
	int MaxSize; //размер стека
	int top;	 //индекс последнего элемента
	T* elems;
public:
	TStack(int size = 10);
	TStack(const TStack<T>& stack);
	~TStack();

	bool IsEmpty() const;
	bool IsFull() const;

	T Pop(); // убрать элемнт с вершины стека
	void Push(const T& elem);

	T Top(); // скопировать значение элемента с вершины стека
};

template <typename T>
TStack<T>::TStack(int size) {
	if (size < 0) throw "out_of_range";
	MaxSize = size;
	top = -1;
	elems = new T[MaxSize];
}

template <typename T>
TStack<T>::TStack(const TStack<T>& stack) {
	MaxSize = stack.MaxSize;
	top = stack.top;
	elems = new T[MaxSize];
	for (int i = 0; i <= top; i++) elems[i] = stack.elems[i];
}

template <typename T>
TStack<T>::~TStack() {
	delete[] elems;
}

template <typename T>
bool TStack<T>::IsEmpty() const {
	return (top == -1);
}

template <typename T>
bool TStack<T>::IsFull() const {
	return (top == MaxSize - 1);
}

template <typename T>
T TStack<T>::Pop() {
	if (IsEmpty()) throw "stack_is_empty";
	return elems[top--];
}

template <typename T>
void TStack<T>::Push(const T& elem) {
	if (IsFull()) throw "stack_is_full";
	elems[++top] = elem;
}

template <typename T>
T TStack<T>::Top() {
	if (IsEmpty()) throw "stack_is_empty";
	return elems[top];
}