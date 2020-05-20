#include "TGraph.h"

TGraph::TGraph(int _verticesCount, int *_vertices)
{
  verticesCount = _verticesCount;
  vertices = new int[verticesCount];
  for (int i = 0; i < verticesCount; i++)
    vertices[i] = _vertices[i];
  edgesCount = _verticesCount * (_verticesCount - 1) / 2;
  edges = new TEdge[edgesCount];
  edgesCount = 0;
}

TGraph::TGraph(int _verticesCount, int * _vertices, TEdge * _edges, int _edgesCount)
{
  verticesCount = _verticesCount;
  vertices = new int[verticesCount];
  for (int i = 0; i < verticesCount; i++)
    vertices[i] = _vertices[i];
  edgesCount = _edgesCount;
  edges = new TEdge[edgesCount];
  for (int j = 0; j < edgesCount; j++)
    edges[j] = _edges[j];
}

TGraph::TGraph(const TGraph & _graph)
{
  verticesCount = _graph.verticesCount;
  edgesCount = _graph.edgesCount;
  vertices = new int[verticesCount];
  for (int i = 0; i < verticesCount; i++)
    vertices[i] = _graph.vertices[i];
  edges = new TEdge[edgesCount];
  for (int j = 0; j < edgesCount; j++)
    edges[j] = _graph.edges[j];
}

TGraph::~TGraph()
{
  delete[] vertices;
  delete[] edges;
}

void TGraph::addNewEdge(const TEdge & _newEdge)
{
  int maxCountOfEdges = verticesCount * (verticesCount - 1) / 2;
  if (edgesCount + 1 > maxCountOfEdges)
    throw ExceptionOutOfRange(__LINE__, __FILE__);
  if (!isEdgeInGraph(_newEdge))
    edges[edgesCount++] = _newEdge;
}

bool TGraph::isEdgeInGraph(const TEdge & _edge) const
{
  for (int i = 0; i < edgesCount; i++)
    if (edges[i] == _edge)
      return true;
  return false;
}

bool TGraph::isGraphConnected() const
{
  if (numberOfComponents() < 1)
    throw ExceptionGraphWithoutVertices(__LINE__, __FILE__);
  if (numberOfComponents() == 1)
    return true;
  return false;
}

bool TGraph::isGraphDisconnected() const
{
  if (numberOfComponents() < 1)
    throw ExceptionGraphWithoutVertices(__LINE__, __FILE__);
  if (numberOfComponents() > 1)
    return true;
  return false;
}

std::ostream & operator<<(std::ostream & out, const TGraph & _graph)
{
  out << "Vertices: [ ";
  for (int i = 0; i < _graph.verticesCount; i++)
    out << _graph.vertices[i] << " ";
  out << "]" << std::endl;
  out << "Edges: [ ";
  for (int i = 0; i < _graph.edgesCount; i++)
    out << "(" << _graph.edges[i].startVertex << " " << _graph.edges[i].endVertex << ") ";
  //<< " " << _graph.edges[i].weight << ") ";
  out << "]" << std::endl;
  return out;
}

int* TGraph::getAdjacencyMatrix() const
{
  int* adjacencyMatrix = new int[verticesCount * verticesCount];
  for (int k = 0; k < verticesCount * verticesCount; k++)
    adjacencyMatrix[k] = 0;

  for (int i = 0; i < edgesCount; i++)
  {
    TEdge currentEdge = edges[i];
    int startVertex = currentEdge.startVertex;
    int endVertex = currentEdge.endVertex;
    adjacencyMatrix[startVertex * verticesCount + endVertex] = currentEdge.weight;
    adjacencyMatrix[endVertex * verticesCount + startVertex] = currentEdge.weight;
  }

  return adjacencyMatrix;
}

void TGraph::printAdjacencyMatrix() const
{
  int* adjacencyMatrix = getAdjacencyMatrix();

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
  int numberOfComponents = 0;
  if (verticesCount == 0)
    return numberOfComponents;
  bool *isVertexPassed = new bool[verticesCount];
  std::pair<int, int> *verticesWithIndexes = new std::pair<int, int>[verticesCount];
  for (int i = 0; i < verticesCount; i++)
  {
    isVertexPassed[i] = false;
    verticesWithIndexes[i].first = i;                //first - index
    verticesWithIndexes[i].second = vertices[i];     //second - vertex
  }
  
  for (int i = 0; i < verticesCount; i++)
  {
    if (!isVertexPassed[i])
    {
      std::queue<std::pair<int, int>> qVertices;
      qVertices.push(verticesWithIndexes[0]);
      while (!qVertices.empty())
      {
        std::pair<int, int> vertexWithIndex(qVertices.front());
        qVertices.pop();
        isVertexPassed[vertexWithIndex.first] = true;
        for (int i = 0; i < edgesCount; i++)
        {
          if (edges[i].startVertex == vertexWithIndex.second)
            for (int j = 0; j < verticesCount; j++)
              if ((vertices[j] == edges[i].endVertex) && (!isVertexPassed[j]))
              {
                qVertices.push(std::pair<int, int>(j, vertices[j]));
                break;
              }
          if (edges[i].endVertex == vertexWithIndex.second)
            for (int j = 0; j < verticesCount; j++)
              if ((vertices[j] == edges[i].startVertex) && (!isVertexPassed[j]))
              {
                qVertices.push(std::pair<int, int>(j, vertices[j]));
                break;
              }
        }
      }
      numberOfComponents++;
    }
  }
  return numberOfComponents;

  /*std::queue<int> qVertices;
  std::queue<int> verticesIndexes;
  qVertices.push(vertices[0]);
  verticesIndexes.push(0);
  while (!qVertices.empty())
  {
    int vertex = qVertices.front();
    int vertexIndex = verticesIndexes.front();
    qVertices.pop();
    verticesIndexes.pop();
    isVertexPassed[vertexIndex] = true;
    for (int i = 0; i < edgesCount; i++)
    {
      if (edges[i].startVertex == vertex)
        for (int j = 0; j < verticesCount; j++)
          if ((vertices[j] == edges[i].endVertex) && (!isVertexPassed[j]))
          {
            qVertices.push(vertex);
            verticesIndexes.push(j);
            break;
          }
      if (edges[i].endVertex == vertex)
        for (int j = 0; j < verticesCount; j++)
          if ((vertices[j] == edges[i].startVertex) && (!isVertexPassed[j]))
          {
            qVertices.push(vertex);
            verticesIndexes.push(j);
            break;
          }
    }
  }*/
};