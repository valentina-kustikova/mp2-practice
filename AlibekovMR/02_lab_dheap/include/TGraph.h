#ifndef __TGRAPH__H__
#define __TGRAPH__H__

#include "TDisjointSet.h"
#include "TEdge.h"
#include "iostream"
#include <queue>
#include <utility> //temporarily (for pair)

class TGraph
{
public:
  int* vertices;
  int  verticesCount;
  TEdge* edges;
  int edgesCount;

  TGraph(int _verticesCount, int *_vertices);
  TGraph(int _verticesCount, int *_vertices, TEdge* _edges, int _edgesCount);
  TGraph(const TGraph& _graph);
  ~TGraph();

  void addNewEdge(const TEdge& _newEdge);
  bool isEdgeInGraph(const TEdge& _edge) const;
  bool isGraphConnected() const;
  bool isGraphDisconnected() const;

  int* getAdjacencyMatrix() const;
  void printAdjacencyMatrix() const;
  int numberOfComponents() const;

  friend std::ostream& operator<<(std::ostream& out, const TGraph& _graph);

};

#endif // !__TGRAPH__H__