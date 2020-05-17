#ifndef _DHEAP_H_
#define _DHEAP_H_

template<class Tkey>
class DHeap
{
private:
    int d;//арность
    int n;//количество элементов
    Tkey* keys;
public:
    DHeap();
    DHeap(int _d, int _n, Tkey* _keys);
    DHeap(const DHeap& tmp);
    ~DHeap();

    void Transpon(int i, int j);//транспонирование
    void Ascent(int i);//всплытие
    int minchild(int i);//минимальный потомок
    int min(int x, int y);
    void Immersion(int i);//погружение
    void DelMin();//изъятие минимума
    void Hilling();//окучивание
    int GetN();
    static void Sort();
};

template<class Tkey>
DHeap<Tkey>::DHeap()
{
    d = 0;
    n = 0;
}

template<class Tkey>
DHeap<Tkey>::DHeap(int _d, int _n, Tkey* _keys)
{
    d = _d;
    n = _n;
    keys = new Tkey[n];
    for (int i = 0; i < n; i++)
        keys[i] = _keys[i];
}

template<class Tkey>
DHeap<Tkey>::DHeap(const DHeap& tmp)
{
    d = tmp.d;
    n = tmp.n;
    keys = new Tkey[n];
    for (int i = 0; i < n; i++)
        keys[i] = tmp.keys[i];
}

template<class Tkey>
DHeap<Tkey>::~DHeap()
{
    delete[] keys;
    d = 0;
    n = 0;
}

template<class Tkey>
void DHeap<Tkey>::Transpon(int i, int j)
{
    Tkey tmp = keys[i];
    keys[i] = keys[j];
    keys[j] = tmp;
}

template<class Tkey>
void DHeap<Tkey>::Ascent(int i)
{
    int p;
    while (i > 0)
    {
        p = (i - 1) / d;
        if (keys[p] > keys[i])
        {
            Transpon(i, p);
            i = p;
        }
        else i--;
    }
}

template<class Tkey>
int DHeap<Tkey>::min(int x, int y)
{
    return x < y ? x : y;
}

template<class Tkey>
int DHeap<Tkey>::minchild(int i)
{
    int ind1 = i * d + 1;
    if (ind1 > n)
        return -1;
    int ind2 = min(i*d + d, n - 1);
    int c = ind1;
    for (int j = ind1 + 1; j <= ind2; i++)
    {
        if (keys[j] < keys[c])
            c = j;
    }
    return c;
}

template<class Tkey>
void DHeap<Tkey>::Immersion(int i)
{
    int c = minchild(i);
    while (c > 0)
    {
        if (keys[c] < keys[i])
        {
            Transpon(i, c);
            c = i;
        }
        else
            break;
    }
}

template<class Tkey>
void DHeap<Tkey>::DelMin()
{
    Transpon(0, n - 1);
    n--;
    Immersion(0);
}

template<class Tkey>
void DHeap<Tkey>::Hilling()
{
    for (int i = n - 1; i >= 0; i--)
        Immersion(i);
}

template<class Tkey>
int DHeap<Tkey>::GetN()
{
    return n;
}

template<class Tkey>
void DHeap<Tkey>::Sort()
{
    Hilling();
    int s = n;
    for (int i = 0; i < n; i++)
    {
        Transpon(0, s - 1);
        s--;
        Immersion(0);
    }
}

#endif
