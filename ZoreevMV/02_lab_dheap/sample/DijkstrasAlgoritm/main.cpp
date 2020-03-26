#include <iostream>

#include "TGenerator.h"
#include "TGraph.h"
#include "TDijkstrasAlgorithm.h"

int main()
{
    std::cout << "Dijkstras's algorithm demo" << std::endl;
    std::cout << "Random graph test" << std::endl;
    TGraph random_graph = TGenerator::getRandomConnectedGraph(10);
    std::cout << "Initial graph:" << std::endl << random_graph << std::endl;
    std::cout << "Final graph for root 0" << std::endl;
    std::cout << TDijkstrasAlgorithm::findTree(random_graph, 0) << std::endl;

    std::cout << "Manual graph test" << std::endl;
    std::cout << "Please, input graph" << std::endl;
    try
    {
    TGraph manual_graph(5);
    std::cin >> manual_graph;
    std::cout << "Please, input root vertex: ";
    size_t root;
    std::cin >> root;
    if (root >= manual_graph.getVerticiesCount()) throw TException(BadId, __LINE__);
    std::cout << "Initial graph:" << std::endl << manual_graph << std::endl;
    std::cout << "Final graph" << std::endl;
    
        std::cout << TDijkstrasAlgorithm::findTree(manual_graph, 0) << std::endl;
    }
    catch (TException exception)
    {
        if (exception.code == WrongGraph)
        {
            std::cout << "Wrong kind of graph";
        }
        else if ((exception.code == BadEdge) || (exception.code == BadSize))
        {
            std::cout << "Wrong input";
            return 1;
        }
        else if (exception.code == BadId)
        {
            std::cout << "Wrong root vertex";
            return 2;
        }
        else
        {
            std::cout << "Unexpected exception";
            return 3;
        }
    }
    return 0;
}