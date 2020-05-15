#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>
#include <exception>

#include "TDHeap.h"
#include "Edge.h"

using namespace std;

class Graph
{
private:
    int countVertices;
    float* weights;

public:
    Graph();
    Graph(int _size);
    Graph(float* _vector, int _size);
    Graph(const Graph& _graph);
    ~Graph();

    int GetVerticesCount() const;

    void RandomGraph();
    void RandomConnectedGraph();
    void ListOfEdges(Edge*, int&) const;
    float* AdjacencyMatrix() const;
    bool IsConnected() const;

    friend istream& operator>>(istream&, Graph&);
    friend ostream& operator<<(ostream&, const Graph&);
};

#endif