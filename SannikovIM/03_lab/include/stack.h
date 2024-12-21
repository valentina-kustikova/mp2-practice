#include <iostream>
#include "list.h"


using namespace std;


template <class T>
class TStack {
public:
	virtual ~TStack() = default;
	virtual bool isFull() const = 0;
	virtual bool isEmpty() const = 0;
	virtual void push(T val) = 0;
	virtual void pop() = 0;
	virtual T Top() const = 0;
};


template <typename T>
class TStackList: public TStack<T> {
private:
	TList<T> pMem;
	int maxSize;
	int top;
public:
	TStackList(int maxSize = 10) {
		if (maxSize <= 0) throw range_error("Negative size");
		this->maxSize = maxSize;
		top = -1;
	}
	TStackList(const TStack& ts) {
		this->maxSize = ts.maxSize;
		this->top = ts.top;
		TNode<T>* tmp = ts.pMem.GetLast();
		while (tmp != nullptr) {
			pMem.InsertEnd(tmp->key);
			tmp = tmp->pNext;
		}
	}
	~TStackList() {	}

	bool isFull() const {
		return (this->top == this->maxSize - 1);
	}
	bool isEmpty() const {
		return (this->top == -1);
	}
	void push(T val)
	{
		if (isFull()) throw "error";
		this->top++;

		pMem.InsertFirst(val);
	}
	void pop() {
		if (isEmpty()) throw "error";

		this->top--;
		pMem.DeleteFirst();


	}

	T Top() const {
		if (pMem.GetFirst() == nullptr) return 0;
		return pMem.GetFirst()->key;
	}
};


template <typename T>
class TStackArray : public TStack<T> {
private:
	T* pMem;
	int maxSize;
	int top;
public:
	TStackArray(int maxSize = 10) {
		if (maxSize <= 0) throw range_error("Negative size");
		this->maxSize = maxSize;
		this->pMem = new T[maxSize];
		for (int i = 0; i < this->maxSize; i++) {
			this->pMem[i] = 0;
		}
		this->top = -1;
	}
	TStackArray(const TStackArray& ts) {
		this->maxSize = ts.maxSize;
		this->top = ts.top;
		this->pMem = new T[this->maxSize];
		for (int i = 0; i < this->maxSize; i++) {
			this->pMem[i] = ts.pMem[i];
		}
	}
	~TStackArray() {
		delete [] pMem;
	}

	bool isFull() const {
		return (this->top == this->maxSize - 1);
	}
	bool isEmpty() const {
		return (this->top == -1);
	}
	void push(T val)
	{
		if (isFull()) throw "error";
		top++;
		this->pMem[top] = val;
	}
	void pop() {
		if (isEmpty()) throw "error";

		this->top--;
	}

	T Top() const {
		if (isEmpty()) throw "error";
		return pMem[top];
	}
};
