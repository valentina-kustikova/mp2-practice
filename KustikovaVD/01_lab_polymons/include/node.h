#pragma once

#include "data.h"

class TNode
{
public:
    TData data;
    TNode* pNext;
//������������
    TNode() : pNext(nullptr) { };
    TNode(TData const data) : data(data) , pNext(nullptr){};
    TNode(TData const _data, TNode* const pNext) : data(_data), pNext(pNext) {};
    TNode(const TNode& node) { data = node.data; pNext = nullptr; }; //���������� �����������
    ~TNode()
    {

    };
//���������� �������� 
    bool operator < (const TNode& N) const { return( data < N.data ); }
   
    bool operator > (const TNode& N) const { return (data > N.data); }
   
    bool operator == (const TNode& N) const { return (data == N.data); }
    
    bool operator != (const TNode& N) const
    { return !(*this == N); }

};
