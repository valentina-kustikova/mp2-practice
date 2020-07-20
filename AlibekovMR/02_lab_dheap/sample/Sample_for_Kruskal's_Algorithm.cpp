#include "Algorithms.h"
#include "iostream"

int main()
{
  int verticesCount_1 = 7;
  int edgesCount_1 = 12;
  TWeightedEdge edges_1[12] = 
  { 
    TWeightedEdge(0, 5, 2), 
    TWeightedEdge(0, 4, 3), 
    TWeightedEdge(0, 1, 8), 
    TWeightedEdge(1, 4, 6),      
    TWeightedEdge(1, 2, 7), 
    TWeightedEdge(1, 3, 1), 
    TWeightedEdge(1, 5, 2), 
    TWeightedEdge(2, 3, 5),
    TWeightedEdge(2, 4, 2), 
    TWeightedEdge(2, 5, 9), 
    TWeightedEdge(3, 4, 4), 
    TWeightedEdge(6, 6, 9)
  };

  TGraph graph_1(verticesCount_1, edges_1, edgesCount_1);
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
    std::cout << "Error: "     << e.what()      << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }

  int verticesCount_2 = 6;
  int edgesCount_2 = 11;
  TWeightedEdge edges_2[11] = 
  { 
    TWeightedEdge(0, 5, 2), 
    TWeightedEdge(0, 4, 3), 
    TWeightedEdge(0, 1, 8), 
    TWeightedEdge(1, 4, 6),
    TWeightedEdge(1, 2, 7), 
    TWeightedEdge(1, 3, 1), 
    TWeightedEdge(1, 5, 2), 
    TWeightedEdge(2, 3, 5),
    TWeightedEdge(2, 4, 2), 
    TWeightedEdge(2, 5, 9), 
    TWeightedEdge(3, 4, 4)
  };

  TGraph graph_2(verticesCount_2, edges_2, edgesCount_2);
  std::cout << std::endl << graph_2 << std::endl;
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
    std::cout << "Error: "     << e.what()      << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }

  std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~//" << std::endl << std::endl;
  system("pause");
  return 0;
}