#ifndef __TEDGE_H__
#define __TEDGE_H__

#include "MyExceptions.h"
#include "iostream"

class TEdge
{
private:
  int startVertex;
  int endVertex;

public:
  TEdge() :startVertex(0), endVertex(0) {};
  TEdge(int _startVertex, int _endVertex)
    : startVertex(_startVertex), endVertex(_endVertex) {};
  TEdge(const TEdge& _edge);
  ~TEdge() {};

  bool operator==(const TEdge& _edge) const;
  bool operator!=(const TEdge& _edge) const;

  int getStartVertex() const;
  int getEndVertex()   const;

  void setStartVertex(int _startVertex);
  void   setEndVertex(int _endVertex);

  const TEdge& operator=(const TEdge& _edge);

  friend std::ostream& operator<<(std::ostream& out, const TEdge& _edge);
  friend std::istream& operator>>(std::istream& in, TEdge& _edge);
};

#endif // !__TEDGE_H__