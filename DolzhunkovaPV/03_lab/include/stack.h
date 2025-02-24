#include <iostream>

enum stack_type {
    list,
    array
}; 

template<typename data_type>
class Stack {
public:
    virtual ~Stack() {}

    virtual data_type top() = 0;
    virtual bool empty() = 0;
    virtual void push(data_type) = 0;
    virtual void pop() = 0;
};

template<typename data_type>
class List {
    struct Node {
        data_type data;
        Node* next;
    };

    Node* head;

public:
    List() {
        head = nullptr;
    }

    ~List() {
        while (!empty()) pop();
    }

    data_type front() {
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }

    void push(data_type data) {
        head = new Node{data, head};
    }

    void pop() {
        if (!head) throw "pop from empty stack";
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
    }
};

template<typename data_type>
class StackList : public Stack<data_type> {
    List<data_type> list_;

public:
    StackList() {}
    ~StackList() {}

    data_type top() {
        return list_.front();
    }
    bool empty() {
        return list_.empty();
    }
    void push(data_type data) {
        list_.push(data);
    }
    void pop() {
        list_.pop();
    }
};

template<typename data_type>
class StackArray : public Stack<data_type> {
    data_type* data_array_;
    int capacity_;
    int size_;

    void resize(int new_capacity) {
        data_type* new_array = new data_type[new_capacity];

        for (int i = 0; i < size_; ++i) {
            new_array[i] = data_array_[i];
        }

        delete[] data_array_;
        data_array_ = new_array;
        capacity_ = new_capacity;
    }

public:
    StackArray(int capacity = 10) {
        size_ = 0;
        capacity_ = capacity;
        data_array_ = new data_type[capacity_];
    }

    ~StackArray() {
        delete[] data_array_;
    }

    data_type top() {
        return data_array_[size_ - 1];
    }

    bool empty() {
        return size_ == 0;
    }

    void push(data_type data) {
        if (size_ + 1 > capacity_) {
            resize(capacity_ * 2);
        }

        data_array_[size_] = data;
        size_++;
    }

    void pop() {
        if (size_ == 0) throw "pop from empty stack";
        size_--;
    }
};

