#include <iostream>

template <typename T>
class TStack {
private:
	T* pMem;
	int maxSize;
	int top;
public:
	TStack(int maxSize = 10) {
		this->maxSize = maxSize;
		this->pMem = new T[maxSize];
		for (int i = 0; i < maxSize; i++) {
			this->pMem[i] = 0;
		}
		top = -1;
	}
	TStack(const TStack& ts) {
		this->maxSize = ts.maxSize;
		this->pMem = new T[this->maxSize];
		for (int i = 0; i < this->maxSize; i++) {
			this->pMem[i] = ts.pMem[i];
		}
		this->top = ts.top;
	}
	~TStack() {
		delete[] pMem;
	}

	bool isFull() const {
		return (this->top == this->maxSize-1);
	}
	bool isEmpty() const {
		return (this->top ==  - 1)
	}
	void push(const T& val)
	{
		if (isFull) throw "error";
		this->top++;
		this->pMem[top] = val;
	}
	void pop() {
		if (isEmpty) throw "error";
		delete this->pMem[top];
		this->top--;
		
	}

	T Top() const {
		return pMem[top];
	}
};

