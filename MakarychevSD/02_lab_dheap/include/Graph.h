#ifndef GRAPH_H    
#define GRAPH_H

#include "WeightedEdge.h"
#include <cstdlib>
#include <time.h>
#include <queue>
#include "Exception.h"

class Graph
{
private:
	int numVertex;
	int numEdges;
	WeightedEdge* Edges;
public:
	Graph();
	Graph(int _numVertex, int _numEdges);
	Graph(int _numVertex, int _numEdges, WeightedEdge* _Edges);
	Graph(const Graph&);
	~Graph();
	void GenerateConnectedGraph();

	bool IsCorrectEdge(const WeightedEdge& Edge);
	bool IsConnected()const;

	int GetnumVertex()const;
	int GetnumEdges()const;

	friend ostream& operator << (ostream& out, const Graph& G);
	friend istream& operator >> (istream& in, Graph& G);

	friend class KruskalsAlgorithm;
};

#endif
