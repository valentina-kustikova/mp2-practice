#include <exception>
#include "SeparatedSet.h"


using namespace std;

SeparatedSet::SeparatedSet(int _size)
{
    if (_size <= 0)
        throw exception("Incorrect data for SeparatedSet");
    size = _size;

    arr = new int[size];
    for (int i = 0; i < size; i++) 
        arr[i] = i;

};

SeparatedSet::SeparatedSet(int _size, int* _arr)
{
    if (_size <= 0 || _arr == nullptr)
        throw exception("Incorrect data for SeparatedSet");
    size = _size;

    arr = new int[size];
    for (int i = 0; i < size; i++) 
        arr[i] = _arr[i];
};

SeparatedSet::SeparatedSet(const SeparatedSet& _copy)
{
    size = _copy.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = _copy.arr[i];
};

SeparatedSet::~SeparatedSet()
{
    size = 0;
    delete[] arr;
};
//----------------------------------------------------------

void SeparatedSet::CreateSingleton(int i)
{
    arr[i] = i;
};

void SeparatedSet::Unite(int i, int j)
{
    if (i < 0 || j < 0 || i >= size || j >= size)
        throw exception("Incorrect set names");

    for (int k = 0; k < size; k++)
        if (arr[k] == j)
            arr[k] = i;
};

int SeparatedSet::Definition(int i) const
{
    if (i < 0 || i >= size)
        throw exception("Incorrect set number");

    return arr[i];
};