#include "TGraph.h"

TGraph::TGraph(int _verticesCount)
{
  if (_verticesCount < 0)
    throw ExceptionIncorrectCountOfVertices(__LINE__, __FILE__);
  verticesCount = _verticesCount;
  edgesCount = 0;
  edges = nullptr;
}

TGraph::TGraph(int _verticesCount, int _edgesCount, TWeightedEdge* _edges)
{
  if (_verticesCount < 0)
    throw ExceptionIncorrectCountOfVertices(__LINE__, __FILE__);
  if ((_edgesCount < 0) || (_edgesCount > _verticesCount * _verticesCount))
    throw ExceptionIncorrectCountOfEdges(__LINE__, __FILE__);

  verticesCount = _verticesCount;
  edgesCount = _edgesCount;
  edges = new TWeightedEdge[edgesCount];

  for (int i = 0; i < edgesCount; i++)
  {
    if ((_edges[i].getStartVertex() >= _verticesCount)
     || (_edges[i].getEndVertex()   >= _verticesCount))
    {
      delete[] edges;
      throw ExceptionIncorrectVertex(__LINE__, __FILE__);
    }
    edges[i] = _edges[i];
  }
}

TGraph::TGraph(int _verticesCount, double* _adjacencyMatrix)
{
  if (_verticesCount < 0)
    throw ExceptionIncorrectCountOfVertices(__LINE__, __FILE__);

  verticesCount = _verticesCount;
  edgesCount = 0;

  for (int i = 0; i < _verticesCount * _verticesCount; i++)
    if (_adjacencyMatrix[i] != 0)
      edgesCount++;

  edges = new TWeightedEdge[edgesCount];

  for (int i = 0, currIdx = 0; i < _verticesCount * _verticesCount; i++)
  {
    if (_adjacencyMatrix[i] != 0)
    {
      edges[currIdx].setStartVertex(i % _verticesCount);
      edges[currIdx].setEndVertex(i / _verticesCount);
      edges[currIdx++].setWeight(_adjacencyMatrix[i]);
    }
  }
}

TGraph::TGraph(const TGraph& _graph)
{
  verticesCount = _graph.verticesCount;
  edgesCount = _graph.edgesCount;
  edges = new TWeightedEdge[edgesCount];
  for (int j = 0; j < edgesCount; j++)
    edges[j] = _graph.edges[j];
}

TGraph::~TGraph()
{
  delete[] edges;
}

bool TGraph::isConnected() const
{
  if (numberOfComponents() < 1)
    throw ExceptionGraphWithoutVertices(__LINE__, __FILE__);
  if (numberOfComponents() == 1)
    return true;
  return false;
}

bool TGraph::isDisconnected() const
{
  if (numberOfComponents() < 1)
    throw ExceptionGraphWithoutVertices(__LINE__, __FILE__);
  if (numberOfComponents() > 1)
    return true;
  return false;
}

bool TGraph::isDirected() const
{
  return !isUndirected();
}

bool TGraph::isUndirected() const
{
  for (int i = 0; i < edgesCount - 1; i++)
    for (int j = i + 1; j < edgesCount; j++)
    {
      if ((edges[i].getEndVertex()   == edges[j].getStartVertex())
       && (edges[i].getStartVertex() == edges[j].getEndVertex()))
        return false;
    }
  return true;
}

bool TGraph::hasLoop() const
{
  for (int i = 0; i < edgesCount; i++)
    if (edges[i].getStartVertex() == edges[i].getEndVertex())
      return true;
  return false;
}

double* TGraph::getAdjacencyMatrix() const
{
  double* adjacencyMatrix = new double[verticesCount * verticesCount];
  for (int k = 0; k < verticesCount * verticesCount; k++)
    adjacencyMatrix[k] = 0;

  bool isUndirectedGraph = this->isUndirected();

  for (int i = 0; i < edgesCount; i++)
  {
    TWeightedEdge currentEdge = edges[i];
    int startVertex = currentEdge.getStartVertex();
    int endVertex = currentEdge.getEndVertex();
    adjacencyMatrix[startVertex * verticesCount + endVertex]   = currentEdge.getWeight();
    if (isUndirectedGraph)
      adjacencyMatrix[endVertex * verticesCount + startVertex] = currentEdge.getWeight();
  }

  return adjacencyMatrix;
}

void TGraph::printAdjacencyMatrix() const
{
  double* adjacencyMatrix = getAdjacencyMatrix();

  for (int i = 0; i < verticesCount; i++)
  {
    for (int j = 0; j < verticesCount; j++)
      std::cout << adjacencyMatrix[i * verticesCount + j] << " ";
    std::cout << std::endl;
  }

  delete[] adjacencyMatrix;
}

