#ifndef _KRUSKAL_H_
#define _KRUSKAL_H_
#include "Graph.h"
#include "DHeap.h"
#include "Edge.h"
#include <vector>

class Kruskal
{
public:
    static void KruskalAlg(const Graph&, vector<Edge>&);
};

#endif 

