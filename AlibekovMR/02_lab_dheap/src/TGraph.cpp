#include "TGraph.h"

TGraph::TGraph(int _verticesCount)
{
  verticesCount = _verticesCount;
  edgesCount = _verticesCount * (_verticesCount - 1) / 2;
  edges = new TWeightedEdge[edgesCount];
  edgesCount = 0;
}

TGraph::TGraph(int _verticesCount, int _edgesCount, TWeightedEdge* _edges)
{
  verticesCount = _verticesCount;
  edgesCount = _edgesCount;
  edges = new TWeightedEdge[edgesCount];
  for (int j = 0; j < edgesCount; j++)
    edges[j] = _edges[j];
}

TGraph::TGraph(const TGraph & _graph)
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

  for (int i = 0; i < edgesCount; i++)
  {
    TWeightedEdge currentEdge = edges[i];
    int startVertex = currentEdge.getStartVertex();
    int endVertex = currentEdge.getEndVertex();
    adjacencyMatrix[startVertex * verticesCount + endVertex] = currentEdge.getWeight();
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