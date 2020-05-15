#ifndef _DIJKSTRAALGORITH_H_
#define _DIJKSTRAALGORITH_H_
#include "TGraph.h"
#include "Pair.h"
#include "THeap.h"

class DijkstraAlgorithm
{
public:
	static void dijkstraAlgorithm(const TGraph& graph, std::vector<std::vector<int>>& path, float*& resultDist, int vertexStart = 0);
};

#endif //!_DIJKSTRAALGORITH_H_
