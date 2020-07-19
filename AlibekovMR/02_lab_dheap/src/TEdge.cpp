#include "TEdge.h"

TEdge::TEdge()
{
  setStartVertex(0);
  setEndVertex(0);
}

TEdge::TEdge(int _startVertex, int _endVertex)
{
  setStartVertex(_startVertex);
  setEndVertex(_endVertex);
}

TEdge::TEdge(const TEdge & _edge)
{
  startVertex = _edge.startVertex;
  endVertex = _edge.endVertex;
}

bool TEdge::operator==(const TEdge & _edge) const
{
  if ((this->startVertex == _edge.startVertex)
    && (this->endVertex == _edge.endVertex))
    return true;
  if ((this->startVertex == _edge.endVertex)
    && (this->endVertex == _edge.startVertex))
    return true;
  return false;
}

bool TEdge::operator!=(const TEdge & _edge) const
{
  return !(_edge == *this);
  /*
  if ((this->startVertex == _edge.startVertex)
    && (this->endVertex == _edge.endVertex))
    return false;
  if ((this->startVertex == _edge.endVertex)
    && (this->endVertex == _edge.startVertex))
    return false;
  return true;
  */
}

int TEdge::getStartVertex() const
{
  return startVertex;
}

int TEdge::getEndVertex() const
{
  return endVertex;
}

void TEdge::setStartVertex(int _startVertex)
{
  if (_startVertex < 0)
    throw ExceptionIncorrectVertex(__LINE__, __FILE__);
  startVertex = _startVertex;
}

void TEdge::setEndVertex(int _endVertex)
{
  if (_endVertex < 0)
    throw ExceptionIncorrectVertex(__LINE__, __FILE__);
  endVertex = _endVertex;
}

bool TEdge::isIncidental(int _vertex) const
{
  return (getStartVertex() == _vertex || getEndVertex() == _vertex);
}

bool TEdge::isAdjacent(TEdge& _edge) const
{
  return (_edge.isIncidental(getStartVertex())
       || _edge.isIncidental(getEndVertex()));
}

const TEdge & TEdge::operator=(const TEdge & _edge)
{
  if (*this == _edge)
    return *this;
  startVertex = _edge.startVertex;
  endVertex = _edge.endVertex;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const TEdge& _edge)
{
  out << "(" << _edge.getStartVertex() << " " << _edge.getEndVertex() << ")";
  return out;
}

std::istream& operator>>(std::istream& in, TEdge& _edge)
{
  int _startVertex = -1;
  int _endVertex = -1;
  std::cout << "Enter start_vertex: ";
  in >> _startVertex;
  _edge.setStartVertex(_startVertex);
  std::cout << "Enter end_vertex: ";
  in >> _endVertex;
  _edge.setEndVertex(_endVertex);
  return in;
};