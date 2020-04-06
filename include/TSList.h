#ifndef TSLIST_H
#define TSLIST_H
#include "TNode.h"
#include "TList.h"
#include "TMonom.h"
#include <iostream>

using namespace std;

template<>
class TList<double, unsigned int>
{
public:
    TNode<double, unsigned int>* pFirst;
    TNode<double, unsigned int>* pPrev;
    TNode<double, unsigned int>* pCur;
    TNode<double, unsigned int>* pNext;

    TList();
    TList(const TNode<double, unsigned int>*);
    TList(const TList&);
    ~TList();

    bool operator==(const TList&) const;
    bool IsEnded() const;
    void Next();
    void Reset();

    TNode<double, unsigned int>* Search(unsigned int);
    void InsertEnd(unsigned int, double);
    void InsertFirst(unsigned int, double);
    void InsertAfter(unsigned int, double, unsigned int);
    void InsertBefore(unsigned int, double, unsigned int);
    void Remove(unsigned int);

    friend std::ostream& operator << (std::ostream& out, TList<double, unsigned int>& list)
    {
        list.Reset();
        while (!(list.IsEnded()))
        {
            out << (*list.pCur);
            list.Next();
        }
        return out;
    }
};

#endif