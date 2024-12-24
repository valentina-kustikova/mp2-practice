#pragma once

#include <iostream>
#include <string>

template <typename T>
struct TNode {
    T data;
    TNode* pNext;
    TNode() : data(0), pNext(nullptr) {};
    TNode(const T& data) : data(data), pNext(nullptr) {};
};

template<typename T>
class List {
private:
    TNode<T>* pFirst;
public:
    List();
    List(const T& list);
    ~List();

    const List& operator=(const List<T>& list);
    bool operator==(const List<T>& list);

    void pushFront(TNode<T>* pNode);
    void pushBack(TNode<T>* pNode);
    void insertAfter(TNode<T>* pNode, int key);
    void insertBefore(TNode<T>* pNode, int key);
    void remove(int key);
    T reset() const;
    void removefirst();
    bool IsEmpty() const;
    int Size();
};