#include "TDistances.h"

TDistances::TDistances(int _startVertex, int _verticesCount, double* _dist, int* _up)
{
  startVertex   = _startVertex;
  verticesCount = _verticesCount;
  dist = new double[verticesCount];
  up = new int[verticesCount];

  for (int i = 0; i < verticesCount; i++)
    dist[i] = _dist[i];

  for (int i = 0; i < verticesCount; i++)
    up[i] = _up[i];
}

TDistances::TDistances(const TDistances& _distances)
{
  startVertex   = _distances.startVertex;
  verticesCount = _distances.verticesCount;
  dist = new double[verticesCount];
  up = new int[verticesCount];

  for (int i = 0; i < verticesCount; i++)
    dist[i] = _distances.dist[i];

  for (int i = 0; i < verticesCount; i++)
    up[i] = _distances.up[i];
}

TDistances::~TDistances()
{
  if (dist) delete[] dist;
  if (up)   delete[] up;
}

bool TDistances::operator==(const TDistances& _distances) const
{
  if (startVertex != _distances.startVertex)
    return false;
  if (verticesCount != _distances.verticesCount)
    return false;

  for (int i = 0; i < verticesCount; i++)
    if (dist[i] != _distances.dist[i])
      return false;

  for (int i = 0; i < verticesCount; i++)
    if (up[i] != _distances.up[i])
      return false;

  return true;
}

bool TDistances::operator!=(const TDistances& _distances) const
{
  return !(*this != _distances);
  /*
  if (startVertex != _distances.startVertex)
    return false;
  if (vertexCount != _distances.vertexCount)
    return false;
  for (int i = 0; i < vertexCount; i++)
    if (dist[i] != _distances.dist[i])
      return false;
  for (int i = 0; i < vertexCount; i++)
    if (up[i] != _distances.up[i])
      return false;
  return true;
  */
}

const TDistances& TDistances::operator=(const TDistances& _distances)
{
  if (*this == _distances)
    return *this;

  startVertex = _distances.startVertex;
  verticesCount = _distances.verticesCount;

  if (dist) delete[] dist;
  if (up)   delete[] up;

  dist = new double[verticesCount];
  for (int i = 0; i < verticesCount; i++)
    dist[i] = _distances.dist[i];

  up = new int[verticesCount];
  for (int i = 0; i < verticesCount; i++)
    up[i] = _distances.up[i];

  return *this;
}

void TDistances::printPaths() const
{
  int* paths = new int[verticesCount * verticesCount];
  for (int i = 0; i < verticesCount * verticesCount; i++)
    paths[i] = -1;

  for (int i = 0; i < verticesCount; i++)
  {
    if (i == startVertex) continue;
    int idx = i * verticesCount + (verticesCount - 1);
    for (int vertex = i; vertex != startVertex; vertex = up[vertex])
      paths[idx--] = vertex;
    paths[idx] = startVertex;
  }

  for (int i = 0; i < verticesCount; i++)
  {
    if (i == startVertex) continue;
    std::cout << "distance(" << startVertex << ", " << i << ") = " << dist[i] << " || ";
    std::cout << "{" << startVertex << "}-->";
    for (int j = 0; j < verticesCount - 1; j++)
    {
      int vertex = paths[i * verticesCount + j];
      if ((vertex >= 0) && (vertex != startVertex))
        std::cout << "[" << vertex << "]-->";
    }
    std::cout << "{" << i << "}" << std::endl;
  }

  delete[] paths;
}

std::ostream& operator<<(std::ostream& out, const TDistances& _distances)
{
  out << "Start vertex: " << _distances.startVertex << std::endl;
  out << "Count of vertices: " << _distances.verticesCount << std::endl;

  out << "Dist: [ ";
  for (int i = 0; i < _distances.verticesCount; i++)
    out << _distances.dist[i] << " ";
  out << "]" << std::endl;

  out << "Up: [ ";
  for (int i = 0; i < _distances.verticesCount; i++)
    out << _distances.up[i] << " ";
  out << "]" << std::endl << std::endl;

  _distances.printPaths();

  return out;
}
