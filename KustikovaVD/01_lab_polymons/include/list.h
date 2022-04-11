#pragma once

#include "data.h"
#include "node.h"

class TList
{
private:
    TNode* pFirst;
    TNode* pStop; // nullptr ��� ���. ������������ ������ � pHead ��� ����. � �������
    TNode* pCurr;
    TNode* pNext;
    TNode* pPrev;

public:
    // ������������
    TList();
    TList(TNode* pFirst);
    TList(const TList& list);
    // ����������
    ~TList();

    // �������� ��� �������
    virtual TNode* Search(TData* const data);
    virtual void InsertToHead(TData* const data);
    virtual void InsertToTail(TData* const data);
    virtual void InsertBefore(TData* const data, TData* const before_data);
    virtual void InsertAfter(TData* const data, TData* const after_data);
    virtual void RemoveFirst();
    virtual void RemoveLast();
    virtual void Remove(TData* const data);
    virtual void Clear();
    virtual void Sort();
    virtual int GetLenght() const;

    // ���������
    virtual void Next(); // ������� � ���������� �����
    virtual void Reset(); // ������� � ������ ������
    virtual bool IsEnded() const; // �������� �� ����� ������
    virtual bool IsEmpty() const; // �������� �� ������� ������

    // ��������� ������
    // ...
};
