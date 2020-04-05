#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include "Set.h"
#include "Edge.h"

using namespace std;

class Graph
{
private:
    int size;
    int countEdges;
    Edge* edges;

public:
    Graph();
    Graph(const Graph&);
    Graph(int* matrix, int size);
    ~Graph();

    int GetSize() const;
    Edge* GetEdges() const;
    int GetCountEdges() const;
    void SetCountEdges(int);
    bool IsConnected() const;
    float* GetWeightMatrix() const;

    friend istream& operator>>(istream& in, Graph& gr);
};
#endif
