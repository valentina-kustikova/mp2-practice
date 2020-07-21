#ifndef __TGRAPH__H__
#define __TGRAPH__H__

#include "TDisjointSet.h"
#include "TWeightedEdge.h"

class TGraph
{
public:
  int verticesCount;
  int edgesCount;
  TWeightedEdge* edges;

  explicit TGraph(int _verticesCount);
  TGraph(int _verticesCount, int _edgesCount, TWeightedEdge* _edges);
  TGraph(int _verticesCount, double* AdjacencyMatrix);
  TGraph(const TGraph& _graph);
  ~TGraph();

  bool isConnected() const;
  bool isDisconnected() const;
  bool hasLoop() const;

  int numberOfComponents() const;

  double* getAdjacencyMatrix() const;
  void printAdjacencyMatrix() const;

  TGraph generateRandomGraph(int _verticesCount, int _min, int _max);
  TGraph generateRandomConnectedGraph(int _verticesCount, int _min, int _max);
  TGraph generateRandomConnectedGraphWithoutLoops(int _verticesCount, int _min, int _max);

  friend std::ostream& operator<<(std::ostream& out, const TGraph& _graph);
  friend std::istream& operator>>(std::istream& in, TGraph& _graph);
};

#endif // !__TGRAPH__H__