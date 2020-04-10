#include "TSet.h"

TSet::TSet(size_t size_)
{
    size = size_;
    keys = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        keys[i] = -1;
    }
}

TSet::TSet(size_t size_, int* elements_)
{
    size = size_;
    keys = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        keys[i] = elements_[i];
    }
}

TSet::~TSet()
{
    size = 0;
    delete[] keys;
}

void TSet::createSubset(int id)
{
    if (keys[id] != -1) throw TBadIdException();
    keys[id] = id;
}

void TSet::uniteSubsets(int a, int b)
{
    for (size_t i = 0; i < size; i++)
    {
        if (keys[i] == b) keys[i] = a;
    }
}

int TSet::getSubsetName(int id)
{
    return keys[id];
}