#ifndef __TGRAPH__H__
#define __TGRAPH__H__

#include "TDisjointSet.h"
#include "TWeightedEdge.h"

class TGraph
{
public:
  int  verticesCount;
  TWeightedEdge* edges;
  int edgesCount;

  TGraph(int _verticesCount);
  TGraph(int _verticesCount, TWeightedEdge* _edges, int _edgesCount);
  TGraph(const TGraph& _graph);
  ~TGraph();

  void addNewEdge(const TWeightedEdge& _newEdge);
  bool isEdgeInGraph(const TWeightedEdge& _edge) const;
  bool isGraphConnected() const;
  bool isGraphDisconnected() const;

  bool hasLoop() const;

  double* getAdjacencyMatrix() const;
  void printAdjacencyMatrix() const;
  int numberOfComponents() const;

  friend std::ostream& operator<<(std::ostream& out, const TGraph& _graph);

};

#endif // !__TGRAPH__H__