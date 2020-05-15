#ifndef _TGRAPH_H_
#define _TGRAPH_H_
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Edge.h"
#include "THeap.h"
#include "TSplitSet.h"

class TGraph
{
	Edge* edges = nullptr;
	int vertexCount = 0, edgesCount = 0;
	bool Connectivity(const bool* adjacencyMatrix) const;

	friend class KruskalAlgorithm;
	friend class DijkstraAlgorithm;
public:
	TGraph();
	TGraph(Edge* edges_, int edgesCount_, int vertexCount_);

	friend std::ostream& operator<< (std::ostream& out, const TGraph& temp);
	friend std::istream& operator>> (std::istream& out, TGraph& temp);
};

#endif // !_TGRAPH_H_