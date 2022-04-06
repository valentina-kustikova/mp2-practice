#pragma once

#include "data.h"
#include "node.h"

class TList
{
private:
    TNode* pFirst; //������ 
    TNode* pCurr; //��������� �� ������� �����
    TNode* pLast;//��������� �� ����� 

public:
    // ������������
    TList();
    TList(TNode* pFirst) : pFirst(pFirst) {};
    TList(const TList& list);
    // ����������
    ~TList();

    // �������� ��� �������
    bool is_empty() //���������, �������� �� ������ ���� ������ 
    {
        return pFirst == nullptr;
    }
    TNode* Search(TData* const data) //����� ���� � ������ �� ��������� �������� 
    {
        if (is_empty()) return;
        TNode* p = pFirst; 
        while (p && p->data != *(data)) //������� ������, ���� ��������� p �� ������ � ���� �������� ���� p �� ����� ��������� ��������
            p = p->pNext;
        return (p && p->data == *(data)) ? p : nullptr;
    };

    void InsertToHead(TData* const data); //�������� � ������ ������ 
    void InsertToTail(TData* const data); //�������� � �����
    void InsertBefore(TData* const data, TData* const before_data); //�������� ���� data ����� before_data
    void InsertAfter(TData* const data, TData* const after_data);  //�������� ���� data ����� after_data 
    void RemoveFirst(); //������� ������ ���� 
    void RemoveLast(); //������� ��������� ����
    void Remove(TData* const data); //������� ���� �� ��������� data
    virtual void Clear();
    virtual void Sort();
    virtual int GetLenght() const; //�������� ����� ������, ������� ���������� �����  

    // ���������
    virtual void Next(); // ������� � ���������� �����
    virtual void Reset(); // ������� � ������ ������
    virtual bool IsEnded() const; // �������� �� ����� ������
    virtual bool IsEmpty() const; // �������� �� ������� ������

    // ��������� ������
    // ...
};
TList::TList(const TList& list) //����������� ����������� 
{
    TNode* tmp = list.pFirst;
    pFirst = new TNode(tmp->data);
    pFirst->pNext = pFirst; 
    pCurr = pFirst;
    while (tmp->pNext != list.pFirst)
    {
        tmp = tmp->pNext;
        pCurr->pNext = new TNode(tmp->data);
        pCurr = pCurr->pNext; 
    }
    pCurr->pNext = pFirst;
    
    
}

void TList::InsertToHead(TData* const data)
{
    TNode* p = new TNode(*data);
    if (is_empty()) 
    {
        pFirst = p;
        pLast = p;
        return; 
    }
    p->pNext = pFirst; //������ ����� ����� ������ ���� (??)
    pFirst = p;
};
void TList::InsertToTail(TData* const data)
{
    TNode* p = new TNode(*data);
    if (is_empty())
    {
        pFirst = p;
        pLast = p;
        return;
    }
    pLast->pNext = p; //����� ���� ����� ����� ���������� ���� 
    pLast = p; 
};
void TList::InsertBefore(TData* const data, TData* const before_data)
{
    TNode* bf = new TNode(*before_data);
    TNode* p = new TNode(*data);
    p->pNext = bf;
};
void TList::InsertAfter(TData* const data, TData* const after_data)
{
    TNode* af = new TNode(*after_data);
    TNode* p = new TNode(*data);
    af->pNext = p;
};

void TList::RemoveFirst()
{
    if (is_empty()) return;
    TNode* p = pFirst; 
    pFirst = p->pNext; //������ �������� ������� ���� �� ���������
    delete p; 
};

void TList::RemoveLast()
{
    if (is_empty()) return;
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
};

void TList::Remove(TData* const data) //�� �������� !
{
    TNode* p = new TNode(*data);
    if (p == pFirst)
    {
        RemoveFirst();
        return;
    }
    else if (p == pLast)
    {
        RemoveFirst();
        return;
    }
    TNode* slow = pFirst;
    TNode* fast = pFirst->pNext;


};














