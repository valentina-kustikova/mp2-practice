#ifndef __ALGORITHMS__H__
#define __ALGORITHMS__H__

#include "TDHeap.h"
#include "TDisjointSet.h"
#include "TGraph.h"
#include "TPair.h"
#include "TDistances.h"

static class HeapSort
{
public:
  static void heapSort(int _size, int _array[]);
};

static class KruskalAlgorithm
{
public:
  static TGraph kruskalAlgorithm(const TGraph& _graph);
};

static class DijkstraAlgorithm
{
public:
  static TDistances dijkstraAlgorithm(const TGraph& _graph, const int _startVertex);
};

#endif // !__ALGORITHMS__H__