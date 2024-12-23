#pragma once

#include <iostream>

template<typename T>
class List {
private:
    struct TNode {
        int key;
        T data;
        TNode* pNext;
        TNode() : data(0), pNext(nullptr) {};
        TNode(const T& data) : data(data), pNext(nullptr) {};
    };
    TNode* pFirst;
    int size;

public:
    List();
    ~List();

    void print(TNode* pFirst);
    TNode* search(TNode* pFirst, int key);
    void pushFront(TNode*& pFirst, TNode* pNode);
    void pushBack(TNode*& pFirst, TNode* pNode);
    void inseartAfter(TNode*& pFirst, TNode* pNode, int key);
    void inseartBefore(TNode*& pFirst, TNode* pNode, int key);
    void remove(TNode*& pFirst, TNode* pNode, int key);
};