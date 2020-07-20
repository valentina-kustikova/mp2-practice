#include "Algorithms.h"

void HeapSort::heapSort(int _size, int _array[])
{
  const int base = 2;
  if (_size < 0)
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  int size = _size;
  TDHeap<int> heap(base, size, size, _array);
  for (int i = size - 1; i >= 0; i--)
  {
    _array[size - i - 1] = heap.getRoot();
    heap.removeMinKey();
  }
};

TGraph KruskalAlgorithm::kruskalAlgorithm(const TGraph& _graph)
{
  const int base = 2;

  if (_graph.verticesCount < 1)
    throw ExceptionGraphWithoutVertices(__LINE__, __FILE__);
  if (_graph.isGraphDisconnected())
    throw ExceptionDisconnectedGraph(__LINE__, __FILE__);
  if (_graph.hasLoop())
    throw ExceptionGraphWithLoop(__LINE__, __FILE__);

  int verticesCount = _graph.verticesCount;
  TDisjointSet vertices(verticesCount);
  for (int i = 0; i < verticesCount; i++)
    vertices.makeSet(i);

  TWeightedEdge* edgesOfResultTree = new TWeightedEdge[verticesCount - 1];
  int currentCountEdgesOfResultTree = 0;

  TDHeap<TWeightedEdge> edges(base, _graph.edgesCount, _graph.edgesCount, _graph.edges);

  while (currentCountEdgesOfResultTree != verticesCount - 1)
  {
    TWeightedEdge edgeWithMinWeight = edges.getRoot();
    edges.removeMinKey();
    if (vertices.find(edgeWithMinWeight.getStartVertex())
     != vertices.find(edgeWithMinWeight.getEndVertex()))
    {
      vertices.unite(vertices.find(edgeWithMinWeight.getStartVertex()),
                     vertices.find(edgeWithMinWeight.getEndVertex()));
      edgesOfResultTree[currentCountEdgesOfResultTree++] = edgeWithMinWeight;
    }
  }

  TGraph resultTree(verticesCount, _graph.vertices, edgesOfResultTree, verticesCount - 1);

  delete[] edgesOfResultTree;
  return resultTree;
};