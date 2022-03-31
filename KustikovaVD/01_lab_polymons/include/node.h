#pragma once

#include "data.h"

class TNode : public TData
{
public:
    TData data;
    TNode* pNext;
//конструкторы
    TNode() { };
    TNode(TData const data) : data(data) , pNext(nullptr){};
    TNode(TData const _data, TNode* const pNext) : data(_data), pNext(pNext) {};
    TNode(const TNode& node) { data = node.data; pNext = nullptr; }; //конструтор копирования
    ~TNode();;
//перегрузки операций 
    bool operator < (const TNode& N) const
    { return (dgr_x < N.dgr_x && dgr_y < N.dgr_y && dgr_z < N.dgr_z && cfc < N.cfc);}
    bool operator > (const TNode& N) const
    { return (dgr_x > N.dgr_x&& dgr_y > N.dgr_y&& dgr_z > N.dgr_z&& cfc > N.cfc);}
    bool operator == (const TNode& N) const
    { return (dgr_x == N.dgr_x && dgr_y == N.dgr_y && dgr_z == N.dgr_x && cfc == N.cfc && pNext == N.pNext); }
    bool operator != (const TNode& N) const
    { return !(*this == N); }
};
