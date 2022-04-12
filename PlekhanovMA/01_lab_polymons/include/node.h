#pragma once

struct TData
{
    double coeff; // ���������� ����� �������
    int degree;   // ������� �������
    int degx, degy, degz;// ������� x, y, z
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
    TData data;// ������
    TNode* pNext;// ��������� �� ��������� ������� ������

public:
    TNode();
    TNode(TData const data);
    TNode(TData const data, TNode* const pNext);
    TNode(const TNode& node);
    TNode& operator=(const TNode& node);
    ~TNode() { };
};