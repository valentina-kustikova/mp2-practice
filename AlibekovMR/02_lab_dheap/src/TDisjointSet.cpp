#include "..\include\TDisjointSet.h"

TDisjointSet::TDisjointSet(int _size)
{
  size = _size;
  keys = new int[size];
  for (int i = 0; i < size; i++)
    keys[i] = -1;
}

TDisjointSet::TDisjointSet(int _size, int * _keys)
{
  size = _size;
  keys = new int[size];
  for (int i = 0; i < size; i++)
    keys[i] = _keys[i];
}

TDisjointSet::~TDisjointSet()
{
  delete[] keys;
}

void TDisjointSet::makeSet(int x)
{
  if ((x < 0) || (x >= size))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  keys[x] = x;
}

void TDisjointSet::unite(int r, int s)
{
  if ((r < 0) || (r >= size) || (s < 0) || (s >= size))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  for (int i = 0; i < size; i++)
    if (keys[i] == s)
      keys[i] = r;
}

int TDisjointSet::find(int x)
{
  if ((x < 0) || (x >= size))
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  return keys[x];
}