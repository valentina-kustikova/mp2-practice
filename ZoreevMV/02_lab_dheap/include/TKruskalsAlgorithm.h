#pragma once

#include "THeap.h"
#include "TSet.h"
#include "TGraph.h"

static class TKruskalsAlgorithm
{
public:
    static TGraph findTree(const TGraph& graph);
};

