#include <iostream>

#include "TGenerator.h"
#include "TGraph.h"
#include "TKruskalsAlgorithm.h"

int main()
{
    std::cout << "Kruskal's algorithm demo" << std::endl;
    std::cout << "Random graph test" << std::endl;
    TGraph random_graph = TGraph::getRandomConnectedGraph(10);
    std::cout << "Initial graph:" << std::endl << random_graph << std::endl;
    std::cout << "Final graph" << std::endl;
    std::cout << TKruskalsAlgorithm::findTree(random_graph) << std::endl;

    std::cout << "Manual graph test" << std::endl;
    std::cout << "Please, input graph" << std::endl;
    try
    {
    TGraph manual_graph(5, nullptr, 0);
    std::cin >> manual_graph;
    std::cout << "Initial graph:" << std::endl << manual_graph << std::endl;
    std::cout << "Final graph" << std::endl;
    
        std::cout << TKruskalsAlgorithm::findTree(manual_graph) << std::endl;
    }
    catch (const TWrongGraphException& exception)
    {
        std::cout << "Wrong kind of graph";
        return 1;
    }
    catch (const TBadEdgeException& exception)
    {
        std::cout << "Wrong input";
        return 1;
    }
    catch (const TBadSizeException exception)
    {
        std::cout << "Wrong input";
        return 1;
    }
    return 0;
}