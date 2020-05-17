#ifndef _PQUEUE_H_
#define _PQUEUE_H_
#include <iostream>

template <class Prior, class TData>
struct PQueueElem
{
    Prior prior;
    TData* data;
};

template <class Prior, class TData>
class PQueue
{
private:
    int size;
    int count;
    int hi;
    int li;
    PQueueElem* elems;
public:
    PQueue();
    PQueue(int _size);
    PQueue(int, Prior*, TData*);
    PQueue(const PQueue& tmp);
    ~PQueue();

    void Push(Prior p, TData _data);
    PQueueElem Pop();//удаление наибольшего приор
    bool IsFull();
    bool IsEmpty();

    int GetNextIndex(int ind);
    int GetPrevIndex(int ind);
};

template <class Prior, class TData>
PQueue<Prior, TData>::PQueue() {}

template <class Prior, class TData>
PQueue<Prior, TData>::PQueue(int _size)
{
    size = _size;
    count = 0;
    hi = 0;
    li = 0;
    elems = new PQueueElem<Prior, TData>[size];
}

template <class Prior, class TData>
PQueue<Prior, TData>::PQueue(int _size, Prior* priors, TData* datas)
{
    size = _size;
    count = size;
    hi = 0;
    li = size;
    elems = new PQueueElem<Prior, TData>[size];
    for (int i = 0; i < count; i++)
    {
        elems[i].prior = priors[i];
        elems[i].data = datas[i];
    }
}

template <class Prior, class TData>
PQueue<Prior, TData>::PQueue(const PQueue& tmp)
{
    size = tmp.size;
    count = tmp.count;
    hi = tmp.count;
    li = 0;
    elems = new PQueueElem<Prior, TData>[size];
    for (int i = 0; i < count; i++)
    {
        elems[i] = tmp.elems[(li + i) % size];
    }
}

template <class Prior, class TData>
PQueue<Prior, TData>::~PQueue()
{
    delete[] elems;
    size = 0;
    count = 0;
    hi = 0;
    li = 0;
}

template <class Prior, class TData>
void PQueue<Prior, TData>::Push(Prior p, TData _data)
{
    if (IsFull())
        throw "!size";
    PQueueElem<Prior, TData> tmp = new PQueueElem<Prior, TData>(p, _data);
    int i = li;
    while ((i != hi) && (elems[i].prior < p))
    {
        i = GetNextIndex(i);
    }
    int j = GetNextIndex(hi);
    int k = hi;
    while (j != i)
    {
        elems[j] = elems[k];
        k = GetPrevIndex(k);
        j = GetPrevIndex(j);
    }
    elems[i] = tmp;
    hi = GetNextIndex(hi);
    count++;
}

template <class Prior, class TData>
PQueueElem<Prior, TData> PQueue<Prior, TData>::Pop()
{
    if (IsEmpty())
        throw "!IsEmpty";
    PQueueElem<Prior, TData> rez = elems[hi];
    delete elems[hi];
    hi = GetPrevIndex(hi);
    count--;
    return rez;
}

template <class Prior, class TData>
bool PQueue<Prior, TData>::IsFull()
{
    return (size == count);
}

template <class Prior, class TData>
bool PQueue<Prior, TData>::IsEmpty()
{
    return (count == 0);
}

template <class Prior, class TData>
int PQueue<Prior, TData>::GetNextIndex(int ind)
{
    return ((++ind) % size);
}

template <class Prior, class TData>
int PQueue<Prior, TData>::GetPrevIndex(int ind)
{
    return ind == 0 ? size - 1 : ind--;
}

#endif
