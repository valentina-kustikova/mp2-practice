#pragma once

#include <iostream>
#include "data.h"
#include "node.h"

class TList
{
private:
    TNode* pFirst; //������ 
    TNode* pCurr; //��������� �� ������� �����
    TNode* pLast;//��������� �� ����� 


    // ������������
    TList();
    TList(TNode* pFirst) : pFirst(pFirst), pCurr(pFirst), pLast(pFirst) {};
    TList(const TList& list);
    // ����������
    ~TList();

    // �������� ��� �������

    TNode* Search(TData* const data) //����� ���� � ������ �� ��������� �������� 
    {
        if (IsEmpty())
        {
            TNode* p = pFirst;
            while (p && p->data != *(data)) //������� ������, ���� ��������� p �� ������ � ���� �������� ���� p �� ����� ��������� ��������
                p = p->pNext;
            return p && p->data == *(data) ? p : nullptr;
        }

    };
    
    virtual void InsertToHead(TData* const data); //�������� � ������ ������ 
    virtual void InsertToTail(TData* const data); //�������� � �����
    virtual void InsertBefore(TData* const data, TData* const before_data); //�������� ���� data ����� before_data
    virtual void InsertAfter(TData* const data, TData* const after_data);  //�������� ���� data ����� after_data 
    virtual void RemoveFirst(); //������� ������ ���� 
    virtual void RemoveLast(); //������� ��������� ����
    virtual void Remove(TData* const data); //������� ���� �� ��������� data
    virtual void Clear(); //�������� ������ 
    int GetLenght() const; //�������� ����� ������ 

    // ���������
    void Next(); // ������� � ���������� �����
    void Reset(); // ������� � ������ ������
    bool IsEnded() const  // �������� �� ����� ������
    {
        this->pCurr;
        return pCurr->pNext == nullptr;
    }
    bool IsEmpty() const // �������� �� ������� ������
    {
        return pFirst == nullptr;
    }

    // ��������� ������
    // ...
};
//������������
TList::TList()
{
    pFirst = new TNode;
    pFirst->pNext = nullptr;
    pCurr = pFirst; 
    pLast = pFirst;
}

TList::TList(const TList& list) //����������� ����������� 
{
    TNode* tmp = list.pFirst;
    pFirst = new TNode(tmp->data);
    pFirst->pNext = pFirst; 
    pCurr = pFirst;
    pLast = pFirst; 
    while (tmp->pNext != list.pLast)
    {
        tmp = tmp->pNext;
        pCurr->pNext = new TNode(tmp->data);
        pCurr = pCurr->pNext; 
    }
}
//���������� 
TList::~TList()
{
    Clear();
}
void TList::InsertToHead(TData* const data)
{
    TNode* p = new TNode(*data);
    if (IsEmpty())
    {
        pFirst = p;
        pLast = p;
        return; 
    }
    p->pNext = pFirst; //������ ����� ����� ������ ���� (??)
    pFirst = p;
}
void TList::InsertToTail(TData* const data)
{
    TNode* p = new TNode(*data);
    if (IsEmpty())
    {
        pFirst = p;
        pLast = p;
        return;
    }
    pLast->pNext = p; //����� ���� ����� ����� ���������� ���� 
    pLast = p; 
}
void TList::InsertBefore(TData* const data, TData* const before_data)
{
    TNode* bf = new TNode(*before_data);
    TNode* p = new TNode(*data);
    p->pNext = bf;
}
void TList::InsertAfter(TData* const data, TData* const after_data)
{
    TNode* af = new TNode(*after_data);
    TNode* p = new TNode(*data);
    af->pNext = p;
}

void TList::RemoveFirst()
{
    if (IsEmpty()) return;
    TNode* p = pFirst; 
    pFirst = p->pNext; //������ �������� ������� ���� �� ���������
    delete p; 
}

void TList::RemoveLast()
{
    if (IsEmpty()) return;
    if (pFirst == pLast)
    {
        RemoveFirst();
        return;
    }
    TNode* p = pFirst;
    while (p->pNext != pLast)
        p = p->pNext;
    p->pNext = nullptr;
    delete pLast;
    pLast = p;
}

void TList::Remove(TData* const _data) 
{
    TNode* p = new TNode(*_data);
    if (p == pFirst)
    {
        RemoveFirst();
        return;
    }
    else if (p == pLast)
    {
        RemoveLast();
        return;
    }
    TNode* slow = pFirst;
    TNode* fast = pFirst->pNext;
    while (fast && fast->data != *_data)
    {
        fast = fast->pNext;
        slow = slow->pNext;
    }
    if (!fast)
    {
        setlocale(LC_ALL, "Russian");
        std::cout << "������: ������ �������� ���" << std::endl;
        return;
    }
    slow->pNext = fast->pNext; 
    delete fast;
}

int TList::GetLenght() const
{
    int it = 1;
    if (pFirst == nullptr)
    {
        return 0;
    }
    else
    while (pFirst->pNext)
    {
        pFirst->pNext = pFirst;
        ++it; 
    }
    return it; 
}
void TList::Next() //???
{
    if (IsEmpty())
        pCurr = pCurr->pNext;
}

void TList::Reset()
{
    TNode* tmp = pFirst;
    pCurr->pNext = pFirst;
    return; 
}
void TList::Clear()
{
    if (IsEmpty()) return; 
    TNode* p = new TNode; 
    TNode* p = pFirst;
    int size = GetLenght();
    int i=0;
    while (i != size)
    {
        pFirst = p->pNext;
        delete p;
        ++i;
    }
}

   

















