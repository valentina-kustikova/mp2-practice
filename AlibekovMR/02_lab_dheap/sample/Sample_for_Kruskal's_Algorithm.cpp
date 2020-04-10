#include "..\include\Algorithms.h"
#include "iostream"

int main()
{
  int verticesCount_1 = 7;
  int *vertices_1 = new int[verticesCount_1];
  for (int i = 0; i < verticesCount_1; i++)
    vertices_1[i] = i;
  int edgesCount_1 = 12;
  TEdge edges_1[12] = { TEdge(0, 5, 2), TEdge(0, 4, 3), TEdge(0, 1, 8), TEdge(1, 4, 6),
                      TEdge(1, 2, 10), TEdge(1, 3, 1), TEdge(1, 5, 2), TEdge(2, 3, 5),
                      TEdge(2, 4, 2), TEdge(2, 5, 9), TEdge(3, 4, 4), TEdge(6, 6, 9)};

  TGraph graph_1(verticesCount_1, vertices_1, edges_1, edgesCount_1);
  std::cout << graph_1 << std::endl;
  std::cout << "//--------------------------------//" << std::endl;
  graph_1.printAdjacencyMatrix();
  std::cout << "//--------------------------------//" << std::endl;
  std::cout << "// Number of components graph_1: " << graph_1.numberOfComponents() << std::endl;
  std::cout << "//--------------------------------//" << std::endl;

  try
  {
    TGraph spanningTree = KruskalAlgorithm::kruskalAlgorithm(graph_1);
    std::cout << spanningTree;
    spanningTree.printAdjacencyMatrix();
  }
  catch (MyException const & e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile:" << e.errorFile() << std::endl;
  }

  int verticesCount_2 = 6;
  int *vertices_2 = new int[verticesCount_2];
  for (int i = 0; i < verticesCount_2; i++)
    vertices_2[i] = i;
  int edgesCount_2 = 11;
  TEdge edges_2[11] = { TEdge(0, 5, 2), TEdge(0, 4, 3), TEdge(0, 1, 8), TEdge(1, 4, 6),
                      TEdge(1, 2, 10), TEdge(1, 3, 1), TEdge(1, 5, 2), TEdge(2, 3, 5),
                      TEdge(2, 4, 2), TEdge(2, 5, 9), TEdge(3, 4, 4)};

  TGraph graph_2(verticesCount_2, vertices_2, edges_2, edgesCount_2);
  std::cout << graph_2 << std::endl;
  std::cout << "//--------------------------------//" << std::endl;
  graph_2.printAdjacencyMatrix();
  std::cout << "//--------------------------------//" << std::endl;
  std::cout << "// Number of components graph_2: " << graph_2.numberOfComponents() << std::endl;
  std::cout << "//--------------------------------//" << std::endl;
  try
  {
    TGraph spanningTree = KruskalAlgorithm::kruskalAlgorithm(graph_2);
    std::cout << spanningTree;
    spanningTree.printAdjacencyMatrix();
  }
  catch (MyException const & e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile:" << e.errorFile() << std::endl;
  }

  std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~//" << std::endl << std::endl;
  delete[] vertices_1;
  delete[] vertices_2;
  system("pause");
  return 0;
}