#include "..\include\TEdge.h"

TEdge::TEdge(const TEdge & _edge)
{
  startVertex = _edge.startVertex;
  endVertex = _edge.endVertex;
  weight = _edge.weight;
}

bool TEdge::operator>(const TEdge & _edge)
{
  return this->weight > _edge.weight;
}

bool TEdge::operator<(const TEdge & _edge)
{
  return this->weight < _edge.weight;
}

bool TEdge::operator==(const TEdge & _edge)
{
  if ((this->startVertex == _edge.startVertex)
    && (this->endVertex == _edge.endVertex))
    return true;
  if ((this->startVertex == _edge.endVertex)
    && (this->endVertex == _edge.startVertex))
    return true;
  return false;
}

const TEdge & TEdge::operator=(const TEdge & _edge)
{
  if (*this == _edge)
    return *this;
  startVertex = _edge.startVertex;
  endVertex = _edge.endVertex;
  weight = _edge.weight;
  return *this;
};