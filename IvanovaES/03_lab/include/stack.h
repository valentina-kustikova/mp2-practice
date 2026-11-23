#pragma once
#include <iostream>
#include <stdexcept>

#define MAX_STACK_SIZE 100000000

template <class T>
class TStack {
protected:
	T* pMem;
	int memSize;
	int topIndex;
public:
	TStack(int size = 10) : memSize(size), topIndex(-1) {
		if (size <= 0 || size > MAX_STACK_SIZE) {
			throw std::out_of_range("Invalid stack size");
		}
		pMem = new T[memSize];
	}

	TStack(const TStack& s) {
		memSize = s.memSize;
		topIndex = s.topIndex;
		pMem = new T[memSize];
		for (int i = 0; i <= topIndex; i++) {
			pMem[i] = s.pMem[i];
		}
	}

	~TStack() {
		delete[] pMem;
	}

	TStack& operator=(const TStack& s) {
		if (this == &s) {
			return *this;
		}

		T* newMem = new T[s.memSize];
		try {
			for (int i = 0; i <= s.topIndex; ++i) {
				newMem[i] = s.pMem[i];
			}
		}
		catch (...) {
			delete[] newMem;
			throw;
		}

		delete[] pMem;
		pMem = newMem;
		memSize = s.memSize;
		topIndex = s.topIndex;

		return *this;
	}

	bool IsEmpty() const {
		return topIndex == -1;
	}

	bool IsFull() const {
		return topIndex == memSize - 1;
	}

	void Clear() {
		topIndex = -1;
	}

	size_t size() const { 
		return topIndex + 1; 
	}

	T Top() const {
		if (IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		return pMem[topIndex];
	}

	void Push(const T& elem) {
		if (IsFull()) {
			throw std::out_of_range("Stack is full");
		}
		pMem[++topIndex] = elem;
	}

	void Pop() {
		if (IsEmpty()) {
			throw std::out_of_range("Stack is empty");
		}
		--topIndex;
	}
};