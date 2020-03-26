#include <iostream>

#include "TGenerator.h"
#include "TGraph.h"
#include "TKruskalsAlgorithm.h"

int main()
{
    std::cout << "Kruskal's algorithm demo" << std::endl;
    std::cout << "Random graph test" << std::endl;
    TGraph random_graph = TGenerator::getRandomConnectedGraph(10);
    std::cout << "Initial graph:" << std::endl << random_graph << std::endl;
    std::cout << "Final graph" << std::endl;
    std::cout << TKruskalsAlgorithm::findTree(random_graph) << std::endl;

    std::cout << "Manual graph test" << std::endl;
    std::cout << "Please, input graph" << std::endl;
    try
    {
    TGraph manual_graph(5);
    std::cin >> manual_graph;
    std::cout << "Initial graph:" << std::endl << manual_graph << std::endl;
    std::cout << "Final graph" << std::endl;
    
        std::cout << TKruskalsAlgorithm::findTree(manual_graph) << std::endl;
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
        else
        {
            std::cout << "Unexpected exception";
            return 2;
        }
    }
    return 0;
}