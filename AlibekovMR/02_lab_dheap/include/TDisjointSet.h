#ifndef __TDISJOINTSET__H__
#define __TDISJOINTSET__H__

#include "MyExceptions.h"

class TDisjointSet
{
private:
  int  size;
  int* keys;

public:
  explicit TDisjointSet(int _size);
  TDisjointSet(int _size, int* _keys);
  TDisjointSet(const TDisjointSet& _set);
  ~TDisjointSet();

  void makeSet(int x);
  void unite(int r, int s);
  int find(int x) const;
};

#endif // !__TDISJOINTSET__H__