TGraph TGraph::generateRandomDigraph(int _verticesCount, int _min, int _max)
{
  if (_verticesCount < 0)
    throw ExceptionIncorrectCountOfVertices(__LINE__, __FILE__);

  if (_min > _max)
    throw ExceptionIncorrectValueBoundaries(__LINE__, __FILE__);

  double* adjacencyMatrix = new double[_verticesCount * _verticesCount];

  for (int i = 0; i < _verticesCount * _verticesCount; i++)
  {
    if (rand() / (double)RAND_MAX < .5)
      adjacencyMatrix[i] = 0;
    else 
      adjacencyMatrix[i] = (_max - _min + 1) / (double)RAND_MAX * rand() + _min;
  }

  TGraph resultGraph(_verticesCount, adjacencyMatrix);
  delete[] adjacencyMatrix;

  return resultGraph;
}

TGraph TGraph::generateRandomUndirectedGraph(int _verticesCount, int _min, int _max)
{
  if (_verticesCount < 0)
    throw ExceptionIncorrectCountOfVertices(__LINE__, __FILE__);

  if (_min > _max)
    throw ExceptionIncorrectValueBoundaries(__LINE__, __FILE__);

  double* adjacencyMatrix = new double[_verticesCount * _verticesCount];

  for (int i = 0; i < _verticesCount; i++)
    for (int j = 0; j < _verticesCount; j++)
      adjacencyMatrix[i * _verticesCount + j]
        = (j < i) ? 0 : (_max - _min + 1) / (double)RAND_MAX * rand() + _min;

  TGraph resultGraph(_verticesCount, adjacencyMatrix);
  delete[] adjacencyMatrix;

  return resultGraph;
}

TGraph TGraph::generateRandomConnectedGraph(int _verticesCount, int _min, int _max)
{
  if (_verticesCount < 0)
    throw ExceptionIncorrectCountOfVertices(__LINE__, __FILE__);

  if (_min > _max)
    throw ExceptionIncorrectValueBoundaries(__LINE__, __FILE__);

  double* adjacencyMatrix = new double[_verticesCount * _verticesCount];
  for (int i = 0; i < _verticesCount * _verticesCount; i++)
    adjacencyMatrix[i] = 0;

  int _minEdgesCount = _verticesCount - 1;
  int _maxEdgesCount = _verticesCount * (_verticesCount + 1) / 2;
  int edgesCount = (_maxEdgesCount - _minEdgesCount) / (double)RAND_MAX * rand() + _minEdgesCount;

  int* path = new int[_verticesCount];
  for (int i = 0; i < _verticesCount; i++)
    path[i] = i;
  for (int i = _verticesCount - 1; i >= 0; i--)
  {
    int j = i / (double)RAND_MAX * rand();
    int tmp = path[i];
    path[i] = path[j];
    path[j] = tmp;
  }

  for (int j = 0; j < _verticesCount - 1; j++)
  {
    int idx;
    if (path[j] <= path[j + 1])
      idx = path[j] * _verticesCount + path[j + 1];
    else
      idx = path[j + 1] * _verticesCount + path[j];
    adjacencyMatrix[idx] = (_max - _min + 1) / (double)RAND_MAX * rand() + _min;
  }
  delete[] path;

  int* indexes = new int[_maxEdgesCount - _minEdgesCount];
  for (int i = 0, j = 0; i < _verticesCount * _verticesCount; i++)
  {
    if ((i / _verticesCount <= i % _verticesCount) && (adjacencyMatrix[i] == 0))
      indexes[j++] = i;
  }

  for (int i = _maxEdgesCount - _minEdgesCount - 1; i >= _maxEdgesCount - edgesCount; i--)
  {
    int j = i / (double)RAND_MAX * rand();
    int tmp = indexes[i];
    indexes[i] = indexes[j];
    indexes[j] = tmp;

    adjacencyMatrix[indexes[i]] = (_max - _min + 1) / (double)RAND_MAX * rand() + _min;
  }
  delete[] indexes;

  TGraph resultGraph(_verticesCount, adjacencyMatrix);
  delete[] adjacencyMatrix;

  return resultGraph;
}

int TGraph::numberOfComponents() const
{
  if (verticesCount == 0) return 0;
  if (edgesCount == 0) return verticesCount;

  int numberOfComponents = verticesCount;
  TDisjointSet components(verticesCount);
  for (int i = 0; i < verticesCount; i++)
    components.makeSet(i);

  for (int i = 0; i < edgesCount; i++)
  {
    if (components.find(edges[i].getStartVertex())
     != components.find(edges[i].getEndVertex()))
    {
      components.unite(components.find(edges[i].getStartVertex()),
                       components.find(edges[i].getEndVertex()));
      numberOfComponents--;
    }
  }

  return numberOfComponents;
}

std::ostream& operator<<(std::ostream& out, const TGraph& _graph)
{
  out << "Vertices: [ ";
  for (int i = 0; i < _graph.verticesCount; i++)
    out << i << " ";
  out << "]" << std::endl;
  out << "Edges: [ ";
  for (int i = 0; i < _graph.edgesCount; i++)
    out << _graph.edges[i] << " ";
  out << "]" << std::endl;
  return out;
};