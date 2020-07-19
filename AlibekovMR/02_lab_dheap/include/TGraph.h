#ifndef __TGRAPH__H__
#define __TGRAPH__H__

#include "TDisjointSet.h"
#include "TWeightedEdge.h"
#include <queue>
#include <utility> //temporarily (for pair)

class TGraph
{
public:
  int* vertices;
  int  verticesCount;
  TWeightedEdge* edges;
  int edgesCount;

  TGraph(int _verticesCount, int *_vertices);
  TGraph(int _verticesCount, int *_vertices, TWeightedEdge* _edges, int _edgesCount);
  TGraph(const TGraph& _graph);
  ~TGraph();

  void addNewEdge(const TWeightedEdge& _newEdge);
  bool isEdgeInGraph(const TWeightedEdge& _edge) const;
  bool isGraphConnected() const;
  bool isGraphDisconnected() const;

  double* getAdjacencyMatrix() const;
  void printAdjacencyMatrix() const;
  int numberOfComponents() const;

  friend std::ostream& operator<<(std::ostream& out, const TGraph& _graph);

};

#endif // !__TGRAPH__H__