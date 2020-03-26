#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "DivSets.h"
#include "PQueue.h"

class Edge
{
public:
    int a;
    int b;
    double w;//вес
    Edge();
    Edge(int _a, int _b, int _w = 0);
    Edge(const Edge& tmp);
    ~Edge();
};

class Graph
{
public:
    int n;
    int m;
    Edge* E;

    Graph();
    Graph(int _n, int _m, Edge* _E);
    Graph(const Graph& tmp);
    ~Graph();
    int GetN();

    static Edge* AKraskal(const Graph& tmp);
    static void ADijkstra(const Graph& tmp, int* up, double* dist, int start);
};

#endif
