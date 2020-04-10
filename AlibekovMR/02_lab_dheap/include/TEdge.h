#ifndef __TEDGE_H__
#define __TEDGE_H__

struct TEdge
{
  int startVertex;
  int endVertex;
  int weight;

  TEdge() :startVertex(0), endVertex(0), weight(0) {};
  TEdge(int _startVertex, int _endVertex, int _weight)
    : startVertex(_startVertex), endVertex(_endVertex), weight(_weight) {};
  TEdge(const TEdge& _edge);
  ~TEdge() {};

  bool operator>(const TEdge& _edge);
  bool operator<(const TEdge& _edge);
  bool operator==(const TEdge& _edge);

  const TEdge& operator=(const TEdge& _edge);
};

#endif // !__TEDGE_H__