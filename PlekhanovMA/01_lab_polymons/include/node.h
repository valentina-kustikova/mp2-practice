#pragma once

struct TData
{
    double coeff; // коэффицент перед мономом
    int degree;   // свертка степени
    int degx, degy, degz;// степень x, y, z
    int operator==(const TData data) const
    {
        return (degree == data.degree) && (coeff == data.coeff);
    }
    int operator!=(const TData data) const
    {
        return (degree != data.degree) || (coeff != data.coeff);
    }
};

class TNode
{
public:
    TData data;// данные
    TNode* pNext;// указатель на следующий элемент списка

public:
    TNode();
    TNode(TData const data);
    TNode(TData const data, TNode* const pNext);
    TNode(const TNode& node);
    TNode& operator=(const TNode& node);
    ~TNode() { };
};