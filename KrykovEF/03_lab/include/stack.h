#include <iostream>
#include <string>
using namespace std;



template <typename T>
class TStack {
public:
    void virtual push(const T& elem) = 0;
    void virtual pop() = 0;
    T virtual Top() = 0;
    bool virtual IsEmpty() = 0;
    bool virtual IsFull() = 0;
};


template <typename T>
class TArrayStack : public TStack<T> {
private:
    int maxSize;
    int top;
    T* arr;
public:
    TArrayStack() : top(-1), maxSize(0) {};
    TArrayStack(int sz) : top(-1) {
        if (sz <= 0) 
            throw "negative size";
        maxSize = sz;
        arr = new T[maxSize];
    };
    TArrayStack(const TArrayStack<T>& s) {
        top = s.top;
        maxSize = s.maxSize;
        arr = new T[maxSize];
        for (int i = 0; i < maxSize; i++) {
            arr[i] = s.arr[i];
        }
    };
    ~TArrayStack() {
        delete[] arr;
    }
    void push(const T& elem) {
        if (IsFull())
            throw "stack is full";
        top++;
        arr[top] = elem;
    };
    void pop() {
        if (IsEmpty())
            throw "stack is empty";
        top--;
    };
    T Top() const {
        if (IsEmpty())
            throw "stack is empty";
        return arr[top];
    };
    bool IsEmpty() { return (top == -1); };
    bool IsFull() { return (top == maxsz - 1); };


    const TArrayStack<T>& operator=(const TArrayStack<T>& s) {
        if (this == &s)
            return *this;
        if (maxSize != s.maxSize) {
            delete[] arr;
            maxSize = s.maxSize;
            arr = new T[maxSize];
        }
        top = s.top;
        for (int i = 0; i <= top; i++) {
            arr[i] = s.arr[i];
        }
        return *this;
    };

    bool operator==(const TArrayStack<T>& s) {
        if (maxSize != s.maxSize || top != s.top) {
            return 0;
        }
        for (int i = 0; i < maxSize; i++) {
            if (arr[i] != s.arr[i]) {
                return 0;
            }
        }
        return 1;
    };

    friend istream& operator>>(istream& istr, TArrayStack& s){//TODO

        /*for (size_t i = 0; i < s.max; i++)
            istr >> v.pMem[i]; // требуется оператор>> для типа T
        return istr;*/
    }
    friend ostream& operator<<(ostream& ostr, const TArrayStack& s)
    {
        TArrayStack tmp(s);
        while (tmp.top != -1) {
            ostr << tmp.Top() << " ";
            top--;
        }
        return ostr;
    }
};


template <typename T>
struct TNode{
    T Key;
    TNode* pNext;
    TNode(T new_key) : Key(new_key), pNext(nullptr) {};
    ~TNode() {};
};


template <typename T>
class TListStack : public TStack<T> {
private:
    TNode* pFirst;
public:
    TListStack():pNext(nullptr) {};
    TListStack(const TListStack<T>& s) {
        if (s.pFirst == nullptr)
            pFirst = nullptr;
        TNode* tmp1 = s.pFirst; *tmp2;
        pFirst->Key = s.pFirst->Key;
        tmp2 = pFirst;
        tmp1 = tmp1->pNext;
        while (tmp1 != nullptr) {
            tmp2->pNext = new TNode[];
            tmp2->pNext->Key = tmp1->key;
            tmp1 = tmp1->pNext;
            tmp2 = tmp2->pNext;
        }
        tmp2->pNext = nullptr;
    };
    ~TListStack() {
        pFirst = nullptr;
    };

    TNode* search(T s_key) {
        TNode* tmp = pFirst;
        while ((tmp != nullptr) && (tmp->Key != s_key)) {
            tmp = tmp->pNext;
        }
        return tmp;
    };

    void pushFront(TNode* newNode) {
        if (pFirst == nullptr) {
            pFirst = newNode;
            return;
        }
        newNode->pNext = pFirst;
        pFirst = newNode;
    };

    void pushBack(TNode* newNode) {
        if (newNode == nullptr)
            throw "nullptr push";

        TNode* curr = pFirst;
        while (curr->pNext != nullptr) {
            curr = curr->pNext;
        }
        curr->pNext = newNode;
    };

    void InsertAfter(TNode* newNode, T pKey) {
        TNode* curr = search(pKey);
        if (curr == nullptr) 
            throw "no element";
        
        newNode->pNext = curr->pNext;
        curr->pNext = newNode;

    };

    void InsertBefore(TNode* newNode, T pKey) {
        TNode* prev = nullptr, *curr = pFirst;
        while ((curr != nullptr) && (curr->key != pKey)) {
            prew = curr;
            curr = curr->pNext;
        }
        if (curr == nullptr)
            throw "no element";

        if (prev == nullptr) {
            pushFront(newNode);
            return;
        }
        newNode->pNext = curr;
        prev->pNext = newNode;
    };

    void remove(T pKey) {
        TNode* prev = nullptr, *curr = pFirst;
        while ((curr != nullptr) && (curr->key != pKey)) {
            prew = curr;
            curr = curr->pNext;
        }
        if (curr == nullptr)
            throw "no element";

        if (prev == nullptr) {
            pFirst = pFirst->pNext;
            delete curr;
        }
        prev->pNext = curr->pNext;
        delete curr;
    };

    int size() {
        TNode* curr = pFirst;
        int size = 0;
        while (curr != nullptr) {
            size++;
            curr = curr->pNext;
        }
        return size;
    };

    void reset(TNode* curr) {
        curr = pFirst;
    }
    void next(TNode* curr) {
        curr = curr->pNext;
    }

    const TListStack<T>& operator=(const TListStack<T>& s) {
        if (this == &s)
            return *this;
        if (s.pFirst == nullptr)
            pFirst = nullptr;
        TNode* tmp1 = s.pFirst; *tmp2;
        pFirst->Key = s.pFirst->Key;
        tmp2 = pFirst;
        tmp1 = tmp1->pNext;
        while (tmp1 != nullptr) {
            tmp2->pNext = new TNode[];
            tmp2->pNext->Key = tmp1->key;
            tmp1 = tmp1->pNext;
            tmp2 = tmp2->pNext;
        }
        tmp2->pNext = nullptr;
        
        return *this;
    };

    bool operator==(const TListStack<T>& s) {
        if (this->size() != st.size()) {
            return 0;
        }
        TNode* curr1 = pFirst, * curr2 = s.pFirst;
        while (curr1 != nullptr) {
            if (curr1->Key != curr2->Key)
                return 0;
            curr1 = curr1->pNext;
            curr2 = curr2->pNext;
        }
        return 1;
    };


    //add to git
};





