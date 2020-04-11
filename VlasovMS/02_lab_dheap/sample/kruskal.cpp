#include <iostream>
#include "KruskalAlgorithm.h"

int main()
{
    TGraph graph1({
        TEdge(1, 4, 0),
        TEdge(1, 3, 1),
        TEdge(2, 4, 2),
        TEdge(0, 5, 2),
        TEdge(1, 5, 2),
        TEdge(0, 4, 3),
        TEdge(3, 4, 4),
        TEdge(2, 3, 5),
        TEdge(0, 1, 8),
        TEdge(2, 5, 9),
        TEdge(1, 2, 10)
        }, 6);
    std::cout << "Test Graph 1:\n" << graph1;
    std::cout << "Paths Tree 1:\n" << GraphAlgorithms::kruskalAlgorithm(graph1);

    TGraph graph3;
    std::cout << "Test Graph 3:\nInput >> ";
    std::cin >> graph3;
    std::cout << graph3;
    std::cout << "Paths Tree 3:\n" << GraphAlgorithms::kruskalAlgorithm(graph3);
}