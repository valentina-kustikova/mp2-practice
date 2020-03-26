#include "DivSets.h"

DivSets::DivSets()
{
    n = 0;
}
DivSets::DivSets(int _n)
{
    n = _n;
    sets = new int[n];
    for (int i = 0; i < n; i++)
        sets[i] = -1;
}
DivSets::DivSets(int* _sets, int _n)
{
    n = _n;
    sets = new int[n];
    for (int i = 0; i < n; i++)
        sets[i] = _sets[i];
}
DivSets::DivSets(const DivSets& tmp)
{
    n = tmp.n;
    sets = new int[n];
    for (int i = 0; i < n; i++)
        sets[i] = tmp.sets[i];
}
DivSets::~DivSets()
{
    delete[] sets;
    n = 0;
}

void DivSets::CreateSingl()
{
    for (int i = 0; i < n; i++)
        sets[i] = i;
}
void DivSets::Unification(int i, int j)
{
    for (int k = 0; k < n; k++)
    {
        if (sets[k] == j)
            sets[k] = i;
    }
}
int DivSets::Subset(int i)
{
    return sets[i];
}