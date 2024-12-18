#include <iostream>
#include <map>



using namespace std;



template <typename T>
struct TNode {
	T key;
	TNode* pNext;
	TNode(T k) : key(k), pNext(nullptr) {}

};

template <typename T>
class TList {
private:
	TNode<T>* pFirst;
public:
	TList() :pFirst(nullptr){}
	TList(const TList& other) : pFirst(nullptr) {
		if (other.pFirst == nullptr) {
			return; 
		}
		pFirst = new TNode<T>(other.pFirst->key);
		TNode<T>* tmp = pFirst;
		TNode<T>* curr = other.pFirst->pNext;
		while (otherCurrent != nullptr) {
			tmp->pNext = new TNode<T>(curr->key); 
			tmp = tmp->pNext;                      
			curr = curr->pNext;
		}
	}
	~TList() {
		while (pFirst != nullptr) {
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	TNode<T>* Search(T key) {
		if (this->pFirst == nullptr) throw range_error("First element is null");
		TNode<T>* tmp = pFirst;
		T a;
		TNode<T>* tmp1(a);
		while (tmp != nullptr || tmp->key != key) {
			tmp = tmp->pNext;
		}
		return tmp;

	}
	void Insert(T key) {
		TNode<T>* tmp1 = new TNode<T>(key);
		if (pFirst == nullptr) {
			pFirst = tmp1;
			return;
		}
		TNode<T>* tmp = this->pFirst;
		while (tmp->pNext != nullptr) {
			tmp = tmp->pNext;
		}
		tmp->pNext = tmp1;

	}
	TNode<T>* GetLast() const{
		if (pFirst == nullptr) return nullptr; //throw range_error("First element is null");
		TNode<T>* tmp = pFirst;

		//if (tmp->pNext == nullptr) throw "error";
		while (tmp->pNext != nullptr) {
			tmp = tmp->pNext;
		}
		return tmp;

	}
	void DeleteLast() {
		if (pFirst == nullptr)
			throw range_error("List is empty");

		if (pFirst->pNext == nullptr) {
			delete pFirst;
			pFirst = nullptr;
			return;
		}

		TNode<T>* tmp = pFirst;
		while (tmp->pNext->pNext != nullptr) {
			tmp = tmp->pNext;
		}

		delete tmp->pNext;
		tmp->pNext = nullptr;
	}

};





template <typename T>
class TStack {
private:
	TList<T> pMem;
	int maxSize;
	int top;
public:
	TStack(int maxSize = 10) {
		if (maxSize <= 0) throw range_error("Negative size");
		this->maxSize = maxSize;
		top = -1;
	}
	TStack(const TStack& ts) {
		this->maxSize = ts.maxSize;
		this->top = ts.top;
		TNode<T>* tmp = ts.pMem.GetLast();
		while (tmp != nullptr) {
			pMem.Insert(tmp->key);
			tmp = tmp->pNext;
		}
	}
	~TStack() {
	
	}

	bool isFull() const {
		return (this->top == this->maxSize-1);
	}
	bool isEmpty() const {
		return (this->top == -1);
	}
	void push(T val)
	{
		if (isFull()) throw "error";
		this->top++;
		
		pMem.Insert(val);
	}
	void pop() {
		if (isEmpty()) throw "error";

		this->top--;
		pMem.DeleteLast();

		
	}

	T Top() const {
		if (pMem.GetLast() == nullptr) return 0;
		return pMem.GetLast()->key;
	}
	int getSteckSize() const { return top; }
};





string getPostform(char* simpleForm, int n) {
	
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
	string newForm = "";
	while (!s1.isEmpty()) {
		newForm =  s1.Top() + newForm ;
		s1.pop();
		//i--;
	}

	return newForm;

}

int Calculate(string postForm, int n, map<char, int>& values) {

	TStack<char> s1(n);
	
	for (int i = 0; i < n; i++) {
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
			s1.push(k);
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
/*
string getPostform1(string simpleForm, int n) {

	TStack<string> s1(n);
	TStack<string> s2(n);
	string stakItem;
	int i = 0;
	while(i<n) {
		if (simpleForm[i] == '+' || simpleForm[i] == '-') {
			if (s2.Top() == "/" || s2.Top() == "*") {
				while (s2.Top() == "/" || s2.Top() == "*") {
					s1.push(s2.Top());
					s2.pop();
				}
				s2.push(""+simpleForm[i]);
			}
			else {
				s2.push("" + simpleForm[i]);
			}
		}
		else if (simpleForm[i] == '*' || simpleForm[i] == '/') {
			s2.push("" + simpleForm[i]);

		}
		else if (simpleForm[i] == '(') s2.push("" + simpleForm[i]);
		else if (simpleForm[i] == ')') {
			stakItem = s2.Top();
			s2.pop();
			while (s2.Top() != "(") {
				s1.push(stakItem);

				stakItem = s2.Top();
				s2.pop();
			}
			s1.push(stakItem);
			s2.pop();
		}
		else {
			string s = "";
			while (simpleForm[i] != '+' && simpleForm[i] != '*' && simpleForm[i] != '-' && simpleForm[i] != '/') {
				s = s + simpleForm[i];
				i++;
			}
			s1.push(s);
			
		}
	}
	while (!s2.isEmpty()) {
		s1.push(s2.Top());
		s2.pop();
	}
	string newForm;
	//int i = s1.getSteckSize();
	while (!s1.isEmpty()) {
		newForm = newForm + s1.Top();
		s1.pop();
	}

	return newForm;
	*/

