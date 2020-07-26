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
  TGraph(int _verticesCount, double* _adjacencyMatrix);
  TGraph(const TGraph& _graph);
  ~TGraph();

  bool isConnected()    const;
  bool isDisconnected() const;
  bool isDirected()     const;
  bool isUndirected()   const;
  bool hasLoop()        const;

  int numberOfComponents() const;

  double* getAdjacencyMatrix() const;
  void  printAdjacencyMatrix() const;

  static TGraph generateRandomDigraph(int _verticesCount, int _min, int _max);
  static TGraph generateRandomUndirectedGraph(int _verticesCount, int _min, int _max);
  static TGraph generateRandomConnectedGraph(int _verticesCount, int _min, int _max);
  static TGraph generateRandomConnectedGraphWithoutLoops(int _verticesCount, int _min, int _max);

  bool operator==(const TGraph& _graph) const;
  bool operator!=(const TGraph& _graph) const;

  const TGraph& operator=(const TGraph& _graph);

  friend std::ostream& operator<<(std::ostream& out, const TGraph& _graph);
  friend std::istream& operator>>(std::istream& in, TGraph& _graph);
};

#endif // !__TGRAPH__H__