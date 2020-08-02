#include "Algorithms.h"
#include <time.h>

//------------------------------------ Test (example) -----------------------------------//

void _tETestMain()
{
  const int startVertex = 0;

  //------------------ graph_1 ------------------//

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

  TGraph graph_1(verticesCount_1, edgesCount_1, edges_1);
  std::cout << std::endl << "  Graph #1: " << std::endl;
  std::cout << graph_1 << std::endl;
  std::cout << "  --------- adjacency matrix of graph #1 -----------  " << std::endl;
  graph_1.printAdjacencyMatrix();
  std::cout << std::endl;

  try
  {
    TDistances distances = DijkstraAlgorithm::dijkstraAlgorithm(graph_1, startVertex);
    std::cout << "  -------------------- result ----------------------  " << std::endl;
    std::cout << std::endl << distances << std::endl;
  }
  catch (MyException const& e)
  {
    std::cout << "Error: "     << e.what()      << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }

  //------------------ graph_2 ------------------//

  int verticesCount_2 = 6;
  int edgesCount_2 = 11;
  TWeightedEdge edges_2[11] =
  {
    TWeightedEdge(0, 5, -2),
    TWeightedEdge(0, 4,  3),
    TWeightedEdge(0, 1,  8),
    TWeightedEdge(1, 4,  6),
    TWeightedEdge(1, 2, -7),
    TWeightedEdge(1, 3,  1),
    TWeightedEdge(1, 5, -2),
    TWeightedEdge(2, 3,  5),
    TWeightedEdge(2, 4,  2),
    TWeightedEdge(2, 5, -9),
    TWeightedEdge(3, 4, -4)
  };

  TGraph graph_2(verticesCount_2, edgesCount_2, edges_2);
  std::cout << std::endl << std::endl << "  Graph #2: ";
  std::cout << std::endl << graph_2 << std::endl;
  std::cout << "  --------- adjacency matrix of graph #2 -----------  " << std::endl;
  graph_2.printAdjacencyMatrix();
  std::cout << std::endl;

  try
  {
    TDistances distances = DijkstraAlgorithm::dijkstraAlgorithm(graph_2, startVertex);
    std::cout << "  -------------------- result ----------------------  " << std::endl;
    std::cout << std::endl << distances << std::endl;
  }
  catch (MyException const& e)
  {
    std::cout << "Error: "     << e.what()      << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }

  //------------------ graph_3 ------------------//

  int verticesCount_3 = 6;
  int edgesCount_3 = 11;
  TWeightedEdge edges_3[11] =
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

  TGraph graph_3(verticesCount_3, edgesCount_3, edges_3);
  std::cout << std::endl << std::endl << "  Graph #3: ";
  std::cout << std::endl << graph_3 << std::endl;
  std::cout << "  --------- adjacency matrix of graph #3 -----------  " << std::endl;
  graph_3.printAdjacencyMatrix();
  std::cout << std::endl;

  try
  {
    TDistances distances = DijkstraAlgorithm::dijkstraAlgorithm(graph_3, startVertex);
    std::cout << "  -------------------- result ----------------------  " << std::endl;
    std::cout << std::endl << distances << std::endl;
  }
  catch (MyException const& e)
  {
    std::cout << "Error: " << e.what() << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }
}

//--------------------------------- Test (random graphs) --------------------------------//

