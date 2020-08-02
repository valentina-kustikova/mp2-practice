#include "Algorithms.h"

void HeapSort::heapSort(int _size, int _array[])
{
  const int base = 2;

  if (_size < 0)
    throw ExceptionOutOfRange(__LINE__, __FILE__);

  int size = _size;
  TDHeap<int> heap(base, size, size, _array);

  for (int i = 0; i < size; i++)
    heap.removeMinKey();
};

TGraph KruskalAlgorithm::kruskalAlgorithm(const TGraph& _graph)
{
  const int base = 2;

  int verticesCount = _graph.getVerticesCount();
  int    edgesCount = _graph.getEdgesCount();

  if (verticesCount < 1)
    throw ExceptionGraphWithoutVertices(__LINE__, __FILE__);

  if (_graph.isDisconnected())
    throw ExceptionDisconnectedGraph(__LINE__, __FILE__);

  if (_graph.hasLoop())
    throw ExceptionGraphWithLoop(__LINE__, __FILE__);

  TDisjointSet vertices(verticesCount);
  for (int i = 0; i < verticesCount; i++)
    vertices.makeSet(i);

  TWeightedEdge* edgesOfResultTree = new TWeightedEdge[verticesCount - 1];
  int currentCountEdgesOfResultTree = 0;

  TDHeap<TWeightedEdge> edges(base, edgesCount, edgesCount, _graph.getEdges());

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

  TGraph resultTree(verticesCount, verticesCount - 1, edgesOfResultTree);

  delete[] edgesOfResultTree;
  return resultTree;
};

TDistances DijkstraAlgorithm::dijkstraAlgorithm(const TGraph& _graph, const int _startVertex)
{
  const int base = 2;

  TWeightedEdge* edges = _graph.getEdges();
  int    edgesCount    = _graph.getEdgesCount();
  int verticesCount    = _graph.getVerticesCount();

  if (verticesCount < 0)
    throw ExceptionGraphWithoutVertices(__LINE__, __FILE__);

  if ((_startVertex < 0) || (_startVertex > verticesCount))
    throw ExceptionIncorrectVertex(__LINE__, __FILE__);

  if (_graph.isDisconnected())
    throw ExceptionDisconnectedGraph(__LINE__, __FILE__);

  if (_graph.hasLoop())
    throw ExceptionGraphWithLoop(__LINE__, __FILE__);

  for (int i = 0; i < edgesCount; i++)
    if (edges[i].getWeight() < 0)
      throw ExceptionGraphWithNegativeWeights(__LINE__, __FILE__);

  TPair* pairs = new TPair[verticesCount];
  double* dist = new double[verticesCount];
  int* up = new int[verticesCount];

  for (int i = 0; i < verticesCount; i++)
  {
    pairs[i].setDistance(DBL_MAX);
    pairs[i].setVertex(i);
    up[i] = _startVertex;
  }
  pairs[_startVertex].setDistance(0);

  TDHeap<TPair> marksQueue(base, verticesCount, verticesCount, pairs);

  while (marksQueue.getSize() != 0)
  {
    TPair mark = marksQueue.getRoot();
    TPair* adjacentVertices = new TPair[verticesCount - 1];
    int adjacentVerticesCount = 0;

    for (int i = 0; i < edgesCount; i++)
      if (edges[i].isIncidental(mark.getVertex()))
        adjacentVertices[adjacentVerticesCount++] = TPair((edges[i].getStartVertex() == mark.getVertex()) ?
          edges[i].getEndVertex() : edges[i].getStartVertex(), edges[i].getWeight());

    for (int i = 0; i < adjacentVerticesCount; i++)
    {
      int idx = -1;
      while (idx < verticesCount)
        if (adjacentVertices[i].getVertex() == pairs[++idx].getVertex())
          break;

      if (mark.getDistance() + adjacentVertices[i].getDistance() < pairs[idx].getDistance())
      {
        pairs[idx].setDistance(mark.getDistance() + adjacentVertices[i].getDistance());
        up[adjacentVertices[i].getVertex()] = mark.getVertex();
      }
    }
    dist[mark.getVertex()] = mark.getDistance();

    marksQueue.removeMinKey();
    marksQueue.heapify();

    delete[] adjacentVertices;
  }

  TDistances result(_startVertex, verticesCount, dist, up);

  delete[] dist;
  delete[] up;
  delete[] pairs;

  return result;
};