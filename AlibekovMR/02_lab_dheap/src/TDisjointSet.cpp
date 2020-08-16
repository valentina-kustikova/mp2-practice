#include "TDisjointSet.h"

TDisjointSet::TDisjointSet(int _size)
{
  if (_size <= 0)
    throw ExceptionIncorrectSize(__LINE__, __FILE__);
  size = _size;
  keys = new int[size];
  for (int i = 0; i < size; i++)
    keys[i] = -1;
}

TDisjointSet::TDisjointSet(int _size, int* _keys)
{
  if (_size <= 0)
    throw ExceptionIncorrectSize(__LINE__, __FILE__);
  if (_keys == nullptr)
    throw ExceptionEmptyData(__LINE__, __FILE__);
  size = _size;
  keys = new int[size];
  for (int i = 0; i < size; i++)
    keys[i] = _keys[i];
}

TDisjointSet::TDisjointSet(const TDisjointSet& _set)
{
  size = _set.size;
  keys = new int[size];
  for (int i = 0; i < size; i++)
    keys[i] = _set.keys[i];
}

TDisjointSet::~TDisjointSet()
{
  size = 0;
  delete[] keys;
}

void TDisjointSet::makeSet(int x)
{
  if (x < 0 || x >= size)
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  keys[x] = x;
}

void TDisjointSet::unite(int r, int s)
{
  if (r < 0 || r >= size || s < 0 || s >= size)
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  for (int i = 0; i < size; i++)
    if (keys[i] == s)
      keys[i] = r;
}

int TDisjointSet::find(int x) const
{
  if (x < 0 || x >= size)
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return keys[x];
};