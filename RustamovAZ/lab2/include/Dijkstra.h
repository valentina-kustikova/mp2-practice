#ifndef __DIJKSTRA__H__
#define __DIJKSTRA__H__

#include "Graph.h"

#include <vector>

class Dijkstra
{
public:
    static void Algorithm(const Graph& _graph, const int _start, vector<vector<int> >& _paths, float* _result); // .., start, paths, result
};

#endif