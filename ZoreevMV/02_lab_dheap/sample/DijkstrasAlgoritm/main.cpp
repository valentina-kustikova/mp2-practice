#include <iostream>

#include "TGenerator.h"
#include "TGraph.h"
#include "TDijkstrasAlgorithm.h"

int main()
{
    std::cout << "Dijkstras's algorithm demo" << std::endl;
    std::cout << "Random graph test" << std::endl;
    TGraph random_graph(10, 20);
    std::cout << "Initial graph:" << std::endl << random_graph << std::endl;
    std::cout << "Final graph for root 0" << std::endl;
    std::cout << TDijkstrasAlgorithm::findTree(random_graph, 0) << std::endl;

    std::cout << "Manual graph test" << std::endl;
    std::cout << "Please, input graph" << std::endl;
    try
    {
    TGraph manual_graph(5, nullptr, 0);
    std::cin >> manual_graph;
    std::cout << "Please, input root vertex: ";
    size_t root;
    std::cin >> root;
    if (root >= manual_graph.getVerticiesCount()) throw TBadIdException();
    std::cout << "Initial graph:" << std::endl << manual_graph << std::endl;
    std::cout << "Final graph" << std::endl;
    
        std::cout << TDijkstrasAlgorithm::findTree(manual_graph, root) << std::endl;
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
    catch (const TBadIdException& exception)
    {
        std::cout << "Wrong root vertex";
        return 1;
    }
    return 0;
}