void _tRGTestMain()
{
  int _min;
  int _max;
  int _verticesCount;
  int _startVertex;

  srand((unsigned int)time(0));

  std::cout << std::endl;
  std::cout << "Enter count of vertices: ";
  std::cin >> _verticesCount;
  while (_verticesCount < 0)
  {
    std::cout << std::endl;
    std::cout << "Count of vertices must be > 0!" << std::endl;
    std::cout << "Enter count of vertices: ";
    std::cin >> _verticesCount;
  };

  std::cout << std::endl;
  std::cout << "Enter left border value: ";
  std::cin >> _min;
  std::cout << "Enter right border value: ";
  std::cin >> _max;

  while (_min > _max)
  {
    std::cout << std::endl;
    std::cout << "Left border value must be < right border value!" << std::endl;
    std::cout << "Enter left border value: ";
    std::cin >> _min;
    std::cout << "Enter right border value: ";
    std::cin >> _max;
  };

  std::cout << std::endl;
  std::cout << "Enter start vertex for Dijkstra's algorithm: ";
  std::cin >> _startVertex;
  while ((_startVertex < 0) || (_startVertex >= _verticesCount))
  {
    std::cout << std::endl;
    std::cout << "Start vertex must be >= 0 and < count of vertices!" << std::endl;
    std::cout << "Enter start vertex for Dijkstra's algorithm: ";
    std::cin >> _startVertex;
  };

  try
  {
    TGraph graph = TGraph::generateRandomConnectedGraphWithoutLoops(_verticesCount, _min, _max);
    std::cout << std::endl << std::endl << "  Random connected graph without loops: ";
    std::cout << std::endl << graph << std::endl;
    std::cout << "  --------- adjacency matrix of random graph -----------  " << std::endl;
    graph.printAdjacencyMatrix();
    std::cout << std::endl;

    TDistances distances = DijkstraAlgorithm::dijkstraAlgorithm(graph, _startVertex);
    std::cout << "  -------------------- result ----------------------  " << std::endl;
    std::cout << std::endl << distances << std::endl;
  }
  catch (MyException const& e)
  {
    std::cout << "Error: "     << e.what()      << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }
}

//----------------------------------- Test (user input) ---------------------------------//

void _tUITestMain()
{
  try
  {
    int startVertex;

    TGraph graph(5);
    std::cin >> graph;

    std::cout << std::endl << "  Graph: ";
    std::cout << std::endl << graph << std::endl;
    std::cout << "  --------- adjacency matrix of graph -----------  " << std::endl;
    graph.printAdjacencyMatrix();
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Enter start vertex for Dijkstra's algorithm: ";
    std::cin >> startVertex;
    while ((startVertex < 0) || (startVertex >= graph.getVerticesCount()))
    {
      std::cout << std::endl;
      std::cout << "Start vertex must be >= 0 and < count of vertices!" << std::endl;
      std::cout << "Enter start vertex for Dijkstra's algorithm: ";
      std::cin >> startVertex;
    };

    TDistances distances = DijkstraAlgorithm::dijkstraAlgorithm(graph, startVertex);
    std::cout << "  -------------------- result ----------------------  " << std::endl;
    std::cout << std::endl << distances << std::endl;
  }
  catch (MyException const& e)
  {
    std::cout << "Error: "     << e.what()      << std::endl;
    std::cout << "errorLine: " << e.errorLine() << std::endl;
    std::cout << "errorFile: " << e.errorFile() << std::endl;
  }
}

//----------------------------------------- Main ----------------------------------------//

int main()
{
  bool isItAll = false;
  std::cout << "---------------|| Dijkstra's Shortest Path First Algorithm ||--------------" << std::endl;
  do
  {
    std::cout << "Choose mode of test: " << std::endl;
    std::cout << "  0 - \"Example\"     1 - \"Random graphs\"     2 - \"User input\"" << std::endl;
    int mode = 0;
    std::cin >> mode;
    std::cin.ignore();
    switch (mode)
    {
    case 0:
      std::cout << "//-------------------------- Test (example) -------------------------//";
      _tETestMain();
      std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//";
      std::cout << std::endl << std::endl;
      break;
    case 1:
      std::cout << "//---------------------- Test (random graphs) -----------------------//";
      _tRGTestMain();
      std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//";
      std::cout << std::endl << std::endl;
      break;
    case 2:
      std::cout << "//------------------------ Test (user input) ------------------------//";
      _tUITestMain();
      std::cout << "//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//";
      std::cout << std::endl << std::endl;
      break;
    }
    std::cout << "Do you want to exit?" << std::endl;
    std::cout << "  1 - Yes     0 - No" << std::endl << std::endl;
    std::cin >> isItAll;
    std::cin.ignore();
  } while (!isItAll);

  system("pause");
  return 0;
}