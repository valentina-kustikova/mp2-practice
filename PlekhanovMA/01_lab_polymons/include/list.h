#pragma once

#include "monom.h"

class TList
{
private:
    TMonom* pFirst;// ������ ������� ������
    TMonom* pStop;// nullptr ��� ���. ������������ ������ � pHead ��� ����. � �������
    TMonom* pCurr;// ������� ������� ������
    TMonom* pNext;// ��������� ������� ������ �� ��������
    int Size; // ����� ������

public:
    // ������������
    TList();
    TList(TMonom* pFirst);
    TList(const TList& list);
    ~TList();
    
    // �������� ��� �������
     TMonom* Search(TData const data);// ����� �������� ������
     void InsertToHead(TData const data);// �������� ������� � ������
     void InsertToTail(TData const data);// �������� ������� � �����
     void InsertAfter(TData const data, TData const after_data);// �������� ������� ����� �������
     void RemoveFirst();// ������� ������ �������
     void RemoveLast();// ������� ��������� �������
     void Remove(TMonom* monom);// ������� ������ �������
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
     TMonom* GetMonom();
     TMonom* GetNextMonom();
     TMonom* GetFirstMonom();
     TMonom* SearchSimilar(TData const data);
};
