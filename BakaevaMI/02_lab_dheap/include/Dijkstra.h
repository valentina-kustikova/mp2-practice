#ifndef _DIJKSTRA_H_
#define _DIJKSTRAL_H_
#include "Graph.h"
#include "DHeap.h"
#include "Edge.h"
#include <vector>

class Dijkstra
{
public:
    static void DijkstraAlg(const Graph&, int, float*, vector<vector<int>>&);
};

#endif 