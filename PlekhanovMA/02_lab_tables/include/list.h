#pragma once
#include "node.h"

class TList
{
protected:
    TNode* pFirst;// ������ ������� ������
    TNode* pStop;// nullptr ��� ���. ������������ ������ � pHead ��� ����. � �������
    TNode* pCurr;// ������� ������� ������
    TNode* pNext;// ��������� ������� ������ �� ��������
    int Size; // ����� ������

public:
    // ������������
    TList();
    TList(TNode* pFirst);
    TList(const TList& list);
    ~TList();
    
    // �������� ��� �������
     TNode* Search(TData* const data);// ����� �������� ������
     void InsertToHead(TData* const data);// �������� ������� � ������
     void InsertToTail(TData* const data);// �������� ������� � �����
     void InsertAfter(TData* const data, TData* const after_data);// �������� ������� ����� �������
     void RemoveFirst();// ������� ������ �������
     void RemoveLast();// ������� ��������� �������
     void Remove(TData* curr_data);// ������� ������ �������
     int GetLenght() const;// �������� ����� ������
     void Clear(); // �������� ������

    // ���������
     void Next(); // ������� � ���������� �����
     void Reset(); // ������� � ������ ������
     bool IsEnded() const; // �������� �� ����� ������
     bool IsEmpty() const; // �������� �� ������� ������

    // ��������� ������
     TList& operator =(const TList& list);
     int operator==(const TList list) const;
     TNode* GetLast();
     TNode* GetCurr();
     TNode* GetNext();
     TNode* GetFirst();
};
