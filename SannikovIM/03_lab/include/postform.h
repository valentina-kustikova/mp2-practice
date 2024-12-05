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
		return (this->top == -1);
	}
	void push(const T& val)
	{
		if (isFull()) throw "error";
		this->top++;
		this->pMem[top] = val;
	}
	void pop() {
		if (isEmpty()) throw "error";

		this->top--;
		
	}

	T Top() const {
		return pMem[top];
	}


};
char* getPostform(char* simpleForm, int n) {
	TStack<char> s1(n);
	TStack<char> s2(n);
	for (int i = 0; i < n; i++) {
		if (simpleForm[i] == '+' || simpleForm[i] == '-') {
			if (s2.Top() == '*' || s2.Top() == '/') {
				while (!s2.isEmpty()) {
					s1.push(s2.Top());
					s2.pop();
				}
				
			}
			s2.push(simpleForm[i]);
		}
		else if (simpleForm[i] == '*' || simpleForm[i] == '/') {
				s2.push(simpleForm[i]);
			
		}
		else if (simpleForm[i] == '(') s2.push(simpleForm[i]);
		else if (simpleForm[i] == ')') {
			while (!s2.isEmpty()) {
				if (s2.Top() != '(') {
					s1.push(s2.Top());
					s2.pop();
				}else{ s2.pop(); }
			}
		}
		else {
			s1.push(simpleForm[i]);
		}
	}
	while (!s2.isEmpty()) {
		s1.push(s2.Top());
		s2.pop();
	}
	char* newForm = new char[n];
	
	while (!s2.isEmpty()) {
		s1.push(s2.Top());
		s2.pop();
	}
	int i = n-1;
	while (!s1.isEmpty()) {
		newForm[i] = s1.Top();
		s1.pop();
		i--;
	}

	return newForm;

}



