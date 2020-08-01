#include "TPair.h"

TPair::TPair()
{
  setDistance(0);
  setVertex(-1);
}

TPair::TPair(int _vertex, double _distance)
{
  setVertex(_vertex);
  setDistance(_distance);
}

TPair::~TPair() {}

int TPair::getVertex() const
{
  return vertex;
}

double TPair::getDistance() const
{
  return distance;
}

void TPair::setVertex(int _vertex)
{
  vertex = _vertex;
}

void TPair::setDistance(double _distance)
{
  distance = _distance;
}

bool TPair::operator>(const TPair& _pair) const
{
  return (distance > _pair.getDistance());
}

bool TPair::operator<(const TPair& _pair) const
{
  return (distance < _pair.getDistance());
}

bool TPair::operator>=(const TPair& _pair) const
{
  return (distance >= _pair.getDistance());
}

bool TPair::operator<=(const TPair& _pair) const
{
  return (distance <= _pair.getDistance());
}

bool TPair::operator==(const TPair& _pair) const
{
  if ((distance == _pair.getDistance())
     && (vertex == _pair.getVertex()))
    return true;
  return false;
}

bool TPair::operator!=(const TPair& _pair) const
{
  return !(_pair == *this);
  /*
  if ((distance == _pair.distance)
     && (vertex == _pair.vertex))
    return false;
  return true;
  */
}

const TPair& TPair::operator=(const TPair& _pair)
{
  if (*this == _pair)
    return *this;
  setVertex(_pair.getVertex());
  setDistance(_pair.getDistance());
  return *this;
}

std::ostream& operator<<(std::ostream& out, const TPair& _pair)
{
  out << "Vertex: "   << _pair.getVertex()   << "   ";
  out << "Distance: " << _pair.getDistance() << "   ";
  return out;
}

std::istream& operator>>(std::istream& in, TPair& _pair)
{
  int _distance = 0;
  int _vertex = -1;

  std::cout << "Enter vertex: ";
  in >> _vertex;
  _pair.setVertex(_vertex);

  std::cout << "Enter distance: ";
  in >> _distance;
  _pair.setDistance(_distance);

  return in;
};