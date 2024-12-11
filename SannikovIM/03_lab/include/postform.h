#include <iostream>
#include <map>

using namespace std;
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
	int getSteckSize() const { return top; }
};


char* getPostform(char* simpleForm, int n) {
	
	TStack<char> s1(n);
	TStack<char> s2(n);
	char stakItem;
	for (int i = 0; i < n; i++) {
		if (simpleForm[i] == '+' || simpleForm[i] == '-') {
			if (s2.Top() == '/' || s2.Top() == '*') {
				while (s2.Top() == '/' || s2.Top() == '*') {
					s1.push(s2.Top());
					s2.pop();
				}
				s2.push(simpleForm[i]);
			}
			else {
				s2.push(simpleForm[i]);
			}
		}
		else if (simpleForm[i] == '*' || simpleForm[i] == '/') {
				s2.push(simpleForm[i]);
			
		}
		else if (simpleForm[i] == '(') s2.push(simpleForm[i]);
		else if (simpleForm[i] == ')') {
			stakItem = s2.Top();
			s2.pop();
			while (s2.Top() != '(') {
				s1.push(stakItem);
				
				stakItem = s2.Top();
				s2.pop();
			}
			s1.push(stakItem);
			s2.pop();
		}
		else {
			s1.push(simpleForm[i]);
		}
	}
	while (!s2.isEmpty()) {
		s1.push(s2.Top());
		s2.pop();
	}
	char* newForm = new char[s1.getSteckSize()+1];
	int i = s1.getSteckSize();
	while (!s1.isEmpty()) {
		newForm[i] = s1.Top();
		s1.pop();
		i--;
	}

	return newForm;

}

int Calculate(char* postForm, int n, map<char, int>& values) {

	TStack<char> s1(n);
	
	for (int i = 0; i < n; i++) {
		//cout << s1.Top() << endl;
		if (postForm[i] == '+') {
			char num2 = s1.Top();
			s1.pop();
			char num1 = s1.Top();
			s1.pop();
			int k = (values[num1] + values[num2]);
			s1.push( k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '*') {
			char num2 = s1.Top();
			s1.pop();
			char num1 = s1.Top();
			s1.pop();
			int k = (values[num1] * values[num2]);
			s1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '/') {
			char num2 = s1.Top();
			s1.pop();
			char num1 = s1.Top();
			s1.pop();
			int k = (values[num1] / values[num2]);
			s1.push(k);
			values.insert({ k, k });
		}
		else if (postForm[i] == '-') {
			char num2 = s1.Top();
			s1.pop();
			char num1 = s1.Top();
			s1.pop();
			int k = (values[num1] - values[num2]);
			cout << values[num1] << endl;
			s1.push(k);
			cout << k << endl;
			values.insert({  k, k });
		}
		else {
			s1.push(postForm[i]);
		}
	}
	return (int)s1.Top();
}

int getSymb(char* a, int n) {
	int d = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '(' || a[i] == ')') d++;
	}
	return d;
}
