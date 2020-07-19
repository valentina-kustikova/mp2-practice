#include "TWeightedEdge.h";

TWeightedEdge::TWeightedEdge()
{
  setStartVertex(0);
  setEndVertex(0);
  setWeight(.0);
}

TWeightedEdge::TWeightedEdge(int _startVertex, int _endVertex, double _weight)
{
  setStartVertex(_startVertex);
  setEndVertex(_endVertex);
  setWeight(_weight);
}

TWeightedEdge::TWeightedEdge(const TWeightedEdge& _edge)
{
  setStartVertex(_edge.getStartVertex());
  setEndVertex(_edge.getEndVertex());
  setWeight(_edge.getWeight());
}

bool TWeightedEdge::operator>(const TWeightedEdge& _edge)
{
  return (getWeight() > _edge.getWeight());
}

bool TWeightedEdge::operator<(const TWeightedEdge& _edge)
{
  return (getWeight() < _edge.getWeight());
}

bool TWeightedEdge::operator>=(const TWeightedEdge& _edge)
{
  return (getWeight() >= _edge.getWeight());
}

bool TWeightedEdge::operator<=(const TWeightedEdge& _edge)
{
  return (getWeight() <= _edge.getWeight());
}

bool TWeightedEdge::operator==(const TWeightedEdge& _edge)
{
  return (getWeight() == _edge.getWeight()
    && getEndVertex() == _edge.getEndVertex()
  && getStartVertex() == _edge.getStartVertex());
}

bool TWeightedEdge::operator!=(const TWeightedEdge& _edge)
{
  return !(*this == _edge);
  /*
  return (getWeight() != _edge.getWeight()
    || getEndVertex() != _edge.getEndVertex()
    || getStartVertex() != _edge.getStartVertex());
  */
}

double TWeightedEdge::getWeight() const
{
  return weight;
}

void TWeightedEdge::setWeight(double _weight)
{
  weight = _weight;
}

const TWeightedEdge& TWeightedEdge::operator=(const TWeightedEdge& _edge)
{
  if (*this == _edge)
    return *this;
  setStartVertex(_edge.getStartVertex());
  setEndVertex(_edge.getEndVertex());
  setWeight(_edge.getWeight());
  return *this;
}

std::ostream& operator<<(std::ostream& out, const TWeightedEdge& _edge)
{
  out << "(" << _edge.getStartVertex() << " " << _edge.getEndVertex() 
    << " " << _edge.getWeight() << ")";
  return out;
}

std::istream& operator>>(std::istream& in, TWeightedEdge& _edge)
{
  int _startVertex = -1;
  int _endVertex = -1;
  double _weight = .0;

  std::cout << "Enter start_vertex: ";
  in >> _startVertex;
  _edge.setStartVertex(_startVertex);

  std::cout << "Enter end_vertex: ";
  in >> _endVertex;
  _edge.setEndVertex(_endVertex);

  std::cout << "Enter weight: ";
  in >> _weight;
  _edge.setWeight(_weight);

  return in;
};