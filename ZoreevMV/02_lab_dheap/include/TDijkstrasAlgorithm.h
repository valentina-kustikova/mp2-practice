#pragma once

#include "TGraph.h"
#include "THeap.h"

struct VertexDistance
{
    size_t vertex;
    size_t distance;

    bool operator<(const VertexDistance& temp);
    bool operator>(const VertexDistance& temp);
    bool operator==(const VertexDistance& temp);
};

static class TDijkstrasAlgorithm
{
public:
    static TGraph findTree(const TGraph& graph, size_t root);
};

