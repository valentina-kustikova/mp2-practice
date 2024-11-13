

template <typename T>
class Stack {
public:
    virtual void push(const T& elem) = 0;
    virtual void pop() = 0;
    virtual T Top() = 0;
    virtual bool IsEmpty() = 0;
    virtual bool IsFull() = 0;
};

template <typename T>
class ArrayStack : public Stack<T> {
private:
    int top;
    size_t maxsz;
    T* arr;
public:
    ArrayStack() : top(-1), maxsz(0) {};
    ArrayStack(int sz) : top(-1)
    {
        if (sz <= 0) {
            throw "size must be greater than 0";
        }
        maxsz = sz;
        arr = new T[sz];
    };

    ArrayStack(const ArrayStack<T>& s) {
        top = s.top;
        maxsz = s.maxsz;
        arr = new T[maxsz];
        for (int i = 0; i < maxsz; i++) {
            arr[i] = s.arr[i];
        }
    };

    ~ArrayStack() {
        delete[] arr;
    }

    void push(const T& elem)  {

        if (top == -1 || top == maxsz) {
            maxsz += (maxsz + 1) * 3;
            arr = new T[maxsz];
            if (top == -1) {
                top++;
            }
        }
        arr[top] = elem;
        top++;
    }


    void pop()   {
        if (IsEmpty()) {
            throw "stack is empty";
        }
        top--;
    };
    T Top()  {
        if (IsEmpty()) {
            throw "stack is empty";
        }
        return arr[top];
    };
    bool IsEmpty()  { return top == -1; };
    bool IsFull()  { return top == maxsz; };

    const ArrayStack<T>& operator=(const ArrayStack<T>& s) {
        if (*this == &s) {
            return *this;
        }
        if (maxsz != s.maxsz) {
            if (maxsz != 0) {
                delete[] arr;
            }
            maxsz = s.maxsz;
            arr = new T[maxsz];
        }
        top = s.top;
        for (int i = 0; i < maxsz; i++) {
            arr[i] = s.arr[i];
        }
        return *this;
    }

    bool operator==(const ArrayStack<T>& s) {
        if (maxsz != s.maxsz || top != s.top) {
            return 0;
        }
        for (int i = 0; i < maxsz; i++) {
            if (arr[i] != s.arr[i]) {
                return 0;
            }
        }
        return 1;
    }
};
